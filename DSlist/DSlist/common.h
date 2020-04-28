#pragma once

#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable : 4996)

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<stdbool.h>

#define ElemType int

void Swap(ElemType* a, ElemType* b)
{
	ElemType tmp = *a;
	*a = *b;
	*b = tmp;
}