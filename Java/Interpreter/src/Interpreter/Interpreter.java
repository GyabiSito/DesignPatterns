package Interpreter;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

interface Element {
    int eval();
}

class Integer implements Element {
    private int value;

    public Integer(int value) {
        this.value = value;
    }

    @Override
    public int eval() {
        return value;
    }
}

class BinaryOperation implements Element {
    public enum Type {
        ADDITION, SUBTRACTION
    }

    public Type type;
    public Element left, right;

    @Override
    public int eval() {
        switch (type) {
            case ADDITION:
                return left.eval() + right.eval();
            case SUBTRACTION:
                return left.eval() - right.eval();
            default:
                return 0;
        }
    }
}


class Token {
    public enum Type {
        INTEGER, PLUS, MINUS, LPAREN, RPAREN
    }

    public Type type;
    public String text;

    public Token(Type type, String text) {
        this.type = type;
        this.text = text;
    }

    @Override
    public String toString() {
        return "`" + text + "`";
    }
}

class Demo {
    static List<Token> lex(String input) {
        ArrayList<Token> tokens = new ArrayList<Token>();
        for (int i = 0; i < input.length(); ++i) {
            switch (input.charAt(i)) {
                case '+':
                    tokens.add(new Token(Token.Type.PLUS, "+"));
                    break;
                case '-':
                    tokens.add(new Token(Token.Type.MINUS, "-"));
                    break;
                case '(':
                    tokens.add(new Token(Token.Type.LPAREN, "("));
                    break;
                case ')':
                    tokens.add(new Token(Token.Type.RPAREN, ")"));
                    break;
                default:
                    if (Character.isDigit(input.charAt(i))) {
                        StringBuilder sb = new StringBuilder();
                        sb.append(input.charAt(i));
                        while (i + 1 < input.length() && Character.isDigit(input.charAt(i + 1))) {
                            sb.append(input.charAt(++i));
                        }
                        tokens.add(new Token(Token.Type.INTEGER, sb.toString()));
                    }
                    break;

            }
        }
        return tokens;
    }


    static Element parse(List<Token> tokens) {
        List<Element> elements = new ArrayList<>();
        List<Token> current = new ArrayList<>();
        int parenDepth = 0;

        BinaryOperation.Type pendingOp = null;

        for (int i = 0; i < tokens.size(); ++i) {
            Token token = tokens.get(i);

            switch (token.type) {
                case LPAREN:
                    parenDepth++;
                    current.add(token);
                    break;

                case RPAREN:
                    parenDepth--;
                    current.add(token);
                    if (parenDepth == 0) {
                        // Sublista sin paréntesis exteriores
                        List<Token> inner = current.subList(1, current.size() - 1);
                        elements.add(parse(inner));
                        current.clear();
                    }
                    break;

                case INTEGER:
                    if (parenDepth > 0) {
                        current.add(token);
                    } else {
                        elements.add(new Integer(java.lang.Integer.parseInt(token.text)));
                    }
                    break;

                case PLUS:
                    if (parenDepth > 0) {
                        current.add(token);
                    } else {
                        pendingOp = BinaryOperation.Type.ADDITION;
                    }
                    break;

                case MINUS:
                    if (parenDepth > 0) {
                        current.add(token);
                    } else {
                        pendingOp = BinaryOperation.Type.SUBTRACTION;
                    }
                    break;
            }

            if (parenDepth == 0 && pendingOp != null && elements.size() >= 2) {
                BinaryOperation op = new BinaryOperation();
                op.right = elements.remove(elements.size() - 1);
                op.left = elements.remove(elements.size() - 1);
                op.type = pendingOp;
                elements.add(op);
                pendingOp = null;
            }
        }

        return elements.size() == 1 ? elements.get(0) : null;
    }



    public static void main(String[] args) {
        String input = "(13+4)-(12+1)";
        List<Token> tokens = lex(input);
        System.out.println(tokens.stream().map(t -> t.toString()).collect(Collectors.joining("\t")));

        Element parsed=parse(tokens);
        System.out.println(input + " = " + parsed.eval());
    }
}