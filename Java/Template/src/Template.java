abstract class Game {

    protected final int numberOfPlayers;
    protected int currentPlayer;

    public Game(int numberOfPlayers) {
        this.numberOfPlayers = numberOfPlayers;
    }
    public void run(){
        start();
        while(!haveWinner()){
            turnTurn();
        }
        System.out.println("player " + getWinningPlayer() + "Wins");
    }

    protected abstract int getWinningPlayer();
    protected abstract void start();
    protected abstract void turnTurn();
    protected abstract boolean haveWinner();

}


class Chess extends Game{
    private int maxTurns=10;
    private int turn=1;

    Chess() {
        super(2);
    }

    @Override
    protected boolean haveWinner() {
        return turn==maxTurns;
    }

    @Override
    protected void turnTurn() {
        System.out.println("Turn " + turn++  + "taken by player" + currentPlayer);
        currentPlayer=(currentPlayer+1) % numberOfPlayers;
    }

    @Override
    protected void start() {
        System.out.println("Starting game");
    }

    @Override
    protected int getWinningPlayer() {
        return 0;
    }

}

class Demo{
    public static void main(String[] args) {
        new Chess().run();
    }
}



