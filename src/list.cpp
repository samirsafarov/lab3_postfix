#include "list.h"
#include "node.cpp"
#include "node.h"

template<class VT>
List<VT>::List() //конструктор по умолчанию
{
	First = 0;
}

template<class VT>
List<VT>::List(const List<VT>& l) //конструктор копирования
{
	First = 0;
	Node<VT>* tmp = l.First;
	while (tmp != 0)
	{
		PushEnd(tmp->key);
		tmp = tmp->Next;
	}
}

template<class VT>
List<VT>::~List() //деструктор
{
	Node<VT> *tmp = First;
	while (First != 0)
	{
		First = First->Next;
		delete tmp;
		tmp = First;
	}
}

template<class VT>
Node<VT>* List<VT>::Find(VT k) //поиск по ключу
{
	if (First == 0)
		throw
			exception("List doesn't exist");	
	Node<VT>* tmp = First;
	while ((tmp != 0) && (k != tmp->key))
		tmp = tmp->Next;
	if (tmp == 0)
	{
		delete tmp;
		throw
			exception("Key was not found");
	}
	return tmp;
}

template<class VT>
void List<VT>::PushAfter(VT findkey, VT k) //вставка после указанного ключа
{
	Node<VT>* l = Find(findkey);
	Node<VT>* tmp = l->Next;
	Node<VT>* n;
	try
	{
		n = new Node<VT>(k);
	}
	catch (...)
	{
		throw
			exception("You can't create node");
	}
	l->Next = n;
	n->Next = tmp;
}

template<class VT>
int List<VT>::PushEnd(VT k) //вставка в конец
{
	if (First == 0)
	{
		PushStart(k);
		return 0;
	}
	Node<VT>* n;
	try
	{
		n = new Node<VT>(k);
	}
	catch (...)
	{
		throw
			exception("You can't create node");
	}
	Node<VT>* first = First;
	while (first->Next != 0)
		first = first->Next;
	first->Next = n;
	return 0;
}

template<class VT>
Node<VT>* List<VT>::GetFirst(void) //получение указателя на начало
{
	return First;
}

template<class VT>
void List<VT>::Remove(VT findkey) 
{
	if (!First)
		throw
		exception("List is empty");
	Node<VT>* n = Find(findkey);
	if (First == n)
	{
		First = First->Next;
		return;
	}
	Node<VT>* tmp = First;
	while (tmp->Next != n)
		tmp = tmp->Next;
	tmp->Next = n->Next;
	delete n;
}

template<class VT>
void List<VT>::PushStart(VT k) //вставка в начало
{
	Node<VT>* tmp;
	try
	{
		tmp = new Node<VT>(k);
	}
	catch (...)
	{
		throw
			exception("You can't create list");
	}
	tmp->Next = First;
	First = tmp;
}

template<class VT>
int List<VT>::operator==(const List<VT>& l)const //перегрузка сравнения на равенство
{
	Node<VT>* f1 = First;
	Node<VT>* f2 = l.First;
	while ((f1 != 0) && (f2 != 0)) 
	{
		if (f1->key != f2->key)
			return 0;
		f1 = f1->Next;
		f2 = f2->Next;
	}
	if (f1 != f2)
		return 0;
	return 1;
}

template<class VT>
int List<VT>::operator!=(const List<VT>& l)const //перегрузка на неравенство
{
	return !(*this == l);
}

template <class VT>
void List<VT>::PushBefore(VT findkey, VT k) //вставка перед элементов с заданным ключом
{
	Node<VT>* n = Find(findkey);
	if (First == n)
	{
		PushStart(k);
		return;
	}
	Node<VT>* prevnode = First;
	while (prevnode->Next != n)
		prevnode = prevnode->Next;
	Node<VT>* t = prevnode->Next;
	Node<VT>* tmp = new Node<VT>(k);
	prevnode->Next = tmp;
	tmp->Next = t;
}

template<class VT>
void List<VT>::Print()const //вывод списка
{
	if (!First)
	{
		cout << "List is empty";
		return;
	}
	Node<VT>* tmp = First;
	while (tmp != 0)
	{
		cout << tmp->key << ' ';
		tmp = tmp->Next;
	}
	cout << endl;
}