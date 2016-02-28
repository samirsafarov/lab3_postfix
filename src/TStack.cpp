#include "TStack.h"

TStack::TStack()
{
	Top = -1;
	Size = MemSize;
	pMem = new int[Size];
	for (int i = 0; i < Size; i++)
		pMem[i] = 0;
}

TStack::TStack(int s) {
/*	if (s<0)
		throw invalid_argument("SIZE < 0");*/
	Top = -1;
	Size = s;
	pMem = new int[Size];
	for (int i = 0; i < Size; i++)
		pMem[i] = 0;
}

TStack::~TStack()
{
	delete[]pMem;
}

TStack::TStack(const TStack &s)
{
	Size = s.Size;
	pMem = new int[Size];
	Top = s.Top;
	for (int i = 0; i < Size; i++)
		pMem[i] = s.pMem[i];
}

bool TStack :: IsEmpty() const
{
	if (Top == -1)
		return true;
	else
		return false;
}

bool TStack::IsFull() const 
{
	if (Top == Size - 1)
		return true;
	else
		return false;
}

void TStack::Put(int Val)
{
/*	if (this->IsFull())
		throw invalid_argument ("STACK FULL");*/
	pMem[++Top] = Val;
}

int TStack::Peek() const
{
	/*if (Top == -1)
		throw ("NON ELEMENTO IN DE STACKO");*/
	return pMem[Top];
}

int TStack::Push()
{
	if (this->IsEmpty())
		throw ("STACK EMPTY");
	return pMem[Top--];
}

void TStack::SetSize(int n)
{
/*	if (n<0)
		throw invalid_argument("NEW SIZE < 0");
	if (n<Top + 1)
		throw invalid_argument("NEW SIZE < TOP");*/
	int *p = new int[Top + 1];
	for (int i = 0; i < Top + 1; i++)
		p[i] = pMem[i];

	Size = n;
	delete[]pMem;
	pMem = new int[Size];
	for (int i = 0; i < Top + 1; i++)
		pMem[i] = p[i];
	for (int i = Top + 1; i < Size; i++)
		pMem[i] = 0;
}