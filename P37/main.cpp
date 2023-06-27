#include <iostream>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;


int bfs(vector<vector<int>>& graph, queue<int>& q, int start, int end, vector<int>& visited, vector<int> &steps) {
    if (start == end) {
        return 0;
    }


    q.push(start);
    visited[start] = 1;
    steps[start] = 0;
    
    while (!q.empty()) {
        int cur = q.front();

        q.pop();

        for (int i = 1; i < graph.size(); i++) {
            if (graph[cur][i] == 1) {
                if (visited[i] != 1) {
                    q.push(i);
                    visited[i] = 1;
                    steps[i] = steps[cur] + 1;
                    /*if (i == end) {
                        return steps[end];
                    }*/
                }

            }
        }
        
    }
    return steps[end];
}

vector<int> searchBFS(vector<vector<int>>& graph, int start, int end, vector<int>& steps, vector<int>& steps2, int &len) {
    if (start == end) {
        return vector<int>{};
    }
    queue<int> q;
    vector<int> visited(graph.size(), -1);
    vector<int> res;

    q.push(start);
    visited[start] = 1;
    int step = 0;
    res.push_back(start);

    while (!q.empty()) {
        int cur = q.front();

        q.pop();

        for (int i = 1; i < graph.size(); i++) {
            if (graph[cur][i] == 1 ) {
                if (visited[i] != 1 && steps[i] == step+1 && steps[i]+steps2[i] == len) {
                    step++;
                    res.push_back(i);
                    q.push(i);
                    visited[i] = 1;
                    
                    //steps[i] = steps[cur] + 1;
                    if (i == end) {
                        return res;
                    }
                    i = graph.size();
                }

            }
        }

    }
    return vector<int>{};
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
    queue<int> q2;


    in >> N;

    vector<int> visited(N + 1, -1);
    vector<int> visited2(N + 1, -1);
    vector<int> steps(N+1, -1);
    vector<int> steps2(N + 1, -1);
    vector<int> prev(N+1, 0);
    vector<vector<int>> graph(N + 1, vector<int>(N + 1, 0));


    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            in >> graph[i][j];
        }
    }
    in >> from >> to;


    //cout << bfs(graph, q, from, to, visited, steps);
    //cout << bfs(graph, q2, to, from, visited2, steps2);

    int length = bfs(graph, q, from, to, visited, steps);
    bfs(graph, q2, to, from, visited2, steps2);

    vector<int> res = searchBFS(graph, from, to, steps, steps2, length);

    out << length << '\n';



    for (int i = 0; i < res.size(); i++) {
        out << res[i] << ' ';
    }

    in.close();
    out.close();

    return 0;
}
