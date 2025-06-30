package BasicSingleton;

import java.io.*;

class BasicSingleton implements Serializable {
    private static final BasicSingleton INSTANCE = new BasicSingleton();
    private int value = 0;

    private BasicSingleton() {

    }

    public static BasicSingleton getInstance() {
        return INSTANCE;
    }

    public int getValue() {
        return value;
    }
    public void setValue(int value) {
        this.value = value;
    }
}

class Demo{
    static void saveToFile(BasicSingleton singleton, String filename) throws Exception{
        try(FileOutputStream fileOutputStream=new FileOutputStream(filename);
            ObjectOutputStream objectOutputStream=new ObjectOutputStream(fileOutputStream)
        ){
            objectOutputStream.writeObject(singleton);
        }
    }
    static BasicSingleton readFromFile(String filename) throws Exception{
        try(FileInputStream fileInputStream=new FileInputStream(filename);
        ObjectInputStream objectInputStream=new ObjectInputStream(fileInputStream)) {
            return (BasicSingleton) objectInputStream.readObject();
        }
    }
    public static void main(String[] args) throws Exception{
//        BasicSingleton s1 = BasicSingleton.getInstance();
//        s1.setValue(10);
//        System.out.println(s1.getValue());
//        BasicSingleton s2 = BasicSingleton.getInstance();
//        s2.setValue(20);
//        System.out.println(s1.getValue());

        BasicSingleton singleton = BasicSingleton.getInstance();
        singleton.setValue(111);

        String filename="singleton.txt";
        saveToFile(singleton,filename);

        BasicSingleton singleton2 = BasicSingleton.getInstance();
        singleton2.setValue(222);
        System.out.println(singleton == singleton2);

        System.out.println(singleton.getValue());
        System.out.println(singleton2.getValue());

    }
}
