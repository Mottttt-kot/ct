#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <map>
#include <thread>
#include <chrono>
#define DEBUG

using namespace std;
int main()
{
    map<string, long> mp;
    string key;
    string value;
    while (true)
    {
        string path = "input.txt";
        fstream file;
        file.open(path, fstream::in | fstream::out);
        while (file >> key >> value)
            mp[key] = stol(value);
        srand(time(NULL));
        file.clear();
        file.seekp(0, ios::beg);
        long temp = 0;
        if (mp.size() == 4)
        {
            for (map<string, long>::iterator iter = begin(mp); iter != end(mp); ++iter)
            {
                iter->second += (rand() % 80) - 40;
            }
            for (map<string, long>::iterator iter = begin(mp); iter != end(mp); ++iter)
            {
                if (iter->second < 0)
                {
                    iter->second = 0L;
                }
                file << iter->first << " " << iter->second << endl;
            }
            file.close();
        }
        else
        {
            cout << "Error!" << endl;

        }
#ifdef DEBUG
        cout << "###############################################################################" << endl;
        for (map<string, long>::iterator iter = begin(mp); iter != end(mp); ++iter)
        {
            cout << iter->first << " " << iter->second << endl;
        }
        cout << "###############################################################################" << endl;
#endif // DEBUG
        std::this_thread::sleep_for(std::chrono::seconds(2));

    }
    


}
