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

int gen_hash_index(const string &);                           // Receives a single string and returns the sum of that string's character's ASCII values
int mainMenu();                                               // Outputs prompt and collects user selection
bool isValidOption(string, const int, const int);             // Helper function to validate user input
void PrintEntries(const map<int, list<string>> &, const int); // Print number of entries specified
void addKey();                                                // Adds key to table
void searchKey();                                             // Returns whether key exists and related values
void removeKey();                                             // Removes key and related values
void modifyKey();                                             // Modifies a key and transfers list values to new key

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
    int userSelectedOption = 0;        // Holds user selection

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

    // Prompt user for selection and input
    // User selection 0 is the program exit code
    do
    {
        userSelectedOption = mainMenu();
        switch (userSelectedOption)
        {
        case 1:
            // Outputs given number of items to console
            PrintEntries(hash_table, NUM_LINES_OUTPUT);
            break;
        case 2:
            // Takes user to function to delete a given text string within tree
            addKey();
            break;
        case 3:
            // Deletes key and associated data
            removeKey();
            break;
        case 4:
            // Tells user whether a key exists
            searchKey();
            break;
        case 5:
            // Allows user to modify a key
            modifyKey();
            break;
        default:
            break;
        }
    } while (userSelectedOption != 0);

    cout << "Thank you for using the BST management tool" << endl;

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

// Main menu for application
int mainMenu()
{
    string userInput = "";

    do
    {
        // Output prompt
        cout << "\nHash Table Menu" << "\n"
             << "[1] Print first 100 entries" << "\n"
             << "[2] Add key" << "\n"
             << "[3] Remove key" << "\n"
             << "[4] Modify key" << "\n"
             << "[0] Quit" << "\n"
             << "Choice --> ";
        getline(cin, userInput); // Get user input as string and test
        cout << endl;
    } while (!isValidOption(userInput, 0, 4));

    // If isValidOption passed, stoi(userInput) has already been tested and is safe
    return stoi(userInput);
}

// Return t/f if userInput is a valid int between min and max
// WARNING: stoi() will convert a double to an int or any string following an int.
// Ex: stoi("2.9") will return 2 and so will stoi("2tGznso"), etc.
bool isValidOption(string userInput, const int minOption, const int maxOption)
{
    int selectedOption = 0;
    try
    {
        selectedOption = stoi(userInput);
    }
    catch (const std::exception &e)
    {
        cout << "Invalid input: Please enter a valid integer." << "\n\n";
        return false;
    }

    // if userInput is an int but outside expected range
    if (selectedOption < minOption || selectedOption > maxOption)
    {
        cout << "Invalid input: Please enter an integer between " << minOption << " and " << maxOption << "." << "\n\n";
        return false;
    }

    return true;
}

// Print number of entries specified
void PrintEntries(const map<int, list<string>> &mapContainer, const int numToPrint)
{
    int counter = 0;                                                                                      // Counter for lines of output
    for (auto itMap = mapContainer.begin(); itMap != mapContainer.end() && counter < numToPrint; itMap++) // For each map object
    {
        for (auto itList = itMap->second.begin(); itList != itMap->second.end() && counter < numToPrint; itList++) // For each list inside map
        {
            cout << fixed << setw(3) << right << ++counter << ". " << *itList << endl; // Counter incremented in statement
        }
    }
}

// Adds key to table
void addKey()
{
}

// Returns whether key exists and related values
void searchKey()
{
}

// Removes key and related values
void removeKey()
{
}

// Modifies a key and transfers list values to new key
void modifyKey()
{
}
