class Solution {
public:
    string gcdOfStrings(string str1, string str2) 
    {
        string ans = "";
        vector<string> v;
        string sm = "";
        string l = "";
        int n = str1.size();
        int m = str2.size();
        if(n<m)
        {
            sm = str1;
            l = str2;
        }
        else
        {
            sm = str2;
            l = str1;
        }
        string temp = "";
        for(int i = 0;i<sm.size();i++)
        {
            temp+=sm[i];
            v.push_back(temp);
        }
        
        for(int i = 0;i<v.size();i++)
        {
            string str = v[i];
            int sml = sm.size();
            int ll = l.size();
            int t = str.size();
            if((sml%t==0) && (ll%t==0))
            {
                int sn = sml/t;
                int ln = ll/t;
                string st = "";
                for(int j = 0;j<sn;j++)
                    st+=str;
                string lt = "";
                for(int j = 0;j<ln;j++)
                    lt+=str;
                if(lt == l && st == sm)
                    ans = str;
            }
        }
        return ans;
        
    }
};