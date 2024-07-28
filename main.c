#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Customer {
    int account_number;
    char name[50];
    float balance;
};    

struct Customer user[50];
int user_number;

// Define functions for operations on the customer data
// Function prototypes:
void createAccount();
void displayDetails();
void deposit();
void withdraw();
void listAllAccounts();	

// Function to create a new account
void createAccount() {
    // Code to add a new customer to the system
    char leave;
    while (1) {
        printf("Please Enter Your Account Number: ");
        scanf("%d", &user[user_number].account_number);
        printf("Please Enter Your Name: ");
        scanf("%s", &user[user_number].name);
        user[user_number].balance = 0;
        printf("Your Account Details:\nAccount Number: %d\nName: %s\nBalance: %d $\nEnter anything to continue: ", user[user_number].account_number, user[user_number].name,user[user_number].balance);
        scanf("%s", &leave);
        ++user_number;
        break;
    }
}

// Function to display customer details
void displayDetails() {
    // Code to display customer details based on the account number
	int account_number_compare;
	char account_name;
	float balance;
	int i;
    int leave;
    
	//printf("Your Account Details: \nAccount Number: %d\nName: %s\nBalance: %f", user[0].account_number, user[0].name, user[0].balance);
    while (1) {
        printf("Please Enter Your Account Number OR Type 1 to exit: ");
        scanf("%d", &account_number_compare);
        if (account_number_compare == 1) {
            printf("\n****  Going back to main menu   ****\n");
            break;
        }
        for (i = 0; i < user_number; i++) {
            if (account_number_compare == user[i].account_number) {
                printf("Your Account Details: \nAccount Number: %d\nName: %s\nBalance: %f\n\nPlease type 1 to go back main menu \nPlease type 2 to restart\nEnter Here: ", user[i].account_number, user[i].name, user[i].balance);
                scanf("%d", &leave);
                break;
            }
            else {
                printf("\n****ERROR****\n\nAccount with the account number entered not found! Please Try Again!\n\n");
                break;
            }
        }
    
        if (leave == 1) {
            printf("\n****  Going back to main menu   ****\n");
            break;
        }
    }
}

// Function to deposit money into an account
void deposit() {
    // Code to deposit money into a customer's account
    int account_number;
    int i;
    float balance;
    int confirmation;
    float current_balance;
    char leave;
    int l;
    int correct;

    while (1) {
        while (1) {
            correct = 0;
            printf("Please enter your account number you would like to deposit money into (Enter 1 to go back main menu): ");
            scanf("%d", &account_number);
            if (account_number == 1) {
                printf("\n****  Going back to main menu   ****\n");
                break;
            }
            for (l = 0; l < user_number; l++) {
                if (account_number == user[l].account_number) {
                    correct = 1;
                    break;
                } else {
                    printf("\n****ERROR****\n\nAccount with the account number entered not found! Please Try Again!\n\n");
                    continue;
                }
            }
            if (correct == 1) {
                break;
            }
        }

        for (i = 0; i < user_number; i++) {
            if (account_number == user[i].account_number) {
                while (1) {
                    printf("How much would you like to deposit: ");
                    scanf("%f", &balance);
                    printf("\nConfirmation\nYou would like to deposit %f $?\nEnter 1 to confirm (Enter 2 if not correct): ", balance);
                    scanf("%d", &confirmation);
                    if (confirmation == 1) {
                        user[i].balance = user[i].balance + balance;
                        current_balance = user[i].balance;
                        printf("Your new balance is now: %f $, Please enter anything to leave:\n", current_balance);
                        scanf("%s", &leave);
                        break;
                    } else {
                        continue;
                    }
                }
                break;
            }
        }
        if (account_number == 1) {
            break;
        }
        
        while (1) {
            printf("Would you like to deposit more? (Enter 1 to deposit or enter 2 to go back to main menu): ");
            scanf("%d", &leave);
            if (leave == 1) {
                break;
            } else if (leave == 2) {
                printf("\n****  Going back to main menu   ****\n");
                break;
            } else {
                printf("\n****ERROR****\n\nIncorrect text entered, please try again\n");
            }
        }
         if (leave == 1) {
                continue;
        } else if (leave == 2) {
            break;
        }
    }
}

