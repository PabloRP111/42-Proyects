#include "BigInt.hpp"

BigInt::BigInt()
{
	this->n = "0";
}

BigInt::BigInt(unsigned int number)
{
	std::stringstream ss;
	ss << number;
	this->n = ss.str();
}

BigInt::BigInt(const BigInt &bi)
{
	*this = bi;
}

BigInt &BigInt::operator=(const BigInt &bi)
{
	if (this == &bi)
		return *this;
	this->n = bi.getStr();
	return *this;
}

BigInt::~BigInt(){}

std::string BigInt::getStr() const
{
	return this->n;
}

std::string reverse(std::string n)
{
	std::string rev;

	for (int i = n.size(); i > 0; i--)
	{
		rev.push_back(n[i - 1]);
	}
	return rev;
}

std::string sumar(std::string n1, std::string n2)
{
	std::string n1r = reverse(n1);
	std::string n2r = reverse(n2);
	std::string suma;

	while (n1r.length() < n2r.length())
		n1r.push_back('0');
	while (n2r.length() < n1r.length())
		n2r.push_back('0');

	int d1, d2, carry = 0;
	for(size_t i = 0; i < n1r.size(); i++)
	{
		d1 = n1r[i] - '0';
		d2 = n2r[i] - '0';
		carry = d1 + d2 + carry;
		suma.push_back((carry % 10 ) + '0');
		if (carry > 9)
			carry = 1;
		else
			carry = 0;
	}
	suma = reverse(suma);
	return suma;
}

BigInt BigInt::operator+(const BigInt &other) const 
{
	std::string num = sumar(this->n, other.n);
	BigInt bi;
	bi.n = num; 
	return bi;
}

BigInt &BigInt::operator+=(const BigInt &other)
{
	*this = *this + other;
	return *this;	
}

BigInt &BigInt::operator++()
{
	*this += BigInt(1);
	return *this;
}

BigInt BigInt::operator++(int)
{
	BigInt tmp(*this);
	*this += BigInt(1);
	return tmp;
}

BigInt BigInt::operator<<(unsigned int num) const
{
	BigInt tmp(*this);

	tmp.n.append(num, '0');
	return tmp;
}

BigInt &BigInt::operator<<=(unsigned int num) 
{
	*this = *this << num;
	return *this;
}

BigInt BigInt::operator>>(unsigned int num) const
{
	BigInt tmp(*this);

	if (num >= tmp.getStr().length())
		tmp.n = "0";
	else
		tmp.n.erase(tmp.getStr().length() - num, num);
	return tmp;
}

BigInt &BigInt::operator>>=(unsigned int num)
{
	*this = *this >> num;
	return *this;
}

unsigned int stringToUInt(std::string std)
{
	std::stringstream ss(std);
	unsigned int ui;
	ss >> ui;
	return ui;
}

BigInt BigInt::operator<<(const BigInt &bi) const
{
	BigInt tmp;

	tmp = *this << stringToUInt(bi.getStr());
	return tmp;
}

BigInt BigInt::operator>>(const BigInt &bi) const
{
        BigInt tmp;

        tmp = *this >> stringToUInt(bi.getStr());
	return tmp;
}

BigInt &BigInt::operator<<=(const BigInt &bi)
{
        *this = *this << stringToUInt(bi.getStr());
        return *this;
}

BigInt &BigInt::operator>>=(const BigInt &bi)
{
       *this = *this >> stringToUInt(bi.getStr());
        return *this;
}

bool BigInt::operator==(const BigInt& other) const
{
	if (this->n.size() == other.n.size())
		return this->n == other.getStr();
	return false;
}

bool BigInt::operator!=(const BigInt& other) const
{
	if (this->n.size() == other.n.size())
                return this->n != other.getStr();
        return true;
}

bool BigInt::operator<(const BigInt& other) const
{
	if (this->n.size() != other.n.size())
		return this->n.size() < other.getStr().size();
	return this->n < other.getStr();
}

bool BigInt::operator>(const BigInt& other) const
{
	if (this->n.size() != other.getStr().size())
		return this->n.size() > other.getStr().size();
	return this->n > other.getStr();
}

bool BigInt::operator<=(const BigInt& other) const
{
	if (this->n.size() != other.getStr().size())
                return this->n.size() < other.getStr().size();
	return this->n <= other.getStr();
}

bool BigInt::operator>=(const BigInt& other) const
{
	if (this->n.size() != other.getStr().size())
		return this->n.size() >= other.getStr().size();
	return this->n >= other.getStr();
}

std::ostream &operator<<(std::ostream &output, const BigInt &obj)
{
	output << obj.getStr();
	return output;
}
