public:
    int dp[501][501];
    int solve(vector<int> a,int i,int j)
    {
        if(i == j)
            return a[i];
        if(i>j)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
            
        int l = a[i] + min(solve(a,i+2,j),solve(a,i+1,j-1));
        int r = a[j] + min(solve(a,i+1,j-1),solve(a,i,j-2));
        
        int ans = max(l,r);
        dp[i][j] = ans;
        
        return ans;
            
    }
    int maxCoins(vector<int>&A,int n)
    {
        memset(dp,-1,sizeof(dp));
        int ans = solve(A,0,n-1);
	    return ans;
    }
};