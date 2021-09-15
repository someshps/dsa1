#include <stdio.h>
#include <stdlib.h>
void merge(int arr_res[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int Left_half[n1], Right_half[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        Left_half[i] = arr_res[left + i];
    for (j = 0; j < n2; j++)
        Right_half[j] = arr_res[mid + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0;    // Initial index of first subarray
    j = 0;    // Initial index of second subarray
    k = left; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (Left_half[i] <= Right_half[j])
        {
            arr_res[k++] = Left_half[i++];
        }
        else
        {
            arr_res[k++] = Right_half[j++];
        }
    }

    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1)
    {
        arr_res[k++] = Left_half[i++];
    }

    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2)
    {
        arr_res[k++] = Right_half[j++];
    }
}
void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        //Same as mid = (left+right)/2 but avoids overflow
        int mid = left + (right - left) / 2;
        //Sort left half
        mergeSort(arr, left, mid);
        //Sort right half
        mergeSort(arr, mid + 1, right);
        //Merge the sorted halves
        merge(arr, left, mid, right);
    }
}
int main()
{
    int arr[100] = {0}, arr_size;
    scanf("%d", &arr_size);
    for (int i = 0; i < arr_size; i++)
    {
        scanf("%d", &arr[i]);
    }
    mergeSort(arr, 0, arr_size - 1);

    for (int i = 0; i < arr_size - 1; i++)
        printf("%d ", arr[i]);
    printf("%d", arr[arr_size - 1]);
    return 0;
}