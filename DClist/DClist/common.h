#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable : 4996)
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