#include <iostream>
#include <string>

using namespace std;

class Account {
public:
    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
    virtual void displayAccountDetails() const = 0;
    virtual ~Account() {}
};

class Information : public Account {
public:
    string id;
    string name;
    string nationalID;
    double balance;
public:


    Information(string id, string name, string nationalID, double balance)
        : id(id), name(name), nationalID(nationalID), balance(balance) {}

    void deposit(double amount) override {
        balance += amount;
    }

    void withdraw(double amount) override {
        if (amount <= balance) {
            balance -= amount;
        } else {

            cout <<"\n" <<"Insufficient balance!" << endl;
        }
    }

    void displayAccountDetails() const override {
        cout<<endl;
        cout<<"----------------------------------------------------"<<endl;
        cout<<"----------------------------------------------------"<<endl;
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "National ID: " << nationalID << endl;
        cout << "Balance: " << balance << endl;
        cout<<"----------------------------------------------------"<<endl;
        cout<<"----------------------------------------------------"<<endl;
    }
};

class Deposit : public Account {
public:
    double balance;

    Deposit() : balance(0.0) {}

    void deposit(double amount) override {
        balance += amount;
        cout<<endl;
        cout << "Deposited: " << amount << endl;
    }

    void withdraw(double amount) override {

    }

    void displayAccountDetails() const override {
        cout << "Balance: " << balance << endl;
    }
};

class ATMManagementSystem {
private:
    Account* accounts[10];
    int accountCount;
    Account* currentAccount;

public:
    ATMManagementSystem() : accountCount(0), currentAccount(nullptr) {}

    void addAccount(Account* account) {
        if (accountCount < 10) {
            accounts[accountCount++] = account;
        } else {
            cout << "Account limit reached!" << endl;
        }
    }

    bool login(const string& id) {
        for (int i = 0; i < accountCount; ++i) {
            Information* info = dynamic_cast<Information*>(accounts[i]);
            if (info && info->id == id) {
                currentAccount = accounts[i];
                return true;
            }
        }
        return false;
    }

    void checkBalance() {
        if (currentAccount) {
            Information* info = dynamic_cast<Information*>(currentAccount);
            if (info) {
                    cout<<endl;
                cout << "Current Balance: " << info->balance << endl;
            }
        } else {
            cout<<endl;
            cout << "No account logged in!" << endl;
        }
    }

    void withdraw(double amount) {
        if (currentAccount) {
            currentAccount->withdraw(amount);
        } else {
            cout << "No account logged in!" << endl;
        }
    }

    void deposit(double amount) {
        if (currentAccount) {
            currentAccount->deposit(amount);
        } else {
            cout << "No account logged in!" << endl;
        }
    }

    void viewAccountDetails() {
        if (currentAccount) {
            currentAccount->displayAccountDetails();
        } else {
            cout << "No account logged in!" << endl;
        }
    }

    void logout() {
        currentAccount = nullptr;
    }

    ~ATMManagementSystem() {
        for (int i = 0; i < accountCount; ++i) {
            delete accounts[i];
        }
    }
};

int main() {
    ATMManagementSystem atm;
    atm.addAccount(new Information("0001", "azmol", "9876564321", 1000.50));
    atm.addAccount(new Information("0002", "sudipa", "123355678", 3500.0));
    atm.addAccount(new Information("0003", "masum", "9876534321", 1500.50));
    atm.addAccount(new Information("0004", "roman", "1234588789", 3500.0));
    atm.addAccount(new Information("0005", "rony", "98765432100", 0005.50));
    atm.addAccount(new Information("0006", "sumaiya", "123456789",10000.0));
    atm.addAccount(new Deposit());

    string userID;
    cout << "Enter user ID to login: ";
    cin >> userID;

    if (atm.login(userID)) {
        int choice;
        do {
            cout << "\n1. Check Balance\n2. Withdraw\n3. Deposit\n4. View Account Details\n5. Logout\nEnter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    atm.checkBalance();
                    break;
                case 2: {
                    double amount;
                    cout << "Enter amount to withdraw: ";
                    cin >> amount;
                    atm.withdraw(amount);
                    break;
                }
                case 3: {
                    double amount;
                    cout << "Enter amount to deposit: ";
                    cin >> amount;
                    atm.deposit(amount);
                    break;
                }
                case 4:
                    atm.viewAccountDetails();
                    break;
                case 5:
                    atm.logout();
                    cout << "Logged out successfully!" << endl;
                    break;
                default:
                    cout << "Invalid choice!" << endl;
            }
        } while (choice != 5);
    } else {
        cout << "Login failed!" << endl;
    }
     return 0 ;}