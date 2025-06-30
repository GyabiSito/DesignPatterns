import java.util.ArrayList;
import java.util.List;

class Buffer
{
    private char[] characters;
    private int lineWidth;

    public Buffer(int lineWidth, int lineHeight){
        this.lineWidth = lineWidth;
        characters = new char[lineWidth * lineHeight];
    }

    public char charAt(int x, int y){
        return characters[y * lineWidth + x];
    }
}

class Viewport{
    private final Buffer buffer;
    private final int width;
    private final int height;
    private final int offsetX;
    private final int offsetY;
    public Viewport(Buffer buffer, int width, int height, int offsetX, int offsetY){
        this.buffer = buffer;
        this.width = width;
        this.height = height;
        this.offsetX = offsetX;
        this.offsetY = offsetY;
    }

    public char charAt(int x,int y){
        return buffer.charAt(x+offsetX,y+offsetY);
    }
}

class Console{
    private List<Viewport> viewports=new ArrayList<>();

    int width,height;

    public Console(int width, int height){
        this.width = width;
        this.height = height;
    }

    public void addViewport(Viewport viewport){
        viewports.add(viewport);
    }
    public static Console newConsole(int width, int height){
        Buffer buffer = new Buffer(width,height);
        Viewport viewport = new Viewport(buffer,width,height,0,0);
        Console console = new Console(width,height);
        console.addViewport(viewport);
        return console;
    }
    public void render(){
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                for (Viewport viewport : viewports) {
                    System.out.print(viewport.charAt(j,i));
                }
                System.out.println();
            }
        }
    }
}

class Demo{
    public static void main(String[] args) {
//        Buffer buffer = new Buffer(30,20);
//        Viewport viewport = new Viewport(buffer, 30,20,0,0);
//        Console console = new Console(30,20);
//        console.addViewport(viewport);
//        console.render();

        Console console=Console.newConsole(20,30);
        console.render();
    }
}