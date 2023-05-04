#include <iostream>
#include <vector>
#include <deque>
#include <fstream>

using namespace std;



int main()
{
    deque<int> d;
    ifstream in;
    ofstream out;
    in.open("input.txt");
    out.open("output.txt");

    while (true) {
        string com;
        in >> com;

        if (com == "push_front") {
            int x;
            in >> x;
            d.push_front(x);
            out << "ok\n";
        }
        else if (com == "push_back") {
            int x;
            in >> x;
            d.push_back(x);
            out << "ok\n";
        }
        else if (com == "pop_front") {
            if (d.size() > 0) {
                out << d.front() << '\n';
                d.pop_front();
            }
            else {
                out << "error\n";
            }
        }
        else if (com == "pop_back") {
            if (d.size() > 0) {
                out << d.back() << '\n';
                d.pop_back();
            }
            else {
                out << "error\n";
            }
        }
        else if (com == "front") {
            if (d.size() > 0) {
                out << d.front() << '\n';
            }
            else {
                out << "error\n";
            }
        }
        else if (com == "back") {
            if (d.size() > 0) {
                out << d.back() << '\n';
            }
            else {
                out << "error\n";
            }
        }
        else if (com == "size") {
            out << d.size() << '\n';
        }
        else if (com == "clear") {
            d.clear();
            out << "ok\n";
        }
        else if (com == "exit") {
            out << "bye\n";
            return 0;
        }
    }
    
}

