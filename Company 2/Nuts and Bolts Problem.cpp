class Solution{
public:	

	void matchPairs(char nuts[], char bolts[], int n) 
	{
	   unordered_map<char,int> mp;
	   mp['!'] = 0;
	   mp['#'] = 1;
	   mp['$'] = 2;
	   mp['%'] = 3;
	   mp['&'] = 4;
	   mp['*'] = 5;
	   mp['@'] = 6;
	   mp['^'] = 7;
	   mp['~'] = 8;
	   
	   unordered_map<int,char> mmp;
	   mmp[0] = '!';
	   mmp[1] = '#';
	   mmp[2] = '$';
	   mmp[3] = '%';
	   mmp[4] = '&';
	   mmp[5] = '*';
	   mmp[6] = '@';
	   mmp[7] = '^';
	   mmp[8] = '~';
	   
	   vector<int> cal(9,0);
	   for(int i = 0;i<n;i++)
	    cal[mp[nuts[i]]]++;
	   
	   for(int i = 0;i<n;i++)
	    cal[mp[bolts[i]]]++;
	    
	   int index = 0;
	   for(int i = 0;i<9;i++)
	   {
	       if(cal[i] == 2)
	       {
	           nuts[index] = mmp[i];
	           bolts[index] = mmp[i];
	           index++;
	       }
	   }
	}

};