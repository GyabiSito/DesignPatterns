package State;
class State {
    void on(LightSwitch ls){}
    void off(LightSwitch ls){}
}
class OnState extends State{
    public OnState(){
        System.out.println("Light on");
    }
    @Override
    void off(LightSwitch ls){
        System.out.println("Switching Light Off...");
        ls.setState(new OffState());
    }
}

class OffState extends State{
    public OffState(){
        System.out.println("Light Turned Off");
    }
    @Override
    void on(LightSwitch ls){
        System.out.println("Switching light on...");
        ls.setState(new OnState());
    }
}

class LightSwitch {
    private State state;
    public LightSwitch(){
        state=new OffState();
    }
    void on(){
        state.on(this);

    }
    void off(){
        state.off(this);
    }

    public void setState(State state){
        this.state=state;
    }
    public State getState(){
        return state;
    }
}
class Demo{
    public static void main(String[] args) {
        LightSwitch ls=new LightSwitch();
        ls.on();
        ls.off();
        ls.off();
    }
}