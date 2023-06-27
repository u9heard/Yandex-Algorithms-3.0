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
    int l1, l2;
    in >> l1;

    vector<int> x(l1 + 1, 0);

    for (int i = 1; i <= l1; i++) {
        in >> x[i];
    }
    in >> l2;
    vector<int> y(l2 + 1, 0);

    for (int i = 1; i <= l2; i++) {
        in >> y[i];
    }

    vector<vector<int>> full(l2 + 1, vector<int>(l1 + 1, 0));


    for (int i = 1; i <= l2; i++) {
        for (int j = 1; j <= l1; j++) {
            if (x[j] == y[i]) {
                full[i][j] = full[i - 1][j - 1] + 1;
            }
            else {
                full[i][j] = max(full[i - 1][j], full[i][j - 1]);
            }
        }
    }


    vector<int> res;
    int i = x.size() - 1;
    int j = y.size() - 1;

    while (i > 0 && j > 0) {
        if (x[i] == y[j]) {
            res.push_back(x[i]);
            i--;
            j--;
        }
        else if (full[j - 1][i] > full[j][i - 1]) {
            j--;
        }
        else {
            i--;
        }

    }



    for (int i = res.size() - 1; i >= 0; i--){
        out << res[i] << ' ';
    }

    in.close();
    out.close();



    return 0;
}
