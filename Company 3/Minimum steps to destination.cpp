class Solution{
public:
    int minSteps(int D)
    {
        int n = 1;
        while(1)
        {
            int s = n*(n+1)/2;
            if(s == D)
                break;
            
            if(s>D && (s-D)%2==0)// Checking the case when we need to take backward step 
                break;
            
            n++;
        }
        return n;
    }
};