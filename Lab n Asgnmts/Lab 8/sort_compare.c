#include<string.h>
#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void show(int *a, int n)
{
    for(int i = 0; i < n; i++)
        printf("%d  ", a[i]);
    printf("\n");
}



void swap(int* a, int* b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// SELCTION SORT
void selection_sort(int *a, int s, int n)
{
    n++;
    int i,j, mn;
    
    for (i = 0; i < n - 1; i++)
    {
        mn = i;
        for(j = i + 1; j < n; j++)
            if (a[j] < a[mn])
                mn = j;
        if(mn != i)
            swap(&a[i], &a[mn]);
    }
}
//


// BUBBLE SORT
void bubble_sort(int *a, int s, int n)
{
    n++;
    int i,j;
    bool swaps;
    
    for(i = 0; i < n; i++)
    {
        swaps = false;
        for(j = 0; j < n - i - 1; j++)
        {
            if(a[j] > a[j + 1])
            {
                swap(&a[j], &a[j + 1]);
                swaps = true;
            }
        }
        if(!swaps)
            break;
    }
}
//
void insertion_sort(int *a, int s, int n)
{
    n++;
    int i, key, j;
    for(i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;
        
        while(j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}
//

// MERGE SORT
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m; 
 
    
    int L[n1], R[n2];
 
    
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
     while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 

void merge_sort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
 
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
}
//

// QUICK SORT
int partition(int arr[], int low, int high) 
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) 
    {
        if (arr[j] < pivot) 
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}


void quick_sort(int arr[], int low, int high)
{
    if (low < high) 
    {
        int pivotIndex = partition(arr, low, high);

        quick_sort(arr, low, pivotIndex - 1);
        quick_sort(arr, pivotIndex + 1, high);
    }
}
//


int main(void)
{
    int input[] = {10000, 20000, 30000, 40000, 50000};
    clock_t start, end;

    //     BEST CASE
    printf("BEST CASE SCENARIO\n");
    for (int i = 0; i < 5; i++)
    {
        // for each type of sort
        void (*funcs[])(int* , int, int) = {selection_sort, bubble_sort, insertion_sort, merge_sort, quick_sort};
        for (int j = 0; j < 5; j++)
        {
            int a[input[i]];
            for (int k = 0; k < input[i]; k++)
                a[k] = k + 1;
            
            start = clock();
            (*funcs[j])(a, 0, input[i] - 1);
            end = clock();
            double execTime = ((double) end - start) / CLOCKS_PER_SEC;
            printf("%lf, ", execTime);
        }
        printf("\n");
    }
    
    
    // AVERAGE CASE
    printf("\nAverage CASE SCENARIO\n");
    for (int i = 0; i < 5; i++)
    {
        // for each type of sort
        void (*funcs[])(int* , int, int) = {selection_sort, bubble_sort, insertion_sort, merge_sort, quick_sort};
        for (int j = 0; j < 5; j++)
        {
            int a[input[i]];
            for (int k = 0; k < input[i]; k++)
                a[k] = (int)(clock() * clock()) % input[i];
            
            start = clock();
            (*funcs[j])(a, 0, input[i] - 1);
            end = clock();
            double execTime = ((double) end - start) / CLOCKS_PER_SEC;
//            printf("Execution time of %d is %lf\n",j, execTime);
            printf("%lf, ", execTime);

        }
        printf("\n");
    }
    
    
    
    // WORST CASE
    printf("\nWORST CASE SCENARIO\n");
    for (int i = 0; i < 5; i++)
    {
        // for each type of sort
        void (*funcs[])(int* , int, int) = {selection_sort, bubble_sort, insertion_sort, merge_sort, quick_sort};
        for (int j = 0; j < 4; j++)
        {
            int a[input[i]];
            for (int k = 0; k < input[i]; k++)
                a[k] = input[i] - k;
            
            start = clock();
            (*funcs[j])(a, 0, input[i] - 1);
            end = clock();
            double execTime = ((double) end - start) / CLOCKS_PER_SEC;
//            printf("Execution time of %d is %lf\n",j, execTime);
            printf("%lf, ", execTime);
        }
        printf("\n");
    }
    
    }
