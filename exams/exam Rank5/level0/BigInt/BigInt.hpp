#ifndef BIGINT
#define BIGINT

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>

class BigInt
{
	private:
		std::string n;

	public:
		BigInt();
		BigInt(unsigned int number);
		BigInt(const BigInt &bi);
		~BigInt();

		std::string getStr() const;

		BigInt &operator=(const BigInt &bi);
		
		BigInt operator+(const BigInt &bi) const;
		BigInt &operator+=(const BigInt &bi);
		
		BigInt &operator++();
	       	BigInt operator++(int);

		BigInt operator<<(unsigned int number) const;
		BigInt operator>>(unsigned int number) const;
		BigInt &operator<<=(unsigned int number);
		BigInt &operator>>=(unsigned int number);

		BigInt operator<<(const BigInt &bi) const;
		BigInt operator>>(const BigInt &bi) const;
		BigInt &operator>>=(const BigInt &bi);
		BigInt &operator<<=(const BigInt &bi);

		bool operator<(const BigInt &bi) const;
		bool operator>(const BigInt &bi) const;
		bool operator>=(const BigInt &bi) const;
		bool operator<=(const BigInt &bi) const;
		bool operator==(const BigInt &bi) const;
		bool operator!=(const BigInt &bi) const;
};

std::ostream &operator<<(std::ostream &output, const BigInt &obj);

#endif
