class Solution {
public:
    void bfs(vector<vector<int>>graph, vector<bool> &visit,int start)
    {
        visit[start] = true;
        queue<int> qu;
        qu.push(start);
        
        while(qu.empty() == false)
        {
            int cur = qu.front();
            qu.pop();
            for(int i = 0;i<graph.size();i++)
            {
                if(graph[cur][i] == 1 && visit[i] == false)
                {
                    visit[i] = true;
                    qu.push(i);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int n = isConnected.size();
        vector<bool> visit(n,false);
        
        int ans = 0;
        for(int i = 0;i<n;i++)
        {
            if(visit[i] == false)
            {
                ans++;
                bfs(isConnected,visit,i);
            }
        }
        return ans;
        
    }
};