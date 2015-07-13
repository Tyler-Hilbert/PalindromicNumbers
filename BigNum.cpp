#include "BigNum.h"
#include <algorithm>

BigNum::BigNum(const string& n) {
	nums = vector<char>(n.begin(), n.end());
}

string BigNum::toString() {
	return string(nums.begin(), nums.end());
}

BigNum BigNum::add(BigNum &bn) {
	int carry = 0;
	string newBigNum = "";
	string n1 = bn.toString();
	string n2 = toString();
	
	while (n1.length() > 0 || n2.length() > 0) {
		int c1;
		if (n1.length() > 0) {
			c1 = n1.back() - '0';
			n1.pop_back();
		} else {
			c1 = 0;
		}

		int c2;
		if (n2.length() > 0) {
			c2 = n2.back() - '0';
			n2.pop_back();
		} else {
			c2 = 0;
		}

		int num = c1 + c2 + carry;
		if (num > 9) {
			carry = 1;
			num -= 10;
		} else {
			carry = 0;
		}
		char c = num + '0';
		newBigNum = c + newBigNum;
	}

	if (carry > 0) {
		char c = carry + '0';
		newBigNum = c + newBigNum;
	}

	BigNum returnNum(newBigNum);
	return returnNum;
}