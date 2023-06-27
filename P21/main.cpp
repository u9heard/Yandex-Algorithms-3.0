#include <iostream>
#include <vector>

using namespace std;


int main()
{
    vector<unsigned long long> v(100002, -1);
    int in;
    cin >> in;

    v[1] = 2; 
    v[2] = 4;
    v[3] = 7;

    if (in == 1) {
        cout << 2;
        return 0;
    }
    if (in == 2) {
        cout << 4;
        return 0;
    }
    if (in == 3) {
        cout << 7;
        return 0;
    }

    for (int i = 4; i <= in; i++) {
        v[i] = v[i - 1] + v[i - 2] + v[i - 3];
    }

    cout << v[in];

    return 0;
}
