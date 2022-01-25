class Solution{

  public:
	int minDifference(int arr[], int n)  
	{ 
	    int sum = 0;
	    for(int i = 0;i<n;i++)
	        sum+=arr[i];
	       
	    bool dp[n+1][sum+1];
	    for(int i = 0;i<n+1;i++)
	    {
	        for(int j = 0;j<sum+1;j++)
	        {
	            if(i == 0)
	                dp[i][j] = false;
	            if(j == 0)
	                dp[i][j] = true;
	            
	            if(i!=0 && j!=0)
	            {
	                if(arr[i-1]>j)
	                    dp[i][j] = dp[i-1][j];
	                else
	                    dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
	            }
	        }
	    }
	   // for(int i = 0;i<n+1;i++)
	   // {
	   //     for(int j = 0;j<sum+1;j++)
	   //        cout<<dp[i][j]<<" ";
	        
	   //     cout<<"\n";
	   // }
	    
	    int ans = INT_MAX;
	    for(int j = 0;j<=sum/2;j++)
	    {
	        if(dp[n][j] == true)
	            ans = min(ans,(sum - 2*j));
	    }
	    return ans;
	} 
};