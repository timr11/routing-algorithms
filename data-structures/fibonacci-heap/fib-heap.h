#pragma once

#include <cstddef>

template< typename T >
struct fib_node
{
	T key;
	unsigned int rank;
	bool marked;
	fib_node * parent;
	fib_node * child;
	fib_node * left_sibling;
	fib_node * right_sibling;
	bool operator<( fib_node< T > const& node ) const;
	void concat( fib_node< T > * node );
};

template< typename T >
class fib_heap
{
public:
	fib_node< T > * find_min() const;
	void meld( fib_node< T > * h );
	void insert( T i );
	void delete_min();

private:
	fib_node< T > * min_node = NULL;
};

