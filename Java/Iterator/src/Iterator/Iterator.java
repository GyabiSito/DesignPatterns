package Iterator;

import java.util.Iterator;
import java.util.Spliterator;
import java.util.function.Consumer;

class Node<T> {
    public T value;
    public Node<T> left, right, parent;

    public Node(T value) {
        this.value = value;
    }

    public Node(T value, Node<T> left, Node<T> right) {
        this.value = value;
        this.left = left;
        this.right = right;

        left.parent = right.parent = this;
    }
}

class InOrderIterator<T> implements Iterator<T> {
    private Node<T> current, root;
    private boolean yieldedStart;

    public InOrderIterator(Node<T> root) {
        this.root = current = root;

        while (current.left != null) {
            current = current.left;
        }
    }

    private boolean hasRightmostParent(Node<T> node) {
        if (node.parent == null) return false;
        return node == node.parent.left || hasRightmostParent(node.parent);
    }

    @Override
    public boolean hasNext() {
        return current.left != null || current.right != null || hasRightmostParent(current);
    }

    @Override
    public T next() {
        if (!yieldedStart) {
            yieldedStart = true;
            return current.value;
        }
        if (current.right != null) {
            current = current.right;
            while (current.left != null) {
                current = current.left;
            }
            return current.value;
        } else {
            Node<T> p = current.parent;
            while (p != null && current == p.right) {
                current = p;
                p = p.parent;
            }
            current = p;
            return current.value;

        }

    }


    @Override
    public void forEachRemaining(Consumer<? super T> action) {
        Iterator.super.forEachRemaining(action);
    }

    @Override
    public void remove() {
        Iterator.super.remove();
    }
}

class BinaryTree<T> implements Iterable<T> {
    private Node<T> root;

    public BinaryTree(Node<T> root) {
        this.root = root;
    }

    @Override
    public Iterator<T> iterator() {
        return new InOrderIterator<T>(root);
    }

    @Override
    public Spliterator<T> spliterator() {
        return Iterable.super.spliterator();
    }

    @Override
    public void forEach(Consumer<? super T> action) {
        for(T item : this){
            action.accept(item);
        }
    }
}

class Demo {
    public static void main(String[] args) {
        //  1
        // /\
        // 2 3
        //213

        Node<Integer> root = new Node<>(1, new Node<>(2), new Node<>(3));

        InOrderIterator<Integer> it = new InOrderIterator<Integer>(root);

        while (it.hasNext()){
            System.out.print("" + it.next() + ",");
        }
        System.out.println();

        BinaryTree<Integer> bt=new BinaryTree<Integer>(root);
        for (int n: bt){
            System.out.print("" + n + ",");
        }
        System.out.println();
    }
}