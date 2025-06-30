package StaticBlockSingleton;

import java.io.File;
import java.io.IOException;

class StaticBlockSingleton {
    private static StaticBlockSingleton instance;

    private StaticBlockSingleton() throws IOException {
        System.out.println("Construccion de StaticBlockSingleton");
        File.createTempFile("test", ".tmp");
    }

    static {
        try {
            System.out.println("Estoy en el bloque estatico, antes del constructor");
            instance = new StaticBlockSingleton();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    public static StaticBlockSingleton getInstance() {
        return instance;
    }
}
class Demo2{
    public static void main(String[] args) {
        StaticBlockSingleton s1 = StaticBlockSingleton.getInstance();
    }
}