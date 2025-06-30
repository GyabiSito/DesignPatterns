package InnerStaticSingleton;

public class InnerStaticSingleton {
    private InnerStaticSingleton(){}
    private static class Impl{
        private static InnerStaticSingleton instance = new InnerStaticSingleton();
    }
    public InnerStaticSingleton getInstance(){
        return Impl.instance;
    }
}
