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
    std::ofstream outputFile;
    outputFile.open("BHCC.txt");

    // Check if the file is succesfully opened
    if (!outputFile.is_open())
    {
        cout << "Error: Unable to open file!" << "\n";
        return 1; // Exit the program with an error code
    }

    //Initialzed varaiables for the loop to run properly
    int total_students = 0;
    int total_textbooks = 0;
    double average_textbooks = 0;
    int input;
    int count = 0;

    // Input Loop
    while(true) 
    {
        cout << "Enter the number of textbooks purchased by a student (0 to 50, -999 to exit):  ";
        
        while(!(cin >> input))
        {
            cout << "Invalid input. Please enter a number between 0 and 50 or -999 to exit:  " << "\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

        }
        if(input == -999)
        {
            cout << "\n";
            break;
        }

        if (input >= 0 && input <= 50 )
        {
            total_students++; //Adds total amount of students inputting data
            total_textbooks += input; // Adds total amount of textbooks purchased per student input
            count++;
        } 
        else
        {
            cout << "Invalid input. Please enter a number between 0 and 50 or -999 to exit:  " << "\n";
            continue;
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
        outputFile << "Average number of textbooks: " << average_textbooks << "\n\n";
    } 

    else 
    {

        cout << "No valid data entered:  ";
    }
    //Close the output file
    outputFile.close(); // File ends here

    // Open and read from the file
    std::string fileName = "BHCC.txt";
    std::ifstream inputFile (fileName);

    if (!inputFile.is_open())
    {
        cout << "Error: Unable to open file: '" << fileName << "'!" << "\n";
        return 1;
    }

    // Read data from the file
    unsigned int readTotalStudents = 0, readTotalTextbooks = 0;
    long double readAverageTextbooks = 0;

    // Verify if the string is within an exisiting value
    try
    {

    // Read the lines and output them
    std::string line;    
    for (int i = 0; i < 4; ++i) // Loops the appearance of lines within the file
    {
        getline(inputFile, line);
        cout << line << endl; 
    }

        // Read and discard the first line
        getline(inputFile, line);

        // Read second line and extract the value of the total students
        getline(inputFile, line);
        readTotalStudents = stoi(line.substr(line.find(":") + 2));

        // Read the third line and extract the value of total textbooks
        getline(inputFile, line);
        readTotalTextbooks = stoi(line.substr(line.find(":") + 2));

        getline(inputFile, line);
        readAverageTextbooks = stod(line.substr(line.find(":") + 2));

    } 
    catch(const std::exception &e) 
    {
        // Verify if string is assigned real value 
        std::cerr << "Error: Invalid data format in the file:  " << e.what() << std::endl;
        return 1;
    }
  
    // Close the input file
    inputFile.close(); // File ends its executions

    return 0; // Code ends
}