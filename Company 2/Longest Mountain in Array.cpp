class Solution {
public:
    int longestMountain(vector<int>& arr) 
    {
        int n = arr.size();
        vector<int> pre(n,0);
        vector<int> pos(n,0);
        
        int temp = 0;
        for(int i = 1;i<n;i++)
        {
            if(arr[i-1]<arr[i])
                temp++;
            else
                temp = 0;
            
            pre[i] = temp;
        }
        
        temp = 0;
        for(int i = n-2;i>=0;i--)
        {
            if(arr[i]>arr[i+1])
                temp++;
            else
                temp = 0;
            
            pos[i] = temp;
        }
        
        int ans = 0;
        for(int i = 1;i<n-1;i++)
        {
            if(pos[i]!=0 && pre[i]!=0)
            ans = max(ans,(pos[i]+pre[i]+1));
        }
        
        return ans;
    }
};