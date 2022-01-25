class Solution {
public:
    void bfsp(vector<vector<int>>& heights,vector<vector<bool>> &pacific)
    {
        int n = heights.size();
        int m = heights[0].size();
        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};
        
        bool visit[n][m];
        memset(visit,false,sizeof(visit));
        queue<pair<int,int>> qu;
        
        for(int i = 0;i<m;i++)
        {
            visit[0][i] = true;
            qu.push(make_pair(0,i));
            pacific[0][i] = true;
        }
        
        for(int i = 1;i<n;i++)
        {
            visit[i][0] = true;
            qu.push(make_pair(i,0));
            pacific[i][0] = true;
        }
        
        while(qu.empty() == false)
        {
            int x = qu.front().first;
            int y = qu.front().second;
            qu.pop();
            
            for(int i = 0;i<4;i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx>=0 && nx<n && ny>=0 && ny<m)
                {
                    if(heights[nx][ny]>=heights[x][y] && visit[nx][ny] == false)
                    {
                        qu.push(make_pair(nx,ny));
                        visit[nx][ny] = true;
                        pacific[nx][ny] = true;
                    }
                }
            }
        }
        
    }
    void bfsa(vector<vector<int>>& heights,vector<vector<bool>> &atlantic)
    {
        int n = heights.size();
        int m = heights[0].size();
        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};
        
        bool visit[n][m];
        memset(visit,false,sizeof(visit));
        queue<pair<int,int>> qu;
        
        for(int i = 0;i<m;i++)
        {
            visit[n-1][i] = true;
            qu.push(make_pair(n-1,i));
            atlantic[n-1][i] = true;
        }
        for(int i = 0;i<n-1;i++)
        {
            visit[i][m-1] = true;
            qu.push(make_pair(i,m-1));
            atlantic[i][m-1] = true;
        }
        
        while(qu.empty() == false)
        {
            int x = qu.front().first;
            int y = qu.front().second;
            qu.pop();
            
            for(int i = 0;i<4;i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx>=0 && nx<n && ny>=0 && ny<m)
                {
                    if(heights[nx][ny]>=heights[x][y] && visit[nx][ny] == false)
                    {
                        qu.push(make_pair(nx,ny));
                        visit[nx][ny] = true;
                        atlantic[nx][ny] = true;
                    }
                }
            }
        }
        
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
    {
        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<bool>> pacific(n,vector<bool>(m,false));
        vector<vector<bool>> atlantic(n,vector<bool>(m,false));
            
        bfsp(heights,pacific);
        bfsa(heights,atlantic);
        
        vector<vector<int>> ans;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(pacific[i][j] == true && atlantic[i][j] == true)
                    ans.push_back({i,j});
            }
        }
        return ans;
    }
};