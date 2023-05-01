#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>

using namespace std;

int findMax(map<char, int> &mp) {
	int res = 0;
	map <char, int> ::iterator it = mp.begin();
	for (int i = 0; it != mp.end(); ++it, ++i) {
		if (res < it->second) {
			res = it->second;
		}
	}
	return res+1;
}

int main()
{
	string inp;
	map<char, int> pairs;
	
	
		while (getline(cin, inp) && inp[0]!='\0') {
			for (int i = 0; i < inp.size(); ++i) {
				if (inp[i] != ' ') {
					if (pairs.find(inp[i]) != pairs.end()) {
						pairs[inp[i]] += 1;
					}
					else {
						pairs[inp[i]] = 1;
					}
				}
			}
		}
		
	
	
	string n(pairs.size(), ' ');

	vector<string> outp;

	int max = findMax(pairs);

	for (int i = 0; i < max; i++) {
		outp.push_back(n);
	}

	map <char, int> ::iterator it = pairs.begin();
	
	for (int i = 0; it != pairs.end(); ++it, ++i) {
		outp[outp.size()-1][i] = it->first;
		outp[outp.size()-it->second-1][i] = '#';

		for (int j = outp.size()-2; j > outp.size() - it->second - 1; --j) {
			outp[j][i] = '#';
		}
	}
	
	
	for (int i = 0; i < outp.size(); ++i) {
		cout << outp[i] << endl;
	}

	return 0;
}

