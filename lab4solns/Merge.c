#include <stdio.h>

void merge(int arr1[], int n1, int arr2[], int n2, int arr_res[])
{
    int i = 0, j = 0, k = 0;
    //Check which element is smaller and put in the result array
    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
            arr_res[k++] = arr1[i++];
        else
            arr_res[k++] = arr2[j++];
    }
    //Store the remaining element if present from arr1
    while (i < n1)
        arr_res[k++] = arr1[i++];
    //Store the remaining element if present from arr2
    while (j < n2)
        arr_res[k++] = arr2[j++];
}
int main()
{
    int arr1[100] = {0}, arr2[100] = {0}, arr_res[200] = {0}, n1, n2, i;
    //printf("Take two elements");
    scanf("%d ", &n1);
    scanf("%d", &n2);
    //printf("Enter array1 elements\n");
    for (i = 0; i < n1; i++)
    {
        scanf("%d", &arr1[i]);
    }

    //printf("Enter array2 elements\n");
    for (i = 0; i < n2; i++)
    {
        scanf("%d", &arr2[i]);
    }

    merge(arr1, n1, arr2, n2, arr_res);

    for (i = 0; i < n1 + n2 - 1; i++)
    {
        printf("%d ", arr_res[i]);
    }
    //Last element gets printed without space in the end
    printf("%d", arr_res[n1 + n2 - 1]);
}