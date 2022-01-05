class Solve {
    int[] findTwoElement(int arr[], int n) 
    {
        int up = n+1;
        for(int i = 0;i<n;i++)
        {
            int num = arr[i] % up;
            arr[num-1]+=up;
        }
        
        int miss = -1;
        int repeat = -1;
        
        for(int i = 0;i<n;i++)
        {
            int t = arr[i]/up;
            if(t == 0)
                miss = i+1;
            else if(t == 2)
                repeat = i+1;
        }
        int ans[] = new int[2];
        ans[0] = repeat;
        ans[1] = miss;
        return ans;
    }
}