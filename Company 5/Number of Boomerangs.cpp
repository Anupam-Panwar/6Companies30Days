class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) 
    {
        int ans = 0;
        int n = points.size();
        unordered_map<int,unordered_map<int,int>> mp; // <index,unordered_map<distance,count>>
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(i == j)
                    continue;
                int d = pow((points[i][0]-points[j][0]),2) +  pow((points[i][1]-points[j][1]),2);
                mp[i][d]++;
            }
        }
        // nPr : where order also matters
        // nCr : where order doesn't matters
        for(auto i : mp)
        {
            for(auto j : i.second)
            {
                int temp = j.second;
                if(temp>=2)
                    ans+=(temp*(temp-1));
            }
        }
        return ans;
    }
};