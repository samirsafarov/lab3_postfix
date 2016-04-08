#include <iostream>
#include "list.h"
#include "list.cpp"

using namespace std;


void main(void)
{
	List<int>* l = new List<int>;
	cout << "Enter the element: " << endl;
	int a;
	cin >> a;
	l->PushStart(a);
	cout << "You have created a list with key = " << a << endl;
	l->Print();
	int b;
	cout << "Enter the element: " << endl;
	cin >> b;
	l->PushEnd(b);
	cout << endl << "You have pushed a node with key = " << b << " at the end " << endl;
	l->Print();
	int c;
	cout << "Enter the element: " << endl;
	cin >> c;
	l->PushAfter(b, c);
	cout << endl << "You have pushed a node with key = " << c << " after a node with key = " << b << endl;
	l->Print();
	l->Remove(a);
	cout << endl << "You have Removed a node with key = " << a << endl;
	l->Print();
	int d;
	cout << "Enter the element: " << endl;
	cin >> d;
	l->PushStart(d);
	cout << endl << "You have pushed a node with key = " << d << " at the beginning ";
	l->Print();
	int e;
	cout << "Enter the element: " << endl;
	cin >> e;
	l->PushBefore(c, e);
	cout << endl << "You have pushed a node with key = " << e << " before a node with key = " << c << endl;
	l->Print();
	return;
}