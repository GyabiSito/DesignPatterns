package Observer;

import java.util.ArrayList;
import java.util.List;

class PropertyChangedEventArgs<T> {
    public T source;
    public String propertyName;
    public Object newValue;

    public PropertyChangedEventArgs(T source, String propertyName, Object newValue) {
        this.source = source;
        this.propertyName = propertyName;
        this.newValue = newValue;
    }
}

interface Observer<T> {
    void handle(PropertyChangedEventArgs<T> args);
}

class Observable<T> {
    private List<Observer<T>> observers = new ArrayList<Observer<T>>();

    public void subscribe(Observer<T> observer) {
        observers.add(observer);
    }

    protected void propertyChanged(PropertyChangedEventArgs<T> args) {
        for (Observer<T> observer : observers) {
            observer.handle(new PropertyChangedEventArgs(args.source, args.propertyName, args.newValue));
        }
    }
}

class Person extends Observable {
    private int age;
    private String name;

    Person(int age, String name) {
        this.age = age;
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setAge(int age) {
        if (this.age == age) return;
        this.age = age;
        propertyChanged(new PropertyChangedEventArgs(this, "age", age));
    }
}

class Demo implements Observer<Person> {
    public static void main(String[] args) {

        Demo demo = new Demo();

    }

    public Demo() {
        Person person = new Person(1, "jhon");
        Person person2 = new Person(1, "pepe");
        Person person3 = new Person(2, "maria");
        person.subscribe(this);
        person2.subscribe(this);
        person3.subscribe(this);
        for (int i = 0; i < 11; i++) {
            if (i == 6) {
                person2.setAge(i);
                person3.setAge(81);
                continue;
            }
            if (i == 10) {
                person3.setAge(i);
                continue;
            }
            person.setAge(i);
        }
    }

    @Override
    public void handle(PropertyChangedEventArgs<Person> args) {
        System.out.println("Person: " + args.source.getName() + " " + args.propertyName + " has changed to: " + args.newValue);
    }
}