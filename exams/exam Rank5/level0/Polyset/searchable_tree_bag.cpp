#include "searchable_tree_bag.hpp"

searchable_tree_bag::searchable_tree_bag(){}

searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag &src) : tree_bag(src) {}

searchable_tree_bag &searchable_tree_bag::operator=(const searchable_tree_bag &src)
{
	if (this != &src)
		tree_bag::operator=(src);
	return *this;
}

bool searchable_tree_bag::search(node *n, const int num) const
{
	if (n == nullptr)
		return false;
	if (n->value == num)
		return true;
	else if (n->value < num)
		search(n->l, num);
	else
		search(n->r, num);
	return false;
}

bool searchable_tree_bag::has(int n) const
{
	return (search(this->tree, n));
}

searchable_tree_bag::~searchable_tree_bag(){}
