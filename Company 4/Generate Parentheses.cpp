class Solution
{
    public:
    vector<string> ans;
    void generate(int n,string str,int a, int b)
    {
        if(str.size() == (2*n))
        {
            if(a == b)
                ans.push_back(str);
            
            return;
        }
        str+='(';
        a++;
        //cout<<str<<" "<<a<<" "<<b<<" -> ";
        generate(n,str,a,b);
        str.pop_back();
        a--;
        //cout<<str<<" "<<a<<" "<<b<<"\n\n";
        
        
        b++;
        if(b>a)
            return;
        str+=')';

        //cout<<str<<" "<<a<<" "<<b<<" -> ";
        generate(n,str,a,b);
        //cout<<str<<" "<<a<<" "<<b<<"\n\n";
    }
    vector<string> AllParenthesis(int n) 
    {
        ans.clear();
        generate(n,"",0,0);
        return ans;
    }
};