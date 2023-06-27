#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

struct point {
    int x;
    int y;
    int z;
};

int bfs(vector<vector<vector<char>>> &cave, int N, int x, int y, int z) {
    if (x == 1) {
        return 0;
    }

    queue<point> q;
    vector<vector<vector<int>>> visited(N + 1, vector<vector<int>>(N + 1, vector<int>(N + 1, -1)));


    q.push(point{ x, y, z});
    visited[x][y][z] = 0;

    while (!q.empty()) {
        int curX = q.front().x;
        int curY = q.front().y;
        int curZ = q.front().z;

        q.pop();

        if (curX == 1) {
            return visited[x][y][z];
        }

        if (curX+1 <= N && cave[curX + 1][curY][curZ] == '.' && visited[curX + 1][curY][curZ] == -1) {
            q.push(point{curX+1, curY, curZ});
            visited[curX + 1][curY][curZ] = visited[curX][curY][curZ] + 1;
            if (curX + 1 == 1) {
                return visited[curX + 1][curY][curZ];
            }
        }
        if (curX - 1 > 0 && cave[curX - 1][curY][curZ] == '.' && visited[curX - 1][curY][curZ] == -1) {
            q.push(point{ curX - 1, curY, curZ });
            visited[curX - 1][curY][curZ] = visited[curX][curY][curZ] + 1;
            if (curX - 1 == 1) {
                return visited[curX - 1][curY][curZ];
            }
        }
        if (curY + 1 <= N && cave[curX ][curY + 1][curZ] == '.' && visited[curX][curY + 1][curZ] == -1) {
            q.push(point{ curX, curY + 1, curZ });
            visited[curX][curY + 1][curZ] = visited[curX][curY][curZ] + 1;
            
        }
        if (curY - 1 >0 && cave[curX][curY - 1][curZ] == '.' && visited[curX][curY - 1][curZ] == -1) {
            q.push(point{ curX, curY - 1, curZ });
            visited[curX][curY - 1][curZ] = visited[curX][curY][curZ] + 1;
            
        }
        if (curZ + 1 <= N && cave[curX][curY][curZ+1] == '.' && visited[curX][curY][curZ+1] == -1) {
            q.push(point{ curX, curY, curZ+1 });
            visited[curX][curY][curZ+1] = visited[curX][curY][curZ] + 1;

        }
        if (curZ - 1 > 0 && cave[curX][curY][curZ - 1] == '.' && visited[curX][curY][curZ - 1] == -1) {
            q.push(point{ curX, curY, curZ - 1 });
            visited[curX][curY][curZ - 1] = visited[curX][curY][curZ] + 1;

        }
    }
}

int main()
{
    ifstream in;
    ofstream out;

    in.open("input.txt");
    out.open("output.txt");

    int N;
    in >> N;

    int startI = 0;
    int startJ = 0;
    int startK = 0;

    vector<vector<vector<char>>> cave(N + 1, vector<vector<char>>(N + 1, vector<char>(N + 1, 0)));
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= N; k++) {
                in >> cave[i][j][k];
                if (cave[i][j][k] == 'S') {
                    startI = i;
                    startJ = j;
                    startK = k;
                }
            }
        }
    }


    out << bfs(cave, N, startI, startJ, startK);
    
    return 0;
}
