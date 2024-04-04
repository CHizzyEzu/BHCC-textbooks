// BHCC Textbook Purchase Tracker
// Junior Ezuma-Ngwu April 2, 2024

#include <iostream>
#include <fstream>
#include <string>
#include <limits>
using namespace std;

int main()
{
    // Code is contained within a file that can be used to add more information for later 
    // File is declared BHCC.txt and all code following this statement will be stored in a file
    ofstream outputFile;
    outputFile.open("BHCC.txt");

    // Check if the file is succesfully opened
    if (!outputFile.is_open())
    {
        cout << "Error: Unable to open file!" << "\n";
        return 1; // Exit the program with an error code
    }

    //Initialzed varaibles for the loop to run properly
    int total_students = 0;
    int total_textbooks = 0;
    double average_textbooks = 0;
    int input;
    int count = 0;

    // Input Loop
    while(true) 
    {
        cout << "Enter the number of textbooks purchased by a student (0 to 50, -999 to exit):  ";
        cin >> input;

        if(input == -999)
        {
            break;
            "\n";
        }

        if (input > 0 || input < 50 )
        {
            total_students++; //Adds total amount of students inputting data
            total_textbooks += input; // Adds total amount of textbooks purchased per student input
            count++;
        } 

        if (!(cin >> input) || (input > 50 || input < 0))
        {
            cout << "Invalid input. Please enter a number  between 0 and 50 or -999 to exit. " << "\n";

            // Clear input buffer
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignores letters for input

        }

    }

    // Calculate average amount of textbooks
    if (count > 0) 
    {

        // Output results to terminal 
        average_textbooks = static_cast <double> (total_textbooks) / count; // average initialzed before calculations
        cout << "Total students: " << total_students << "\n";
        cout << "Total textbooks: " << total_textbooks << "\n";
        cout << "Average number of textbooks: " << average_textbooks << "\n";

        // Write data to output file
        outputFile << "Total students: " << total_students << "\n";
        outputFile << "Total textbooks: " << total_textbooks << "\n";
        outputFile << "Average number of textbooks: " << average_textbooks << "\n";
    } 

    else 
    {

        cout << "No valid data entered. ";
    }
    //Close the output file
    outputFile.close(); // File ends here

    // Open and read from the file
    string fileName = "BHCC.txt";
    ifstream inputFile (fileName);

    if (!inputFile.is_open())
    {
        cout << "Error: Unable to open file '" << fileName << "'!" << "\n";
        return 1;
    }

    // Read data from the file
    int readTotalStudents, readTotalTextbooks;
    double readAverageTextbooks;

    inputFile.ignore(numeric_limits<streamsize>::max(), '\n'); //Skips the first line

    //Initialzied Values
    const int readTotalStudents = total_students;
    const int readTotalTextbooks = total_textbooks;
    const int readAverageTextbooks = average_textbooks;

    inputFile >> readTotalStudents >> readTotalTextbooks >> readAverageTextbooks;

    // Output data read from the file
    cout << "\n Data read from the file: \n";
    cout << "Total students: " << readTotalStudents << "\n";
    cout << "Total textbooks: " << readTotalTextbooks << "\n";
    cout << "Average number of textbooks: " << readAverageTextbooks << "\n";

    // Close the input file
    inputFile.close(); // File ends its executions

    return 0; // Code ends
}