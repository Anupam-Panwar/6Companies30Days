class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int a[], int n, long long s)
    {
        int start = 0;
        int end = -1;
        long long sum = 0;
        while(end<n)
        {
            if(sum == s)
                break;
            else if(sum>s)
            {
                sum-=a[start];
                start++;
            }
            else
            {
                end++;
                sum+=a[end];
            }
        }
        vector<int> ans;
        if(sum == s)
        {
            ans.push_back(start+1);
            ans.push_back(end+1);
        }
        else
        {
            ans.push_back(-1);
        }
        return ans;
    }
};