#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct date //structure for holding dates
{
    int day, month, year;
} date;

typedef struct account
{
    char acc_no[10];
    char name[50];
    date dob;
    int age;
    char phn_no[10];
    float amount;
    char address[100];
    char acc_type;
    char citizenship[10];
    date deposit;
    date withdraw;
} account;

account customer[10];                                    //array for holding customer details
int mpin, option, exit_status = 0, acc_create = 5, flag; //acc_create=1 if account is created
char match_acc_no[10];
void details()
{
    char add_name[100];
    printf("Enter the bank account number\n");
    printf("The bank account number should be 5 digits\n");
    scanf("%s", &match_acc_no);

    for (int i = 0; i < acc_create; i++)
    {
        if (strcmp(match_acc_no, customer[i].acc_no) == 0)
        {
            system("cls");
            printf("\nAccount no. already in use!....Try again\n\n");
            sleep(4);
            system("cls");
            menu();
        }
    }
    if (strlen(match_acc_no) == 5)
    {
        system("cls");
        strcpy(customer[acc_create].acc_no, match_acc_no);
        printf("Your generated mpin is 2021 remember this for future use\n");
        printf("Enter today's date(mm dd yyyy):\n");
        scanf("%d %d %d", &customer[acc_create].dob.day, &customer[acc_create].dob.month, &customer[acc_create].dob.year);
        printf("Enter your correct name to open your account\n");
        fflush(stdin);
        gets(add_name);
        strcpy(customer[acc_create].name, add_name);
        printf("Enter your date of birth(mm dd yyyy):\n");
        scanf("%d %d %d", &customer[acc_create].dob.day, &customer[acc_create].dob.month, &customer[acc_create].dob.year);
        fflush(stdin);
        printf("\nEnter your age:");
        scanf("%d", &customer[acc_create].age);
        fflush(stdin);
        printf("\nEnter your address:");
        scanf("%s", customer[acc_create].address);
        fflush(stdin);
        printf("\nEnter your citizenship:");
        scanf("%s", customer[acc_create].citizenship);
        fflush(stdin);
        printf("\nEnter your phone number: ");
        scanf("%s", &customer[acc_create].phn_no);
        fflush(stdin);
        printf("\nEnter the amount to deposit:$");
        scanf("%f", &customer[acc_create].amount);
        fflush(stdin);
        system("cls");
        printf("Thank you for opening account\n %s your account has been created succesfully\n", customer[acc_create].name);
        acc_create++;
    }
    else
    {
        printf("Invalid account number\nTry again\n");
        sleep(4);
    }
}

