#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <char> vowels {'a','e','i','o','u'};
    cout << "The first vowel is " << vowels[0] << endl;
    cout << "The last vowel is " << vowels[4] << endl;

    //vector <int> test_scores(3);    // All 3 elements initialized to zero.
    vector <int> test_scores(3,100);    // All 3 elements initialized to Hundred.

    vector <int> marks {100,96,89};
    cout << "The marks at 1st position is " << marks[0] << endl;
    cout << "The marks at 2nd position is " << marks[1] << endl;
    cout << "The marks at 3rd position is " << marks[2] << endl;

    // Marks using vector syntax

    cout << "Marks using vector syntax: " << endl;

    cout << "The marks at 1st position is " << marks.at(0) << endl;
    cout << "The marks at 2nd position is " << marks.at(1) << endl;
    cout << "The marks at 3rd position is " << marks.at(2) << endl;
    cout << "The size of vector marks is " << marks.size() << endl;

    return 0;
}