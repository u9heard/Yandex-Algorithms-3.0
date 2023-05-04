#include <iostream>
#include <stack>
#include <string>
#include <fstream>

using namespace std;

int myAtoi(char &a) {
    return (int)a - 48;
}

void deleteSpaces(string &s) {
    
    int pos = s.find("  ");
    if (pos != string::npos) {
        s.erase(pos, s.size()-1);
        
    }
}

int main()
{
    stack<int> st;
    ifstream in;
    in.open("input.txt");
    string s;
    getline(in, s);

    deleteSpaces(s);
    int res = 0;

    for (int i = 0; i < s.length(); i++)
    {
        
            if (isdigit(s[i])) {
                st.push(myAtoi(s[i]));
            }
            else if (s[i] == '+') {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b + a);
            }
            else if (s[i] == '-') {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b - a);
            }
            else if (s[i] == '*') {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b * a);
            }
        
    }

    if (!st.empty()) {
        cout << st.top();
        
    }
    else {
        cout << 0;
    }

    in.close();
    return 0;
}
