string encode(string s)
{     
  string ans = "";
  int c = 1;
  int n = s.size();
  for(int i = 0;i<n-1;i++)
  {
     if(s[i] == s[i+1])
        c++;
     else
     {
         ans+=s[i];
         ans+=to_string(c);
         c = 1;
     }
  }
  if(s[n-1]==s[n-2])
  {
      ans+=s[n-1];
      ans+=to_string(c);
  }
  else
  {
      ans+=s[n-1];
      ans+='1';
  }
  return ans;
}  