class Solution {
public:
    int bfs(vector<vector<int>>&grid, int i, int j)
    {
        int rowIdx[8] = {-1,1,0,0,-1,-1,1,1};
        int colIdx[8] = {0,0,-1,1,-1,1,-1,1};
        
        int n = grid.size();
        bool visit[n][n];
        memset(visit,false,sizeof(visit));
        
        queue<pair<int,int>> qu;
        qu.push(make_pair(i,j));
        visit[i][j] = true;
        vector<pair<int,int>> temp;
        
        while(qu.empty() == false)
        {
            int s = qu.size();
            for(int j = 0;j<s;j++)
            {
                pair<int,int> p = qu.front();
                qu.pop();
                int x = p.first;
                int y = p.second;

                for(int i = 0;i<8;i++)
                {
                    int dx = x + rowIdx[i];
                    int dy = y + colIdx[i];

                    if(dx>=0 && dx<n && dy>=0 && dy<n)
                    {
                        if(visit[dx][dy] == false)
                        {
                            if(grid[dx][dy] == 1)
                                temp.push_back(make_pair(dx,dy));
                            else
                            {
                                visit[dx][dy] = true;
                                qu.push(make_pair(dx,dy));
                            }
                        }
                    }
                }
            }
            if(temp.size()!=0)
                break;
        }
        int ans = INT_MAX;
        for(int k = 0;k<temp.size();k++)
        {
            int d = abs(temp[k].first-i) + abs(temp[k].second-j);
            //cout<<d<<"\n";
            ans = min(ans,d);
        }
        return ans;
    }
    int maxDistance(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int ans = -1;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(grid[i][j] == 0)
                {
                    int temp = bfs(grid,i,j);
                    if(temp!=INT_MAX)
                        ans = max(ans,temp);
                }
            }
        }
        return ans;
    }
};




// Optimized Approach

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        queue<pair<int,int>> q;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j])
                    q.push(make_pair(i,j));
            }
        }
        if(q.size() == 0) 
            return -1;
        if(q.size() == n*n) 
            return -1;
        
        int dirx[]={-1,1,0,0};
        int diry[]={0,0,-1,1};
        int d=0;
        
        while(q.empty() == false)
        {
            int t=q.size(); 
            for(int j = 0;j<t;j++)
            {
                int x = q.front().first;
                int y = q.front().second; 
                q.pop();
                for(int i=0;i<4;i++)
                {
                    int nx=x+dirx[i]; 
                    int ny=y+diry[i];
                    if(nx>=0 && nx<n && ny>=0 && ny<n && grid[nx][ny]==0)
                    {
                        grid[nx][ny]=1;
                        q.push(make_pair(nx,ny));                    
                    }
                }
            }      
            d++;
        }
        return d-1;
    }
};