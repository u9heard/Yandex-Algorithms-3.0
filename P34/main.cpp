#include <fstream>
#include <vector>

using namespace std;


void dfs(vector<vector<int>>& graph, vector<int>& visited, vector<int>& res, int &error, int now) {
    if (error == 1) {
        return;
    }
    visited[now] = 1;



    for (int i = 0; i < graph[now].size(); i++) {
        if (visited[graph[now][i]] == 1) {
            error = 1;
            return;
        }

        if (visited[graph[now][i]] == 0) {
            dfs(graph, visited, res, error, graph[now][i]);
        }
    }

    visited[now] = 2;
    res.push_back(now);

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

    vector<int> res;
    int error = 0;

    for (int i = 1; i <= countR; i++) {
        int ver;
        int reb;

        in >> ver >> reb;

        graph[ver].push_back(reb);
    }

    for (int i = 1; i < visited.size(); i++) {
        if (visited[i] == 0) {

            dfs(graph, visited, res, error, i);

        }
    }
   

    if (error == 1) {
        out << -1;
        in.close();
        out.close();

        return 0;
    }

    for (int i = res.size() - 1; i >= 0; i--) {
        out << res[i] << ' ';
    }

    in.close();
    out.close();

    return 0;
}