// Function to withdraw money from an account
void withdraw() {
    // Code to withdraw money from a customer's account
    int account_number;
    float withdrawal;
    int confirmation;
    float current_balance;
    int i;
    int leave;
    int l;
    int correct;

    while (1) {
        while (1) {
            correct = 0;
            printf("Please enter your account number you would like to withdraw money from (Enter 1 to go back main menu): ");
            scanf("%d", &account_number);
            if (account_number == 1) {
                printf("\n****  Going back to main menu   ****\n");
                break;
            }
            for (l = 0; l < user_number; l++) {
                if (account_number == user[l].account_number) {
                    correct = 1;
                    break;
                } else {
                    printf("\n****ERROR****\n\nAccount with the account number entered not found! Please Try Again!\n\n");
                    continue;
                }
            }
            if (correct == 1) {
                break;
            }
        }
        
        for (i = 0; i < user_number; i++) {
            if (account_number == user[i].account_number) {
                while (1) {
                    printf("How much would you like to withdraw: ");
                    scanf("%f", &withdrawal);
                    printf("\nConfirmation\nYou would like to withdraw %f $ (Enter 1 to confirm and 2 to withdraw another amount?): ", withdrawal);
                    scanf("%d", &confirmation);
                    if (confirmation == 1) {
                        user[i].balance = user[i].balance - withdrawal;
                        current_balance = user[i].balance;
                        printf("Your new balance is now: %f $, Please enter anything to leave:\n", current_balance);
                        scanf("%s", &leave);
                        break;
                    } else {
                        continue;
                    }
                }
            }
        }
        if (account_number == 1) {
            break;
        }
        
        while (1) {
            printf("Would you like to deposit more? (Enter 1 to deposit or enter 2 to go back to main menu): ");
            scanf("%d", &leave);
            if (leave == 1) {
                break;
            } else if (leave == 2) {
                printf("\n****  Going back to main menu   ****\n");
                break;
            } else {
                printf("\n****ERROR****\n\nIncorrect text entered, please try again\n");
            }
        }
         if (leave == 1) {
                continue;
        } else if (leave == 2) {
            break;
        }
    
    }
}

// Function to list all accounts
void listAllAccounts() {
    // Code to display details of all customers
    int i;
    char leave;


    
    while (1) {
        printf("\n-----------------------------------\nAll accounts:");
        for (i = 0; i < user_number; i++) {
            printf("\n-----------------------------------\nAccount Number: %d\nAccount Name: %s\nAccount Balance %f\n-----------------------------------\n", user[i].account_number, user[i].name, user[i].balance);
        }
        printf("Enter anything to go back to main menu\n");
        scanf("%s", &leave);
        break;
    }
}

int main() {
    int choice;
    int i;
    int dec;
    FILE *inputfile;
    FILE *acc;
    FILE *account_saved;
    FILE *inputaccount;
    
    inputfile = fopen("user_number.dat","rw");
    inputaccount = fopen("account_saved.dat", "rw");
    fread(&user_number, sizeof(user_number), 1, inputfile);
    fread(&user, sizeof(struct Customer), 50, inputaccount);
    
    while (1) {
        acc = fopen("user_number.dat", "w");
        fwrite(&user_number, sizeof(user_number), 1, acc);
        fclose(acc);
        account_saved = fopen("account_saved.dat", "w");
        fwrite(&user, sizeof(struct Customer), 50, account_saved);
        fclose(account_saved);
        printf("\nBank Management System\n");
        printf("1. Create Account\n");
        printf("2. Display Details\n");
        printf("3. Deposit\n");
        printf("4. Withdraw\n");
        printf("5. List All Accounts\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                displayDetails();
                break;
            case 3:
                deposit();
                break;
            case 4:
                withdraw();
                break;
            case 5:
                listAllAccounts();
                break;
            case 0:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}

