#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int min(int a, int b) {
    if (a <= b) {
        return a;
    }
    else {
        return b;
    }
}

int main()
{
    ifstream in;
    ofstream out;
    in.open("input.txt");
    out.open("output.txt");
    int N;
    in >> N;
    vector<int> A(N + 3, 3601);
    vector<int> B(N + 3, 3601);
    vector<int> C(N + 3, 3601);

    for (int i = 3; i < N+3; i++) {
        int a, b, c;
        in >> a >> b >> c;
        A[i] = a;
        B[i] = b;
        C[i] = c;
    }

    vector<int> res(N+3, 0);

    for (int i = 3; i < N+3; i++) {
        res[i] = min(res[i - 1] + A[i], min(res[i - 2] + B[i - 1], res[i - 3] + C[i - 2]));
    }

    out << res[N+2];

    in.close();
    out.close();

    return 0;
}
