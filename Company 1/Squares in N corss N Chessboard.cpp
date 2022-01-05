class Solution {
  public:
    long long squaresInChessBoard(long long n) 
    {
        long long ans = ((n)*(n+1)*(2*n+1))/6; // Sum of square of first n natural numbers
        return ans;
    }
};