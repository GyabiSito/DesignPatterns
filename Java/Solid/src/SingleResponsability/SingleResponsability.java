package SingleResponsability;

import java.io.*;
import java.util.ArrayList;
import java.util.List;

//SRP
class Journal {
    private final List<String> entries=new ArrayList<>();
    private static int count=0;

    public void addEntry(String text){
        entries.add("" + (++count) + ": " + text);
    }
    public void removeEntry(int index){
        entries.remove(index);
    }

    @Override
    public String toString(){
        return String.join(System.lineSeparator(), entries);
    }

//    public void save(String filename){
//        try(PrintStream out = new PrintStream(filename)){
//            out.println(toString());
//        } catch (FileNotFoundException e) {
//            throw new RuntimeException(e);
//        }
//    }

//    public void load(String filename){}
//    public void load(URL url){}

}

class Persistence{
    public void saveToFile(Journal journal, String filename, boolean overwrite){
        if(overwrite || new File(filename).exists()){
            try(PrintWriter out = new PrintWriter(filename)){
                out.println(journal.toString());
            }catch(FileNotFoundException e){
                throw new RuntimeException(e);
            }
        }
    }
//    public Journal load(String filename){}
//    public Journal load(URL url){}
}


class Demo{
    public static void main(String[] args) throws IOException {
        Journal journal=new Journal();
        journal.addEntry("Hello");
        journal.addEntry("World");
        System.out.println(journal);

        Persistence persistence=new Persistence();
        String filename="filename.txt";
        persistence.saveToFile(journal, filename, true);

        Runtime.getRuntime().exec("notepad.exe " + filename);
    }
}
