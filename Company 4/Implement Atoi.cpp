class Solution{
  public:
    int atoi(string str) 
    {
       int num = 0;
       bool sign = true;
       int i = 0;
       if(str[i] == '-')
       {
           i++;
           sign = false;
       }
       for(;i<str.size();i++)
       {
           if(str[i]>='0' && str[i]<='9')
           {
               int d = str[i]-'0';
               num = num*10+d;
           }
           else
            return -1;
       }
       if(sign == false)
        num = -num;
       return num;
    }
};