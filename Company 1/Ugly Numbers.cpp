class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(int n) 
	{
	    set<ull> ans;
	    ans.insert(1);
	    n--;
	    while(n--)
	    {
	        ull temp = *(ans.begin());
	        ans.erase(ans.begin());
	        ull t1 = temp*2;
	        ans.insert(t1);
	        
	        t1 = temp*3;
	        ans.insert(t1);
	        
	        t1 = temp*5;
	        ans.insert(t1);
	    }
	    return *(ans.begin());
	}
};