int numSpecial(int** mat, int matSize, int* matColSize) {

    int specialCount = 0;
    
    int rows = matSize;
    int cols = *matColSize;
    
    int countX[cols];
    int countY[rows];
    
    memset(countX, 0, sizeof(countX));
    memset(countY, 0, sizeof(countY));

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
            if (mat[y][x] == 1 && countY[y] == 1 && countX[x] == 1) {
                specialCount++;
            }
        }
    }
    
    return specialCount;
}