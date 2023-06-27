#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int maxf(int& a, int& b) {

    if (a >= b) {
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

    int maxI=1;
    int maxJ=1;

    int max = 0;

    vector<vector<int>> v(N + 1, vector<int>(M + 1));




    vector<vector<int>> res(N + 1, vector<int>(M + 1, 0));

    for (int i = 1; i <= N; i++) {
        vector<int> a(M + 1);
        for (int j = 1; j <= M; j++) {
            int x;
            in >> x;
            a[j] = x;
        }
        v[i] = a;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (j == 1) {
                res[i][j] = res[i - 1][j] + v[i][j];
                if (res[i][j] >= max) {
                    max = res[i][j];
                    maxI = i;
                    maxJ = j;
                }
            }
            else if (i == 1) {
                res[i][j] = res[i][j - 1] + v[i][j];
                if (res[i][j] >= max) {
                    max = res[i][j];
                    maxI = i;
                    maxJ = j;
                }
            }
            else {
                res[i][j] = maxf(res[i - 1][j], res[i][j - 1]) + v[i][j];
                if (res[i][j] >= max) {
                    max = res[i][j];
                    maxI = i;
                    maxJ = j;
                }
            }
        }
    }

   // vector<char> way(M + N-2);
    vector<char> way;
   
   
    while(maxI > 1 || maxJ > 1){
        if (maxI == 1) {
            maxJ--;
            way.push_back('R');
            
        }
        else if (maxJ == 1) {
            maxI--;
            way.push_back('D');
            
        }
        else {
            if (res[maxI - 1][maxJ] > res[maxI][maxJ-1]) {
                way.push_back('D');
                maxI--;
                
            }
            else {
                way.push_back('R');
                maxJ--;
               
            }
        }
    }

    out << max << '\n';

    for (int i = way.size()-1; i >= 0; i--) {
        out << way[i] << ' ';
    }


    return 0;
}
