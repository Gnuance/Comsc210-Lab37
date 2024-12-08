/*  
    Lab 37: Hash table
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <list>
using namespace std;

int gen_hash_index(const string &); // Receives a single string and returns the sum of that string's character's ASCII values

const string INPUT_FILENAME = "lab37Data.txt"; // Filename for data input

int main()
{
    ifstream inputFile;                // For ascii codes
    string fileLine = "";              // A line from the input file
    int lineCount = 0;                 // Count of the number of lines from input file
    int sum = 0;                       // Sum of ascii codes
    map<int, list<string>> hash_table; // Table holding values from file
    int hashIndex = 0;                 // Hash index of line within loop
    const int NUM_LINES_OUTPUT = 100;  // Number of lines to output

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
            hashIndex = gen_hash_index(fileLine);
            auto it = hash_table.find(hashIndex);
            if (it == hash_table.end()) // Key does NOT exist
            {
                hash_table.insert({hashIndex, {fileLine}}); // Create new entry
            }
            else
            {
                it->second.push_back(fileLine); // Add to current entry
            }

            lineCount++;
        }
        // CLOSE THE F-ING FILE
        inputFile.close();
    }

    int counter = 0;    // Counter to determine number of lines to output
    for (auto itMap = hash_table.begin(); itMap != hash_table.end() && counter < NUM_LINES_OUTPUT; itMap++) // For each map object
    {
        for (auto itList = itMap->second.begin(); itList != itMap->second.end() && counter < NUM_LINES_OUTPUT; itList++) // For each list inside map
        {
            cout << fixed << setw(3) << right << ++counter << ". " << *itList << endl; // Counter incremented in statement
        }
    }

    cout << "\nTotal lines read from " << INPUT_FILENAME << ": " << lineCount << endl;

    return 0;
}

// Receives a single string and returns the sum of that string's character's ASCII values
int gen_hash_index(const string &s)
{
    int sum = 0;
    for (char letter : s)
    {
        sum += (int)letter;
    }
    return sum;
}
