#include "fib-heap.h"

#include <algorithm>

template< typename T >
bool fib_node< T >::operator<( fib_node< T > const& node ) const
{
	return key < node.key;
}

template< typename T >
void fib_node< T >::concat( fib_node< T > * node )
{
	fib_node< T > * old_left_sibling;

	if( parent )
	{
		fib_node< T > * n = node;
		do
		{
			n->parent = parent;
			n->parent->rank += n->rank + 1;
			n = n->right_sibling;
		} while( n != node );
	}

	left_sibling->right_sibling = node;
	old_left_sibling = left_sibling;
	left_sibling = node->left_sibling;
	node->left_sibling->right_sibling = this;
	node->left_sibling = old_left_sibling;
}

template< typename T >
fib_node< T > * fib_heap< T >::find_min() const
{
	return min_node;
}

template< typename T >
void fib_heap< T >::meld( fib_node< T > * min )
{
	if( find_min() == NULL )
	{
		min_mode = h;
	}
	else
	{
		find_min()->concat( min );
		min_node = find_min()->key < min->key ? find_min() : min;
	}
}

template< typename T >
void fib_heap< T >::insert( T i )
{
	auto * node = (fib_node< T > *)malloc( sizeof( fib_node< T > * ) );
	node->key = i;
	node->rank = 0;
	node->marked = false;
	node->parent = NULL;
	node->child = NULL;
	node->left_sibling = node;
	node->right_sibling = node;
	meld( node );
}

template< typename T >
void fib_heap< T >::delete_min()
{
	fib_node< T > * min, child;

	min = find_min();
	child = min->child;
	if( min->right_sibling != min )
	{
		min->right_sibling->left_sibling = min->left_sibling;
		min->left_sibling->right_sibling = min->right_sibling;
		min->left_sibling->concat( min->child );
	}
	min->child->parent = NULL;
}
