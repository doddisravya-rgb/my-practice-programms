
#include <stdio.h>
#include <string.h>

struct bank_details {
    int accountNo;
    char name[30];
    float balance;
};

int main()
{
    struct bank_details s;
    int choice, count = 0, i;
    float amount;
    char history[100][50];

    // Account details
    printf("Enter account number: ");
    if (scanf("%d", &s.accountNo) != 1 || s.accountNo <= 0) {
        printf("Invalid account number!");
        return 1;
    }

    printf("Enter account holder name: ");
    scanf(" %29[^\n]", s.name);

    printf("Enter initial balance: ");
    if (scanf("%f", &s.balance) != 1 || s.balance < 0) {
        printf("Invalid balance!");
        return 1;
    }

    while (1)
    {
        printf("\n\n===== BANKING SYSTEM =====\n");
        printf("1. Account Details\n");
        printf("2. Check Balance\n");
        printf("3. Deposit Money\n");
        printf("4. Withdraw Money\n");
        printf("5. Transaction History\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!");
            break;
        }

        if (choice == 6)
            break;

        switch (choice)
        {
            case 1:
                printf("\nAccount Number: %d", s.accountNo);
                printf("\nHolder Name: %s", s.name);
                break;

            case 2:
                printf("\nAvailable Balance: Rs. %.2f",
                       s.balance);
                break;

            case 3:
                printf("\nEnter deposit amount: ");

                if (scanf("%f", &amount) != 1) {
                    printf("Invalid input!");
                    return 1;
                }

                if (amount > 0) {
                    s.balance += amount;

                    if (count < 100) {
                        sprintf(history[count],
                                "Deposited: Rs. %.2f", amount);
                        count++;
                    }

                    printf("Deposit successful!");
                }
                else {
                    printf("Invalid amount!");
                }
                break;

            case 4:
                printf("\nEnter withdrawal amount: ");

                if (scanf("%f", &amount) != 1) {
                    printf("Invalid input!");
                    return 1;
                }

                if (amount > 0 && amount <= s.balance) {
                    s.balance -= amount;

                    if (count < 100) {
                        sprintf(history[count],
                                "Withdrawn: Rs. %.2f", amount);
                        count++;
                    }

                    printf("Withdrawal successful!");
                }
                else {
                    printf("Invalid amount or insufficient balance!");
                }
                break;

            case 5:
                printf("\n===== TRANSACTION HISTORY =====\n");

                if (count == 0) {
                    printf("No transactions yet.");
                }
                else {
                    for (i = 0; i < count; i++) {
                        printf("%d. %s\n", i + 1, history[i]);
                    }
                }
                break;

            default:
                printf("\nInvalid choice!");
        }
    }

    // Final bank report
    printf("\n\n===== FINAL BANK REPORT =====\n");
    printf("Account Number: %d\n", s.accountNo);
    printf("Holder Name: %s\n", s.name);
    printf("Total Balance: Rs. %.2f\n", s.balance);
    printf("Total Transactions: %d\n", count);

    printf("\nThank you for using our banking system!");

    return 0;
}
