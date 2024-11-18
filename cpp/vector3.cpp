#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<vector<int>>ratings
    {
        {1,2,3,4},
        {5,6,7,8},
        {9,7,5,3}
    };

    cout << "Here are the movie ratings for the watcher using first syntax" << endl;
    cout << ratings[0][0] << endl;
    cout << ratings[0][1] << endl;
    cout << ratings[0][2] << endl;
    cout << ratings[0][3] << endl;

    cout << "Here are the movie ratings for the watcher using second syntax" << endl;
    cout << ratings.at(0).at(0) << endl;
    cout << ratings.at(0).at(1) << endl;
    cout << ratings.at(0).at(2) << endl;
    cout << ratings.at(0).at(3) << endl;


    return 0;
}