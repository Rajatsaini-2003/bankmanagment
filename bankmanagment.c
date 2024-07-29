#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 100

typedef struct {
    int accountNumber;
    char name[100];
    double balance;
} Customer;

Customer customers[MAX_CUSTOMERS];
int numCustomers = 0;

void createAccount() {
    if (numCustomers >= MAX_CUSTOMERS) {
        printf("Maximum number of customers reached!\n");
        return;
    }
    
    int accountNumber;
    char name[100];
    double initialDeposit;
    
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    
    printf("Enter name: ");
    scanf("%s", name);
    
    printf("Enter initial deposit: ");
    scanf("%lf", &initialDeposit);
    
    customers[numCustomers].accountNumber = accountNumber;
    strcpy(customers[numCustomers].name, name);
    customers[numCustomers].balance = initialDeposit;
    
    numCustomers++;
    
    printf("Account created successfully!\n");
}

void depositMoney() {
    int accountNumber;
    double amount;
    
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    
    for (int i = 0; i < numCustomers; i++) {
        if (customers[i].accountNumber == accountNumber) {
            printf("Enter amount to deposit: ");
            scanf("%lf", &amount);
            customers[i].balance += amount;
            printf("Amount deposited successfully! New balance: %.2lf\n", customers[i].balance);
            return;
        }
    }
    
    printf("Account not found!\n");
}

void withdrawMoney() {
    int accountNumber;
    double amount;
    
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    
    for (int i = 0; i < numCustomers; i++) {
        if (customers[i].accountNumber == accountNumber) {
            printf("Enter amount to withdraw: ");
            scanf("%lf", &amount);
            if (customers[i].balance >= amount) {
                customers[i].balance -= amount;
                printf("Amount withdrawn successfully! New balance: %.2lf\n", customers[i].balance);
            } else {
                printf("Insufficient balance!\n");
            }
            return;
        }
    }
    
    printf("Account not found!\n");
}

void checkBalance() {
    int accountNumber;
    
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    
    for (int i = 0; i < numCustomers; i++) {
        if (customers[i].accountNumber == accountNumber) {
            printf("Account balance: %.2lf\n", customers[i].balance);
            return;
        }
    }
    
    printf("Account not found!\n");
}

void menu() {
    printf("\n--- Bank Management System ---\n");
    printf("1. Create Account\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Check Balance\n");
    printf("5. Exit\n");
}

int main() {
    int choice;
    
    while (1) {
        menu();
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                depositMoney();
                break;
            case 3:
                withdrawMoney();
                break;
            case 4:
                checkBalance();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}