/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct {
    int val;
    int index;
} HashTable;

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    
    // check what current_number it need to reach the target and store it
    // go next
    // check what current_number it need to reach the target and store it
    // check if we found any stored_number
    // and when it is found we return that
    
    HashTable* hashTable = (HashTable*)malloc(numsSize * sizeof(HashTable));
    int* result = (int*)malloc(2 * sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];

        for (int j = 0; j < i; j++) {
            if (hashTable[j].val == complement) {
                result[0] = hashTable[j].index;
                result[1] = i;
                *returnSize = 2;
                free(hashTable);
                return result;
            }
        }

        // If the complement does not exist, add the current number to the hash table
        hashTable[i].val = nums[i];
        hashTable[i].index = i;
    }

    free(hashTable);
    return result;
}