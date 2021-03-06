#include <bits/stdc++.h>
using namespace std;

vector<int> split(string s)
{
    int i = 0;
    int num = 0;
    vector<int> v;
    for (; i < s.size(); i++)
    {
        if (s[i] == '.')
        {
            v.push_back(num);
            num = 0;
        }
        else
            num = num * 10 + (s[i] - '0');
    }
    v.push_back(num);
    return v;
}
int main()
{
    string x, y;
    cin>>x>>y;
    vector<int> xv = split(x);
    vector<int> yv = split(y);
    int i = 0;
    while (i < xv.size() && i < yv.size())
    {
        if (xv[i] != yv[i])
        {
            x = ((xv[i] > yv[i]) ? x : y);
            break;
        }
        i++;
    }
    if (i == xv.size())
        cout << y;
    else
        cout << x;
    return 0;
}