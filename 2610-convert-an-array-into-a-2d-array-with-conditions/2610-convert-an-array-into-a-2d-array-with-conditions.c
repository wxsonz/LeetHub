/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** findMatrix(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    int maxNum = 0;
    for (int i = 0; i < numsSize; ++i) 
    {
        if (nums[i] > maxNum) maxNum = nums[i];
    }

    int* freq = (int*)calloc(maxNum + 1, sizeof(int));

    int** ans = (int**)malloc(numsSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(numsSize * sizeof(int));
    *returnSize = 0;

    for (int i = 0; i < numsSize; ++i) 
    {
        int c = nums[i];
        if (freq[c] >= *returnSize) 
        {
            ans[*returnSize] = (int*)malloc(numsSize * sizeof(int));
            (*returnColumnSizes)[*returnSize] = 0;
            (*returnSize)++;
        }

        ans[freq[c]][(*returnColumnSizes)[freq[c]]++] = c;
        freq[c]++;
    }

    free(freq);
    return ans;
}