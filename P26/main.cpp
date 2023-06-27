#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int min(int &a, int &b) {
    
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

    int N, M;
    in >> N >> M;

    vector<vector<int>> v(N+1, vector<int>(M+1));
   

   

    vector<vector<int>> res(N+1, vector<int>(M+1, 0));

    for (int i = 1; i <= N; i++) {
        vector<int> a(M+1);
        for (int j = 1; j <= M; j++) {
            int x;
            in >> x;
            a[j]=x;
        }
        v[i]=a;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (j == 1) {
                res[i][j] = res[i - 1][j] + v[i][j];
            }
            else if (i == 1) {
                res[i][j] = res[i][j-1] + v[i][j];
            }
            else {
                res[i][j] = min(res[i - 1][j], res[i][j - 1]) + v[i][j];
            }
        }
    }

    out << res[N][M];


    return 0;
}
