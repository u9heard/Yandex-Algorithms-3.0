#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void dfs(vector<vector<int>>& graph, vector<int>& visited, int now, int &error, int color) {
    visited[now] = color;
    
    
    
    for (int i = 0; i < graph[now].size(); i++) {
        
        if (visited[graph[now][i]] == 0 ) {
            dfs(graph, visited, graph[now][i], error, 3-color);
        }
        else if (visited[now] == visited[graph[now][i]]) {
            error = 1;
        }
    }
    
}

int main()
{
    ifstream in;
    ofstream out;

    in.open("input.txt");
    out.open("output.txt");

    int countV;
    int countR;

    in >> countV >> countR;

    vector<vector<int>> graph(countV + 1);
    vector<int> visited(countV + 1, 0);

    int error = 0;

    for (int i = 1; i <= countR; i++) {
        int ver;
        int reb;

        in >> ver >> reb;

        graph[ver].push_back(reb);
        graph[reb].push_back(ver);
    }

    for (int i = 1; i < visited.size(); i++) {
        if (visited[i] == 0) {
            
            dfs(graph, visited, i, error, 1);
            
        }
    }
    if (error == 1) {
        out << "NO";
    }
    else {
        out << "YES";
    }
    
    
    return 0;
}

