#pragma once
#include "node.h"


template<class VT>
class List
{
private:
	Node<VT> *First;
public:
	List();
	List(const List<VT>& l);
	~List();
	Node<VT>* Find(VT k);
	void PushAfter(VT findkey, VT k);
	int PushEnd(VT k);
	Node<VT>* GetFirst(void);
	void Remove(VT findkey);
	void PushStart(VT k);
	int operator==(const List<VT>& l)const;
	int operator!=(const List<VT>& l)const;
	void PushBefore(VT findkey, VT k);
	void Print()const;
};

template<class VT>
List<VT>::List();


template<class VT>
List<VT>::List(const List<VT>& l);

template<class VT>
List<VT>::~List();

template<class VT>
Node<VT>* List<VT>::Find(VT k);

template<class VT>
void List<VT>::PushAfter(VT findkey, VT k);

template<class VT>
int List<VT>::PushEnd(VT k);

template<class VT>
Node<VT>* List<VT>::GetFirst(void);

template<class VT>
void List<VT>::Remove(VT findkey);

template<class VT>
void List<VT>::PushStart(VT k);

template<class VT>
int List<VT>::operator==(const List<VT>& l)const;

template<class VT>
int List<VT>::operator!=(const List<VT>& l)const;

template <class VT>
void List<VT>::PushBefore(VT findkey, VT k);

template<class VT>
void List<VT>::Print()const;