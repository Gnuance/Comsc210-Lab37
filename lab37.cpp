/*
    Lab 37: Hash table
        1. Part One: write a function sum_ascii() that receives a single string and returns the sum of that string's character's ASCII values.
        2. Part Two:
            - Your code contains a large dataset: over 100,000 12-character strings of hexadecimal characters. These might represent serial numbers, part numbers, etc.
            - Read the file. Send each string to the function, receiving that string's ASCII sum, and totaling the return value into a grand total.
            - Output the grand total (the sum of all ASCII values in the entire file); it should be 69893419.
        3. Part Three:
            - Change the function sum_ascii() to gen_hash_index(). Adapt the code appropriately.
            - Create the std::map named hash_table. The key in the map is an int, the hash index. The value in a map is a std::list, which will contain the 12-character codes from the file that all map to that hash index.
            - When codes are read from the file, send the code to your function. Receive its hash index that's returned from the function. Input that pair into the map (the hash index and the code string). Remember that the code string is going into a std::list, so use the appropriate method to manipulate that std::list.
            - Display just the first 100 map entries to the console to test your data structure. Remember how to access map elements with .first and .second as necessary.
    
    Lab 38: Hash Tables II
        1. Add an interactive menu to your Lab 37 project with these new features:
            - Print the first 100 entries; search for a key; add a key; remove a key; modify a key; and exit.
        2. In your finished Lab 37, create a new Lab38 branch, and code this assignment on that branch.
            - Do not collapse/merge/pull/squash anything - just leave that branch active so I can see it.
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
            hashIndex = gen_hash_index(fileLine); // Get hash code for line
            auto it = hash_table.find(hashIndex); // Iterator to hash bucket in map
            if (it == hash_table.end())           // Key does NOT exist
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

    int counter = 0;                                                                                        // Counter for lines of output
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
