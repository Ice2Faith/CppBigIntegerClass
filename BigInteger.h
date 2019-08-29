#ifndef _BIGINTEGER_H_
#define _BIGINTEGER_H_
#include<deque>
#include<iterator>
#include<sstream>
#include<iostream>
using namespace std;
class BigInteger
{
public:
	BigInteger(unsigned int num = 0);
	BigInteger(string num);
	BigInteger(BigInteger & num);
	BigInteger& operator=(BigInteger & num);
	BigInteger& operator=(int num);
	BigInteger& operator=(string num);
	BigInteger operator+(BigInteger & num);
	BigInteger operator*(BigInteger & num);
	bool operator==(BigInteger & num);
	bool operator!=(BigInteger & num);
	string toString();
	friend ostream & operator<<(ostream &out, BigInteger & num);
private:
	deque<char> m_num;
};

#endif // !_BIGINTEGER_H_
