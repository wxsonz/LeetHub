char* largestOddNumber(char* num) {
    
    // the concept
    // find index of odd number from backward
    // copy fron num to new num until that found index
    
    int odd_index, length = strlen(num);
    
    // for the case that last odd index is at the last character
    if ((num[length - 1] - '0') % 2 == 1)
        return num;
    
    char* new_num = malloc(length + 1);
    
    for (odd_index = length - 1; odd_index >= 0; odd_index--)
        if (num[odd_index] % 2 == 1) 
            break;
        
    strncpy(new_num, num, odd_index + 1);
    new_num[odd_index + 1] = '\0';
    
    return new_num;
}