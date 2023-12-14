/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int** onesMinusZeros(int** grid, int gridSize, int* gridColSize, int* returnSize, int** returnColumnSizes) {
    
    int xSize = gridSize;
    int ySize = *gridColSize;
    
    int** diff = (int**)malloc(sizeof(int*) * xSize);
    *returnColumnSizes = (int*)malloc(sizeof(int) * xSize);
    *returnSize = xSize;
    
    int* y1 = (int*)calloc(ySize, sizeof(int));
    int* y0 = (int*)calloc(ySize, sizeof(int)); 
    int* x1 = (int*)calloc(xSize, sizeof(int));
    int* x0 = (int*)calloc(xSize, sizeof(int));
    
    for (int x = 0; x < xSize; x++) {
        
        diff[x] = (int*)malloc(sizeof(int) * ySize);
        (*returnColumnSizes)[x] = ySize;
        
        for (int y = 0; y < ySize; y++) {
            
            if (grid[x][y] == 1)
            {
                x1[x]++;
                y1[y]++;
            }
            else
            {
                x0[x]++;
                y0[y]++;
            }
        }
    }
    
    for (int x = 0; x < xSize; x++){
        for (int y = 0; y < ySize; y++){
            diff[x][y] = x1[x] + y1[y] - x0[x] - y0[y];
        }
    }

    free(y1);
    free(y0);
    free(x1);
    free(x0);

    return diff;
}