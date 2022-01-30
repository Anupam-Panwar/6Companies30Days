class Solution{
  public:
    vector<int> find3Numbers(vector<int> arr, int n) 
    {
        vector<int> smallLeft(n,-1);
        vector<int> BiggerRight(n,-1);
        
        stack<int> st;
        st.push(0);
        
        for(int i = 1;i<n;i++)
        {
            while(st.empty() == false && arr[st.top()]>=arr[i])
                st.pop();
            
            if(st.empty() == false)
            smallLeft[i] = st.top();
            
            st.push(i);
        }
        // for(int x : smallLeft)
        //     cout<<x<<" ";
        // cout<<"\n";
        
        while(st.empty() == false)
            st.pop();
        st.push(n-1);
        
        for(int i = n-2;i>=0;i--)
        {
            while(st.empty() == false && arr[st.top()]<=arr[i])
                st.pop();
                
            if(st.empty() == false)
            BiggerRight[i] = st.top();
            st.push(i);
        }
        
        // for(int x : BiggerRight)
        //     cout<<x<<" ";
        // cout<<"\n";
        
        vector<int> ans;
        for(int i = 0;i<n;i++)
        {
            if(smallLeft[i] != -1 && BiggerRight[i] != -1)
            {
                ans.push_back(arr[smallLeft[i]]);
                ans.push_back(arr[i]);
                ans.push_back(arr[BiggerRight[i]]);
                break;
            }
        }
        return ans;
    }
};