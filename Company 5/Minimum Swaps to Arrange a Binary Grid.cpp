class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        vector<int> tz(n,0);
        
        for(int i = 0;i<n;i++)
        {
            int cnt = 0;
            for(int j = n-1;j>=0;j--)
            {
                if(grid[i][j] == 0)
                    cnt++;
                else
                    break;
            }
            tz[i] = cnt;
        }
        
        int swaps = 0;
        for(int i=0; i<n; i++)
        {
            if(tz[i] < n-1-i) 
            {
                int j = i+1;
                while(j<n && tz[j] < n-1-i)
                    j++;
                if(j == n) 
                    return -1;

                while(j > i)
                {
                    swap(tz[j], tz[j-1]);
                    j--;
                    swaps++;
                }
            }
        }
        return swaps;
        
    }
};