class Solution {
public:
    int requiredTime(vector<int> piles, int speed)
    {
        int time = 0;
        for(int x : piles)
        {
            int temp = ceil((double)x/speed);
            time+=temp;
        }
        return time;
    }
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int start = 1;
        int end = piles[0];
        for(int x : piles)
            end = max(end,x);
        
        int ans = INT_MAX;
        while(start<=end)
        {
            int mid = (start+end)/2;
            int reqTime = requiredTime(piles,mid);
            
            if(reqTime<=h)
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