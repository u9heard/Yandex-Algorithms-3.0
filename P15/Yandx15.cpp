#include <iostream>
#include <vector>
#include <fstream>
#include <stack>

using namespace std;

int main()
{
	ifstream in;
	ofstream out;
	vector<int> nums;
	stack<int> st;
	
	int N;
	in.open("input.txt");
	out.open("output.txt");

	in >> N;

	for (int i = 0; i < N; i++) {
		int a;
		in >> a;
		nums.push_back(a);
	}

	vector<int> res(N, -1);

	for (int i = 0; i < N; i++) {
		while (!st.empty() && nums[st.top()] > nums[i]) {
			res[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}

	for (int i = 0; i < N; i++) {
		out << res[i] << ' ';
	}



	in.close();
	out.close();

	return 0;
}
