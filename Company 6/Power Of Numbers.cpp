class Solution{
    public:
    const int M = 1e9+7;
    long long power(int n,int R)
    {
        long long res=1;
        long long N = n;
        if(N==0)
            return 0;
        if(R==0)
            return 1;
        
        while(R>0)
        {
          if(R&1)
            res=(res*N)%M;
          R=R>>1;
          N=(N*N)%M;
        }
        return res%M;
    }
};