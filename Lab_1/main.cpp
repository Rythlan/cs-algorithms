#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Stack
{
private:
    int *arr;
    int capacity;
    int topIndex;

public:
    Stack(int size)
    {
        capacity = size;
        arr = new int[capacity];
        topIndex = -1;
    }

    ~Stack()
    {
        delete[] arr;
    }

    bool isFull()
    {
        return topIndex == capacity - 1;
    }

    bool isEmpty()
    {
        return topIndex == -1;
    }

    bool empty()
    {
        return isEmpty();
    }

    int size()
    {
        return topIndex + 1;
    }

    void push(int val)
    {
        if (!isFull())
        {
            arr[++topIndex] = val;
        }
        else
        {
            cout << "Помилка: Стек переповнений!" << endl;
        }
    }

    int pop()
    {
        if (!isEmpty())
        {
            return arr[topIndex--];
        }
        return -1;
    }

    int top()
    {
        if (!isEmpty())
        {
            return arr[topIndex];
        }
        return -1;
    }

    int peek()
    {
        return top();
    }
};

int main()
{
    srand(time(NULL));

    int variant = 27;
    int S = variant * 5 + 50;

    Stack mainStack(S);
    Stack evenStack(S);
    Stack oddStack(S);

    for (int i = 0; i < S; i++)
    {
        mainStack.push(rand() % 1000 + 1);
    }

    while (!mainStack.isEmpty())
    {
        int currentElement = mainStack.pop();
        if (currentElement % 2 == 0)
        {
            evenStack.push(currentElement);
        }
        else
        {
            oddStack.push(currentElement);
        }
    }

    cout << "Розмір початкового стеку (S): " << S << "\n\n";

    cout << "Елементи 'парного' стеку (Вилучення LIFO): \n";
    while (!evenStack.isEmpty())
    {
        cout << evenStack.pop() << " ";
    }
    cout << "\n\n";

    cout << "Елементи 'непарного' стеку (Вилучення LIFO): \n";
    while (!oddStack.isEmpty())
    {
        cout << oddStack.pop() << " ";
    }
    cout << "\n";

    return 0;
}