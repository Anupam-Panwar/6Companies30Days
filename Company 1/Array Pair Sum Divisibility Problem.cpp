class Solution {
  public:
    bool canPair(vector<int> nums, int k) 
    {
        int n = nums.size();
        
        if(n%2!=0)
            return false;
        else
        {
            unordered_map<int,int> mp;
            for(int x : nums)
                mp[x%k]++;
            
            for(int x : nums)
            {
                int temp = x%k;
                if(mp[temp] == 0)
                    continue;
                    
                int req = k - temp;
                
                if(temp == 0 && mp[temp]>=2)
                    mp[temp]-=2;
                else if(mp.count(req) != 0 && mp[req] != 0 && mp[temp] != 0)
                {
                    mp[req]--;
                    mp[temp]--;
                }
                else
                    return false;
            }
            return true;
        }
    }
};