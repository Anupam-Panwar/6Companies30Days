string decimalToBinary(int n)
{
    string ans = "";
    while(n>0)
    {
        int d = n%2;
        n/=2;
        ans = to_string(d) + ans;
    }
    return ans;
}
vector<string> generate(int N)
{
    vector<string> ans;
    for(int i = 1;i<=N;i++)
        ans.push_back(decimalToBinary(i));
    return ans;
}