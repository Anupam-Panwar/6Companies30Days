class Solution{
public:
    int height(int N)
    {
         int ans = (-1 + sqrt(1 + 8*N)) / 2;
         return ans;
    }
};