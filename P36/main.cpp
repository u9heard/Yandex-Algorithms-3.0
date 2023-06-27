#include <iostream>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;


int bfs(vector<vector<int>> &graph, queue<int> &q, int start, int end, vector<int> & visited) {
    if (start == end) {
        return 0;
    }
    
    
    q.push(start);
    visited[start] = 1;
    vector<int> steps(graph.size(), 0);
    int prev = start;
    int step = 0;
    while (!q.empty()) {
        int cur = q.front();

        q.pop();

        for (int i = 1; i < graph.size(); i++) {
            if (graph[cur][i] == 1) {
                if (visited[i] != 1) {
                    q.push(i);
                    visited[i] = 1;
                    steps[i] = steps[cur] + 1;
                    if (i == end) {
                        return steps[end];
                    }
                }
                
            }
        }
        //step++;
       // prev = steps[cur];
    }
    return -1;
}


int main()
{
    ifstream in;
    ofstream out;
    in.open("input.txt");
    out.open("output.txt");

    int N;
    int from, to;
    queue<int> q;

    

    in >> N;

    vector<int> visited(N+1, -1);
    vector<vector<int>> graph(N + 1, vector<int>(N + 1, 0));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            in >> graph[i][j];
        }
    }
    in >> from >> to;
    

    out << bfs(graph, q, from, to, visited);

    in.close();
    out.close();

    return 0;
}
