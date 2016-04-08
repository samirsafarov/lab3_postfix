#include "node.h"

template<class ValueType>
Node<ValueType>::Node()
{
	Next = 0;
}

template<class ValueType>
Node<ValueType>::Node(const ValueType& k)
{
	Next = 0;
	key = k;
}

