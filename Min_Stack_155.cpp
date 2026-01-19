#include <bits/stdc++.h>
using namespace std;

class MinStack
{
public:
    stack<pair<int, int>> s; // val,minVal
    MinStack() {}
    void push(int x)
    {
        if (s.empty())
        {
            s.push({x, x});
        }
        else
        {
            int minVal = min(x, s.top().second);
            s.push({x, minVal});
        }
    }
    void pop()
    {
        if (!s.empty())
        {
            s.pop();
        }
    }
    int top()
    {
        return s.top().first;
    }
    int getMin()
    {
        return s.top().second;
    }
};

int main()
{
    MinStack ms;
    ms.push(10);
    ms.push(20);
    cout << ms.getMin() << " ";
    ms.push(-2);
    ms.push(-10);

    cout << ms.getMin() << " ";
    ms.pop();
    cout << ms.top() << " ";
    cout << ms.getMin() << " ";

    return 0;
}