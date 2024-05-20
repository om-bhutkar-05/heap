#include<stdio.h>
#include"func.c"
int main()
{
    heap h;
    init(&h, 100);

    insert(&h, 67);
    insert(&h, 57);
    insert(&h, 47);
    insert(&h,95);
    removes(&h);
    print(&h);
}