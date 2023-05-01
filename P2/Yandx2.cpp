#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int searchMax(char &mChar, map<char,int> &mp) {
    map <char, int> ::iterator it = mp.begin();
    int max = 0;
    int lastMax = mp[mChar];
    for (int i = 0; it != mp.end(); ++it, ++i) {
        if (it->second > max) {
            mChar = it->first;
            max = it->second;
        }
    }
    if (max > lastMax) {
        return max;
    }
    return lastMax;
}

int searchBad(char &mChar, map<char, int> mp) {
    map <char, int> ::iterator it = mp.begin();
    int res = 0;
    for (int i = 0; it != mp.end(); ++it, ++i) {
        if (it->first != mChar) {
            res += it->second;
        }
    }
    return res;
}

int main()
{
    int N;
    string s;
    map<char, int> mp;

    cin >> N >> s;

    int ptr1 = 0;
    int ptr2 = 0;
    int max = 0;    //Максимальная длина
    int maxChar = 0; //Больше всего встретилось
    char mCh;
    int cntBad = 0;     //Колво замен
    while (ptr2 <= s.size()) {
        while (cntBad <= N && ptr2 <= s.size()) {
            if (mp.find(s[ptr2]) != mp.end()) {
                mp[s[ptr2]] += 1;
            }
            else {
                mp[s[ptr2]] = 1;
            }
            maxChar = searchMax(mCh, mp);
            cntBad = searchBad(mCh, mp);
            ++ptr2;
        }

        if (ptr2 - ptr1 > max) {
            max = ptr2 - ptr1;
        }

        while (cntBad = searchBad(mCh, mp) > N) {
            mp[s[ptr1]] -= 1;
            ++ptr1;
        }
            
    }

    cout << max-1;

    return 0;
}
