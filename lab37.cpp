#include <iostream>
using namespace std;

int sum_ascii(const string &); // Receives a single string and returns the sum of that string's character's ASCII values

int main()
{
    cout << sum_ascii("Hello") << endl;

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
