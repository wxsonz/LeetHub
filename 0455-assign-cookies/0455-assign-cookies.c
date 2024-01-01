void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int* arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void selectionSort(int* arr, int size)
{
    int minIndex;
    for (int i = 0; i < size - 1; i++)
    {
        minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            swap(&arr[minIndex], &arr[i]);
        }
    }
}

void insertionSort(int* arr, int size)
{
    int key, j;
    for (int i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

typedef void (*SortFunction)(int*, int);

SortFunction selectRandomSort()
{
    int randomNumber = rand() % 3;
    switch (randomNumber)
    {
    case 0:
        return &bubbleSort;
    case 1:
        return &selectionSort;
    case 2:
        return &insertionSort;
    default:
        return &bubbleSort;
    }
}

void sort(int* arr, int size, SortFunction sortingFunction)
{
    sortingFunction(arr, size);
}

int findContentChildren(int* g, int gSize, int* s, int sSize)
{
    SortFunction chosenSort = selectRandomSort();
    sort(g, gSize, chosenSort);
    sort(s, sSize, chosenSort);

    int contentChildren = 0;
    int cookieIndex = 0;

    while (cookieIndex < sSize && contentChildren < gSize)
    {
        if (s[cookieIndex] >= g[contentChildren])
        {
            contentChildren++;
        }
        cookieIndex++;
    }

    return contentChildren;
}