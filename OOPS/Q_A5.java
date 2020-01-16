class SavingsAccount {
    static int annualInterestRate;
    private double savingsBalance;

    SavingsAccount(double s) {
        savingsBalance = s;
    }

    static void modifyInterestRate(int x) {
        annualInterestRate = x;
    }

    void calculateMonthlyInterest() {
        double d = (savingsBalance * annualInterestRate) / 12;
        savingsBalance = savingsBalance + d;
    }

    void display() {
        System.out.println(savingsBalance);
    }
}

public class testa5 {
    public static void main(String[] args) {
        SavingsAccount saver1 = new SavingsAccount(2000);
        SavingsAccount saver2 = new SavingsAccount(3000);
        SavingsAccount.modifyInterestRate(4);
        saver1.calculateMonthlyInterest();
        saver2.calculateMonthlyInterest();
        saver1.display();
        saver2.display();
        SavingsAccount.modifyInterestRate(5);
        saver1.calculateMonthlyInterest();
        saver2.calculateMonthlyInterest();
        saver1.display();
        saver2.display();
    }
}
