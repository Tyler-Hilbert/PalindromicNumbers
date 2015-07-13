#ifndef _BIG_NUM_H
#define _BIG_NUM_H

#include <string>
#include <vector>

using namespace std;

class BigNum {
public:
	BigNum(const string &n);
	string toString();
	BigNum add(BigNum &bn);
private:
	vector<char> nums;
};

#endif 