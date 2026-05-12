#include "set.hpp"
#include "searchable_bag.hpp"

set::set(searchable_bag &sb) : _sb(sb) {}

set::~set(){}

bool set::has(int n) const
{
	return _sb.has(n);
}

void set::insert(int n)
{
	if(!(this->has(n)))
		_sb.insert(n);	
}

void set::insert(int *data, int size)
{
	for (int i = 0; i < size; i++)
	{
		this->insert(data[i]);
	}
}

void set::print() const
{
	_sb.print();
}

void set::clear()
{
	_sb.clear();
}

const searchable_bag &set::get_bag()
{
	return (this->_sb);
}
