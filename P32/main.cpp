#include <iostream>
#include <vector>
#include <fstream>
 
#include <map>

using namespace std;

void dfs(vector<vector<int>>& graph, vector<int>& visited, int now, int comp, map<int, vector<int>> &res) {
    visited[now] = comp;
    res[comp].push_back(now);
    for (int i = 0; i < graph[now].size(); i++) {
        if (visited[graph[now][i]] == 0) {
            dfs(graph, visited, graph[now][i], comp, res);
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

    if (countR == 0) {
        out << countV << '\n';
        for (int i = 0; i < countV; i++) {
            out << 1 << '\n';
            out << i + 1 << '\n';
        }

        in.close();
        out.close();
        return 0;
    }

   

    vector<vector<int>> graph(countV + 1);
    vector<int> visited(countV + 1, 0);
    map<int, vector<int>> res;
 
    if (countV != 0) {
        for (int i = 1; i <= countR; i++) {
            int ver;
            int reb;

            in >> ver >> reb;

            graph[ver].push_back(reb);
            graph[reb].push_back(ver);
        }
    }

    int comp = 0;

    for (int i = 1; i <= countV; i++) {
        if (visited[i] == 0) {
            comp++;
            dfs(graph, visited, i, comp, res);
            
        }
    }


    


    out << comp << '\n';

    


    for (int i = 1; i <= comp; i++) { 
        int size = res[i].size();
        out << size << '\n';
        for (int j = 0; j < res[i].size(); j++) {
            out << res[i][j] << ' ';
        }
        out << '\n';
    }


    

   

    in.close();
    out.close();

    return 0;
}
