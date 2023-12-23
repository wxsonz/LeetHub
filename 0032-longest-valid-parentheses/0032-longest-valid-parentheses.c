#define max(a, b) ((a) > (b) ? (a) : (b))

int longestValidParentheses(char* s) {
    
    int maxLen = 0;
    
    int* stack = (int*)malloc(sizeof(int) * (strlen(s) + 1));
    int top = -1;
    
    stack[++top] = -1;
    
    for (int i = 0; s[i] != '\0'; i++) {
        
        if (s[i] == '(') {
            
            stack[++top] = i; 
            
        }
        else {
            
            if (top != -1) {
                
                top--; 
                
                if (top != -1) {
                    
                    maxLen = max(maxLen, i - stack[top]); 
                    
                }
                else {
                    stack[++top] = i; 
                }
            }
            else {
                stack[++top] = i;
            }
        }
    }

    free(stack);
    return maxLen;
}