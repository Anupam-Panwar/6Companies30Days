class Solution{
    public:
    string amendSentence (string s)
    {
        string ans = "";
        for(int i = 0;i<s.size();i++)
        {
            if(s[i]>='A' && s[i]<='Z')
            {
                if(i!=0)
                    ans+=" ";
                ans+=(char)(s[i]+32); // Converting Upper case letter into lower case letter
            }
            else
                ans+=s[i];
        }
        return ans;
    }
};