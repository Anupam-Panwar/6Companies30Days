class Solution {
public:
    bool cycleDetectionInDG(vector<int> adj[], vector<int> &visit, vector<int> &dfsVisit, int start)
    {
        visit[start] = 1;
        dfsVisit[start] = 1;
        for(int x : adj[start]) 
        {
            if(visit[x] == false) 
            {
                if(cycleDetectionInDG(adj, visit, dfsVisit,x) == true) 
                    return true;
            } 
            else if(dfsVisit[x] == true) 
            {
                return true; 
            }
        }
        dfsVisit[start] = 0; 
        return false;
        
    }
    bool check(vector<int> adj[],int n)
    {
        vector<int> visit(n,0);
        vector<int> dfsVisit(n,0);
        
        for(int i = 0;i<n;i++)
        {
            if(visit[i] == 0)
            {
                if(cycleDetectionInDG(adj,visit,dfsVisit,i) == true)
                    return true;
            }
        }
        return false;
    }
    
	bool isPossible(int n, vector<pair<int, int> >& prerequisites) 
	{
        /*

        Array is memory efficient data structure. 
        Vector takes more time in accessing elements. 
        Array access elements in constant time irrespective of their location as elements are arranged in a contiguous memory allocation.
        
        */
	    vector<int> adj[n]; 
	    for(pair<int,int> p : prerequisites)
	        adj[p.second].push_back(p.first);
	    
	    bool ans = check(adj,n);
	    ans = !ans;
	    return ans;
	}
};