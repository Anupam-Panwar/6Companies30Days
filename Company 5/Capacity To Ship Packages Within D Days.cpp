class Solution {
public:
    int requiredDays(vector<int> weights,int wt)
    {
        int days = 1;
        int c = 0;
        for(int x : weights)
        {
            c+=x;
            if(c>wt)
            {
                days++;
                c = x;
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) 
    {
        int end = 0;
        int start = weights[0];
        for(int x : weights)
        {
            end+=x;
            start = max(start,x);
        }
        
        int ans = INT_MAX;
        while(start<=end)
        {
            int mid = (start+end)/2;
            //cout<<mid<<" ";
            int rday = requiredDays(weights,mid);
            //cout<<rday<<"\n";
            if(rday<=days)
            {
                ans = min(ans,mid);
                end = mid-1;
            }
            else
            {
                start = mid+1;
            }
        }
        return ans;
    }
};