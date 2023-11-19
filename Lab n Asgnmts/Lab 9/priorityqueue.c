#include<string.h>
#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_SIZE 50

int H[MAX_SIZE];
int size = -1;

// Function to return the index of the parent node of a given node
int parent(int i) 
{ return (i - 1) / 2; }

// Function to return the index of the left child of the given node
int leftChild(int i) 
{ return (2 * i) + 1; }

// Function to return the index of the right child of the given node
int rightChild(int i) 
{ return (2 * i) + 2; }

// Function to swap two elements in the heap
void swap(int i, int j) 
{
    int temp = H[i];
    H[i] = H[j];
    H[j] = temp;
}

// Function to shift up the node in order to maintain the heap property
void shiftUp(int i) 
{
    while (i > 0 && H[parent(i)] < H[i]) 
    {
        swap(parent(i), i);
        i = parent(i);
    }
}

// Function to shift down the node in order to maintain the heap property
void shiftDown(int i)
{
    int maxIndex = i;
    int l = leftChild(i);

    if (l <= size && H[l] > H[maxIndex])
        maxIndex = l;

    int r = rightChild(i);

    if (r <= size && H[r] > H[maxIndex])
        maxIndex = r;

    if (i != maxIndex) 
    {
        swap(i, maxIndex);
        shiftDown(maxIndex);
    }
}

// Function to insert a new element into the Binary Heap
void insert(int p) 
{
    size = size + 1;
    H[size] = p;
    shiftUp(size);
}

// Function to extract the element with the maximum priority
int extractMax(void)
{
    int result = H[0];
    H[0] = H[size];
    size = size - 1;
    shiftDown(0);
    return result;
}

// Function to change the priority of an element
void changePriority(int i, int p) 
{
    int oldp = H[i];
    H[i] = p;

    if (p > oldp)
        shiftUp(i);
    else
        shiftDown(i);
}

// Function to get the value of the current maximum element
int getMax(void)
{ return H[0]; }

// Function to remove the element located at a given index
void removeElement(int i) 
{
    H[i] = getMax() + 1;
    shiftUp(i);
    extractMax();
}

int main(void)
{
    insert(45);
    insert(20);
    insert(14);
    insert(12);
    insert(31);
    insert(7);
    insert(11);
    insert(13);
    insert(7);

    printf("Priority Queue: ");
    for (int i = 0; i <= size; i++) {
        printf("%d ", H[i]);
    }
    printf("\n");

    printf("Node with maximum priority: %d\n", extractMax());

    printf("Priority Queue after extracting maximum: ");
    for (int i = 0; i <= size; i++) {
        printf("%d ", H[i]);
    }
    printf("\n");

    changePriority(2, 49);
    printf("Priority Queue after priority change: ");
    for (int i = 0; i <= size; i++) {
        printf("%d ", H[i]);
    }
    printf("\n");

    removeElement(3);
    printf("Priority Queue after removing the element: ");
    for (int i = 0; i <= size; i++) {
        printf("%d ", H[i]);
    }
    printf("\n");

    return 0;
}
