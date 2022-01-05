class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int r = 0;
        int l = 0;
        int sum = 0;
        int ans = INT_MAX;
        int n = nums.size();
        
        while(r<n)
        {
            sum+=nums[r];
            r++;
            if(sum>=target)
            {
                while(sum>=target && l<=r)
                {
                    int s = r-l;
                     //cout<<l<<" "<<r<<" "<<s<<"\n";
                    ans = min(ans,s);
                    sum-=nums[l];
                    l++;
                }
            }
        }
        if(ans == INT_MAX)
            ans = 0;
        return ans;
    }
};