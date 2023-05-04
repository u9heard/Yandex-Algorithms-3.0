#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void heapify(vector<int>& v) {
    int p = (v.size() / 2)-1;
    
    for (int i = p; i >= 0; i--) {
        int pos = i;
        while (pos * 2 + 2 < v.size()+1) {
            int maxIdx = pos * 2 + 1;

            if (pos*2+2 < v.size() && v[pos * 2 + 2] > v[maxIdx]) {
                maxIdx = pos * 2 + 2;
            }
            
            if (v[pos] < v[maxIdx]) {
                swap(v[pos], v[maxIdx]);
                pos = maxIdx;
            }
            else {
                break;
            }
        }
    }
}

int extract(vector<int> &h) {
    int res = h[0];
    h[0] = h[h.size() - 1];
    int pos = 0;

    while (pos * 2 + 2 < h.size()) {
        int maxIdx = pos * 2 + 1;

        if (h[pos * 2 + 2] > h[maxIdx]) {
            maxIdx = pos * 2 + 2;
        }
        if (h[pos] < h[maxIdx]) {
            swap(h[pos], h[maxIdx]);
            pos = maxIdx;
        }
        else {
            break;
        }

    }
    h.pop_back();
    return res;
}

int main()
{
    ifstream in;
    ofstream out;
    vector<int> v;
    vector<int> res;
    in.open("input.txt");
    out.open("output.txt");
    int N;
    in >> N;
    v.reserve(N);
    res.reserve(N);
    for (int i = 0; i < N; i++) {
        int x;
        in >> x;
        v.push_back(x);
    }

    heapify(v);
    int sz = v.size();
    for (int i = sz - 1; i >= 0; i--) {
        res.push_back(extract(v));
    }

    for (int i = N-1; i>=0; i--) {
        out << res[i] << ' ';
    }

    in.close();
    out.close();
    return 0;
}

