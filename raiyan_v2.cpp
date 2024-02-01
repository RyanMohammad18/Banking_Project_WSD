#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include <limits>
#include <windows.h>

using namespace std;

struct Account
{
    string account_type;
    string name;
    long long int number;
    string date;
    double balance;
};

void display_all_account(const vector<Account> &khata);
void addAccount(vector<Account> &khata);
void update_account(vector<Account> &khata);
void delete_account(vector<Account> &khata);
void deposite_account(vector<Account> &khata);
void withdraw_account(vector<Account> &khata);
void search_account(vector<Account> &khata);

void update_account(vector<Account> &khata)
{
    int search_number;
    cout << "Please Enter the Account number that you want to update:";
    cin >> search_number;

    int flag = 0;

    for (int i = 0; i < khata.size(); i++)
    {
        if (khata[i].number == search_number)
        {
            flag = 1;

            cout << " Account Found in our database !" << endl;

            string updated_name;
            double updated_balance;

            string updated_acctype;
            cout << "Please Enter your updated Type:";
            cin >> updated_acctype;

            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Please Enter your updated Name:";
            getline(cin, updated_name);
          
            cout << "Please Enter your updated balance:";
            cin >> updated_balance;

            khata[i].name = updated_name;
            khata[i].account_type = updated_acctype;
            if (updated_balance < 500)
            {
                cout << "Sorry!! minimum 500 should be balance";
            }
            else
            {
                khata[i].balance = updated_balance;
                cout << "\n<~><~><~><~><~><~><~><~><~><~> Account Updated successfully! <~><~><~><~><~><~><~><~><~><~> \n\n"
                     << endl;
            }

            break;
        }
    }
    if (flag == 0)
    {
        cout << " Sorry no Account found in our database !" << endl;
    }
}

void addAccount(vector<Account> &khata)
{
    struct Account temp;
    double minBalance = 500;

    cout << "Please Enter Account Type : ";
    cin >> temp.account_type;

    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    cout << "Please Enter Account holder name : ";
    // cin >> temp.name;
    getline(cin, temp.name);

    cout << "Please Enter Account Number : ";
    cin >> temp.number;

    time_t now = time(0);
    temp.date = ctime(&now);

    for (int i = 0; i < khata.size(); i++)
    {
        if (khata[i].number == temp.number)
        {
            cout << "\n---------------This account number is already exist.----------\n\n\n\n";
            return;
        }
    }

    cout << "Please Enter Account Balance : ";
    cin >> temp.balance;

    if (temp.balance >= minBalance)
    {

        khata.push_back(temp);
        cout << "\n<~><~><~><~><~><~><~><~><~><~> Account added successfully! <~><~><~><~><~><~><~><~><~><~> \n\n"
             << endl;
    }
    else
    {
        cout << "\n<!><!><!><!><!><!><!><!><!><!> Insufficient balance! Minimum amount is Rs: " << minBalance
             << " <!><!><!><!><!><!><!><!><!><!>\n"
             << endl;
    }
}

void display_all_account(const vector<Account> &khata)
{

    for (int i = 0; i < khata.size(); i++)
    {
        cout << "\n\t--------Account no: " << i << "----------" << endl;
        cout << "Account Name: " << khata[i].name << endl;
        cout << "Account Number:" << khata[i].number << endl;
        cout << "Account Balance:" << khata[i].balance << endl;
        cout << "Account Adding Date:" << khata[i].date << endl;
    }
}

void delete_account(vector<Account> &khata)
{
    int delete_number;
    cout << "Please Enter the Account number that you want to delete:";
    cin >> delete_number;

    for (int i = 0; i < khata.size(); ++i)
    {
        if (khata[i].number == delete_number)
        {

            khata.erase(khata.begin() + i);
            cout << "\n<~><~><~><~><~><~><~><~><~><~> Account deleted successfully! <~><~><~><~><~><~><~><~><~><~>\n"
                 << endl;
            return;
        }
    }

    cout << "\n<!><!><!><!><!><!><!><!><!><!> Account does not exist in our database! <!><!><!><!><!><!><!><!><!><!>\n"
         << endl;
}

