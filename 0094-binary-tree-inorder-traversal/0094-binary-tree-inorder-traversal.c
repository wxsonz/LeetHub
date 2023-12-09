/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void inorderTraveler(struct TreeNode* root, int* result, int* index){
    if (root == NULL) return;
    
    inorderTraveler(root -> left, result, index);
    result[(*index)++] = root -> val;
    inorderTraveler(root -> right, result, index);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    
    if (root == NULL) 
    {
        *returnSize = 0;
        return NULL;
    }
    
    int* result = (int*)malloc(sizeof(int) * 100);
    int index = 0;
    
    inorderTraveler(root, result, &index);
    
    *returnSize = index;
    return result;
}

