#include <iostream>
#include <chrono>
#include <list>
#include <set>
#include <vector>
#include <iomanip>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
using namespace std::chrono;

int main() {

    ifstream inputFile("codes.txt");

    if(!inputFile.is_open())
    {
        cout << "Error! Can't open File!";
    }

    vector<int> timeRead;
    vector<int> timeSort;
    vector<int> timeInsert;
    vector<int> timeDelete;

    vector<string> vec;
    list<string> lis;
    set<string> se;

    for(int i = 0; i < 3; i++)
    {
        // Start timing
        auto start = high_resolution_clock::now();

        // Example loop to measure
        if (i == 0)
        {
            string temp;
            while(getline(inputFile, temp))
                vec.push_back(temp);
        }
        if (i == 1)
        {

            string temp;
            while(getline(inputFile, temp))
                lis.push_back(temp);
        }
        if (i == 2)
        {

            string temp;
            while(getline(inputFile, temp))
                se.insert(temp);
        }

        // End timing
        auto end = high_resolution_clock::now();

        // Calculate duration
        auto duration = duration_cast<milliseconds>(end - start);

        timeRead.push_back(duration.count());
    }

    for(int i = 0; i < 3; i++)
    {
        // Start timing
        auto start = high_resolution_clock::now();

        // Example loop to measure
        if (i == 0)
        {
            sort(vec.begin(), vec.end());
        }
        if (i == 1)
        {

            lis.sort();
        }
        if (i == 2)
        {
            timeSort.push_back(-1);
        }

        // End timing
        auto end = high_resolution_clock::now();

        // Calculate duration
        auto duration = duration_cast<milliseconds>(end - start);

        timeSort.push_back(duration.count());
    }

    for(int i = 0; i < 3; i++)
    {
        // Start timing
        auto start = high_resolution_clock::now();

        // Example loop to measure
        if (i == 0)
        {
            sort(vec.begin(), vec.end());
        }
        if (i == 1)
        {

            lis.sort();
        }
        if (i == 2)
        {
            timeSort.push_back(-1);
        }

        // End timing
        auto end = high_resolution_clock::now();

        // Calculate duration
        auto duration = duration_cast<milliseconds>(end - start);

        timeInsert.push_back(duration.count());
    }

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/
