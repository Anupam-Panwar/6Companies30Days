class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        int total = 0;
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]!=0)
                {
                    total++;
                    if(grid[i][j]==2)
                        q.push(make_pair(i,j));
                }
            }
        }
        int t = 0;
        int count = 0;
        while(q.empty() == false)
        {
            int ss = q.size();
            count+=ss;
            //cout<<ss<<" ";
            if(count == total)
            break;
            for(int i=0;i<ss;i++)
            {
                pair<int,int> tmp = q.front();
                int x = tmp.first;
                int y = tmp.second;
                //cout<<x<<" "<<y<<"\n";
                
                if(x-1>=0 && grid[x-1][y] == 1) // up
                {
                    q.push(make_pair(x-1,y));
                    grid[x-1][y] = 2;
                }
                
                if(x+1<n && grid[x+1][y] == 1)// down
                {
                    q.push(make_pair(x+1,y));
                    grid[x+1][y] = 2;
                }
                
                if(y-1>=0 && grid[x][y-1] == 1)// left
                {
                    q.push(make_pair(x,y-1));
                    grid[x][y-1] = 2;
                }
                
                if(y+1<m && grid[x][y+1] == 1)// right
                {
                    q.push(make_pair(x,y+1));
                    grid[x][y+1] = 2;
                }
                
                q.pop();
            }
            t++;
        }
        
        if(count == total)
            return t;
        else
            return -1;
        
    }
};