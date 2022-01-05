class Solution {
  public:
    int findPosition(int N , int M , int K) 
    {
        if(N == 1)
        return K;
        
       M = M % N;
       int ans = K + M - 1;
       if(ans>N)
        ans = ans - N;
        
        return ans;
    }
};