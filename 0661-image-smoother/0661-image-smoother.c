/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int** imageSmoother(int** img, int imgSize, int* imgColSize, int* returnSize, int** returnColumnSizes) {
    int rows = imgSize;
    int cols = *imgColSize;

    int** result = (int**)malloc(rows * sizeof(int*));
    *returnColumnSizes = (int*)malloc(rows * sizeof(int));

    for (int i = 0; i < rows; i++) {
        result[i] = (int*)malloc(cols * sizeof(int));
        (*returnColumnSizes)[i] = cols;
    }

    int directions[3] = {-1, 0, 1};

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int total = 0, count = 0;
            
            for (int dx = 0; dx < 3; dx++) {
                for (int dy = 0; dy < 3; dy++) {
                    int newRow = i + directions[dx];
                    int newCol = j + directions[dy];
                    
                    if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) {
                        total += img[newRow][newCol];
                        count++;
                    }
                }
            }
            
            result[i][j] = total / count;
        }
    }

    *returnSize = rows;
    return result;
}