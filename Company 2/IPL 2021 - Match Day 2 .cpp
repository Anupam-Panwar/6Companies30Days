class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) 
    {
        vector<int> nge(n,n);
        
        stack<int> st;
        st.push(n-1);
        
        for(int i = n-2;i>=0;i--)
        {
            while(st.empty() == false && arr[st.top()]<arr[i])
                st.pop();
            
            if(st.empty() == true)
                nge[i] = n;
            else
                nge[i] = st.top();
                
            st.push(i);
        }
        
        vector<int> ans;
        int nxtlg = 0;
        for(int i = 0;i<=n-k;i++)
        {
            int end = i + k -1;
            if(nxtlg<i)
                nxtlg = i;
            
            while(nge[nxtlg] <= end)
                nxtlg = nge[nxtlg];
                
            ans.push_back(arr[nxtlg]);
        }
        return ans;
    }
};