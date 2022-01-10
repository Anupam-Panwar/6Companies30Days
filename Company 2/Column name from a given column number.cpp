class Solution{
    public:
    string colName (long long int n)
    {
        string ans = "";
        while(n>0)
        {
            int d = n%26;
            string temp = "";
            if(d == 0)
            {
                temp+='Z';
                n/=26;
                n--;
            }
            else
            {
                temp+=('A'+d-1);
                n/=26;
            }
            ans = temp + ans;
        }
        return ans;
    }
};