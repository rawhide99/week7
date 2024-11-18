#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int>vec1;
    vector<int>vec2;

//----------------------------------------------
    vec1.push_back(10);
    vec1.push_back(20);

    cout << "The elements of vector vec1 are: " << endl;
    cout << vec1.at(0) << endl;
    cout << vec1.at(1) << endl;
    cout << "The size of the vec1 vector is " << vec1.size() << endl;

//----------------------------------------------
    vec2.push_back(100);
    vec2.push_back(200);

    cout << "The elements of vector vec2 are: " << endl;
    cout << vec2.at(0) << endl;
    cout << vec2.at(1) << endl;
    cout << "The size of the vec1 vector is " << vec2.size() << endl;


//----------------------------------------------

    vector<vector<int>>vector_2d;

    vector_2d.push_back(vec1);
    vector_2d.push_back(vec2);

    cout << "The elements of vector vector_2d are: " << endl;
    cout << vector_2d.at(0).at(0) << endl;
    cout << vector_2d.at(0).at(1) << endl;
    cout << vector_2d.at(1).at(0) << endl;
    cout << vector_2d.at(1).at(1) << endl;

    cout << "Modifying Vector1's first element to 100." << endl;
    vec1.at(0) = 1000;
    cout << "Showing again the elements of vector vector_2d are: " << endl;
    cout << vector_2d.at(0).at(0) << endl;
    cout << vector_2d.at(0).at(1) << endl;
    cout << vector_2d.at(1).at(0) << endl;
    cout << vector_2d.at(1).at(1) << endl;

    cout << "After modification, the elements of vector vec1 are: " << endl;
    cout << vec1.at(0) << endl;
    cout << vec1.at(1) << endl;

    return 0;
}