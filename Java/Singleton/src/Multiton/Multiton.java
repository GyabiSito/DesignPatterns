package Multiton;

import java.util.HashMap;
enum Subsystem{
    PRIMARY,
    AUXILIARY,
    FALLBACK
}

class Printer{
    private static int instanceCounter=0;
    private static HashMap<Subsystem,Printer> instances = new HashMap<Subsystem,Printer>();
    private Printer(){
        instanceCounter++;
        System.out.println("Instance Counter: "+instanceCounter);
    }
    public static Printer get(Subsystem ss)
    {
        if(instances.containsKey(ss)){
            return instances.get(ss);
        }
        Printer printer = new Printer();
        instances.put(ss,printer);
        return printer;
    }
}

public class Multiton{
    public static void main(String[] args) {
        Printer main = Printer.get(Subsystem.PRIMARY);
        Printer aux=Printer.get(Subsystem.AUXILIARY);
        Printer aux2=Printer.get(Subsystem.AUXILIARY);
    }
}
