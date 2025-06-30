package CombinationLock;

//Usar state design pattern
class CombinationLock
{
    private int[] combination;
    private StringBuilder entered;
    public String status;
    private int currentIndex = 0;
    private boolean failed = false;
    private boolean opened = false;


    public CombinationLock(int[] combination) {
        this.combination = combination;
        this.status = "LOCKED";
        this.entered = new StringBuilder();
    }

    public void enterDigit(int digit) {
        if (failed || opened) return;

        entered.append(digit);

        if (combination[currentIndex] == digit) {
            currentIndex++;
            if (currentIndex == combination.length) {
                status = "OPEN";
                opened = true;
            } else {
                status = entered.toString();
            }
        } else {
            status = "ERROR";
            failed = true;
        }
    }
}

class Demo{
    public static void main(String[] args) {
        CombinationLock combinationLock = new CombinationLock(new int[]{1,2,3,4});
        System.out.println(combinationLock.status); // LOCKED
        combinationLock.enterDigit(1);
        combinationLock.enterDigit(2);
        combinationLock.enterDigit(3);
        combinationLock.enterDigit(4);
        System.out.println(combinationLock.status); // OPENED
    }
}