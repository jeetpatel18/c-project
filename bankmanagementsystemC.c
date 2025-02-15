#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_ACCOUNTS 100

typedef struct 
{
    int accountNumber;
    char name[50];
    float balance;
} 
Account;
Account accounts[MAX_ACCOUNTS];
int numAccounts = 0;

void createAccount() 
{
    if(numAccounts<MAX_ACCOUNTS) 
    {
        Account newAccount;
        
        printf("Enter account number: ");
        scanf("%d", &newAccount.accountNumber);
        
        printf("Enter name: ");
        scanf(" %[^\n]s", newAccount.name); 
        
        printf("Enter initial balance: ");
        scanf("%f", &newAccount.balance);

        accounts[numAccounts] = newAccount;
        numAccounts++;
        printf("Account created successfully.\n");
    } 
    else 
    {
        printf("Maximum number of accounts reached.\n");
    }
}
void deposit() 
{
    int accountNumber;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);

    for (int i = 0; i < numAccounts; i++) 
    {
        if (accounts[i].accountNumber == accountNumber) 
        {
            accounts[i].balance += amount;
            printf("Deposit successful. New balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}
void withdraw() 
{
    int accountNumber;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    for (int i = 0; i < numAccounts; i++) 
    {
        if (accounts[i].accountNumber == accountNumber) 
        {
            if (accounts[i].balance >= amount)
             {
                accounts[i].balance -= amount;
                printf("Withdrawal successful. New balance: %.2f\n", accounts[i].balance);
            } 
            else 
            {
                printf("Insufficient balance.\n");
            }
            return;
        }
    }
    printf("Account not found.\n");
}
void displayAccount() 
{
    int accountNumber;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    for (int i = 0; i < numAccounts; i++) 
    {
        if (accounts[i].accountNumber == accountNumber) 
        {
            printf("Account Number: %d\n", accounts[i].accountNumber);
            printf("Name: %s\n", accounts[i].name);
            printf("Balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}
void displayAllAccounts() 
{
    if (numAccounts == 0)
    {
        printf("No accounts yet.\n");
        return;
    }
    printf("\n--- All Accounts ---\n");
    
    for (int i = 0; i < numAccounts; i++) 
    {
        printf("Account Number: %d, Name: %s, Balance: %.2f\n", accounts[i].accountNumber, accounts[i].name, accounts[i].balance);
    }
    printf("--------------------\n");
}
int main() 
{
    int choice;
    do 
    {
        printf("\nBank Management System\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Display Account Details\n");
        printf("5. Display All Accounts (for testing)\n"); 
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                createAccount();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                displayAccount();
                break;
            case 5:
                displayAllAccounts();
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 6);
      return 0;
}