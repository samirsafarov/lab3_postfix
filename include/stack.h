#pragma once
#include "list.h"


template<class VT>
class Stack
{
private:
	List<VT> *list;
public:
	Stack();
	Stack(const Stack<VT>&);
	~Stack();
	int IsEmpty(void)const;
	int IsFull(void)const;
	void Push(const VT);
	VT Pop();
	int operator==(const Stack<VT>& s)const;
	int operator!=(const Stack<VT>& s)const;
	void Print()const;
	VT GetKey();
};

template<class VT>
Stack<VT>::Stack();

template<class VT>
Stack<VT>::Stack(const Stack<VT>&);

template<class VT>
int Stack<VT>::IsEmpty(void)const;

template<class VT>
int Stack<VT>::IsFull(void)const;

template<class VT>
void Stack<VT>::Push(const VT k);

template<class VT>
VT Stack<VT>::Pop();

template <class VT>
int Stack<VT>::operator!=(const Stack<VT>& s)const;

template <class VT>
int Stack<VT>::operator==(const Stack<VT>& s)const;

template <class VT>
void Stack<VT>::Print()const;

template <class VT>
VT Stack<VT>::GetKey();
