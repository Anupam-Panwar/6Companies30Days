class Solution {
	public:
		string FirstNonRepeating(string A)
		{
		    unordered_map<char,int> mp;
		    string ans = "";
		    queue<char> qu;
		    
		    for(char ch : A)
		    {
		        mp[ch]++;
		        
		        while(qu.empty() == false && mp[qu.front()]>1)
		            qu.pop();
		            
		       
		        if(mp[ch] == 1)
		        qu.push(ch);
		        
		        if(qu.empty() == false)
		            ans+=qu.front();
		        else
		            ans+='#';
		    }
		    return ans;
		}

};