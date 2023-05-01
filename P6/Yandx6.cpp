#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
    int M, N;
    vector<vector<int>> sec;
    ifstream f;
    f.open("input.txt");


    f >> M >> N;

    for (int i = 0; i < N; i++) {
        int a, b;
        f >> a >> b;

        for (int j = 0; j < sec.size(); j++) {
            if (a == 146484632 && sec[j][0] == 134100473) {
                cout << 's';
            }
            if ((sec[j][0] >= a && sec[j][0] <= b) || (sec[j][1] >= a && sec[j][1] <= b)) {
                sec[j][0] = 0;
                sec[j][1] = 0;
            }
            else if ((sec[j][0] <= a && sec[j][1] >= a) || (sec[j][0] <= b && sec[j][1] >= b)) {
                sec[j][0] = 0;
                sec[j][1] = 0;
            }
            
        }
        vector<int> v = { a ,b };
        sec.push_back(v);
        
    }
    int res = 0;
    for (int i = 0; i < sec.size(); i++) {
        if (sec[i][0] != 0 && sec[i][1] != 0) {
            res++;
        }
    }
    cout << res;
    return 0;
}

