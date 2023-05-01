#include <iostream>
#include <string>
#include <map>
#include <fstream>

using namespace std;

int main()
{
    ifstream in;
    in.open("input.txt");
    string str;
    map<char, unsigned long long> counts;

    in >> str;
    
    int size = str.size();
    for (int i = 0; i < size; i++) {
        if (counts.find(str[i]) != counts.end()) {
            counts[str[i]] += (long long)(i + 1) * (size-i);
        }
        else {
            counts[str[i]] = (i + 1) * (size - i);
        }
    }

    for (auto pair : counts) {
        cout << pair.first << ": " << pair.second << '\n';
    }

    return 0;
}
