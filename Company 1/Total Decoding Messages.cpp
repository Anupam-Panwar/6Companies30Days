class Solution {
	public:
		int CountWays(string str)
		{
		    int mod = 1000000007;
		    int n = str.size();
		    vector<long long> dp(n+1,0);
		    
		    dp[0] = 1;
		    dp[1] = 1;
		    
		    if(str[0] == '0')
		        return 0;
		   
		   for(int i = 2;i<n+1;i++)
		   {
		       string temp = "";
		       temp += str[i-2] ;
		       temp += str[i-1];
		       
		       int t = stoi(temp);
		       //cout<<t<<"\n";
		       
		       if(t == 0 || t == 30 || t == 40 || t == 50 || t == 60 || t== 70 || t==80 || t == 90)
		         return 0;
		       else if(t == 20 || t == 10)
		        dp[i] = dp[i-2];
		       else if( t>= 11 && t<= 26)
		        dp[i] = (dp[i-1] % mod + dp[i-2] % mod) % mod;
		       else
		        dp[i] = dp[i-1];
		   }
		  // for(long long x : dp)
		  // cout<<x<<" ";
		  // cout<<"\n";
		    int res = dp[n] % mod;
		    return res;
		}

};