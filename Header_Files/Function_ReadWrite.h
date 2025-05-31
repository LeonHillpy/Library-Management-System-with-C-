
#include <iostream>
#include <fstream> // File handling library.
#include <sstream>
#include <string>
#include <vector>
using namespace std;

namespace read_and_write_functions {

    // A function to write an item to a file
    void writeItem(ofstream& outFile, string name, int year, string subject = "") {
        // Check if the file is opened successfully
        if (outFile.is_open()) {
            // Write the item name and year to the file
            outFile << name << " " << year << " ";
            // If the item has a subject, write it to the file
            if (subject != "") {
                outFile << subject << " ";
            }
            // Write a new line to the file
            outFile << endl;
        } else {
            // Display an error message if the file cannot be opened
            cout << "Error: Unable to open file." << endl;
        }
    }

    // A function to read an item from a file and display its contents.
    void readItem(ifstream& inFile) {
        // Declare variables to store the item name, year, and subject
        string line;
        // Read the entire line from the file
        while (getline(inFile, line)) {
            // Create a stringstream to parse the line
            istringstream iss(line);
            // Declare variables to store the item name, year, and subject
            string name;
            int year;
            string subject;
            // Read the item name and year from the stringstream
            iss >> name;
            // Read the remaining words in the name
            string word;
            while (iss >> word) {
                name += " " + word;
            }
            // Display the item name, year, and subject
            cout << name << endl;
        }
    }
}