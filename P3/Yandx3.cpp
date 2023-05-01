#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <time.h> 

using namespace std;

int binSearch(vector<int> &v, int &val) {
	int l = 0, r = v.size() - 1;
	
	while (r > l) {
		int m = (l + r) / 2;    

		if (v[m] < val) {
			l = m + 1;
		}
		else if (v[m] > val) {
			r = m - 1;
		}
		else {
			return m;
		}
	}

	if (v[r] >= val) {
		return r;
	}
	return r+1;
		
}

int main()
{
	int N;
	int K;
	ifstream inp;
	ofstream out;
	inp.open("input.txt");
	out.open("output.txt");
	ios::sync_with_stdio(0);
	cin.tie(0);
	inp >> N;
	vector<int> vecN;
	
	
	int i = 0;
	while (i<N) {
		int temp;
		inp >> temp;
		vecN.push_back(temp);
		++i;
	}
	
	sort(vecN.begin(), vecN.end());

	auto last = std::unique(vecN.begin(), vecN.end());
	vecN.erase(last, vecN.end());

	

	inp >> K;
	vector<int> res;
	int temp;
	int test;
	int max=0;
	for (int i = 0; i < K; ++i) {
		
		
		inp >> temp;

		int jj = binSearch(vecN, temp);
		
		
		
		

		out << jj << '\n';
	}
	

	inp.close();
	out.close();
	return 0;
}

