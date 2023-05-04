#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

//The problem was intentionally solved without using std::queue

class Queue {
public:
    vector<int> q;
    int head;
    int count;

    Queue() {
        head = 0;
        count = 0;
    }

    void push(int i) {
        q.push_back(i);
        count++;
    }

    int pop() {
        int res = q[head];
        head++;
        count--;
        return res;
    }

    int front() {
        return q[head];
    }

    int size() {
        return count;
    }

    void clear() {
        q.clear();
        head = 0;
        count = 0;
    }
};

int main()
{
    ifstream in;
    in.open("input.txt");
    Queue q;
    while (true) {
        string cmd;
        in >> cmd;

        if (cmd == "push") {
            int x;
            in >> x;
            q.push(x);
            cout << "ok\n";
        }
        else if (cmd == "pop") {
            if (q.size() > 0) {
                cout << q.pop() << '\n';
            }
            else {
                cout << "error\n";
            }
        }
        else if (cmd == "front") {
            if (q.size() > 0) {
                cout << q.front() << '\n';
            }
            else {
                cout << "error\n";
            }
        }
        else if (cmd == "size") {
            cout << q.size() << '\n';
        }
        else if (cmd == "clear") {
            q.clear();
            cout << "ok\n";
        }
        else if (cmd == "exit") {
            cout << "bye";
            return 0;
        }
    }


    return 0;
}
