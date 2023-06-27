#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <math.h>

using namespace std;

struct point
{
    int x;
    int y;
};

vector<vector<int>> bfs(int N, int M, int S, int T) {
    

    vector<vector<int>> visited(N + 1, vector<int>(M + 1, -1));
    queue<point> q;

    q.push(point{ S, T });
    visited[S][T] = 0;

    while (!q.empty()) {
        int curX = q.front().x;
        int curY = q.front().y;

        q.pop();

        int x1 = curX - 2;
        int y1 = curY - 1;
        int x2 = curX - 1;
        int y2 = curY - 2;
        int x3 = curX + 2;
        int y3 = curY + 1;
        int x4 = curX + 1;
        int y4 = curY + 2;

        if (x1 > 0 && y1 > 0) {
            if (visited[x1][y1] == -1) {
                q.push(point{ x1, y1 });
                visited[x1][y1] = visited[curX][curY] + 1;
               /* if (x1 == S && y1 == T) {
                    return visited[x1][y1];
                }*/
            }
        }
        if (x2 > 0 && y2 > 0) {
            if (visited[x2][y2] == -1) {
                q.push(point{ x2,y2 });
                visited[x2][y2] = visited[curX][curY] + 1;
                /*if (x2 == S && y2 == T) {
                    return visited[x2][y2];
                }*/
            }
        }
        if (x3 <= N && y3 <= M) {
            if (visited[x3][y3] == -1) {
                q.push(point{ x3, y3 });
                visited[x3][y3] = visited[curX][curY] + 1;
                /*if (x3 == S && y3 == T) {
                    return visited[x3][y3];
                }*/
            }
        }
        if (x4 <= N && y4 <= M) {
            if (visited[x4][y4] == -1) {
                q.push(point{ x4, y4 });
                visited[x4][y4] = visited[curX][curY] + 1;
                /*if (x4 == S && y4 == T) {
                    return visited[x4][y4];
                }*/
            }
        }

        if (x1 > 0 && y3 <= M) {
            if (visited[x1][y3] == -1) {
                q.push(point{ x1, y3 });
                visited[x1][y3] = visited[curX][curY] + 1;
                /*if (x1 == S && y3 == T) {
                    return visited[x1][y3];
                }*/
            }
        }
        if (x2 > 0 && y4 <= M) {
            if (visited[x2][y4] == -1) {
                q.push(point{ x2, y4 });
                visited[x2][y4] = visited[curX][curY] + 1;
                /*if (x2 == S && y4 == T) {
                    return visited[x2][y4];
                }*/
            }
        }

        if (x3 <= N && y1 > 0) {
            if (visited[x3][y1] == -1) {
                q.push(point{ x3, y1 });
                visited[x3][y1] = visited[curX][curY] + 1;
                /*if (x3 == S && y1 == T) {
                    return visited[x3][y1];
                }*/
            }
        }
        if (x4 <= N && y2 > 0) {
            if (visited[x4][y2] == -1) {
                q.push(point{ x4, y2 });
                visited[x4][y2] = visited[curX][curY] + 1;
                /*if (x4 == S && y2 == T) {
                    return visited[x4][y2];
                }*/
            }
        }

    }


    return visited;
}

int main()
{
    ifstream in;
    ofstream out;

    in.open("input.txt");
    out.open("output.txt");

    int N, M, S, T, Q;

    in >> N >> M >> S >> T >> Q;
    int sum = 0;
    vector<vector<int>> steps = bfs(N, M, S, T);
    for (int i = 0; i < Q; i++) {
        int x, y;
        in >> x >> y;
        int res;

        if (steps[x][y] != -1) {
            sum += abs(steps[S][T] - steps[x][y]);
        }
        else {
            out << -1;
            in.close();
            out.close();
            return 0;
        }
    }


    out << sum;
    in.close();
    out.close();
    return 0;
}
