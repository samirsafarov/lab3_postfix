#include <iostream>
#include "stack.h"
#include "stack.cpp"

using namespace std;

void main(void)
{
	int i = 0;
	Stack<int>* s = new Stack<int>();
	cout << "Enter the size: " << endl;
	int n;
	cin >> n;
	int k;
	for (; i < n; i++)
	{
		cout << "Enter the element: ";
		cin >> k;
		s->Push(k);
	}
	cout << endl << "You have pushed " << n << " elements " << endl;
	s->Print();	
	cout << endl << "You have popped one element. " << endl;
	s->Pop();
	s->Print();
	return;
}