class Solution{   
public:
    string printMinNumberForPattern(string s)
    {
        int n = s.size();
        vector<int> dp(n,0);
        int cnt = 0;
        for(int i = n-1;i>=0;i--)
        {
            if(s[i] == 'D')
                cnt++;
            else
            {
                dp[i] = cnt;
                cnt = 0;
            }
        }
        
        string ans = "";
        int cur = 1;
        int next = 1;
        if(cnt != 0) // If it starts from D
        {
            cur+=cnt;
            next+=cnt;
        }
        ans+=to_string(cur);
        for(int i = 0;i<n;i++)
        {
            if(s[i] == 'I')
            {
                cur = next; 
                cur++;
                cur += dp[i];
                next = cur; // To mark the next increasing number that we should take
                ans += to_string(cur);
            }
            else
            {
                cur--;
                ans += to_string(cur);
            }
        }
        return ans;
    }
};