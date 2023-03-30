/*
    Q.create(y)
    Q.push(y)
    Q.pop()
    Q.f()
    Q.size()
*/
#include <iostream>
#include <stdio.h>
using namespace std; 

struct  Queue
{
    int data[100];
    int f, r;
    int capacity;


    void create(int y)
    {
        capacity =  y; 
        f = 0;
        r = 0;
    }

    void push (int y)
    {
        if (r-f >= capacity)
            printf("Queue overflow!\n");
        else
            data[r++] = y;
    }

    void pop()
    {
        if (r-f <= 0)
            printf("Queue underflow\n");
        else
            data[f++] = 0;
    }

    int front()
    {
        // 큐의 맨 앞에 있는 원소를 반환
        // 단, 반환할 것이 없다면 -1을 반환

        if (r-f <= 0)
            return (-1);
        else
            return (data[f]);
    }

    int size()
    {
        return (r - f);
    }
};

int main()
{
    Queue q;

    q.create(3);

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4); // overflow
    q.push(5); // overflow

    printf("%d\n", q.front()); // 1

    q.pop();
    q.pop();

    printf("%d\n", q.front()); // 3
    printf("%d\n", q.size()); // 1

    q.pop();
    q.pop(); // underflow

    printf("%d\n", q.size());
}