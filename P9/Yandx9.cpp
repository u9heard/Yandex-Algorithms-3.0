#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<int> findPrefs1D(vector<int> &v) {
    vector<int> res(v.size()+1);
    for (int i = 0; i < v.size(); i++) {
        res[i+1] = res[i] + v[i];
    }

    return res;
}

vector<vector<int>> prefix2D(vector<vector<int>> &v) {
    int n = v.size();
    int m = v[0].size();

    vector<vector<int>> pref1d(n);
    
    
    for (int i = 0; i < n; i++) {
        
        pref1d[i]=findPrefs1D(v[i]);
    }
    vector<vector<int>> pref2d(n + 1, vector<int>(m + 1, 0));

    for (int j = 1; j <= m; j++) {
        for (int i = 0; i < n; i++) {
            pref2d[i + 1][j] = pref2d[i][j] + pref1d[i][j];
        }
    }
    return pref2d;
}

int findpref(vector<vector<int>> &v, int x1, int y1, int x2, int y2) {
    int res = v[x2][y2] - v[x1-1][y2] - v[x2][y1-1] + v[x1-1][y1-1];
    return res;
}

int main()
{
    ifstream in;
    ofstream out;
    in.open("input.txt");
    out.open("output.txt");
    int N, M, K;
    in >> N >> M >> K;
    vector<vector<int>> mtx;
    vector<vector<int>> rects;

    mtx.reserve(N);
    rects.reserve(K);

    for (int i = 0; i < N; i++) {
        vector<int> m;
        for (int j = 0; j < M; j++) {
            int el;
            in >> el;
            m.push_back(el);
            
        }
        mtx.push_back(m);
    }

    vector<vector<int>> prefs = prefix2D(mtx);

    int x1, y1, x2, y2;
    for (int i = 0; i < K; ++i) {
        
        in >> x1 >> y1 >> x2 >> y2;

        out << findpref(prefs, x1, y1, x2, y2) << '\n';
    }
    
    return 0;
}
