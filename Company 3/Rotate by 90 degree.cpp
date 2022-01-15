void rotate(vector<vector<int> >& a)
{
    int n = a.size();
    for(int i = 0;i<n;i++) // Doing Transpose
    {
        for(int j = 0;j<i;j++)
            swap(a[i][j],a[j][i]);
    }
    for(int i = 0;i<n;i++) // Reversing each column
    {
        int u = 0;
        int b = n-1;
        while(u<b)
        {
            swap(a[u][i],a[b][i]);
            u++;
            b--;
        }
    }
}