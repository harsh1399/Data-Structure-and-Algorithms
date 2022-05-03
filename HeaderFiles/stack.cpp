#include<iostream>
#include "stack.h"

void stack :: push(int val)
{
    arr[++top] = val;
}
int stack :: pop()
{
    return arr[top--];
}
bool stack :: isEmpty()
{
    return (top==-1)?true:false;
}
bool stack :: isFull()
{
    return (top == size)? true:false;
}