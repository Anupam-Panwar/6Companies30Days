class Solution {
public:
    void topoDfs(int start, vector<bool> &visit, vector<bool> &dfsVisit,  stack<int> &st, vector<int> adj[], int &flag)
    {
        visit[start] = true;
        dfsVisit[start] = true; 
        for(int x : adj[start])
        {
            if(visit[x] == false)
               topoDfs(x,visit,dfsVisit,st,adj,flag);
            else if(dfsVisit[x]==true)
            {
                flag=0;
                return;
            }
        }
        dfsVisit[start] = false;
        st.push(start);        
    }
    vector<int> topoSort(vector<int> adj[],int n)
    {
        stack<int> st;
        vector<bool> visit(n,false);
        vector<bool> dfsVisit(n,false);
        
        int flag;
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            flag=1;
            if(visit[i] == false)
                topoDfs(i,visit,dfsVisit,st,adj,flag);
            
            if(flag==0)
            return ans;
        }
        
        while(st.empty() == false)
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) 
    {
        vector<int> adj[n];
        for(int i = 0;i<prerequisites.size();i++)
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        
        vector<int> ans = topoSort(adj,n);
        return ans;
        
    }
};