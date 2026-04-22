#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cmath>

class Queue
{
private:
    int *arr;
    int front;
    int rear;
    int capacity;
    int currentSize;

public:
    Queue(int size)
    {
        capacity = size;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        currentSize = 0;
    }

    ~Queue()
    {
        delete[] arr;
    }

    bool isFull()
    {
        return currentSize == capacity;
    }

    bool isEmpty()
    {
        return currentSize == 0;
    }

    void enqueue(int value)
    {
        if (isFull())
        {
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        currentSize++;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            return -1;
        }
        int value = arr[front];
        front = (front + 1) % capacity;
        currentSize--;
        return value;
    }

    int peek()
    {
        if (isEmpty())
        {
            return -1;
        }
        return arr[front];
    }

    int size()
    {
        return currentSize;
    }
};

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

int main()
{
    srand(time(NULL));
    int variant = 1;
    int S = variant * 5 + 50;
    Queue q(S);

    for (int i = 0; i < S; ++i)
    {
        q.enqueue(rand() % 1000 + 1);
    }

    std::cout << "Елементи черги, що є простими числами:" << std::endl;
    while (!q.isEmpty())
    {
        int val = q.dequeue();
        if (isPrime(val))
        {
            std::cout << val << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}
