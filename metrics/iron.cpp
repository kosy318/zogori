#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

vector<int> is_palin() {
	int num;
	vector<int> answer;
	string word;

	ifstream in("palin.inp");
	in >> num;
	while (num--) {
		int ans = 1;
		in >> word;
		auto iter1 = word.begin();
		auto iter2 = word.end() - 1;

		while (iter1 != word.end()) {
			if (*iter1 != *iter2 && ans == 1) {
				auto next1 = iter1 + 1;
				auto next2 = iter2 - 1;
				if (*next1 == *iter2) {
					word.erase(iter1);
					iter2--;
				}else if (*iter1 == *next2) {
					word.erase(iter2);
					iter2--;
				}else {
					ans = 3;
					break;
				}
				ans = 2;
			}else if (*iter1 != *iter2 && ans > 1) ans = 3;

			if (iter2 == word.begin()) break;

			iter1++; iter2--;
		}
		answer.push_back(ans);
	}
	in.close();

	return answer;
}

int main() {
	vector<int> answer = is_palin();

	ofstream out("palin.out");
	for (auto a : answer) out << a << endl;
	out.close();
}