class Solution {
public:
    void dfs(vector<pair<int,double>> adj[], vector<bool> &visit, int curr)
    {
        visit[curr] = true;
        for(int i = 0;i<adj[curr].size();i++)
        {
            if(visit[adj[curr][i].first] == false)
                dfs(adj,visit,adj[curr][i].first);
        }
    }
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) 
    {
        vector<pair<int,double>> adj[n];
        for(int i = 0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(make_pair(edges[i][1],succProb[i]));
            adj[edges[i][1]].push_back(make_pair(edges[i][0],succProb[i]));
        }
        vector<bool> visit(n,false);
        dfs(adj,visit,start);
        
        if(visit[end] == false)
            return 0;
        
        visit.assign(n,false);
        vector<double> key(n,0);
        
        priority_queue<pair<double,int>> pq; // Max Heap
        pq.push(make_pair(1.0,start));
        key[start] = 1.0; // initializing it from 1 because we have to do multiplication
        
        while(pq.empty() == false)
        {
            int u=pq.top().second;
            pq.pop();
            visit[u] = true;
            
            for(pair<int,double> k : adj[u])
            {
                int v = k.first;
                double w = k.second;
                if(visit[v] == false && w*key[u]>key[v])
                {
                    key[v]=key[u]*w;
                    pq.push(make_pair(key[v],v));
                }
            }
        }
        
        return key[end];
    }
};