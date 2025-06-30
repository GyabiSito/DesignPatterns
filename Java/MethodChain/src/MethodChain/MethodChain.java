package MethodChain;

class Creature{
    public String name;
    public int attack, defense;

    public Creature(String name, int attack, int defense) {
        this.name = name;
        this.attack = attack;
        this.defense = defense;
    }

    @Override
    public String toString() {
        return "Creature{" +
                "name='" + name + '\'' +
                ", attack=" + attack +
                ", defense=" + defense +
                '}';
    }
}

class CreatureModifier{
    protected Creature creature;
    protected CreatureModifier  next;

    public CreatureModifier(Creature creature) {
        this.creature = creature;
    }
    public void add(CreatureModifier cm){
        if(next != null){
            next.add(cm);
        }else{
            next=cm;
        }
    }

    public void handle(){
        if(next!=null){
            next.handle();
        }
    }
}

class DoubleAttackModifier extends CreatureModifier{
    public DoubleAttackModifier(Creature creature) {
        super(creature);
    }

    @Override
    public void handle() {
        System.out.println("Doubling  " + creature.name + "Attack " + creature.attack);
        creature.attack*=2;
        super.handle();
    }
}

class IncreaseDefenseModifier extends CreatureModifier{
    public IncreaseDefenseModifier(Creature creature) {
        super(creature);
    }

    @Override
    public void handle() {
        creature.defense+=3;
        super.handle();
    }
}

class NoBonusesModifier extends CreatureModifier{
    public NoBonusesModifier(Creature creature) {
        super(creature);
    }

    @Override
    public void handle() {
        System.out.println("No bonuses");
    }
}

class Demo{
    public static void main(String[] args) {
        Creature creature = new Creature("Bob", 10, 10);
        System.out.println(creature);
        CreatureModifier cm = new CreatureModifier(creature);
        cm.add(new NoBonusesModifier(creature));
        cm.add(new IncreaseDefenseModifier(creature));
        cm.add(new DoubleAttackModifier(creature));
        cm.handle();
        System.out.println(creature);
    }
}