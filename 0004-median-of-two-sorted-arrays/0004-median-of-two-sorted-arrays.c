double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {

    int length = nums1Size + nums2Size;
    int merged[length];
    int i = 0, j = 0, k = 0;

    for (; i < nums1Size && j < nums2Size;)
    {
        if (nums1[i] < nums2[j])
            merged[k++] = nums1[i++];
        else
            merged[k++] = nums2[j++];
    }

    for (; i < nums1Size;)
        merged[k++] = nums1[i++];
    
    for (; j < nums2Size;)
        merged[k++] = nums2[j++];
    
    if (length % 2 ==0)
        return (double)(merged[length/2 - 1] + merged[length/2]) / 2.0;
    else
        return (double)merged[length / 2];
    
}