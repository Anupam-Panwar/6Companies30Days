class Solution{
    public:
    vector<vector<int> > fourSum(vector<int> &arr, int k) 
    {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
            
        for(int i = 0;i<n-3;i++)
        {
            if(i>0 && arr[i-1] == arr[i]) // Inorder to eliminate repeating cases
                continue;
            for(int j = i+1;j<n-2;j++)
            {
                if(j>i+1 && arr[j] == arr[j-1]) // Inorder to eliminate repeating cases
                    continue;
                int start = j+1;
                int end = n-1;
                while(start<end)
                {
                    int sum = arr[i] + arr[j] + arr[start] + arr[end];
                    if(sum == k)
                    {
                        vector<int> temp;
                        temp.push_back(arr[i]);
                        temp.push_back(arr[j]);
                        temp.push_back(arr[start]);
                        temp.push_back(arr[end]);
                        ans.push_back(temp);
                        
                        while(start < end and arr[start] == temp[2]) //Inorder to eliminate repeating cases
                            start++;
                        while(start < end and arr[end] == temp[3]) // Inorder to eliminate repeating cases
                            end--;
                    }
                    else if(sum>k)
                        end--;
                    else 
                        start++;
                }
            }
        }
        return ans;
    }
};