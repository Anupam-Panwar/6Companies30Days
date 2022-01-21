class Solution{
  public:
    string nextPalin(string str) 
    { 
        int n = str.size();
        string temp = str.substr(0,n/2);

        bool flag = false;
        for(int i = temp.size()-1;i>=1;i--) // Code to find next greater permutation
        {
            if(temp[i-1]<temp[i])
            {
                int small = temp.size()-1;
                while(temp[small]<=temp[i-1])
                    small--;
                
                swap(temp[i-1],temp[small]);
                sort(temp.begin()+i,temp.end());
                flag = true;
                break;
            }
        }
        string ans = "";
        if(flag == false)
            ans = "-1";
        else
        {
            ans+=temp;
            reverse(temp.begin(),temp.end());
            if(n%2!=0)
                ans+=str[n/2];
                
            ans+=temp;
        }
        return ans;
    }
};