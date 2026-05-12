#ifndef VECT2
#define VECT2 

#include <iostream>

class vect2
{
	private:
		int _x;
		int _y;
	public:
		vect2();
		vect2(int x, int y);
		vect2(const vect2 &v);
		~vect2();
		
		vect2 &operator=(const vect2 &v);

		int &operator[](int index);
		int operator[](int index) const;

		vect2 &operator++();
		vect2 operator++(int);
		vect2 &operator--();
		vect2 operator--(int);

		vect2 operator+(const vect2 &v) const;
		vect2 operator-(const vect2 &v) const;
		vect2 &operator+=(const vect2 &v);
		vect2 &operator-=(const vect2 &v);

		vect2 operator*(int n) const;
		vect2 &operator*=(int n);

		vect2 operator-() const;
		
		bool operator==(const vect2 &v2) const;
		bool operator!=(const vect2 &v2) const;
};

vect2 operator*(int num, const vect2 &v2);

std::ostream &operator<<(std::ostream &output, const vect2 &v2);

#endif
