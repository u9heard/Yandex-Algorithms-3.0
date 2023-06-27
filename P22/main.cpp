#include <iostream>
#include <vector>

using namespace std;

void init(vector<int> &v, int k) {
    v[0] = 1;
    for (int i = 1; i <= k; i++) {
        int cur = 0;
        int start = i - k;
        if (start <= 0) {
            for (int j = 0; j < i; j++) {
                cur += v[j];
            }
        }
        v[i] = cur;

    }
}

int main()
{
    int N;
    int k;
    vector<int> jump(30, 0);


    cin >> N;
    cin >> k;

    init(jump, k);

    for (int i = k + 1; i < N; i++) {
        int cur = 0;
        for (int j = i - k; j < i; j++) {
            cur += jump[j];
        }
        jump[i] = cur;
    }

    cout << jump[N-1];

    return 0;
}
