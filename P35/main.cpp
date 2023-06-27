#include <fstream>
#include <vector>

using namespace std;


void dfs(vector<vector<int>>& graph, vector<int>& visited, vector<int>& res, int& error, int now, int prev, int &loop) {
    if (error != 0) {
       
        return;
    }
    visited[now] = 1;



    for (int i = 1; i < graph[now].size(); i++) {
        
        if (graph[now][i] == 1 && i!=prev && error==0) {

            if (visited[i] == 0) {
                dfs(graph, visited, res, error, i, now, loop);
                if (error == 1) {
                    if (now == loop) {
                        error = 2;
                        
                    }
                    res.push_back(now);
                    return;
                }
                
            }
            else if (visited[i] == 1) {
                error = 1;
                loop = i;
                res.push_back(now);
                return;
            }
        }
    }

    visited[now] = 2;
   

}

int main()
{
    ifstream in;
    ofstream out;

    in.open("input.txt");
    out.open("output.txt");

    int countV;
   

    in >> countV;

    vector<vector<int>> graph(countV + 1, vector<int>(countV + 1, 0));
    vector<int> visited(countV + 1, 0);

    vector<int> res;
    int error = 0;
    int loop = 0;

    for (int i = 1; i <= countV; i++) {
        
        for (int j = 1; j <= countV; j++) {

            in >> graph[i][j];
        }
    }

    for (int i = 1; i < visited.size(); i++) {
        if (visited[i] == 0 && error == 0) {

            dfs(graph, visited, res, error, i, i, loop);

        }
    }


    if (error != 0) {
        out << "YES\n" << res.size() << '\n';

        for (int i = 0; i < res.size(); i++) {
            out << res[i] << ' ';
        }
        in.close();
        out.close();

        return 0;
    }

    out << "NO";

    in.close();
    out.close();

    

    return 0;
}