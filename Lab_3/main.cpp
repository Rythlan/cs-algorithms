#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

class HashTable
{
private:
    int S;
    vector<list<int>> table;

    int hashFunction(int key)
    {
        return key % S;
    }

public:
    HashTable(int size)
    {
        S = size;
        table.resize(S);
    }

    void insert(int key)
    {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    void remove(int key)
    {
        int index = hashFunction(key);
        table[index].remove(key);
    }

    bool search(int key)
    {
        int index = hashFunction(key);
        for (int val : table[index])
        {
            if (val == key)
            {
                return true;
            }
        }
        return false;
    }

    void removeAllEven()
    {
        for (int i = 0; i < S; i++)
        {
            auto it = table[i].begin();
            while (it != table[i].end())
            {
                if (*it % 2 == 0)
                {
                    it = table[i].erase(it);
                }
                else
                {
                    ++it;
                }
            }
        }
    }

    void print()
    {
        for (int i = 0; i < S; i++)
        {
            for (int val : table[i])
            {
                cout << val << " ";
            }
        }
        cout << endl;
    }
};

int main()
{
    srand(time(NULL));

    int variant = 27;
    int N = variant * 5 + 50;
    int S = (int)(N * 0.75);

    HashTable ht(S);

    for (int i = 0; i < N; i++)
    {
        ht.insert(rand() % 1000 + 1);
    }

    ht.removeAllEven();

    cout << "Розмір ґеш-таблиці (S): " << S << endl;
    cout << "Кількість елементів (N): " << N << endl;
    cout << "Елементи, що залишилися: " << endl;
    ht.print();

    return 0;
}
