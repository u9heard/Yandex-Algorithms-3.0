#include <iostream>
#include <stack>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
    ifstream in;
    in.open("input.txt");

    stack<int> st;
    vector<int> train;
    int N;

    in >> N;
    int num = 1;
    for (int i = 0; i < N; i++) {
        int v;
        in >> v;
        
        if (!st.empty() && v > st.top()) {
            cout << "NO";
            return 0;
        }
        st.push(v);

        while (!st.empty() && st.top() == num) {
            st.pop();
            num++;
        }
    }
    cout << "YES";
    in.close();
    return 0;
}
