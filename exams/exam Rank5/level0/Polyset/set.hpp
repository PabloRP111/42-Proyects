#pragma once

#include "searchable_bag.hpp"

class set
{
	private:
		searchable_bag &_sb;
	public:
	set() = delete;
	set(const set &s) = delete;
	set &operator=(const set &s) = delete;
	set(searchable_bag &sb);
	~set();

	bool has(int) const;
	void insert(int);
	void insert(int *, int);
	void print() const;
	void clear();

	const searchable_bag &get_bag();
};
