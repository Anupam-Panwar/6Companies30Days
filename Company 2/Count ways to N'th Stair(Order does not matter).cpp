class Solution
{
    public:
    //Function to count number of ways to reach the nth stair 
    //when order does not matter.
    long long countWays(int m)
    {
        long long ans = m/2; // counting number of ways we can reach by taking atleast one step of size 2
        ans++;// incrementing if we take all steps of size 1
        return ans;
    }
};