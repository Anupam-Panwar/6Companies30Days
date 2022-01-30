class Solution {
public:
    int divide(int A, int B) 
    {
        if (A == INT_MIN && B == -1) 
            return INT_MAX;
        
        long long a = abs(A);
        long long b = abs(B);
        long long res = 0;
        long long x = 0;
        while (a - b >= 0) 
        {
            for (x = 0; a - (b << x << 1) >= 0; x++);
            
            res += 1 << x;
            a -= b << x;
        }
        return (A > 0) == (B > 0) ? res : -res;
    }
};