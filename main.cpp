#include "BankAccount.h"

int main() {
    try {
        // Create a bank account object with account number and initial balance
        BankAccount myAccount("12345", 100.0);

        // Display the initial balance of the account
        cout << "Initial balance: $" << myAccount.getBalance() << endl;

        // Attempt to deposit $50 into the account
        myAccount.deposit(50);
        // Display the updated balance
        cout << "Updated balance after deposit: $" << myAccount.getBalance() << endl;

        // Attempt to withdraw $200 (will throw InsufficientFunds since balance is insufficient)
        processWithdrawal(myAccount, 200);

    } catch (const InsufficientFunds& e) {
        // Handle insufficient funds exception
        cout << e.what() << endl;
    } catch (const NegativeDeposit& e) {
        // Handle negative deposit exception
        cout << e.what() << endl;
    } catch (...) {
        // Handle any other unexpected exceptions
        cout << "An unexpected error occurred." << endl;
    }

    // Program has completed
    cout << "Program completed." << endl;

    return 0;
}