#include <iostream>
#include "postfix.h"
#include "postfix.cpp"

using namespace std;


int main(void)
{
	/*string str = "a*(b+c-d)+(d/(f-c)-(k+l)/s)";
	Postfix p;
	cout << str << endl;
	map<char, RT> m;
	m['a'] = 1;
	cout << "a = " << m['a'] << endl;
	m['b'] = 5;
	cout << "b = " << m['b'] << endl;
	m['c'] = 3;
	cout << "c = " << m['c'] << endl;
	m['d'] = 4;
	cout << "d = " << m['d'] << endl;
	m['f'] = 5;
	cout << "f = " << m['f'] << endl;
	m['k'] = 10;
	cout << "k = " << m['k'] << endl;
	m['l'] = 15;
	cout << "l = " << m['l'] << endl;
	m['s'] = 5;
	cout << "s = " << m['s'] << endl;
	string str1 = p.Record(str);
	RT res = p.Count(str1, m);
	cout << "Result: " << res << endl;*/
	string str;
	cout << "Enter the expression: " << endl;
	getline(cin, str);
	map<char, RT> m;
	Postfix p;
	string str1;
	try
	{
		str1 = p.Record(str);
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
		return 0;
	}

	cout << "Postfix form: " << str1 << endl;
	RT result;
	try
	{
		result = p.Count(str1, m);
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
		return 0;
	}
	cout << "Result: " << result << endl;
	return 0;
}