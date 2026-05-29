#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Calculator Menu
void calculator()
{
    int choice;
    double a, b;

    do
    {
        cout << "\n========================";
        cout << "\n   CALCULATOR SYSTEM";
        cout << "\n========================";
        cout << "\n1. Addition";
        cout << "\n2. Subtraction";
        cout << "\n3. Multiplication";
        cout << "\n4. Division";
        cout << "\n5. Square";
        cout << "\n6. Cube";
        cout << "\n7. Logout";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "Enter two numbers: ";
                cin >> a >> b;
                cout << "Result = " << a + b << endl;
                break;

            case 2:
                cout << "Enter two numbers: ";
                cin >> a >> b;
                cout << "Result = " << a - b << endl;
                break;

            case 3:
                cout << "Enter two numbers: ";
                cin >> a >> b;
                cout << "Result = " << a * b << endl;
                break;

            case 4:
                cout << "Enter two numbers: ";
                cin >> a >> b;

                if(b == 0)
                    cout << "Division by Zero Not Allowed!\n";
                else
                    cout << "Result = " << a / b << endl;
                break;

            case 5:
                cout << "Enter a number: ";
                cin >> a;
                cout << "Square = " << a * a << endl;
                break;

            case 6:
                cout << "Enter a number: ";
                cin >> a;
                cout << "Cube = " << a * a * a << endl;
                break;

            case 7:
                cout << "\nLogged Out Successfully!\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    } while(choice != 7);
}

// Registration Function
void registerUser()
{
    string username, password;
    string user, pass;
    bool exists = false;

    cout << "\nEnter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    ifstream infile("users.txt");

    while(infile >> user >> pass)
    {
        if(user == username)
        {
            exists = true;
            break;
        }
    }

    infile.close();

    if(exists)
    {
        cout << "\nUsername Already Exists!\n";
        return;
    }

    ofstream outfile("users.txt", ios::app);

    outfile << username << " " << password << endl;

    outfile.close();

    cout << "\nRegistration Successful!\n";
}

// Login Function
void loginUser()
{
    string username, password;
    string user, pass;
    bool found = false;

    cout << "\nEnter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    ifstream infile("users.txt");

    while(infile >> user >> pass)
    {
        if(user == username && pass == password)
        {
            found = true;
            break;
        }
    }

    infile.close();

    if(found)
    {
        cout << "\nLogin Successful!\n";

        // Open Calculator Dashboard
        calculator();
    }
    else
    {
        cout << "\nInvalid Username or Password!\n";
    }
}

int main()
{
    int choice;

    do
    {
        cout << "\n================================";
        cout << "\n LOGIN & REGISTRATION SYSTEM";
        cout << "\n================================";
        cout << "\n1. Register";
        cout << "\n2. Login";
        cout << "\n3. Exit";
        cout << "\nEnter Choice: ";

        cin >> choice;

        switch(choice)
        {
            case 1:
                registerUser();
                break;

            case 2:
                loginUser();
                break;

            case 3:
                cout << "\nThank You!\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    } while(choice != 3);

    return 0;
}