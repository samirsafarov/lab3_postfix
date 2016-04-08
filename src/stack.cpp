#include "stack.h"
#include "list.cpp"
#include "list.h"

template<class VT>
Stack<VT>::Stack()
{
	list = new List<VT>();
}

template<class VT>
Stack<VT>::~Stack()
{
	delete list;
}

template<class VT>
Stack<VT>::Stack(const Stack<VT>& stack)
{
	list = new List<VT>(*(stack.list));
}

template<class VT>
int Stack<VT>::IsEmpty(void)const
{
	return(list->GetFirst() == 0);
}

template<class VT>
int Stack<VT>::IsFull(void)const
{
	Node<VT> *tmp;
	try
	{
		tmp = new Node<VT>;
	}
	catch (...)
	{
		return 1;
	}
	delete tmp;
	return 0;
}

template<class VT>
void Stack<VT>::Push(const VT k)
{
	if (IsFull())
		throw
		exception("Stack is full");
	list->PushStart(k);
}

template<class VT>
VT Stack<VT>::Pop()
{
	if (IsEmpty())
		throw
			exception ("Stack is empty");
	VT tmp = list->GetFirst()->key;
	list->Remove(tmp);
	return tmp;
}

template <class VT>
int Stack<VT>::operator==(const Stack<VT>& s)const
{
	return (*list == *(s.list));
}

template <class VT>
int Stack<VT>::operator!= (const Stack<VT>& s)const
{
	return (*list != *(s.list));
}

template <class VT>
void Stack<VT>::Print()const
{
	Stack<VT>* s = new Stack<VT>(*this);
	while (!(s->IsEmpty()))
		cout << s->Pop() << endl;
}

template <class VT>
VT Stack<VT>::GetKey()
{
	if (IsEmpty())
		throw
		exception ("Stack is empty");
	return list->GetFirst()->key;
}