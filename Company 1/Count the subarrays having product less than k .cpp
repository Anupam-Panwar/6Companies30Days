class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) 
    {
         int ans = 0;
         int l = 0;
         int r = 0;
         long long pro = 1;
         while(r<n)
         {
             pro *= a[r];
             if(pro>=k)
             {
                 while(pro>=k && l<=r)
                 {
                     pro/=a[l];
                     l++;
                 }
             }
             ans += (r-l+1);
             r++;
         }
         return ans;
    }
};