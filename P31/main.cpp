#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void dfs(vector<vector<int>> &graph, vector<bool> &visited, int now) {
    visited[now] = true;
    for (int i = 0; i < graph[now].size(); i++) {
        if (visited[graph[now][i]] != true) {
            dfs(graph, visited, graph[now][i]);
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

    /*if (countR == 0) {
        out << 0;
        in.close();
        out.close();
        return 0;
    }*/

    vector<vector<int>> graph(countV+1);
    vector<bool> visited(countV + 1, false);
    

    for (int i = 1; i <= countR; i++) {
        int ver;
        int reb;

        in >> ver >> reb;

        graph[ver].push_back(reb);
        graph[reb].push_back(ver);
    }

    
    dfs(graph, visited, 1);
        
     

    int visit = 0;

    for (int i = 1; i <= countV; i++) {
        if (visited[i] == true) {
            visit++;
        }
    }

    out << visit << '\n';

    for (int i = 1; i <= countV; i++) {
        if (visited[i] == true) {
            out << i << ' ';
        }
    }

    in.close();
    out.close();
    
    return 0;
}
