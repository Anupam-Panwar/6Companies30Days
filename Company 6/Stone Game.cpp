class Solution {
public:
    bool stoneGame(vector<int>& piles) 
    {
        int sum1 = 0;
        int sum2 = 0;
        for(int i = 0;i<piles.size();i++)
        {
            if(i%2 == 0)
                sum1+=piles[i];
            else 
                sum2+=piles[i];
        }
        if(sum1!=sum2)
            return true;
        else
            return false;
    }
};