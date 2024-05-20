#include "header.h"
int isempty(heap *h)
{
    if (h->rear == -1)
    {
        return 1;
    }
    else
        return 0;
}

int isfull(heap *h)
{
    if (h->size - 1 == h->rear)
    {
        return 1;
    }
    return 0;
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void init(heap *h, int size)
{
    h->rear = -1;
    h->arr = (int *)malloc(size * sizeof(int));
    h->size = size;
}

void insert();
void heapsort(heap *h, int size)
{
    heap h2;
    init(&h2, size);
    for (int i = 0; i < size; i++)
    {
        insert(&h2, h->arr[i]);
    }
    for (int i = 0; i < size; i++)
    {
        h->arr[i] = h2.arr[i];
    }
}
void insert(heap *h, int data)
{
    if (isfull(h))
    {
        return;
    }
    h->rear++;
    int i = h->rear;
    while (i > 0 && data > h->arr[(i - 2) / 2])
    {
        swap(&h->arr[i], &h->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
    h->arr[i] = data;
}

void heapify();

int removes(heap *h)
{
    if (isempty(h))
    {
        return 0;
    }
    int greatest = h->arr[0];
    h->arr[0] = h->arr[h->rear];
    h->rear--;
    heapify(h, 0);
    return greatest;
}
void heapify(heap *h, int dex)
{
    int greatest = dex;
    if (h->arr[dex] < h->arr[2 * dex + 1])
    {
        greatest = 2 * dex + 1;
    }
    if (h->arr[dex] < h->arr[2 * dex + 2])
    {
        greatest = 2 * dex + 2;
    }
    if (greatest != dex)
    {
        swap(&h->arr[dex], &h->arr[greatest]);
        heapify(h, greatest);
    }
}

void print(heap *h)
{
    for (int i = 0; i <= h->rear; i++)
    {
        printf("%d | ", h->arr[i]);
    }
}
