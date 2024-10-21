#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <iostream>
#include <exception>
#include <string>

using namespace std;

// Custom classes for handling error cases
class InsufficientFunds : public exception {
public:
    // Override of the what() function to make an error message for insufficient funds
    const char* what() const noexcept override {
        return "Error: Insufficient funds for this withdrawal.";
    }
};

class NegativeDeposit : public exception {
public:
    // Override of the what() function to provide an error message for negative deposit attempts
    const char* what() const noexcept override {
        return "Error: Deposit amount cannot be negative.";
    }
};

// BankAccount class that simulates basic banking operations
class BankAccount {
    double balance;  // Stores the current account balance
    string accountNumber;  // Stores the account number

public:
    // Constructor to initialize the bank account with account number and initial balance
    BankAccount(string accNo, double initialBalance)
        : accountNumber(accNo), balance(initialBalance) {}

    // Function to withdraw the money from the account
    void withdraw(double amount) {
        if (amount > balance) {
            throw InsufficientFunds();  // Throw exception if withdrawal exceeds the balance
        }
        balance -= amount;
        cout << "Successfully withdrew: $" << amount << endl;
    }

    // Function to deposit money into the account
    void deposit(double amount) {
        if (amount < 0) {
            throw NegativeDeposit();  // Throw exception if deposit amount is negative
        }
        balance += amount;
        cout << "Successfully deposited: $" << amount << endl;
    }

    // Function to get the current balance of the account
    double getBalance() const {
        return balance;
    }
};

// Function to simulate a withdrawal process, which may throw exceptions from the withdraw function
void processWithdrawal(BankAccount& account, double amount) {
    account.withdraw(amount);  // Withdrawal may trigger InsufficientFunds exception
}

#endif