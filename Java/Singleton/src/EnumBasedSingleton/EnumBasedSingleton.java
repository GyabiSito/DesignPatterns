package EnumBasedSingleton;

import java.io.*;

enum EnumBasedSingleton {
    INSTANCE;

    EnumBasedSingleton() {
        value = 42;
    }

    int value;

    public int getValue() {
        return value;
    }

    public void setValue(int value) {
        this.value = value;
    }
}

class EnumBasedSingletonDemo {
    static void saveToFile(EnumBasedSingleton singleton, String filename)
            throws Exception {
        try (FileOutputStream fileOut = new FileOutputStream(filename);
             ObjectOutputStream out = new ObjectOutputStream(fileOut)) {
            out.writeObject(singleton);
        }
    }

    static EnumBasedSingleton readFromFile(String filename)
            throws Exception {
        try (FileInputStream fileIn = new FileInputStream(filename);
             ObjectInputStream in = new ObjectInputStream(fileIn)) {
            return (EnumBasedSingleton) in.readObject();
        }
    }

    //
    public static void main(String[] args) throws Exception {
        String filename = "myfile.txt";

        EnumBasedSingleton singleton2 = readFromFile(filename);
        System.out.println(singleton2.getValue());
    }
}