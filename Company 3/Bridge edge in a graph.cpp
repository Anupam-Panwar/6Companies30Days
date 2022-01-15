class Solution
{
	public:
    void bfs(vector<int> adj[],vector<bool> &visit, int start)
    {
        visit[start] = true;
        queue<int> qu;
        qu.push(start);
        
        while(qu.empty() == false)
        {
            int node = qu.front();
            qu.pop();
            for(int x : adj[node])
            {
                if(visit[x] == false)
                {
                    visit[x] = true;
                    qu.push(x);
                }
            }
        }
        
    }
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        vector<bool> visit(V,false);
        int count = 0;
        for(int i = 0;i<V;i++)
        {
            if(visit[i] == false)
            {
                count++;
                bfs(adj,visit,i);
            }
        }
        
        vector<int> temp;
        for(int x : adj[c])
        {
            if(x!=d)
                temp.push_back(x);
        }
        adj[c] = temp;
        
        temp.clear();
        for(int x : adj[d])
        {
            if(x!=c)
                temp.push_back(x);
        }
        adj[d] = temp;
        
        visit.assign(V,false);
        int cnt = 0;
        for(int i = 0;i<V;i++)
        {
            if(visit[i] == false)
            {
                cnt++;
                bfs(adj,visit,i);
            }
        }
        
        if(cnt>count)
            return 1;
        else
            return 0;
    }
};