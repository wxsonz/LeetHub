char* largestOddNumber(char* num) {
    
    // the concept
    // find index of odd number from backward
    // copy fron num to new num until that found index
    
    int length = strlen(num);
    
    // further optimization
    // for the case that last odd index is at the last character
    if ((num[length - 1] - '0') % 2 == 1)
        return num;
    
    // if not then skip the last character
    int odd_index = length - 2;
    
    // +2 to compensate the length we -2 and reserve space for '\0'
    char* new_num = malloc(odd_index + 2);
    
    for (; odd_index >= 0; odd_index--)
        if (num[odd_index] % 2 == 1) 
            break;
        
    strncpy(new_num, num, odd_index + 1);
    new_num[odd_index + 1] = '\0';
    
    return new_num;
}