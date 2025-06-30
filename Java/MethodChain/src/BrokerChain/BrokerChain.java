package BrokerChain;

import java.util.HashMap;
import java.util.Map;
import java.util.function.Consumer;


class Event<TArgs> {

    private int index = 0;
    private Map<Integer, Consumer<TArgs>> handlers = new HashMap<>();

    public int subscribe(Consumer<TArgs> handler) {
        int i = index;
        handlers.put(index++, handler);
        return i;
    }

    public void unsubscribe(int key) {
        handlers.remove(key);
    }

    public void fire(TArgs args) {
        for (Consumer<TArgs> handler : handlers.values())
            handler.accept(args);
    }
}

class Query {
    public String creatureName;

    enum Argument {
        ATTACK,
        DEFENSE
    }

    public Argument argument;
    public int result;

    public Query(String creatureName, Argument argument, int result) {
        this.creatureName = creatureName;
        this.argument = argument;
        this.result = result;
    }

}

class Game {
    public Event<Query> queries = new Event<>();
}

class Creature {
    private Game game;
    private String creatureName;
    private int baseAttack, baseDefense;

    public Creature(Game game, String creatureName, int baseAttack, int baseDefense) {
        this.game = game;
        this.creatureName = creatureName;
        this.baseAttack = baseAttack;
        this.baseDefense = baseDefense;
    }

    int getAttack() {
        Query q = new Query(getCreatureName(), Query.Argument.ATTACK, baseAttack);
        game.queries.fire(q);
        return q.result;
    }

    int getDefense() {
        Query q = new Query(getCreatureName(), Query.Argument.DEFENSE, baseDefense);
        game.queries.fire(q);
        return q.result;
    }

    public Game getGame() {
        return game;
    }

    public void setGame(Game game) {
        this.game = game;
    }

    public String getCreatureName() {
        return creatureName;
    }

    public void setCreatureName(String creatureName) {
        this.creatureName = creatureName;
    }

    public int getBaseAttack() {
        return baseAttack;
    }

    public void setBaseAttack(int baseAttack) {
        this.baseAttack = baseAttack;
    }

    public int getBaseDefense() {
        return baseDefense;
    }

    public void setBaseDefense(int baseDefense) {
        this.baseDefense = baseDefense;
    }

    @Override
    public String toString() {
        return "Creature{" +
                "name='" + creatureName + '\'' +
                ", attack=" + getAttack() +
                ", defense=" + getDefense() +
                '}';
    }

}


class CreatureModifier {
    protected Game game;
    protected Creature creature;

    public CreatureModifier(Game game, Creature creature) {
        this.game = game;
        this.creature = creature;
    }
}


class IncreasedDefenseModifier extends CreatureModifier {

    public IncreasedDefenseModifier(Game game, Creature creature) {
        super(game, creature);

        game.queries.subscribe(q -> {
            if (q.creatureName.equals(creature.getCreatureName())
                    && q.argument == Query.Argument.DEFENSE) {
                q.result += 3;
            }
        });
    }
}

class DoubleAttackModifier extends CreatureModifier implements AutoCloseable {
    private final int token;

    public DoubleAttackModifier(Game game, Creature creature) {
        super(game, creature);
        token = game.queries.subscribe(q -> {
            if (q.creatureName.equals(creature.getCreatureName()) && q.argument == Query.Argument.ATTACK) {
                q.result = q.result * 2;
            }
        });
    }

    @Override
    public void close() {
        game.queries.unsubscribe(token);

    }
}

class Demo {
    public static void main(String[] args) {
        Game game = new Game();
        Creature creature = new Creature(game, "Creature", 2, 2);
        System.out.println(creature);

        IncreasedDefenseModifier modifier = new IncreasedDefenseModifier(game, creature);
        DoubleAttackModifier dam = new DoubleAttackModifier(game, creature);
        try (dam) {
            System.out.println(creature);
        }
        System.out.println(creature);
    }
}