class Solution
{   
    public: 
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        int left = 0;
        int right = c-1;
        int top = 0;
        int bottom = r-1;
        
        int total = r*c;
        vector<int> ans;
        while(total>0)
        {
            for(int i = left;i<=right;i++)
            {
                ans.push_back(matrix[top][i]);
                total--;
            }
            if(total == 0)
                break;
            top++;
            for(int i = top;i<=bottom;i++)
            {
                ans.push_back(matrix[i][right]);
                total--;
            }
            if(total == 0)
                break;
            right--;
            for(int i = right;i>=left;i--)
            {
                ans.push_back(matrix[bottom][i]);
                total--;
            }
            if(total == 0)
                break;
            bottom--;
            for(int i = bottom;i>=top;i--)
            {
                ans.push_back(matrix[i][left]);
                total--;
            }
            left++;
        }
        return ans;
    }
};