class Solution {
public:
    int requiredSplit(vector<int> nums, int m)
    {
        int ans = 1;
        int sum = 0;
        for(int i = 0; i<nums.size();i++)
        {
            sum+=nums[i];
            if(sum>m)
            {
                ans++;
                sum = nums[i];
            }
        }
        return ans;
    }
    int splitArray(vector<int>& nums, int m) 
    {
        int end = 0;
        int start = nums[0];
        
        for(int x : nums)
        {
            end+=x;
            start = max(start,x);
        }
        
        int ans = INT_MAX;
        while(start<=end)
        {
            int mid = (start+end)/2;
            int req = requiredSplit(nums,mid);
            //cout<<mid<<" "<<req<<"\n";
            if(req<=m)
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