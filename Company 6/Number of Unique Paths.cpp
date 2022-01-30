class Solution
{
    public:
    //Function to find total number of unique paths.
    int NumberOfPath(int a, int b)
    {
        int path[a][b];
        memset(path,0,sizeof(path));
        
        for(int i = 0;i<a;i++)
        {
            for(int j = 0;j<b;j++)
            {
                if(i == 0)
                    path[i][j] = 1;
                else if(j == 0)
                    path[i][j] = 1;
                else
                    path[i][j] = path[i-1][j] + path[i][j-1];
            }
        }
        int ans = path[a-1][b-1];
        return ans;
    }
};