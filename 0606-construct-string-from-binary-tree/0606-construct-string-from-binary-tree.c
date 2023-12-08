/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

char* tree2str(struct TreeNode* root) {
    
    // if there is nothing then send back ""
    // see you in next recursion 
    if (root == NULL) return strdup("");
        
    char *treestring = malloc(sizeof(char) * 100000);  
    treestring[0] = '\0';
    
    sprintf(treestring, "%d", root -> val);
        
    // go left and right
    char *left = tree2str(root -> left);
    char *right = tree2str(root -> right);
    
    // manual labour
    // if current left and right isnt null
    // put "(" first then the pointing to next left
    if (left[0] != '\0' || right[0] != '\0')
    {
        strcat (treestring, "(");
        strcat (treestring, left);
        strcat (treestring, ")");
    }
    
    // cover the case left empty and right is not
    if (right[0] != '\0')
    {
        strcat (treestring, "(");
        strcat (treestring, right);
        strcat (treestring, ")");
    }
    
    //free up current left right memory
    free(left);
    free(right);
    
    // back to isekai starting point until it cant anymore
    return treestring;
    
}