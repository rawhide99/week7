#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int>scores(3);

    cout << "Enter all the 3 scores in vector out of 50." << endl;
    cin >> scores.at(0);
    cin >> scores.at(1);
    cin >> scores.at(2); 

    cout << "The scores given by judges are: " << endl;
    cout << "The first score is: " << scores.at(0) << endl;
    cout << "The second score is: " << scores.at(1) << endl;
    cout << "The Third score is: " << scores.at(2) << endl;

    cout << "Enter to add a new score in vector. " << endl;
    int score_to_add = 0;
    cin >> score_to_add;
    scores.push_back(score_to_add);

    cout << "Enter one more score to add to a vector. " << endl;
    cin >> score_to_add;
    scores.push_back(score_to_add);

    cout << "The total number of scores in vector scores is: " << scores.size() << endl;

    for(int i = 0; i < scores.size(); i++)
    {
        cout << i+1 << " score is " << scores.at(i) << endl;
    }

    return 0;
}