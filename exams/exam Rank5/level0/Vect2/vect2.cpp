#include "vect2.hpp"

vect2::vect2()
{
	this->_x = 0;
	this->_y = 0;
}

vect2::vect2(int x, int y)
{
	this->_x = x;
	this->_y = y;
}

vect2 &vect2::operator=(const vect2 &v)
{
	if (this != &v)
	{
		this->_x = v._x;
        this->_y = v._y;
	}
	return *this;
}

vect2::vect2(const vect2 &v)
{
	*this = v;
}

vect2::~vect2(){}

int &vect2::operator[](int index)
{
        if (index == 0)
                return this->_x;
        return this->_y;
}

int vect2::operator[](int index) const
{
        if (index == 0)
                return this->_x;
        return this->_y;
}

vect2 vect2::operator+(const vect2 &v) const
{
	vect2 tmp(*this);

	tmp._x += v._y;
    tmp._y += v._y;
	return tmp;	
}

vect2 &vect2::operator+=(const vect2 &v)
{
	*this = *this + v;
	return *this;
}

vect2 vect2::operator-(const vect2 &v) const
{
        vect2 tmp(*this);

        tmp._x -= v._x;
        tmp._y -= v._y;
        return tmp;
}

vect2 &vect2::operator-=(const vect2 &v)
{
        *this = *this - v;
        return *this;
}


vect2 &vect2::operator++()
{
	this->_x++;
	this->_y++;
	return *this;
}

vect2 vect2::operator++(int)
{
	vect2 tmp(*this);
	this->_x++;
        this->_y++;
        return tmp;
}

vect2 &vect2::operator--()
{
        this->_x--;
        this->_y--;
        return *this;
}

vect2 vect2::operator--(int)
{
        vect2 tmp(*this);
        this->_x--;
        this->_y--;
        return tmp;
}

vect2 vect2::operator*(int n) const
{
	vect2 tmp(*this);

	tmp._x = this->_x * n;
	tmp._y = this->_y * n;
	return tmp;
}

vect2 &vect2::operator*=(int n)
{
	*this = *this * n;
	return *this;
}

vect2 vect2::operator-() const
{
	vect2 tmp(*this);

	tmp._x = -(this->_x);
	tmp._y = -(this->_y);
	return tmp;
}

vect2 operator*(int n, const vect2 &v)
{
	vect2 tmp(v);
    tmp *= n;
        return tmp;
}

bool vect2::operator==(const vect2 &v) const
{
	if ((this->_x == v._x) && (this->_y == v._y))
		return true;
	return false;
}

bool vect2::operator!=(const vect2 &v) const
{
        if (*this == v)
                return false;
        return true;
}

std::ostream &operator<<(std::ostream &output, const vect2 &v)
{
	std::cout << "{" << v[0] << ", " << v[1] << "}";
	return output;
}
