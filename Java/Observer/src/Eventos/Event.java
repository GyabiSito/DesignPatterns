package Eventos;

import java.util.HashMap;
import java.util.Map;
import java.util.function.Consumer;

class Event<TArgs> {
    private int count = 0;
    private Map<Integer, Consumer<TArgs>> handlers = new HashMap<>();

    public Subscription addHandler(Consumer<TArgs> handler) {
        int i = count;
        handlers.put(count++,handler);
        return new Subscription(this,i);
    }

    public void fire(TArgs args){
        for (Consumer<TArgs> handler : handlers.values()) {
            handler.accept(args);
        }
    }

    public class Subscription implements AutoCloseable {

        private Event<TArgs> event;
        private int id;

        Subscription(Event<TArgs> event, int id) {
            this.event = event;
            this.id = id;
        }

        @Override
        public void close() {
            event.handlers.remove(id);
        }
    }
}

class PropertyChangedEventArgs{
    public Object source;
    public String propertyName;

    public PropertyChangedEventArgs(Object source, String propertyName) {
        this.source = source;
        this.propertyName = propertyName;
    }
}

class Person{
    public Event<PropertyChangedEventArgs> propertyChanged = new Event<>();
    private int age;
    public int getAge() {
        return age;
    }
    public void setAge(int age) {
        if(this.age==age) return;
        this.age = age;
        propertyChanged.fire(new PropertyChangedEventArgs(this,"age"));
    }
}

class Demo{
    public static void main(String[] args) {
        Person person = new Person();
        Event<PropertyChangedEventArgs>.Subscription sub = person.propertyChanged.addHandler(x->{
            System.out.println("Person" + x.propertyName + ":" + x.source + "has Changed");
        });

        person.setAge(21);
        person.setAge(2);
        person.setAge(26);
        sub.close();
        person.setAge(2345);
    }
}