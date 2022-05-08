#include <iostream>
#include <conio.h>
#include <string>
using namespace std;
class Atm
{
private:
    long int account_no;
    string name;
    int PIN;
    double balance;
    string mobile_no;

public:
    void setdata(long int account_no_a, string name_a, int PIN_a, double balance_a, string mobile_no_a)
    {
        account_no = account_no_a;
        name = name_a;
        PIN = PIN_a;
        balance = balance_a;
        mobile_no = mobile_no_a;
    }

    long int getaccountno()
    {
        return account_no;
    }

    string getname()
    {
        return name;
    }
    int getPIN()
    {
        return PIN;
    }
    double getbalance()
    {
        return balance;
    }
    string getmobileno()
    {
        return mobile_no;
    }

    void setmobile(string mob_prev, string mob_new)
    {
        if (mob_prev == mobile_no)
        {
            mobile_no = mob_new;
            cout << "\n Successfully Updated Mobile No.";
            _getch();
        }
        else
        {
            cout << "\n Incorrect !!! Old Mobile No";
            _getch();
        }
    }
    void cashwithdraw(int amount_a)
    {
        if (amount_a > 0 && amount_a < balance)
        {
            balance -= amount_a;
            cout << "\n Please Collect Your cash";
            cout << "\n Available Balance :" << balance;
            _getch();
        }
        else
        {
            cout << "\n Insufficient !! Balance Or Invalid Input ";
            _getch();
        }
    }
};

/////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    int choice = 0, enterPIN;
    long int enteraccountno;

    system("cls");
    Atm user1;
    user1.setdata(1234567, "Niraj", 1111, 45000.89, "9359690887");

    do
    {
        system("cls");
        cout << "\n ****WELCOME TO ATM****";
        cout << "\n ENTER YOUR ACCOUNT NO : ";
        cin >> enteraccountno;
        cout << "\n ENTER PIN : ";
        cin >> enterPIN;
        if ((enteraccountno == user1.getaccountno()) && (enterPIN == user1.getPIN()))
        {
            do
            {
                int amount = 0;
                string oldmobileno, newmobileno;
                system("cls");
                cout << "\n ****WELCOME TO ATM****";
                cout << "\n SELECT OPTIONS";
                cout << "\n 1. CHECK BALANCE";
                cout << "\n 2. CASH WITHDRAW";
                cout << "\n 3. SHOW USER DETAILS ";
                cout << "\n 4. UPDATE YOUR MOBILE NO";
                cout << "\n 5. EXIT :";
                cin >> choice;

                switch (choice)
                {
                case 1:
                    cout << "\n YOUR BANK BALANCE IS :" << user1.getbalance();
                    _getch();
                    break;

                case 2:
                    cout << "\n ENTER THE AMOUNT :";
                    cin >> amount;
                    user1.cashwithdraw(amount);
                    break;

                case 3:
                    cout << "\n ***USER DETAILS ARE -->";
                    cout << "\n <-- ACCOUNT NO -->" << user1.getaccountno();
                    cout << "\n <-- NAME       -->" << user1.getname();
                    cout << "\n <-- BALANCE    -->" << user1.getbalance();
                    cout << "\n <-- MOBILE NO. -->" << user1.getmobileno();

                    _getch();
                    break;

                case 4:
                    cout << "\n ENTER OLD MOBILE NO :";
                    cin >> oldmobileno;

                    cout << "\n ENTER NEW MOBILE NO :";
                    cin >> newmobileno;

                    user1.setmobile(oldmobileno, newmobileno);
                    break;

                case 5:
                    exit(0);

                default:
                    cout << "\n ENTER VALID DATA";
                }

            } while (1);
        }
        else
        {
            cout << "\n USER DETAILS ARE INVALID !!!";
            _getch();
        }

    } while (1);

    return 0;
}
