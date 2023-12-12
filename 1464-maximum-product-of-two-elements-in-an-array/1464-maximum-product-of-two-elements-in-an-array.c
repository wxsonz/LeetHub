int maxProduct(int* nums, int numsSize) {
    
    //extra monke code
    
    int num1 = nums[0], num2 = nums[1];
    
    if (numsSize == 2)
        return (num1 - 1) * (num2 - 1);
    
    if (num2 > num1) {
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }
    
    for (int i = 2; i < numsSize; i++) {
        if (nums[i] > num2) {
            if (nums[i] >= num1) {
                num2 = num1;
                num1 = nums[i];
            } 
            else {
                num2 = nums[i];
            }
        }
    }
    
    return (num1 - 1) * (num2 - 1);
}