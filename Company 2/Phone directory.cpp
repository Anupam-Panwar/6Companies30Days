class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        sort(contact, contact+n);
        vector<int> upto(n,-1);
        
        for(int i = 0;i<n-1;i++) // Dealing with repeated contact
        {
            if(contact[i] == contact[i+1])
                contact[i] = "";
        }
        for(int i = 0;i<n;i++)
        {
            string temp = contact[i];
            int j = 0;
            for(;j<s.size()&&j<temp.size();j++)
            {
                if(s[j] != temp[j])
                    break;
            }
            upto[i] = j-1; 
        }
        
        // for(int i = 0;i<n;i++)
        // cout<<contact[i]<<" "<<upto[i]<<"\n";
        
        vector<vector<string>> ans;
        for(int i = 0;i<s.size();i++)
        {
            vector<string> temp;
            for(int j = 0;j<n;j++)
            {
                if(contact[j] == "")
                    continue;
                if(upto[j] >= i)
                    temp.push_back(contact[j]);
            }
            if(temp.size() == 0)
                temp.push_back("0");
            
            ans.push_back(temp);
        }
        
        return ans;
    }
};