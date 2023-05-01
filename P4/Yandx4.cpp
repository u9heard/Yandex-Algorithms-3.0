#include <iostream>
#include <math.h>
using namespace std;

int arifDiv(int a, int b) {
    
    if (((double)a / b) - (a / b) >= 0.5) {
        return ceil((double)a/b);
    }
    else {
        return a / b;
    }
}

int main()
{
    int N;
    int K;
    int row;
    int place;

    cin >> N >> K >> row >> place;

    int placeNum = (row-1) * 2 + place;

    int nextMax = placeNum + K;
    int nextMin = placeNum - K;

    int r1 = -1;
    int r2 = -1;
    int p1 = -1;
    int p2 = -1;


    if (nextMin <= 0 && nextMax > N) {
        cout << -1;
        return 0;
    }

    if (nextMin >= 1) {
        int correct = 0;
        int pl = (nextMax % 2);
        if (pl == 0) {
            pl = 2;
        }
        r1 = arifDiv(nextMin, 2);
        p1 = pl;
        
    }
    if (nextMax <= N) {
        int correct = 0;
        
        int pl = (nextMax % 2);
        if (pl == 0) {
            pl = 2;
        }
        r2 = arifDiv(nextMax, 2);
        p2 = pl;
      
       

    }
    
    int res1 = 2147483647;
    int res2 = 2147483647;

    


    if (r1 != -1) {
        res1 = row - r1;
    }
    if (r2 != -1) {
        res2 = r2 - row;
    }

    if (res2 > res1 && r1!=-1) {
        cout << r1 << ' ' << p1;
    }
    else if(r2 !=-1) {
        cout << r2 << ' ' << p2;
    }
    else {
        cout << -1;
    }

    return 0;
}
