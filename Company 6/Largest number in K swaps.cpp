class Solution
{
    public:
    string ans;
    //Function to find the largest number after k swaps.
    void findAns(string str,int k)
    {
        if(str>ans)
            ans = str;
        
        if(k == 0)
            return;
            
        int n = str.size();
        for(int i = 0;i<n-1;i++)
        {
            int index = i;
            for(int j = i+1;j<n;j++)
            {
                if(str[j]>=str[index])
                    index = j;
            }
            if(index!=i)
            {
                string temp = str;
                swap(temp[i],temp[index]);
                findAns(temp,k-1);
            }
        }
    }
    string findMaximumNum(string str, int k)
    {
        ans = str;
        findAns(str,k);
        return ans;
    }
};