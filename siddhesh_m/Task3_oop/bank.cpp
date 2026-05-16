#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

class Bank;
class Branch;
class Customer;
class Account;
class SavingsAccount;
class CurrentAccount;
class FixedDepositAccount;
class Transaction;
class Loan;
class ATMCard;
class Employee;
class Notification;
class SMSNotification;
class EmailNotification;
class InsufficientBalanceException;
class InvalidPINException;
class AccountBlockedException;
class LoanRejectedException;

class Bank {
    public:
        int bankId;
        string bankName;
        vector<Branch> branches;
        vector<Customer> customers;
        vector<Employee> employees;
};

class Branch {
    public:
        int branchId;
        string branchName;
        string IFSCCode;
        string address;
        vector<Account> accounts;
        vector<Employee> employees;
};

class Customer {
    public:
        int customerId;
        string fullName;
        tm dob;
        string gender;
        string mobileNumber;
        string email;
        string address;
        string aadhaarNumber;
        string PANNumber;
        vector<Account> accounts;
        vector<Loan> loans;
};

class Account {
    public:
        long accountNumber;
        string accountType;
        double balance;
        tm dateOpened;
        string status;
        Branch branch;
        Customer customer;
        vector<Transaction> transactions;
};

class SavingsAccount: public Account {
    public:
        double interestRate;
        double minimumBalance;
};

class CurrentAccount: public Account {
    public:
        double overdraftLimit;
        string businessName;
};

class FixedDepositAccount: public Account {
    public:
        double FDAmount;
        tm maturityDate;
        double FDInterestRate;
        int tenureMonths;
};

class Transaction {
    public:
        int transactionId;
        string transactionType;
        double amount;
        tm transactionDate;
        Account senderAccount;
        Account receiverAccount;
        string status = "Pending";
};

class Loan {
    public:
        int loanId;
        string loanType;
        double loanAmount;
        double interestRate;
        int tenureMonths;
        double EMIAmount;
        string loanStatus = "Pending";
        Customer customer;
};

class ATMCard {
    public:
        long cardNumber;
        int CVV;
        tm expiryDate;
        int PIN;
        string cardType;
        string cardStatus = "Active";
        Account linkedAccount;
};

class Employee {
    public:
        int employeeId;
        string employeeName;
        string designation;
        double salary;
        Branch branch;
};

class Notification {
    public:
        string message;

    virtual void send() = 0;
};

class SMSNotification: public Notification {
    public:
        string phoneNumber;
        string message;
        string deliveryStatus = "Pending";

        void send() override {
            deliveryStatus = "Sent";
            cout << "Notification - SMS sent to " << phoneNumber << endl;
            cout << message << endl;
        }
};

class EmailNotification: public Notification {
    public:
        string emailAddress;
        string subject;
        string message;
        string deliveryStatus = "Pending";

        void send() override {
            deliveryStatus = "Sent";
            cout << "Notification - Email sent to " << emailAddress << endl;
            cout << subject << endl;
            cout << message << endl;
        }
};

class InsufficientBalanceException: public runtime_error {
    public:
        InsufficientBalanceException(): runtime_error("Error: Insufficient balance") {}
};

class InvalidPINException: public runtime_error {
    public:
        InvalidPINException(): runtime_error("Error: Invalid pin"){}
};

class AccountBlockedException: public runtime_error {
    public:
        AccountBlockedException(): runtime_error("Error: This account has been blocked"){}
};

class LoanRejectedException: public runtime_error {
    public:
        LoanRejectedException(): runtime_error("Error: Loan was rejected"){}
};
