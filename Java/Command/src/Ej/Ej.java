package Ej;

class Command
{
    enum Action
    {
        DEPOSIT, WITHDRAW
    }

    public Action action;
    public int amount;
    public boolean success;

    public Command(Action action, int amount)
    {
        this.action = action;
        this.amount = amount;
    }
}

class Account
{
    public int balance;
    Command command;

    public void process(Command c)
    {
        switch (command.action) {
            case DEPOSIT:
                command.success=deposit(balance);
                break;
            case WITHDRAW:
                command.success=withdraw(balance);
                break;
            default:
                break;
        }
    }
    public boolean deposit(int amount){
        balance += amount;
        return true;
    }
    public boolean withdraw(int amount) {
        if (balance - amount >= 0) {
            balance -= amount;
            return true;
        }
        return false;
    }
}