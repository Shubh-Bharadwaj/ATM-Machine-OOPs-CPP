#include<conio.h> // for using _getch() (Holds the screen unitl user presses another key)
#include<iostream>
#include<string>
using namespace std;

class Atm {
    private:
        long int account_no; //size of long int is 4 byte
        string name;
        int pin;
        double balance;
        string Phone_no; // decreses complexity
    public:
    void setdata(long int account_no_a, string name_a, int pin_a, double balance_a, string Phone_no_a)
    {
        //setting value of member variables
        account_no = account_no_a;
        name = name_a;
        pin =  pin_a;
        balance = balance_a;
        Phone_no = Phone_no_a;
    }
    long int getaccount_no()
    {
        return account_no;
    }
    string getname()
    {
        return name;
    }
    int getpin()
    {
        return pin;
    }
    double getbalance()
    {
        return balance;
    }
    string getPhone_no()
    {
        return Phone_no;
    }
    // Updating Phone number
    void setPhone(string mobold, string mobnew)
    {
        if (mobold == Phone_no)
        {
            Phone_no= mobnew;
            cout<<endl<<"Sucessfully Updated";
            _getch();
        }
        else
        {
            cout<<endl<<"Incorrect Phone Number";
            _getch();
        }
    }
    // Cash withdraw function
    void cashwithdraw(int amount_a)
    {
        if(amount_a>0 && amount_a<balance)
        {
            balance-= amount_a;//balance=balance-amount_a
            cout<<endl<<"Please Collect Your Cash";
            cout<<endl<<"Available Balance: "<<balance;
            _getch();
        }
        else
        {
            cout<<endl<<"Invalid Input or Insufficient Balance: ";
            _getch(); 
        }
    }
    // To deposit cash
    void cashdeposit(int amount_a)
    {
        if(amount_a>0)
        {
            balance+= amount_a;//balance=balance+amount_a
            cout<<endl<<"Done!";
            cout<<endl<<"Available Balance: "<<balance;
            _getch();
        }
        else
        {
            cout<<endl<<"Invalid Input";
            _getch(); 
        }
    }
};

int main()
{
    // enterpin and enteraccount_no is for authentication
    int choice=0, enterpin;
    long int enteraccount_no;
    system("cls"); //clean screen
    // creating object
    Atm user1;
    user1.setdata(1234567, "ABC", 4321, 9999.90, "9638527410" );

    // uing do-while loop for running ATM multiple times
    do
    {
        system("cls");
        cout<<endl<<"******Welcome to ATM******"<<endl;
        cout<<endl<<"Enter Account Number: ";
        cin >> enteraccount_no;
        cout<<endl<<"Enter ATM PIN: ";
        cin >> enterpin;
        
        /*checking wheteher input values match with 
        user details(object)*/
        if ((enteraccount_no==user1.getaccount_no()) && (enterpin==user1.getpin()))
        {
            // This do-while loop is for user-interface
            do
            {
                int amount=0;
                string oldPhoneno, newPhoneno;
                system("cls");
                cout<<endl<<"******Welcome to ATM******"<<endl;
                cout<<endl<<"Select Options";
                cout<<endl<<"1. Check Balance";
                cout<<endl<<"2. Cash Withdraw";
                cout<<endl<<"3. Show User details";
                cout<<endl<<"4. Update Phone Number";
                cout<<endl<<"5. Deposit Cash";
                cout<<endl<<"6. Exit"<<endl;
                cin>>choice;
                switch (choice)
                {
                case 1:
                    cout<<endl<<"Your Balance is: "<<user1.getbalance();
                    _getch(); // To hold screen
                    break;
                case 2:
                    cout<<endl<<"Enter Amount: ";
                    cin>>amount;
                    user1.cashwithdraw(amount);
                    break;
                case 3:    
                    cout<<endl<<"User Details:- ";
                    cout<<"-> Account Number: "<<user1.getaccount_no();
                    cout<<"-> Account Name: "<<user1.getname();
                    cout<<"-> Balance: "<<user1.getbalance();
                    cout<<"-> Phone Number: "<<user1.getPhone_no();
                    _getch();
                    break;
                case 4:
                cout<<endl<<"Enter Old Phone Number: ";
                cin>> oldPhoneno;
                cout<<endl<<"Enter New Phone Number: ";
                cin>> newPhoneno;
                user1.setPhone(oldPhoneno,newPhoneno);
                break;
                case 5:
                cout<<endl<<"Enter Amount: ";
                cin>>amount;
                user1.cashdeposit(amount);
                break;
                case 6:
                exit(0);
                default:
                    cout << "Enter Valid Data";
                }
            } while (1); // Menu condition is always True, loop will run infinte times
        }
        else{
            cout<<endl<<"User Details are Invalid";
            _getch();
        }
    } while (1); // Login condition is always True, loop will run infinte times
    return 0;
}
