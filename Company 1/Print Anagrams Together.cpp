class Solution{
  public:
    vector<vector<string>> Anagrams(vector<string>& string_list) 
    {
        unordered_map<string,vector<string>> mp;
        for(string str : string_list)
        {
            string s = str;
            sort(s.begin(),s.end());
            mp[s].push_back(str);
        }
        vector<vector<string>> ans;
        for(auto i = mp.begin();i!=mp.end();i++)
            ans.push_back(i->second);
        
        return ans;
    }
};