#include"BigInteger.h"

BigInteger::BigInteger(unsigned int num)
{
	string temp;
	ostringstream sout;
	sout << num;
	temp = sout.str();
	for (int i = 0; i < temp.length(); i++)
	{
		this->m_num.push_front(temp[i]);
	}

}
BigInteger::BigInteger(string num)
{
	for (int i = 0; i < num.length(); i++)
	{
		if (num[i] >= '0'&&num[i] <= '9')
			this->m_num.push_front(num[i]);
	}
}
BigInteger::BigInteger(BigInteger & num)
{
	this->m_num = num.m_num;
}
BigInteger& BigInteger::operator=(int num)
{
	BigInteger temp((unsigned int)num);
	this->m_num = temp.m_num;
	return *this;
}
BigInteger& BigInteger::operator=(string num)
{
	BigInteger temp(num);
	this->m_num = temp.m_num;
	return *this;
}
BigInteger& BigInteger::operator=(BigInteger & num)
{
	this->m_num = num.m_num;
	return *this;
}
BigInteger BigInteger::operator+(BigInteger & num)
{
	BigInteger temp;
	temp.m_num.clear();
	int upper = 0;
	deque<char>::iterator self = this->m_num.begin();
	deque<char>::iterator out = num.m_num.begin();
	while (self != this->m_num.end() && out != num.m_num.end())
	{
		int sum = (*self - '0') + (*out - '0') + upper;
		upper = sum / 10;
		sum = sum % 10;
		temp.m_num.push_back(sum + '0');
		self++;
		out++;
	}
	while (self != this->m_num.end())
	{
		int sum = (*self - '0') + upper;
		upper = sum / 10;
		sum = sum % 10;
		temp.m_num.push_back(sum + '0');
		self++;
	}
	while (out != num.m_num.end())
	{
		int sum = (*out - '0') + upper;
		upper = sum / 10;
		sum = sum % 10;
		temp.m_num.push_back(sum + '0');
		out++;
	}
	if (upper != 0)
		temp.m_num.push_back(upper + '0');
	return temp;
}
bool BigInteger::operator!=(BigInteger & num)
{
	return !(*this == num);
}
bool BigInteger::operator==(BigInteger & num)
{
	if (this->m_num.size() != num.m_num.size())
		return false;
	int j = 0;
	for (deque<char>::iterator i = this->m_num.begin(); i != this->m_num.end(); i++)
	{
		if (*i != num.m_num[j++])
			return false;
	}
	return true;
}
ostream & operator<<(ostream &out, BigInteger & num)
{
	string temp;
	deque<char> ptp;
	int j = 0;
	for (deque<char>::iterator i = num.m_num.begin(); i != num.m_num.end(); i++)
	{
		ptp.push_front(*i);
		j++;
		if (j == 3)
		{
			j = 0;
			ptp.push_front(',');
		}
	}
	if (ptp.front() == ',')
		ptp.pop_front();
	for (deque<char>::iterator i = ptp.begin(); i != ptp.end(); i++)
	{
		temp.push_back(*i);
	}
	out << temp;
	return out;
}
BigInteger BigInteger::operator*(BigInteger & num)
{
	BigInteger result=0;
	result.m_num.resize(this->m_num.size()+num.m_num.size()+2,'0');
	for (int i = 0; i < num.m_num.size(); i++)
	{
		int upper = 0;
		int j = 0;
		for (j = 0; j < this->m_num.size(); j++)
		{
			int sum = (num.m_num[i]-'0') * (this->m_num[j]-'0') + upper+(result.m_num[i+j]-'0');
			upper = sum / 10;
			sum = sum % 10;
			result.m_num[i + j] = sum + '0';
		}
		if (upper != 0)
		{
			result.m_num[i + j] = upper + '0';
		}
	}
	string tps=result.toString();
	for (int i = 0; i < tps.length(); i++)
	{
		if (tps[i] != '0')
		{
			result.m_num.resize(result.m_num.size()-i);
			break;
		}	
	}
	return result;
}
string BigInteger::toString()
{
	string temp;
	deque<char> ptp;
	for (deque<char>::iterator i = this->m_num.begin(); i != this->m_num.end(); i++)
	{
		ptp.push_front(*i);
	}
	for (deque<char>::iterator i = ptp.begin(); i != ptp.end(); i++)
	{
		temp.push_back(*i);
	}
	return temp;
}