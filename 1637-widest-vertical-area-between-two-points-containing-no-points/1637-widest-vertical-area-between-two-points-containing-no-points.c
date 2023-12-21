int compare(const void* a, const void* b) {
    return (*(int**)a)[0] - (*(int**)b)[0];
}

int maxWidthOfVerticalArea(int** points, int pointsSize, int* pointsColSize) {
    
    int* xCoordinates = (int*)malloc(sizeof(int) * pointsSize);
    
    for (int i = 0; i < pointsSize; ++i) {
        xCoordinates[i] = points[i][0];
    }
    
    qsort(points, pointsSize, sizeof(int*), compare);

    int res = 0;
    
    for (int i = 1; i < pointsSize; ++i) {
        int diff = points[i][0] - points[i - 1][0];
        res = (diff > res) ? diff : res;
    }
    
    free(xCoordinates);

    return res;
}