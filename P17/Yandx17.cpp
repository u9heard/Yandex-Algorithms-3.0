#include <iostream>
#include <queue>

using namespace std;

int main()
{
    queue<int> q1;
    queue<int> q2;

    int steps=0;

    
    for (int j = 0; j < 5; j++) {
        int a;
        cin >> a;
       
        q1.push(a);
    }
    
    for (int j = 0; j < 5; j++) {
        int a;
        cin >> a;
        
        q2.push(a);
    }

    while (steps != 1000000) {
        int c1=0;
        int c2=0;

        if (!q1.empty()) {
            c1 = q1.front();
            q1.pop();
        }
        else {
            cout << "second " << steps;
            return 0;
        }

        if (!q2.empty()) {
            c2 = q2.front();
            q2.pop();
        }
        else {
            cout << "first " << steps;
            return 0;
        }

        if (c1 > c2) {
            if (c2 == 0 && c1 == 9) {
                q2.push(c1);
                q2.push(c2);
            }
            else {
                q1.push(c1);
                q1.push(c2);
            }
        }
        else {
            if (c1 == 0 && c2 == 9) {
                q1.push(c1);
                q1.push(c2);
            }
            else {
                q2.push(c1);
                q2.push(c2);
            }
        }
        steps++;
    }
    cout << "botva";

    return 0;
}

