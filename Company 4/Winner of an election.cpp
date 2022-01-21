class Solution{
  public:
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n)
    {
        // Return the string containing the name and an integer
        // representing the number of votes the winning candidate got
        map<string,int> mp;
        for(int i = 0;i<n;i++) // Insertion of an element in map takes O(logN) time
            mp[arr[i]]++;
        
        int max = INT_MIN;
        string ans = "";
        for(auto i = mp.rbegin();i!=mp.rend();i++)
        {
            if(i->second>=max)
            {
                max = i->second;
                ans = i->first;
            }
        }
        vector<string> res;
        res.push_back(ans);
        res.push_back(to_string(max));
        return res;
    }
};