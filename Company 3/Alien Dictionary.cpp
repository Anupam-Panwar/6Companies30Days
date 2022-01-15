class Solution{
    public:
    void findTopoSort(int node, vector<int> &vis, stack<int> &st, vector<int> adj[]) 
    {
        vis[node] = 1; 
        
        for(auto it : adj[node]) 
        {
            if(vis[it] == 0)
                findTopoSort(it, vis, st, adj); 
        }
        st.push(node); 
    }
    string topoSort(vector<int> adj[],int n) 
    {
	    stack<int> st; 
	    vector<int> vis(n, 0); 
	    for(int i = 0;i<n;i++) 
	    {
	        if(vis[i] == 0) 
	            findTopoSort(i, vis, st, adj); 
	 
	    }
	    
	    string ans = "";
	    while(!st.empty()) 
	    {
	        ans+=('a'+st.top());
	        st.pop(); 
	    }
	    return ans;
	    
	}
    string findOrder(string dict[], int n, int k) 
    {
        vector<int> adj[k];
        for(int i = 0;i<n-1;i++)
        {
            for(int j = 0;j<min(dict[i].size(),dict[i+1].size());j++)
            {
                if(dict[i][j] != dict[i+1][j])
                {
                    adj[dict[i][j]-'a'].push_back(dict[i+1][j]-'a');
                    break;
                }
            }
        }
    
        string ans = topoSort(adj,k);
        return ans;
    }
};