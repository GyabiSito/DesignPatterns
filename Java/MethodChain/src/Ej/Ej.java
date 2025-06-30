package Ej;
import java.util.ArrayList;
import java.util.List;
abstract class Creature {
    public Game game;
    public abstract int getAttack();
    public abstract int getDefense();
}

class Goblin extends Creature {
    public Goblin(Game game) {
        this.game = game;
    }

    @Override
    public int getAttack() {
        int attack = 1;

        for (Creature c : game.creatures) {
            if (c instanceof GoblinKing && c != this) {
                attack += 1;
                break;
            }
        }

        return attack;
    }
    @Override
    public int getDefense() {
        int defense = 1;

        for (Creature c : game.creatures) {
            if (c instanceof Goblin && c != this) {
                defense += 1;
            }
        }

        return defense;
    }

}

class GoblinKing extends Goblin {
    public GoblinKing(Game game) {
        super(game);
    }

    @Override
    public int getAttack() {
        return 3;
    }

    @Override
    public int getDefense() {
        return 3;
    }
}

enum Statistic {
    ATTACK, DEFENSE
}

class Game {
    public List<Creature> creatures = new ArrayList<>();
}
