int numSpecial(int** mat, int matSize, int* matColSize) {

    int specialCount = 0;
    
    int rows = matSize;
    int cols = *matColSize;
    
    //int countX[cols];
    //int countY[rows];
    
    int* countX = (int*)malloc(sizeof(int) * cols);
    int* countY = (int*)malloc(sizeof(int) * rows);
    
    //memset(countX, 0, sizeof(countX));
    //memset(countY, 0, sizeof(countY));
    
    memset(countX, 0, cols * sizeof(int));
    memset(countY, 0, rows * sizeof(int));

    for (int y = 0; y < rows; y++) {
        for (int x = 0; x < cols; x++) {
            if (mat[y][x] == 1) {
                countX[x]++;
                countY[y]++;
            } 
        }
    }
    
    for (int y = 0; y < rows; y++) {
        for (int x = 0; x < cols; x++) {
            
            if (mat[y][x] == 1 && countY[y] == 1 )
            {
                if (countX[x] == 1)
                {
                    specialCount++;
                    break;
                }
                else if (countX[x] > 1)
                {
                    break;
                }
            } 
        }
    }
    
    free(countX);
    free(countY);
    
    return specialCount;
}