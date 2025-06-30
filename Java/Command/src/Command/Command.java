package Command;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class BankAccount {
    private int balance;
    private int overdraftLimit = -500;

    public boolean deposit(int amount) {
        balance += amount;
        System.out.println("Deposited " + amount + " to the bank. Balance: " + balance);
        return true;
    }

    public boolean withdraw(int amount) {
        if (balance - amount >= overdraftLimit) {
            balance -= amount;
            System.out.println("Deposited " + amount + " to the bank. Balance: " + balance);
            return true;
        }
        return false;
    }

    @Override
    public String toString() {
        return "BankAccount{" +
                "balance=" + balance +
                ", overdraftLimit=" + overdraftLimit +
                '}';
    }
}

interface Command {
    void call();

    void undo();
}

class BankAccountCommand implements Command {
    private BankAccount bankAccount;
    private boolean succeded;
    public enum Action {
        DEPOSIT, WITHDRAW
    }

    private Action action;
    private int amount;

    public BankAccountCommand(BankAccount bankAccount, Action action, int amount) {
        this.bankAccount = bankAccount;
        this.action = action;
        this.amount = amount;
    }

    @Override
    public void call() {
        switch (action) {
            case DEPOSIT:
                succeded= bankAccount.deposit(amount);
                break;
            case WITHDRAW:
                succeded=bankAccount.withdraw(amount);
                break;
            default:
                break;
        }
    }

    @Override
    public void undo() {
        if(!succeded) return;
        switch (action) {
            case DEPOSIT:
                bankAccount.withdraw(amount);
                break;
            case WITHDRAW:
                bankAccount.deposit(amount);
                break;
            default:
                break;
        }
    }

    @Override
    public String toString() {
        return "BankAccountCommand{" +
                "bankAccount=" + bankAccount +
                ", action=" + action +
                ", amount=" + amount +
                '}';
    }
}

class Demo {
    public static void main(String[] args) {
        BankAccount ba = new BankAccount();
        System.out.println(ba);

        List<BankAccountCommand> commands = new ArrayList<>(List.of(
                new BankAccountCommand(ba, BankAccountCommand.Action.DEPOSIT, 100),
                new BankAccountCommand(ba, BankAccountCommand.Action.WITHDRAW, 1000)
        ));

        for (Command command : commands) {
            command.call();
            System.out.println(ba);
        }
        Collections.reverse(commands);
        for (Command command : commands) {
            command.undo();
            System.out.println(ba);
        }
    }
}