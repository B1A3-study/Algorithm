#include <iostream>
#include <string>

using namespace std;

int sum(string str) {
	string temp;
	temp.clear();
	int sum = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] != '+' && str[i] != '-') {
			temp += str[i];
		}
		else {
			sum += stoi(temp);
			temp.clear();
		}
	}
	sum += stoi(temp);
	return sum;
}

int main(void) {
	string str, temp;
	int p = 0, m = 0;
	cin >> str;
	temp = str.substr(0, str.find("-"));
	p = sum(temp);
	if (str.compare(temp) == 0) {
		cout << p;
		return 0;
	}
	temp = str.substr(str.find("-") + 1, str.size());
	m = sum(temp);
	cout << p - m;
	return 0;
}