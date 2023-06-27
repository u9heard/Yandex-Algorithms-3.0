#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int min(int a, int b) {
    if (a <= b) {
        return a;
    }
    return b;
}

int abs(int x) {
    if (x < 0) {
        return x * -1;
    }
    return x;
}

int main()
{
    ifstream in;
    ofstream out;
    in.open("input.txt");
    out.open("output.txt");
    int N;
    
    in >> N;
    vector<int> price(N + 1,0);
    for (int i = 1; i <= N; i++) {
        int x;
        in >> x;
        price[i] = x;
    }

    vector<vector<int>> res(N + 1, vector<int>(N + 1, 1000000));
    res[0][0] = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            int a = 1000000;
            int b = 1000000;
            int c = 1000000;
            
            if (j > 0 && price[i] > 100) {
                a = res[i - 1][j - 1] + price[i];
            }
            b = res[i - 1][j]+price[i];
            if (j < N) {
                c = res[i - 1][j + 1];
            }

           

            res[i][j] = min(a, min(b, c));
        }
    }

    int k1sum= 1000000;
    int k1 = 0;
    

    for (int i = 0; i <= N; i++) {
        if (res[N][i] <= k1sum) {
            k1sum = res[N][i];

            k1 = i;
        }
    }

    int i = N;
    int j = k1;
    vector<int> back;

    while (i > 0) {

        int a = 1000000;
        int b = 1000000;
        int c = 1000000;

        if (j > 0 && price[i] > 100) {
            a = res[i - 1][j - 1] + price[i];
        }
        b = res[i - 1][j] + price[i];
        if (j < N) {
            c = res[i - 1][j + 1];
        }



        int m = min(a, min(b, c));


        if (c==m ) {
            back.push_back(i);
            i--;
            j++;
        }
        else if (a == m) {
            i--;
            j--;
        }
        else {
            i--;
        }
    }
    
    out << k1sum << '\n' << k1 << ' ' << back.size() << '\n';

    for (int i = back.size() - 1; i >= 0; i--) {
        out << back[i] << '\n';
    }

    in.close();
    out.close();

    return 0;
}
