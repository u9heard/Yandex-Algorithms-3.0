#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Heap {
public:
    vector<int> h;
    


    Heap() {
        h.reserve(50);
        
    }

    void insert(int x) {
        h.push_back(x);
        int pos = h.size() - 1;
        
        while (pos > 0 && h[(pos - 1) / 2] < h[pos]) {
            swap(h[(pos - 1)/2], h[pos]);
            pos = (pos - 1) / 2;
        }
    }

    int extract() {
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
};

int main()
{
    Heap h;
    ifstream in;
    ofstream out;
    in.open("input.txt");
    out.open("output.txt");
    int N;
    
    in >> N;

    for (int i = 0; i < N; i++) {
        int c;
        in >> c;

        if (c == 0) {
            int x;
            in >> x;
            h.insert(x);
        }
        else if(c==1){
            out << h.extract() << '\n';
        }
    }
    
    in.close();
    out.close();

    return 0;
}

