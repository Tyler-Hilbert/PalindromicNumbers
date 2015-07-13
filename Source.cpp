/*
	Prompt from: http://www.reddit.com/r/dailyprogrammer/comments/38yy9s/20150608_challenge_218_easy_making_numbers/
	Tyler Hilbert's Implementation
*/

#include <iostream>
#include <string>
#include "BigNum.h"

using namespace std;

void mainChallenge();
void secondChallenge();
bool palindromic(BigNum &n);
BigNum step(BigNum &n);


int main() {
	//mainChallenge();
	secondChallenge();
	system("pause");
	return 1;
}

void mainChallenge() {
	string inStr;
	cout << "Enter Num: ";
	cin >> inStr;
	if (inStr.find_first_not_of("0123456789") != string::npos) {
		cout
			<< inStr
			<< " is not a number\n";
		return;
	}

	BigNum inNum(inStr);
	BigNum num(inNum);
	unsigned int n = 0;
	while (!palindromic(num)) {
		num = step(num);
		n++;
	}

	cout
		<< inNum.toString()
		<< " gets palindromic after "
		<< n
		<< " steps: "
		<< num.toString()
		<< "\n";
}

void secondChallenge() {
	vector<BigNum> palindromics;
	for (int i = 1; i <= 1000; i++) {
		BigNum num(to_string(i));
		
		for (int k = 1; k < 10000; k++) {
			if (palindromic(num)) {
				// Check if palindromic has been found before
				bool found = false;
				for (int p = 0; p < palindromics.size(); p++) {
					if (num.toString() == palindromics.at(p).toString()) {
						found = true;
						break;
					}
				}
				if (found) {
					cout << num.toString() << " is a duplicate\n";
				} else {
					palindromics.push_back(num);
				}
				break;
			}
			num = step(num);
		}
	}

}

bool palindromic(BigNum &n) {
	string num = n.toString();
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

BigNum step(BigNum &n) {
	string s(n.toString());
	BigNum reversed(string(s.rbegin(), s.rend())); // Flip string
	return n.add(reversed);
}