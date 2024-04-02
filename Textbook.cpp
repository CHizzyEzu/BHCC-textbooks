// BHCC Textbook Purchase Tracker
// Junior Ezuma-Ngwu April 2, 2024

#include <iostream>
using namespace std;

int main()
{

// Initialzed Varaibles for the loop to run properly

    int total_students = 0;
    int total_textbooks = 0;
    double average_textbooks = 0;
    int input;
    int count = 0;


// -999 is used to exit the program
// when an input between 0 - 50 is inputted that value gets added to the total amount of textbooks
// After each input is submitted in the loop adds the total amount of students within the prgoram increments by 1
// if and if/else statements are included to specify the parameters and incrementation of the loop

    while(true) 
    {
        cout << "Enter the number of textbooks purchased by a student (0 to 50, -999 to exit):  ";
        cin >> input;

        if(input == -999)
        {
            break;
        }

        if (input >= 0 && input <= 50)
        {
            total_students++;
            total_textbooks += input;
            count++;
        } 

        else
        {
            cout << "Invalid input. Please enter a number  between 0 and 50 or -999 to exit. " << "\n";
            continue;
        }

    }
// Used a static cast for the average_textbooks variable to make the average become a decimal
// Output the totals of students, textbooks, and average of textbooks purchased outside of the loop
// Included an if else statement for the event that the data entered is invalid for this code to function

    if (count > 0) 
    {
        average_textbooks = static_cast <double> (total_textbooks) / count;
        cout << "Total students: " << total_students << "\n";
        cout << "Total textbooks: " << total_textbooks << "\n";
        cout << "Average number of textbooks: " << average_textbooks << "\n";
    } 

    else 
    {

        cout << "No valid data entered. ";
    }

    return 0;
}