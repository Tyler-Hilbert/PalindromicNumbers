#include <iostream>
#include <string>

using namespace std;

bool palindromic(unsigned long long n);
unsigned long long step(unsigned long long n);

int main() {
	unsigned long inNum = 196196871;
	unsigned long long num = inNum;
	unsigned int n = 0;
	while (!palindromic(num)) {
		num = step(num);
		n++;
	}
	
	cout
		<< inNum
		<< " gets palindromic after "
		<< n
		<< " steps: "
		<< num 
		<< "\n";

	system("pause");
	return 1;
}

bool palindromic(unsigned long long n) {
	string num = to_string(n);
	if (num.length() % 2 == 1) {
		num = num.erase(num.length() / 2, 1);
	}

	for (int i = 0; i < num.length() / 2; i++) {
		if (num.substr(i, 1) != num.substr(num.length()-1-i, 1)) {
			return false;
		}
	}

	return true;
}

unsigned long long step(unsigned long long n) {
	string num = to_string(n);
	num = string(num.rbegin(), num.rend()); // Flip string
	return n + stoull(num);
}