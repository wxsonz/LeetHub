int findSpecialInteger(int* arr, int arrSize) {
    
    int mainNumCount = 1, subNumCount = 0;
    int mainNum = arr[0], subNum = 0;
    
    for (int i = 1; i < arrSize; i++)
    {
        if (mainNum == arr[i]) 
        {
            mainNumCount++;
            if (mainNumCount > arrSize / 4) return mainNum;
        }
        
        else 
        {
            subNum = arr[i];
            subNumCount = 1;
            
            if (subNumCount > arrSize / 4) return subNum;
            
            mainNum = arr[i];
            mainNumCount = 1;
        }
    }
    
    return mainNum;
    
}