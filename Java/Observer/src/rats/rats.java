package rats;
import java.io.Closeable;
import java.io.IOException;
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
    private List<Observer<T>> observers = new ArrayList<>();

    public void subscribe(Observer<T> observer) {
        observers.add(observer);
    }

    public void unsubscribe(Observer<T> observer) {
        observers.remove(observer);
    }

    protected void notify(PropertyChangedEventArgs<T> args) {
        for (Observer<T> o : observers) {
            o.handle(args);
        }
    }
}

class Game extends Observable<Rat> {
    private List<Rat> rats = new ArrayList<>();

    public void addRat(Rat rat) {
        rats.add(rat);
        subscribe(rat);
        notify(new PropertyChangedEventArgs<>(rat, "Entra", rats.size()));
    }

    public void removeRat(Rat rat) {
        rats.remove(rat);
        unsubscribe(rat);
        notify(new PropertyChangedEventArgs<>(rat, "Sale", rats.size()));
    }

    public int getRatCount() {
        return rats.size();
    }
}


class Rat implements Closeable, Observer<Rat> {
    private Game game;
    public int attack = 1;

    public Rat(Game game) {
        this.game = game;
        game.addRat(this);
    }

    @Override
    public void handle(PropertyChangedEventArgs<Rat> args) {
        this.attack = game.getRatCount();
    }

    @Override
    public void close() throws IOException {
        game.removeRat(this);
    }
}

