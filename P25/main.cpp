#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int min(int a, int b) {
    if (a <= b) {
        return a;
    }
    return b;
}

int main()
{
    ifstream in;
    ofstream out;

    in.open("input.txt");
    out.open("output.txt");

    

    int N;
    in >> N;
    vector<int> n(N, 0);

    for (int i = 0; i < N; i++) {
        int x;
        in >> x;
        n[i] = x;
    }

    sort(n.begin(), n.end());

    vector<int> res(N ,0);
    res[1] = n[1] - n[0];
    res[2] = n[2] - n[0];

    for (int i = 3; i < N; i++) {
        res[i] = min(res[i - 2], res[i - 1]) + n[i] - n[i - 1];
    }

    out << res[N-1];

    return 0;
}
