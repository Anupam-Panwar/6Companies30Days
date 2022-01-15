class Solution
{
    public:
    vector<string> ans;
    void compute(string key[], int a[], int start, int N,string temp)
    {
        if(start == N)
        {
            ans.push_back(temp);
            return;
        }
        
        for(char ch : key[a[start]])
        {
            temp.push_back(ch);
            compute(key,a,start+1,N,temp);
            temp.pop_back();
        }
    }
    vector<string> possibleWords(int a[], int N)
    {
        string key[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        compute(key,a,0,N,"");
        return ans;
    }
};