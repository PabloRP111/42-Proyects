#include "searchable_array_bag.hpp"

searchable_array_bag::searchable_array_bag(){}

searchable_array_bag::searchable_array_bag(const searchable_array_bag &src) : array_bag(src) {}

searchable_array_bag &searchable_array_bag::operator=(const searchable_array_bag &src)
{
	if(this != &src)
        {
		array_bag::operator=(src);
        }
        return *this;
}

bool searchable_array_bag::has(int n) const
{
	for (int i = 0; i < this->size; i++)
	{
		if(this->data[i] == n)
			return true;
	}
	return false;
}

searchable_array_bag::~searchable_array_bag() {}