void deposite_account(vector<Account> &khata)
{

    int dep_account;
    double dep_amount;

    cout << "Give us your account number: \t" << endl;
    cin >> dep_account;

    for (int i = 0; i < khata.size(); ++i)
    {
        if (khata[i].number == dep_account)
        {

            cout << "Enter your Deposite Amount: \t" << endl;
            cin >> dep_amount;

            khata[i].balance = khata[i].balance + dep_amount;
            cout << "<~><~><~><~><~><~><~><~><~><~>  Deposit Successful! Your new balance is : \t" << khata[i].balance << " <~><~><~><~><~><~><~><~><~><~> " << endl;
            break;
        }
    }
}

void withdraw_account(vector<Account> &khata)
{

    int dep_account;
    double with_amount;

    cout << "Give us your account number :\t" << endl;
    cin >> dep_account;

    for (int i = 0; i < khata.size(); ++i)
    {
        if (khata[i].number == dep_account)
        {

            cout << "Enter your withdraw Amount: \t" << endl;
            cin >> with_amount;

            if ((khata[i].balance - with_amount) > 500)
            {
                khata[i].balance -= with_amount;
                cout << "\n<~><~><~><~><~><~><~><~><~><~> Withdrawal Successful! Your new balance is : " << khata[i].balance << " <~><~><~><~><~><~><~><~><~><~>" << endl;
            }
            else
            {
                cout << "\nSorry, you must have to keep 500 in your account.\n"
                     << endl;
            }
        }
    }
}

void search_account(vector<Account> &khata)
{
    int dep_account;
    cout << "Please Enter Your Account Number: " << endl;
    cin >> dep_account;

    for (int i = 0; i < khata.size(); ++i)
    {
        if (khata[i].number == dep_account)
        {

            cout << "\n----This is your account----- \n"
                 << endl;
            cout << "Account Number : " << khata[i].number << endl;
            cout << "Account type : " << khata[i].account_type << endl;
            cout << "Name  : " << khata[i].name << endl;
            cout << "Balance  : " << khata[i].balance << "\n\n";
        }
        else
        {
            cout << "\n\nNo Account Found!" << endl;
        }
    }
}

int main()
{
    vector<Account> khata;
    int choice;

    cout << "\n\n<~><~><~><~><~><~><~><~><~><~> WELCOME TO BANKING SYSTEM <~><~><~><~><~><~><~><~><~><~> \n\n";

    while (true)
    {
        cout << "1. Create a new Account: \t" << endl;
        cout << "2. Display All account: \t" << endl;
        cout << "3. Update an Account: \t" << endl;
        cout << "4. Delete an account: \t" << endl;
        cout << "5. Deposite an amount into your account: \t " << endl;
        cout << "6. Withdraw an amount into your account: \t " << endl;
        cout << "7. Search your Account: \t " << endl;
        cout << "8. Exit" << endl;

        cout << "\nPlease Enter a choice:  ";
        cin >> choice;

        if (choice == 1)
        {
            system("cls");
            addAccount(khata);
        }
        else if (choice == 2)
        {
            system("cls");
            display_all_account(khata);
        }
        else if (choice == 3)
        {
            system("cls");
            update_account(khata);
        }
        else if (choice == 4)
        {
            system("cls");
            delete_account(khata);
        }
        else if (choice == 5)
        {
            system("cls");
            deposite_account(khata);
        }
        else if (choice == 6)
        {
            system("cls");
            withdraw_account(khata);
        }
        else if (choice == 7)
        {
            system("cls");
            search_account(khata);
        }
        else if (choice == 8)
        {
            system("cls");
            cout << "\n\n<~><~><~><~><~><~><~><~><~><~> Thanks for using our service <~><~><~><~><~><~><~><~><~><~>\n\n"
                 << endl;
            break;
        }
        else
        {
            cout << " You entered a Wrong option! Please Enter Again!" << endl;
        }
    }

    return 0;
}
