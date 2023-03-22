// S.create()
// S.push()
// S.pop()
// S.top()
// S.size()
#include <iostream>
#include <stdio.h>
using namespace std; 

struct Stack
{
	int	data[100];
	int	len = 0; // 현재 원소 개수
	int	capacity = 0; // 최대 크기

	void create(int y)
	{
		capacity = y;
	}

	void push(int y)
	{
		if (len >= capacity)
			printf("Stack overflow!\n");
		else
			data[len++] = y;
	}

	void pop()
	{
		if (len <= 0)
			printf("Stack underflow!\n");
		else
		{
			data[len-1] = 0;
			len--;
		}
	}

	int top()
	{
		if (len <= 0)
			return -1;
		else
			return data[len-1];
	}

	int size()
	{
		return len;
	}
};

int main()
{
	Stack	s;

	s.create(5);
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.push(6); // overflow
	s.push(7); // overflow

	printf("%d\n", s.top()); // 5
	s.pop();
	printf("%d\n", s.top()); // 4
	s.push(6);
	s.push(7); // overflow
	printf("%d\n", s.top()); // 6	1 2 3 4 6

	s.pop();
	s.pop();
	s.pop();
	s.pop();
	s.pop();

	s.pop(); // underflow
	printf("%d\n", s.size()); // 0
	return (0);
}