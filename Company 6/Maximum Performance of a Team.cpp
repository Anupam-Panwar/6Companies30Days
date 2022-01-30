class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) 
    {
        const int MOD = 1e9+7;
        vector<pair<int,int>> eng;// <efficiency,speed>
        for(int i = 0;i<n;i++)
            eng.push_back(make_pair(efficiency[i],speed[i]));
        
        sort(eng.begin(),eng.end(),greater<>());
        
        priority_queue<int,vector<int>,greater<>> pq; // Less speed always at the top
        long long sum = 0;
        long long ans = INT_MIN;

        for(int i = 0;i<n;i++)
        {
            pq.push(eng[i].second);
            sum+=eng[i].second;
            while(pq.size() > k)
            {
                sum-=pq.top();
                pq.pop();
            }
            //cout<<sum<<" "<<eng[i].first<<" -> ";
            long long temp = (long long)(sum * eng[i].first);
            //cout<<temp<<"\n";
            ans = max(ans,temp);
        }
        return ans%MOD;
    }
};