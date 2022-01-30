class Solution {
public:
    struct compare // Custom comparator to check the ordering in priority queue
    {
        bool operator()(string a,string b)
        {
            int n = a.size();
            int m = b.size();

            if(n == m)
                return a>b;
            else
                return n>m;
        } 
    };
    string kthLargestNumber(vector<string>& nums, int k) 
    {
        priority_queue<string,vector<string>,compare> pq; // Top of the heap contains maximum element uptil now;
        for(string s : nums)
        {
            pq.push(s);
            if(pq.size()>k)
                pq.pop();
            
        }
        return pq.top();
        
    }
};