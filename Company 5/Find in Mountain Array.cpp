/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int binarySearchInc(int target, MountainArray &arr, int start, int end)
    {
        int low = start;
        int high = end;
        
        while(low <= high)
        {
            int mid = (low + high)/2;
            
            int ele = arr.get(mid);
            if(ele == target)
                return mid;
            else if(ele > target) 
                high = mid - 1;
            else 
                low = mid + 1;
        }
        return -1;
    }
    int binarySearchDesc(int target, MountainArray &arr, int start, int end)
    {
        int low = start;
        int high = end;
        
        while(low <= high)
        {
            int mid = (low + high)/2;
            
            int ele = arr.get(mid);
            if(ele == target)
                return mid;
            else if(ele > target) 
                low = mid + 1;
            else 
                high = mid - 1;
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &arr) 
    {
        int n = arr.length();
        
        int start = 0;
        int end = n-1;
        int peak = -1;
        
        while(start <= end)
        {
            int mid = (start + end)/2;
            
            int pre = -1;
            int post = -1;
            int ele = -1;
            
            ele = arr.get(mid);
            
            if(mid - 1 >= 0) 
                pre = arr.get(mid-1);
            if(mid + 1 < n) 
                post = arr.get(mid+1);
            
            if(ele > pre and ele > post)
            {
                peak = mid;
                if(ele == target) 
                    return mid;
                break;
            }
            else if(ele > pre)  
            {
                start = mid + 1;
            }
            else 
            {
                end = mid - 1;
            }
        }
        
        int n1 = binarySearchInc(target,arr,0,peak-1);
        if(n1 != -1)
            return n1;
        
        int n2 = binarySearchDesc(target,arr,peak+1,n-1);
        return n2;
        
    }
};