// Yandx11.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

//The problem was intentionally solved without using std::stack

class Stack {
public:
    vector<int> val;
    int top;
    int size;
    

    Stack() {
        size = 0;
        top = -1;
    }
   
   

    void push(int x) {
        val.push_back(x);
        size++;
        top++;
    }

    int back() {
        if (size > 0)
            return val[top];
        else
            return 0;
    }

    int getsize() {
        return size;
    }

    void clear() {
        top = -1;
        size = 0;
        val.clear();
    }

    int pop() {
        int res = val[top];
        val.erase(val.end()-1);
        size--;
        top--;
        return res;
    }
};


int main()
{
    ifstream in;
    in.open("input.txt");
    Stack st;

    while (true) {
        string com;
        in >> com;
        if (com == "push") {
            int x;
            in >> x;
            st.push(x);
            cout << "ok\n";
        }
        else if(com=="pop") {
            if (st.getsize() > 0)
                cout << st.pop() << '\n';
            else
                cout << "error\n";
        }
        else if (com == "back") {
            if (st.getsize() > 0)
                cout << st.back() << '\n';
            else
                cout << "error\n";
        }
        else if (com == "size") {
            cout << st.getsize() << '\n';
        }
        else if (com == "clear") {
            st.clear();
            cout << "ok" << '\n';
        }
        else if (com == "exit") {
          
            cout << "bye" << '\n';
            
            return 0;
        }
    }
    in.close();
    return 0;
}
