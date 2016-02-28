#include "TStack.h"
#include <stdio.h>
#include <cstring>
#include <conio.h>
#pragma warning(disable : 4996)

const int MAX_CHAR = 100;

int bracket(char * str)
{
	TStack s;
	int array[MAX_CHAR][2];
	int n=0, j=0, m = 1, errors = 0, size = strlen(str);
	for (int i = 0; i < size; i++)
	{
		if (str[i] == '(') s.Put(m++);
		if (str[i] == ')') 
			if (!s.IsEmpty())
			{
				n++;
				array[j][0] = s.Push();
				array[j++][1] = m++;
			}
			else
			{
				n++;
				array[j][0] = 0;
				array[j++][1] = m++;
				++errors;
			}
	}
	while (!s.IsEmpty())
	{
		n++;
		array[j][0] = s.Push();
		array[j++][1] = 0;
		errors++;
	}
	if (errors != 0)
	{
		printf("wrong brackets: %d\n", errors);
		for (int i = 0; i < n; i++)
		{
			printf("%d   ", array[i][0]);
			printf("%d\n", array[i][1]);
		}
	}
	return errors;
}

int priority(char ch)
{
	if (ch == '(') return 0;
	if (ch == ')') return 1;
	if ((ch == '+') || (ch == '-')) return 2;
	if ((ch == '*') || (ch == '/')) return 3;
	if (ch == '^') return 4;
}

/*bool check(char * str)
{
	int i = 0;
	while (str[i] != NULL)
	{
		if ((i < 40) || (i > 57)) return false;
		i++;
	}

}*/

 void poland(char * str, char * result)
{
	TStack stack;
	int stri = 0, i = 0;
	while (str[i] != NULL) 
	{
		while ((str[i] <= '9') && (str[i] >= '0'))
		{
			result[stri++] = str[i++];
			if ((str[i] > '9') || (str[i] < '0')) result[stri++] = ' ';
		}
		if ((str[i] == '(') || (str[i] == '*') || (str[i] == '/') || (str[i] == '-') || (str[i] == '+') || (str[i] == '^'))
		{
			if ((stack.IsEmpty()) || (str[i] == '(') || (priority(str[i]) > priority(stack.Peek())))
			{
				stack.Put(str[i]);
			}
			else
			{
				while ((!stack.IsEmpty()) && (priority(str[i]) <= priority(stack.Peek())))
					result[stri++] = stack.Push();
				stack.Put(str[i]);
			}
			i++;
		}
		if (str[i] == ')')
		{
			while (stack.Peek() != '(')
				result[stri++] = stack.Push();
			stack.Push();
			i++;
		}

	}
	while (! stack.IsEmpty())
		result[stri++] = stack.Push();
}

int calc(char * str)
{
	TStack stack;
	int result = 0, elem;
	int  a, i = 0;
	while (str[i] != NULL)
	{
		while ((str[i] != '*') && (str[i] != '/') && (str[i] != '-') && (str[i] != '+') && (str[i] != '^'))
		{
			elem = 0;
			while (str[i] != ' ')
				elem = elem*10 + (str[i++] - 48);
			stack.Put(elem);
			i++;
		}

		if (str[i] == '*')
		{
			a = stack.Push();
			result = stack.Push() * a;
			stack.Put(result);
			i++;
		}
		if (str[i] == '/')
		{
			a = stack.Push();
			if (a != 0){
				result = stack.Push() / a;
				stack.Put(result);
				i++;
			}
			else
			{
				printf("\nDIVIDE BY ZERO\n");
				return 0;
			}

		}
		if (str[i] == '+')
		{
			a = stack.Push();
			result = stack.Push() + a;
			stack.Put(result);
			i++;
		}
		if (str[i] == '-')
		{
			a = stack.Push();
			if (stack.IsEmpty()) stack.Put(0);
			result = stack.Push() - a;
			stack.Put(result);
			i++;
		}
		if (str[i] == '^')
		{
			result = 0;
			a = stack.Push();
			int b = stack.Push();
			for (int j = 1; j < a; j++)
				result += b*b;
			stack.Put(result);
			i++;
		}
	}
	return result;
}

int check (char * str)
{
	int q = 0;
	int i = 0;
	if (bracket(str) != 0)
		return 0;
	while (str[i] != '\0') // проверка на отсутствие лишних символов в строке
	{
		if ((str[i] == '*') || (str[i] == '/') || (str[i] == '-') || (str[i] == '+') || (str[i] == '^') || (str[i] == '(') || (str[i] == ')'))
			q++;
		i++;
	}
	if (q==0) 
	{
		printf("Wrong simbols0\n");
		return 0;
	}
	i = 0;
	while (str[i] != '\0') // проверка на отсутствие лишних символов в строке
	{
		if ((str[i] < 40) || (str[i] > 57) && (str[i] != '^') )
		{
			printf("Wrong simbols1\n");
			return 0;
		}
		i++;
	}
	i = 0;
	while (str[i] != '\0') // проверка на несколько знаков подряд
	{
		if ((str[i] >= 42) && (str[i] <= 47) && (str[i + 1] >= 42) && (str[i + 1] <= 47))
		{
			printf("Wrong simbols2\n");
			return 0;
		}
		i++;
	}
	if ((str[0] > '9') || (str[0] < '0') && (str[0] != '-') && (str[0] != '('))  //проверка на правильность ввода первого символа
	{
		printf("%c\n", str[0]);
		printf("Wrong simbols3\n");
		return 0;
	}
	if ((str[strlen(str) - 1] > '9') || (str[strlen(str) - 1] < '0') && (str[strlen(str) - 1] != ')'))  //проверка на правильность ввода последнего символа
	{
		printf("Wrong simbols4\n");
		return 0;
	}
	return 1;
}


int main()
{
	int res = 0;
	int i = 0;
	char str[MAX_CHAR], paul[MAX_CHAR] = " ";
	scanf("%s", str);
	if (check(str))
	{
		poland(str, paul);
		printf("\n%s", paul);
		res = calc(paul);
		printf("\nres: %d\n", res);
	
	}
	return 0;
}
