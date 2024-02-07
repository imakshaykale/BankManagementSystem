#include <iostream>
#include <iomanip>

using namespace std;

class BankAccount {
private:
    string name;
    int accountNumber;
    float balance;

public:
    BankAccount(const string& n, int accNum, float initialBalance = 5000.0)
        : name(n), accountNumber(accNum), balance(initialBalance) {}

    void displayBalance() const {
        cout << "\t\t\t*BALANCE ENQUIRY*\n\n";
        cout << "Your current balance is: " << fixed << setprecision(2) << balance << " Rs\n";
    }

    void deposit(float amount) {
        cout << "\n\t\t\t*DEPOSIT AMOUNT*\n\n";
        if (amount > 0 && amount <= 20000) {
            cout << "\nYour " << amount << " Rs deposited in your account.\n\n";
            balance += amount;
        } else if (amount > 20000) {
            cout << "\nYou can't deposit that much amount in one time.\n\n";
        } else {
            cout << "\nInvalid deposit amount\n";
        }
    }

    void withdraw(float amount) {
        cout << "\n\t\t*WITHDRAW AMOUNT*\n\n";
        if (amount <= balance && amount <= 20000) {
            cout << "\nYou just withdrew " << amount << " Rs\n\n";
            balance -= amount;
        } else if (amount > 20000) {
            cout << "\nYou can't withdraw that much amount in one time.\n\n";
        } else {
            cout << "\nYou don't have enough money\n\n";
        }
    }

    void displayDetails(float depositAmount, float withdrawAmount) const {
        cout << "\n\t\t\t    -----------------------";
        cout << "\n\t\t\t\tAK BANK LIMITED\n";
        cout << "\t\t\t    -----------------------\n\n";
        cout << "\t\t\t\4 Your name: " << name << "\n";
        cout << "\t\t\t\4 Your account no: " << accountNumber << "\n";
        cout << "\t\t\t\4 You've deposited " << depositAmount << " Rs\n";
        cout << "\t\t\t\4 You've withdrawn " << withdrawAmount << " Rs\n";
        cout << "\t\t\t\4 Your current balance is: " << balance << " Rs\n";
        cout<<"\t\t\4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4";
        cout << "\n\t\t\t\t    Thank you! \n";
        cout << "\t\t\t   Welcome to AK Banking System\n";
        cout<<"\t\t\4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4";
    }

    void transfer(BankAccount& recipient, float amount) {
        cout << "\t\t\tTRANSFER AMOUNT \n\n";
        if (balance >= amount) {
            cout << "\nYour " << amount << " Rs successfully transferred\n\n";
            balance -= amount;
            recipient.balance += amount;
        } else {
            cout << "\nYou do not have sufficient balance\n\n";
        }
    }

    float getBalance() const {
        return balance;
    }
};

int main() {
    string name;
    int accountNumber;
    float initialBalance = 5000;

    cout << "\n\t\t\t\tBANKING SYSTEM\n\n";
    cout << "\t\t\4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4\n";
    cout << "\t\t\4\t\t\t\t\t\t\4\n";
    cout << "\t\t\4\tWELCOME TO OUR AK BANKING SYSTEM\t\4\n";
    cout << "\t\t\4\t\t\t\t\t\t\4\n";
    cout << "\t\t\4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4 \4\n";
    cout<<endl;
    cout << "Enter your name: ";
    getline(cin, name);

    cout << "\nPlease enter your account no.: ";
    cin >> accountNumber;

    BankAccount account(name, accountNumber, initialBalance);

    int transaction = 1;
    BankAccount recipient("Recipient", 9999); // Example recipient account

    while (transaction == 1) {
        int option;
        cout << "\nChoose what you want to do\n";
        cout << "1 - Balance Enquiry\n";
        cout << "2 - Deposit\n";
        cout << "3 - Withdraw\n";
        cout << "4 - Transfer\n";
        cin >> option;

        switch (option) {
            case 1:
                account.displayBalance();
                break;
            case 2:
                float depositAmount;
                cout << "How much money do you want to deposit: ";
                cin >> depositAmount;
                account.deposit(depositAmount);
                break;
            case 3:
                float withdrawAmount;
                cout << "How much money do you want to withdraw: ";
                cin >> withdrawAmount;
                account.withdraw(withdrawAmount);
                break;
            case 4:
                float transferAmount;
                cout << "How much money do you want to transfer: ";
                cin >> transferAmount;
                account.transfer(recipient, transferAmount);
                break;
            default:
                cout << "Invalid transaction\n";
        }

        transaction = 0;
        while (transaction != 1 && transaction != 2) {
            cout << "Do you want to do another transaction?\n";
            cout << "1. Yes 2. No\n";
            cin >> transaction;

            if (transaction != 1 && transaction != 2) {
                cout << "Invalid choice. Choose between 1 and 2 only\n";
            }
        }
    }

    float depositedAmount = (initialBalance < account.getBalance()) ? account.getBalance() - initialBalance : 0;
    float withdrawnAmount = initialBalance - account.getBalance();

    account.displayDetails(depositedAmount, withdrawnAmount);

    cin.ignore(); // Clear input buffer
    cin.get();    // Wait for the user to press Enter
    return 0;
}