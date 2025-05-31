
#include <iostream>
#include <fstream> // File handling library.
#include <sstream>
#include <string>

#include "Header_Files/Class_BookArticle.h" // Header file with classes Book and Article.
#include "Header_Files/Class_Users.h" // Header file with class for users.
#include "Header_Files/Function_ReadWrite.h" // Read and Write functions.

using namespace std;
using namespace book_and_articles;
using namespace read_and_write_functions;
using namespace user;

bool LoggingIn() {

    string username, password, user, pass;

    cout << "Enter username: "; cin >> username;
    cout << "Enter Password: "; cin >> password;

    ifstream read("User_Details/" + username + ".txt");
    getline(read, user);
    getline(read, pass);

    if (user == username && pass == password) {
        return true;
    } else {
        return false;
    }
}

int main() {

    int securityChoice;

    // Log in / Register
    while (true) {

        cout << "\nWelcome to the Library Management System. Please log in or register an account. Please choose an option with its assigned number." << endl;
        cout << "\n1. Register\n2. Log in\n3. Quit" << endl;
        cin >> securityChoice;

        if (securityChoice == 1) { // Registration.

            string username, password;

            cout << "Input a username: "; cin >> username;
            cout << "Input a password: "; cin >> password;

            User newUser(username, password);

            ofstream file;
            file.open("User_Details/" + username + ".txt");
            file << newUser.GetUsername() << endl << newUser.GetPassword();
            file.close();

        } else if (securityChoice == 2) { // Logging in.

            bool status = LoggingIn();
            if (status) {
                cout << "\nLog in successful." << endl;
                break; // If Log in successful, break and begin main do-while loop below.
            } else {
                cout << "Incorrect information, try again." << endl;
            }
        } else if (securityChoice == 3) {
            cout << "Goodbye." << endl;
            return 0;
        } else {
            cout << "Please enter choice 1, 2 or 3." << endl;
        }
    }

    // Begins the main program loop after log in.
    char continueChoice;
    
    do {

        int welcomeChoice, addChoice, viewChoice;
        string bookName;
        int bookYear;
        string articleName, articleSubject;
        int articleYear;

        // Welcome messages.
        cout << "\nWelcome! Please choose an option with its assigned number." << endl;
        cout << "1. Add an item to the system\n2. View the items already in the system\n3. Quit" << endl;
        cin >> welcomeChoice;

        // Check user choice.
        if (welcomeChoice == 1) {

            // Ask user to enter a book or an article.
            cout << "\nWould you like to enter a Book or an Article into the system? Please choose an option with its assigned number.\n1. Book\n2. Article\n3. Quit" << endl;
            cin >> addChoice;
            cin.ignore();

            // Check user input.
            if (addChoice == 1) {

                // Ask the user to enter book name and publication year.
                cout << "You have chosen Book." << endl;
                cout << "\nPlease enter the Book name and publication year." << endl;
                cout << "Name: ";
                getline(cin, bookName);
                cout << "Publication Year: ";
                cin >> bookYear;

                // Create an output file stream object and add new data to the stream.
                ofstream outFile("Text_Files/Books.txt", ios::app);

                // Create object with the user input, accessing class Book.
                Book myBook(bookName, bookYear);

                // Call the writeItem function, passing the outFile object, the book name and year
                writeItem(outFile, myBook.getName(), myBook.getYear());

                // Display book information to the user.
                cout << "Book added." << endl;

            } else if (addChoice == 2) {
                // User chooses article.
                    cout << "You have chosen Article." << endl;

                    cout << "\nPlease enter the Article name, subject/topic and publication year." << endl;
                    cout << "Name: ";
                    getline(cin, articleName);
                    cout << "Subject/topic: ";
                    getline(cin, articleSubject);
                    cout << "Publication Year: ";
                    cin >> articleYear;

                    // Create an output file stream object and add new data to the stream.
                    ofstream outFile("Text_Files/Articles.txt", ios::app);

                    // Create object with the user input, accessing class Article, a child of Book.
                    Article myArticle(articleName, articleYear, articleSubject);

                    // Call the writeItem function, passing the outFile object, the book name and year
                    writeItem(outFile, myArticle.getName(), myArticle.getYear(), myArticle.getSubject());

                    // Display the article information to the user.
                    cout << "Article added." << endl;

            } else if (addChoice == 3) {
                // Quit.
                cout << "Ok goodbye." << endl;
                break;

            
            } else {
                // Display error if user does not enter 1 or 2.
                cout << "Please enter either 1, 2 or 3." << endl;
            }
        
        } else if (welcomeChoice == 2) {
            // User chooses to view Books in the system.
            cout << "\nWould you like to view the books or the articles in the system?" << endl;
            cout << "1. Books\n2. Articles\n3. Quit" << endl;
            cin >> viewChoice;

            if (viewChoice == 1) {
                // Prints new line for readability.
                cout << " " << endl;
                // Create an input file stream object
                ifstream inFile;
                // Open the file that contains the items
                inFile.open("Text_Files/Books.txt", ios::in);
                // Call the readItem function
                while (inFile) { // Check if the inFile object is in a good state
                    readItem(inFile);
                }
                // Close the file
                inFile.close();

            } else if (viewChoice == 2) {
                // Prints new line for readability.
                cout << " " << endl;
                // Create an input file stream object
                ifstream inFile;
                // Open the file that contains the items
                inFile.open("Text_Files/articles.txt", ios::in);
                // Call the readItem function
                while (inFile) { // Check if the inFile object is in a good state
                    readItem(inFile);
                }
                // Close the file
                inFile.close();

            } else if (viewChoice == 3) {
                cout << "Ok goodbye." << endl;
                break;
            }

        } else if (welcomeChoice == 3) {
            // User chooses not to enter into the system.
            cout << "Ok goodbye." << endl;
            break;

        } else {
            // Display an error message if the user enters an invalid choice.
            cout << "Invalid choice. Please enter y or n." << endl;
        }

         // Ask the user if they want to continue or exit the program.
        cout << "\nDo you want to continue or exit the program? (c/e)." << endl;
        cin >> continueChoice;
        cin.ignore();

    // End the do-while loop and check the condition
    } while (continueChoice == 'c');

    // Display a farewell message if the user chooses to exit the program.
    cout << "Thank you for using the Library Management System. Have a nice day." << endl;

    // End of program.
    return 0;
}