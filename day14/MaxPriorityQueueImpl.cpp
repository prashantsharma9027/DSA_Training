#include <bits/stdc++.h>
using namespace std;

class PriorityQueue
{
    vector<int> pq;

public:
    PriorityQueue() {}

    void insert(int element)
    {
        pq.push_back(element);
        int childIndex = pq.size() - 1;
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (pq[childIndex] > pq[parentIndex])
            {
                swap(pq[childIndex], pq[parentIndex]);
            }
            else
            {
                break;
            }
            childIndex = parentIndex;
        }
    }

    int getMax()
    {
        if (pq.empty())
        {
            return INT_MIN;
        }
        return pq.at(0);
    }

    int removeMax()
    {
        int n = getSize();
        if (n <= 0)
        {
            return INT_MIN;
        }
        int elementToDelete = pq[0];
        pq[0] = pq[n - 1];
        pq.pop_back();

        int parentIndex = 0;
        while (parentIndex < n)
        {
            int leftChildIdx = 2 * parentIndex + 1;
            int rightChildIdx = 2 * parentIndex + 2;
            int maxIndex = -1;
            if (leftChildIdx < n && rightChildIdx < n)
            {
                if (pq[leftChildIdx] > pq[rightChildIdx])
                {
                    maxIndex = leftChildIdx;
                }
                else
                {
                    maxIndex = rightChildIdx;
                }
            }
            else if (leftChildIdx < n)
            {
                maxIndex = leftChildIdx;
            }
            else if (rightChildIdx < n)
            {
                maxIndex = rightChildIdx;
            }
            if (maxIndex != -1 && pq[maxIndex] > pq[parentIndex])
            {
                swap(pq[maxIndex], pq[parentIndex]);
                parentIndex = maxIndex;
            }
            else
            {
                break;
            }
        }
        return elementToDelete;
    }

    int getSize()
    {
        return pq.size();
    }

    bool isEmpty()
    {
        return pq.size() == 0;
    }
};

int main()
{
    PriorityQueue pq;
    /*    int choice;
       cin >> choice;
       while (choice != -1)
       {
           switch (choice)
           {
           case 1: // insert
               int element;
               cin >> element;
               pq.insert(element);
               break;
           case 2: // getMax
               cout << pq.getMax() << "\n";
               break;
           case 3: // removeMax
               cout << pq.removeMax() << "\n";
               break;
           case 4: // size
               cout << pq.getSize() << "\n";
               break;
           case 5: // isEmpty
               cout << (pq.isEmpty() ? "true\n" : "false\n");
           default:
               return;
           }

           cin >> choice;
       }
    */
    vector<int> v = {16, 12, 35, 33, 50, 25, 34, 45, 60, 10};

    for (int i = 0; i < v.size(); i++)
    {
        pq.insert(v[i]);
    }

    while (!pq.isEmpty())
    {
        cout << pq.removeMax() << " ";
    }
    return 0;
}
