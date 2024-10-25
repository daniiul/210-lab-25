#include <iostream>
#include <chrono>
#include <list>
#include <set>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;
using namespace std::chrono;

int main() {

    ifstream inputFile("codes.txt");

    if(!inputFile.is_open())
    {
        cout << "Error! Can't open File!";
    }

    vector<string> timeRead;
    vector<string> timeSort;
    vector<string> timeInsert;
    vector<string> timeDelete;

    for(int i = 0; i < 3; i++)
    {
        // Start timing
        auto start = high_resolution_clock::now();

        // Example loop to measure
        if (i == 0)
        {
            vector<string> in;
            string temp;
            while(getline(inputFile, temp))
                in.push_back(temp);
        }
        if (i == 1)
        {
            list<string> in;
            string temp;
            while(getline(inputFile, temp))
                in.push_back(temp);
        }
        if (i == 2)
        {
            set<string> in;
            string temp;
            while(getline(inputFile, temp))
                in.insert(temp);
        }


        // End timing
        auto end = high_resolution_clock::now();

        // Calculate duration
        auto duration = duration_cast<milliseconds>(end - start);

        timeRead.push_back(duration.count());

    }

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/
