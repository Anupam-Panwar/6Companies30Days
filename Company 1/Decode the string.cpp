class Solution{
public:
    string decodedString(string s)
    {
        string ans = "";
        stack<char> st;
        for(char ch : s)
        {
            if(ch != ']')
                st.push(ch);
            else
            {
                string temp = "";
                while(st.top() != '[')
                {
                    temp = st.top() + temp;
                    st.pop();
                }
                st.pop();
                
                string nu = "";
                while(st.empty() == false && st.top()>='0' && st.top()<='9')
                {
                    nu += st.top();
                    st.pop();
                }
                
                reverse(nu.begin(),nu.end());
                int num = stoi(nu);
                
                string tt = "";
                for(int i = 0;i<num;i++)
                    tt+=temp;
                
                for(char ch : tt)
                    st.push(ch);
            }
        }
    
        while(st.empty() == false)
        {
            ans = st.top() + ans;
            st.pop();
        }
        
        return ans;
    }
};