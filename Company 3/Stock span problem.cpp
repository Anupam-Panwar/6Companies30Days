class Solution
{
    public:
    vector <int> calculateSpan(int price[], int n)
    {
       stack<int> st;
       vector<int> prevGreater(n,-1); // Calculating next greater element of current element in the left side of it
       for(int i = 0;i<n;i++)
       {
           
            while(st.empty() == false && price[st.top()]<=price[i])
                st.pop();
               
            if(st.empty() == true)
                prevGreater[i] = -1;
            else
                prevGreater[i] = st.top();
            st.push(i);
       }
       vector<int> ans(n,0);
       for(int i = 0;i<n;i++)
           ans[i] = i - prevGreater[i];
        
       return ans;
    }
};