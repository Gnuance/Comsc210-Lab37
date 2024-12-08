#include <iostream>
#include <fstream>
using namespace std;

int sum_ascii(const string &); // Receives a single string and returns the sum of that string's character's ASCII values

const string INPUT_FILENAME = "lab37Data.txt"; // Filename for data input

int main()
{
    ifstream inputFile;   // For ascii codes
    string fileLine = ""; // A line from the input file
    int lineCount = 0;    // Count of the number of lines from input file
    int sum = 0;          // Sum of ascii codes

    // Try opening file and output error to console if file is no good
    inputFile.open(INPUT_FILENAME);
    if (!inputFile)
    {
        throw runtime_error("Error opening file: " + INPUT_FILENAME);
    }
    else
    {
        while (getline(inputFile, fileLine))
        {
            sum += sum_ascii(fileLine);
            lineCount++;
        }
        // CLOSE THE F-ING FILE
        inputFile.close();
    }

    cout << sum;

    return 0;
}

// Receives a single string and returns the sum of that string's character's ASCII values
int sum_ascii(const string &s)
{
    int sum = 0;
    for (char letter : s)
    {
        sum += (int)letter;
    }
    return sum;
}

/*
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/
