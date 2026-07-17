#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void registerUser()
{
    string username, password;

    cout << "\n========== Registration ==========\n";

    cout << "Enter Username: ";
    cin >> username;

    if (username.empty())
    {
        cout << "Username cannot be empty.\n";
        return;
    }

    ifstream checkFile(username + ".txt");

    if (checkFile)
    {
        cout << "Username already exists.\n";
        checkFile.close();
        return;
    }

    checkFile.close();

    cout << "Enter Password: ";
    cin >> password;

    if (password.length() < 6)
    {
        cout << "Password must be at least 6 characters.\n";
        return;
    }

    ofstream outFile(username + ".txt");

    outFile << username << endl;
    outFile << password << endl;

    outFile.close();

    cout << "Registration Successful!\n";
}

void loginUser()
{
    string username, password;
    string storedUsername, storedPassword;

    cout << "\n============= Login =============\n";

    cout << "Enter Username: ";
    cin >> username;

    ifstream inFile(username + ".txt");

    if (!inFile)
    {
        cout << "User not found.\n";
        return;
    }

    getline(inFile, storedUsername);
    getline(inFile, storedPassword);

    inFile.close();

    cout << "Enter Password: ";
    cin >> password;

    if (password == storedPassword)
    {
        cout << "Login Successful!\n";
        cout << "Welcome, " << storedUsername << "!\n";
    }
    else
    {
        cout << "Incorrect Password.\n";
    }
}

int main()
{
    int choice;

    do
    {
        cout << "\n=====================================\n";
        cout << " LOGIN AND REGISTRATION SYSTEM\n";
        cout << "=====================================\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                registerUser();
                break;

            case 2:
                loginUser();
                break;

            case 3:
                cout << "Thank you for using the system.\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 3);

    return 0;
}