void account_create()
{
    system("cls");
    int choice;
    printf("choose the type of account you want to open\n ");
    printf("\nEnter 1 for SAVINGS ACCOUNT\nEnter 2 for CURRENT ACCOUNT\nEnter 3 for FIXED ACCOUNT\nEnter any other number to go back to main menu\n");
    scanf("%d", &choice);
    system("cls");
    switch (choice)
    {
    case 1:
        printf("\nYou have choosen SAVINGS ACCOUNT\n");
        printf("Thank You for choosing the SAVINGS ACCOUNT\n\n");
        customer[acc_create].acc_type = 'S';
        details();
        break;
    case 2:
        printf("\nYou have choosen CURRENT ACCOUNT\n");
        printf("Thank you for choosing the CURRENT ACCOUNT\n\n");
        customer[acc_create].acc_type = 'C';
        details();
        break;
    case 3:
        printf("\nYou have choosen FIXED ACCOUNT\n");
        printf("Thank you for choosing the FIXED ACCOUNT\n\n");
        customer[acc_create].acc_type = 'F';
        details();
        break;
    default:
        menu();
    }
    end();
}
void edit_account()
{
    flag = 0;
    system("cls");
    printf("Enter account number\n");
    scanf("%s", &match_acc_no);
    char crct_name[30], add[100];
    for (int i = 0; i < acc_create; i++)
    {
        if (strcmp(match_acc_no, customer[i].acc_no) == 0)
        {
            flag = 1;
            printf("Enter your pin\n");
            scanf("%d", &mpin);
            system("cls");
            if (mpin != 2021)
            {
                printf("Invalid PIN\n");
                sleep(3);
                menu();
            }
            printf("WELCOME %s\n", customer[i].name);
            printf("Enter 1 for name change\nEnter 2 for changing date of birth\nEnter 3 for changing your age\nEnter 4 for changing your phone number\nEnter 5 for changing your address\n");
            scanf("%d", &option);
            switch (option)
            {
            case 1:
                system("cls");
                printf("Enter your correct name\n");
                fflush(stdin);
                gets(crct_name);
                // scanf("%s",crct_name);   //doesn't work coz scanf doesn't takes spaces
                strcpy(customer[i].name, crct_name);
                printf(" Name updated\n");
                break;

            case 2:
                system("cls");
                printf("Enter your correct date of birth in the format dd mm yy\n");
                scanf("%d %d %d", &customer[i].dob.day, &customer[i].dob.month, &customer[i].dob.year);
                printf(" Date of Birth updated\n");
                //printf("%d %d %d", customer[i].dob.day, customer[i].dob.month, customer[i].dob.year);
                break;

            case 3:
                system("cls");
                printf("Enter your correct age according to your date of birth\n");
                scanf("%d", &customer[i].age);
                printf(" Age updated\n");
                // printf("%d",customer[i].age);
                break;

            case 4:
                system("cls");
                printf("Enter your correct Phone Number to be linked to the Bank\n");
                fflush(stdin);
                scanf("%s", customer[i].phn_no);
                printf(" Phone number updated\n");
                // printf("%s", customer[i].phn_no);
                break;

            case 5:
                system("cls");
                printf("Enter your correct Address\n");
                fflush(stdin);
                gets(add);
                // scanf("%s",crct_name);   //doesn't work coz scanf doesn't takes spaces
                strcpy(customer[i].address, add);
                printf(" Address updated\n");
                // puts(customer[i].address);
                break;

            default:
                system("cls");
                printf("Invalid\n");
                break;
            }
        }
    }
    if (flag == 0)
        printf("Check your account number\n");
    sleep(3);
    system("cls");
    end();
}
void delete_account()
{
    flag = 0;
    system("cls");
    printf("Enter the account number of the account you want to delete\n");
    scanf("%s", &match_acc_no);
    for (int i = 0; i < acc_create; i++)
    {
        if (strcmp(match_acc_no, customer[i].acc_no) == 0)
        {
            flag = 1;
            printf("Enter your pin\n");
            scanf("%d", &mpin);
            if (mpin != 2021)
            {
                printf("Invalid PIN\n");
                sleep(3);
                menu();
            }
            customer[i] = customer[10];
            system("cls");
            printf("Account deleted successfully\n");
        }
    }
    if (flag == 0)
        printf("Check your account number\n");
    end();
}
void transaction()
{
    flag = 0;
    float deposit_amt, withdraw_amt;
    system("cls");
    printf("Enter your Account Number\n");
    scanf("%s", &match_acc_no);
    for (int i = 0; i < acc_create; i++)
    {
        if (strcmp(match_acc_no, customer[i].acc_no) == 0)
        {
            flag = 1;
            printf("Please enter your Pin\n");
            scanf("%d", &mpin);
            if (mpin != 2021)
            {
                printf("\n\nInvalid PIN\n\n");
                exit(0);
            }
            system("cls");
            printf("WELCOME %s\n", customer[i].name);
            printf("Please select the option to continue\n");
            printf("1.Check Balance\n2.Deposit money\n3.Withdraw money\n");
            scanf("%d", &option);
            system("cls");
            switch (option)
            {
            case 1:
                printf("Your Account balance is  $%.2f:", customer[i].amount);
                break;
            case 2:
                printf("Enter the amount to be deposited\n");
                fflush(stdin);
                scanf("%f", &deposit_amt);
                fflush(stdin);
                if (deposit_amt > 0)
                {
                    customer[i].amount += deposit_amt;
                    system("cls");
                    printf("Your balance after deposit is : %.2f", customer[i].amount);
                }
                else if (deposit_amt <= 0)
                {
                    printf("Deposit amount must be greater than zero");
                }
                break;
            case 3:
                printf("Enter the amount to be withdrawn\n");
                fflush(stdin);
                scanf("%f", &withdraw_amt);
                if (withdraw_amt > customer[i].amount)
                {
                    printf("You can't withdraw amount which is more than your current balance\n");
                    end();
                }
                else
                {
                    customer[i].amount -= withdraw_amt;
                    system("cls");
                    printf("Your balance after withdraw is: %.2f", customer[i].amount);
                }
                break;
            default:
                printf("Invalid choice \n");
                break;
            }
        }
    }
    if (flag == 0)
        printf("Check your account number\n");
    end();
}
void view_account_details()
{
    flag = 0;
    system("cls");
    printf("\nEnter the account number\n");
    scanf("%s", &match_acc_no);
    for (int i = 0; i <= acc_create; i++)
    {
        if (strcmp(match_acc_no, customer[i].acc_no) == 0)
        {
            flag = 1;
            printf("Enter your pin\n");
            scanf("%d", &mpin);
            system("cls");
            if (mpin != 2021)
            {
                printf("Invalid PIN\n");
                sleep(3);
                menu();
            }
            system("cls");
            printf("WELCOME %s\n", customer[i].name);
            printf("\n\nName---->%s\n", customer[i].name);
            printf("Date of birth---->%d/%d/%d\n", customer[i].dob.day, customer[i].dob.month, customer[i].dob.year);
            printf("Age---->%d\n", customer[i].age);
            printf("Phone number:---->%s\n", customer[i].phn_no);
            printf("Amount:---->%.2f\n", customer[i].amount);
            printf("Adress---->%s\n", customer[i].address);
            printf("Citizenship:---->%s\n", customer[i].citizenship);
        }
    }
    if (flag == 0)
        printf("Check your account number\n");
    end();
}
void interest()
{
    flag = 0;
    system("cls");
    printf("Enter your account number\n");
    scanf("%s", &match_acc_no);
    system("cls");
    for (int i = 0; i < acc_create; i++)
    {
        if (strcmp(match_acc_no, customer[i].acc_no) == 0)
        {
            flag = 1;
            acc_interest(i);
            end();
        }
    }
    if (flag == 0)
    {
        printf("Account number does not exist\n");
        sleep(3);
        menu();
        return;
    }
}
void acc_interest(int i)
{
    int time, total_amt, interest, rate;
    printf("Enter the duration of time period in years for interest calculation\n");
    scanf("%d", &time);
    switch (customer[i].acc_type)
    {
    case 'F':
        rate = 13;
        break;
    case 'S':
        rate = 8;
        break;
    case 'C':
        printf("Sorry, You have a current account\nyou won't earn any interest\n");
        return;
    default:
        printf("Invalid account type\n");
        return;
    }

    interest = (customer[i].amount * rate * time) / 100;
    system("cls");
    printf("The interest gained for %d years is %d\n\n", time, interest);
    total_amt = customer[i].amount + interest;
    printf("The total amount at the end of %d years with interest is %d\n", time, total_amt);
}
void customer_list()
{
    system("cls");
    printf("The customers in our bank are as follows\n");
    printf("Acc number  Name\n");
    for (int i = 0; i < acc_create; i++)
    {
        if (strlen(customer[i].acc_no) == 5)
            printf("%s\t%s\n", customer[i].acc_no, customer[i].name);
    }

    end();
}
void end()
{
    printf("\n\nDo you want to continue banking ?\nEnter 1 to continue\n");
    scanf("%d", &exit_status);
    system("cls");
    if (exit_status != 1)
    {
        printf("THANK YOU FOR BANKING WITH US\n");
        exit(0);
    }
}
void menu()
{
    int ch;
    while (1)
    {
        printf("Enter your option\n");
        printf("1.Create new account\n");
        printf("2.Edit account\n");
        printf("3.Delete account\n");
        printf("4.Account transaction\n");
        printf("5.View account information\n");
        printf("6.Interest\n");
        printf("7.Details of Customer list\n");
        printf("8.Exit\n");
        scanf("%d", &ch); //choice
        switch (ch)
        {
        case 1:
            account_create();
            break;
        case 2:
            edit_account();
            break;
        case 3:
            delete_account();
            break;
        case 4:
            transaction();
            break;
        case 5:
            view_account_details();
            break;
        case 6:
            interest();
            break;
        case 7:
            customer_list();
            break;
        case 8:
            system("cls");
            printf("Thank you\n");
            exit(0);
        default:
            system("cls");
            printf("\nChoose a valid option\n\n");
        }
        system("cls");
    }
}

