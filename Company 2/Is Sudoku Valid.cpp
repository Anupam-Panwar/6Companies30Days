class Solution{
public:
    int isValid(vector<vector<int>> mat)
    {
        int n = mat.size();
        for(int i = 0;i<n;i++)
        {
            vector<int> v(n,0);
            for(int j = 0;j<n;j++)
            {
                if(mat[i][j] == 0)
                continue;
                
                v[mat[i][j]-1]++;
                if(v[mat[i][j]-1]>1)
                    return 0;
            }
        }
        for(int j = 0;j<n;j++)
        {
            vector<int> v(n,0);
            for(int i = 0;i<n;i++)
            {
                if(mat[i][j] == 0)
                continue;
                
                v[mat[i][j]-1]++;
                if(v[mat[i][j]-1]>1)
                    return 0;
            }
        }
        
        for(int i = 0;i<n;i+=3)
        {
            for(int j = 0;j<n;j+=3)
            {
                vector<int> v(n,0);
                for(int k = i;k<i+3;k++)
                {
                    for(int l = j;l<j+3;l++)
                    {
                        if(mat[k][l] == 0)
                        continue;
                        
                        v[mat[k][l]-1]++;
                        if(v[mat[k][l]-1]>1)
                            return 0;
                    }
                }
            }
        }
        return 1;
    }
};