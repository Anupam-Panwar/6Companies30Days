#include<bits/stdc++.h>
using namespace std;

vector<int> get10Max(vector<int> &v)
{
    int n = v.size();
    priority_queue<int,vector<int>,greater<int>> pq;
    pq.push(v[0]);
    for(int i=1;i<n;i++)
    {
        if(v[i]>pq.top())
        {
            pq.push(v[i]);
             if(pq.size()>10)
            pq.pop();
        }
    }
    vector<int> ans;
    while(pq.empty()==false)
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}
int main()
{
    srand(time(0));
    int size = 1000000;
    vector<int> v;
    for(int i = 0; i<size; i++)
    {
        int random = rand();
        v.push_back(random);
    }
    vector<int> ans = get10Max(v);
     for(int x : v)
    cout<<x<<" ";
    
    cout<<"\n\n\n";
    
    for(int x : ans)
    cout<<x<<" ";
    return 0;
}