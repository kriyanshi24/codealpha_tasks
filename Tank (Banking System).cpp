#include <iostream>
#include <vector>
using namespace std;

// Transaction Class
class Transaction {
public:
    string type;
    float amount;

    Transaction(string t, float a) {
        type = t;
        amount = a;
    }

    void showTransaction() {
        cout << type << " : Rs." << amount << endl;
    }
};

// Account Class
class Account {
private:
    int accNo;
    float balance;
    vector<Transaction> history;

public:
    Account(int no, float bal = 0) {
        accNo = no;
        balance = bal;
    }

    int getAccNo() {
        return accNo;
    }

    float getBalance() {
        return balance;
    }

    // Deposit
    void deposit(float amt) {
        balance += amt;
        history.push_back(Transaction("Deposit", amt));

        cout << "Amount Deposited Successfully\n";
    }

    // Withdraw
    void withdraw(float amt) {
        if(amt > balance) {
            cout << "Insufficient Balance\n";
            return;
        }

        balance -= amt;
        history.push_back(Transaction("Withdraw", amt));

        cout << "Amount Withdrawn Successfully\n";
    }

    // Transfer
    void transfer(Account &other, float amt) {
        if(amt > balance) {
            cout << "Insufficient Balance\n";
            return;
        }

        balance -= amt;
        other.balance += amt;

        history.push_back(Transaction("Transfer Sent", amt));
        other.history.push_back(Transaction("Transfer Received", amt));

        cout << "Transfer Successful\n";
    }

    // Show Transactions
    void showHistory() {
        cout << "\nTransaction History:\n";

        for(int i = 0; i < history.size(); i++) {
            history[i].showTransaction();
        }
    }

    // Display Account
    void display() {
        cout << "\nAccount Number : " << accNo << endl;
        cout << "Balance        : Rs." << balance << endl;
    }
};

// Customer Class
class Customer {
private:
    string name;
    Account account;

public:
    Customer(string n, int accNo, float bal)
        : account(accNo, bal) {
        name = n;
    }

    Account& getAccount() {
        return account;
    }

    void displayCustomer() {
        cout << "\nCustomer Name : " << name << endl;
        account.display();
    }
};

// Main Function
int main() {

    Customer c1("Rahul", 101, 5000);
    Customer c2("Amit", 102, 3000);

    int choice;
    float amt;

    do {
        cout << "\n====== BANKING SYSTEM ======\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Transfer\n";
        cout << "4. Show Account Details\n";
        cout << "5. Show Transaction History\n";
        cout << "6. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice) {

            case 1:
                cout << "Enter Amount: ";
                cin >> amt;
                c1.getAccount().deposit(amt);
                break;

            case 2:
                cout << "Enter Amount: ";
                cin >> amt;
                c1.getAccount().withdraw(amt);
                break;

            case 3:
                cout << "Enter Amount to Transfer: ";
                cin >> amt;
                c1.getAccount().transfer(c2.getAccount(), amt);
                break;

            case 4:
                c1.displayCustomer();
                break;

            case 5:
                c1.getAccount().showHistory();
                break;

            case 6:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid Choice\n";
        }

    } while(choice != 6);

    return 0;
}