#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
    ifstream in;
    ofstream out;

    in.open("input.txt");
    out.open("output.txt");

    int N, M;
    in >> N >> M;

    vector<vector<int>> res(N+1, vector<int>(M+1, 0));
    res[1][1] = 1;

    for (int i = 2; i <= N; i++) {
        for (int j = 2; j <= M; j++) {
            res[i][j] = res[i - 1][j - 2] + res[i - 2][j - 1];
        }
    }
        
    out << res[N][M];

    return 0;
}
