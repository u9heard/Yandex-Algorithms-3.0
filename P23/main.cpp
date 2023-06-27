#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int mymin(int a, int b) {
    if (a <= b) {
        return a;
    }
    return b;
}

int main()
{
    int N;
    ifstream in;
    ofstream out;
    
    in.open("input.txt");
    out.open("output.txt");

    in >> N;

    vector<int> step(N + 1, 0);
    vector<int> back;


    int min;

    for (int i = 2; i < N+1; i++) {
        min = step[i - 1] + 1;
        if (i % 2 == 0) {
            min = mymin(min, step[i / 2] + 1);
        }
        if (i % 3 == 0) {
            min = mymin(min, step[i / 3] + 1);
        }

        step[i] = min;
    }

    int bStep = N;
    back.push_back(bStep);
    while (bStep > 1) {
        if (step[bStep] == step[bStep - 1] + 1) {
            back.push_back(bStep-1);
            bStep--;
        }
        else if (bStep%2==0 && step[bStep] == step[bStep / 2] + 1) {
            back.push_back(bStep/2);
            bStep /= 2;
        }
        else {
            back.push_back(bStep/3);
            bStep /= 3;
        }
    }

    out << back.size()-1 << '\n';

    for (int i = back.size()-1; i >= 0; i--) {
        out << back[i] << ' ';
    }

    in.close();
    out.close();

    return 0;
}
