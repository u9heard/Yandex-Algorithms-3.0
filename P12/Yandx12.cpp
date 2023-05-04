#include <iostream>
#include <stack>
#include <fstream>

using namespace std;

int main()
{
    stack<char> st;
    ifstream in;
    in.open("input.txt");

    string s;
    in >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            st.push(s[i]);
        }
        else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
            if (st.size() != 0 && (s[i] - 1 == st.top() || s[i] - 2 == st.top()) ) {
                st.pop();
            }
            else {
                cout << "no";
                return 0;
            }
        }
    }
    if (st.size() != 0) {
        cout << "no";
        return 0;
    }

    cout << "yes";
    return 0;
}