int main()
{
    strcpy(customer[0].acc_no, "10000");
    strcpy(customer[0].name, "Suchith Kumar G M");
    customer[0].dob.day = 29;
    customer[0].dob.month = 10;
    customer[0].dob.year = 2002;
    customer[0].age = 19;
    strcpy(customer[0].phn_no, "9108733565");
    // customer[0].phn_no[10] = 9108733565;     //can use string to store instead of int
    customer[0].amount = 10000.00;
    strcpy(customer[0].address, "Arishinakunte Bangalore-562162");
    customer[0].acc_type = 'F';
    strcpy(customer[0].citizenship, "Indian");

    strcpy(customer[1].acc_no, "10001");
    strcpy(customer[1].name, "Shashidhar A S");
    customer[1].dob.day = 9;
    customer[1].dob.month = 04;
    customer[1].dob.year = 2002;
    customer[1].age = 19;
    strcpy(customer[1].phn_no, "9019071753");
    customer[1].amount = 10000.00;
    strcpy(customer[1].address, "Chintamani Karnataka");
    customer[1].acc_type = 'C';
    strcpy(customer[1].citizenship, "Indian");

    strcpy(customer[2].acc_no, "10002");
    strcpy(customer[2].name, "Pavan S G");
    customer[2].dob.day = 07;
    customer[2].dob.month = 10;
    customer[2].dob.year = 2002;
    customer[2].age = 19;
    strcpy(customer[2].phn_no, "7411771796");
    customer[2].amount = 10000.00;
    strcpy(customer[2].address, "Channagiri Karnataka");
    customer[2].acc_type = 'S';
    strcpy(customer[2].citizenship, "Indian");

    strcpy(customer[3].acc_no, "10003");
    strcpy(customer[3].name, "Sukanya Bakare");
    customer[3].dob.day = 28;
    customer[3].dob.month = 07;
    customer[3].dob.year = 2001;
    customer[3].age = 20;
    strcpy(customer[3].phn_no, "8904679969");
    customer[3].amount = 10000.00;
    strcpy(customer[3].address, "Nayandhalli Bangalore-560039");
    customer[3].acc_type = 'F';
    strcpy(customer[3].citizenship, "Indian");

    strcpy(customer[4].acc_no, "10004");
    strcpy(customer[4].name, "Murali A D");
    customer[4].dob.day = 18;
    customer[4].dob.month = 11;
    customer[4].dob.year = 2001;
    customer[4].age = 19;
    strcpy(customer[4].phn_no, "7975360768");
    customer[4].amount = 10000.00;
    strcpy(customer[4].address, "shivamogga(D), Aklapura (p)");
    customer[4].acc_type = 'C';
    strcpy(customer[4].citizenship, "Indian");
    printf("\n\nWELLCOME TO THE BANK OF SSSPM\n\n");

    menu(); //calls menu function for displaying menu
    return 0;
}