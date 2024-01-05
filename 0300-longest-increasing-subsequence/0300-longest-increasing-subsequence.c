int lengthOfLIS(int* nums, int numsSize) 
{   
    int res[numsSize];
    int len = 0;
    
    for (int i = 0; i < numsSize; i++) 
    {
        int left = 0, right = len;
        
        while (left < right) 
        {
            int mid = left + (right - left) / 2;
            if (res[mid] < nums[i])
                left = mid + 1;
            else
                right = mid;
        }
        
        res[left] = nums[i];
        if (left == len)
            len++;
    }
    
    return len;
}