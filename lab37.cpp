#include <iostream>
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
                hash_table.insert({hashIndex, {fileLine}});     // Create new entry
            }
            else
            {
                it->second.push_back(fileLine);   // Add to current entry
            }

            lineCount++;
        }
        // CLOSE THE F-ING FILE
        inputFile.close();
    }

    int counter = 0;
    for (auto it = hash_table.begin(); it != hash_table.end() && counter < 100; it++)
    {
        
    }
    

    cout << lineCount << endl;

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

/*
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/
