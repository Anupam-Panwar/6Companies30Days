class Solution
{
  public:
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        deque<int> dq;
        vector<int> ans;
        for(int i = 0;i<n;i++)
        {
            while(dq.empty() == false && dq.front()<=(i-k))
                dq.pop_front();
            
            while(dq.empty() == false && *(arr+dq.back())<*(arr+i))
                dq.pop_back();
            
            dq.push_back(i);
            
            if(i+1>=k)
                ans.push_back(*(arr+dq.front()));
        }
        return ans;
    }
};