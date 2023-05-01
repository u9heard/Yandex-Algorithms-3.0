#include <iostream>

using namespace std;

int main()
{
    int N;
    int x, y;
    int minX = 1000000001;
    int minY = 1000000001;
    int maxX = -1000000001;
    int maxY = -1000000001;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        if (x > maxX) {
            maxX = x;
        }
        if (x < minX) {
            minX = x;
        }
        if (y > maxY) {
            maxY = y;
        }
        if (y < minY) {
            minY = y;
        }
    }

    cout << minX << ' ' << minY << ' ' << maxX << ' ' << maxY;

    return 0;
}
