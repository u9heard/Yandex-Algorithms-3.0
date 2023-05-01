#include <iostream>

using namespace std;

int main()
{
    int N;
    long long res=0;
    int current = 0;
    int next = 0;

    cin >> N;
    cin >> current;

    
    for (int i = 1; i < N; i++) {
        cin >> next;

        if (next >= current) {
            res += current;
            current = next;
        }
        else {
            res += next;
            current = next;
        }
       
    }

    cout << res;

    return 0;
}



