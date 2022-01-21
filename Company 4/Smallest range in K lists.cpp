class Solution{
    public:
    pair<int,int> findSmallestRange(int arr[][N], int n, int k)
    {
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
       int maxi=INT_MIN;
       int minrange=INT_MAX;
       int start;
       for(int i=0;i<k;i++) 
       {
          pq.push(make_pair(arr[i][0],i));
          maxi=max(maxi,arr[i][0]);
       }
       int a[k]={0};
       while(1)
       {
           pair<int,int> p=pq.top();
           pq.pop();
           int mini=p.first;
           int range=maxi-mini;
           if(range<minrange) 
           {
               start=mini;
               minrange=range;
           }
           a[p.second]++;
           if(a[p.second]==n)
            break;
           pq.push(make_pair(arr[p.second][a[p.second]],p.second));
           maxi=max(maxi,arr[p.second][a[p.second]]);
       }
       return make_pair(start,minrange+start);
    }
};