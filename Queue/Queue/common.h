#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdbool.h>
#include<stdlib.h>

#define ElemType char

void Swap(ElemType* a, ElemType* b)
{
	ElemType tmp = *a;
	*a = *b;
	*b = tmp;
}