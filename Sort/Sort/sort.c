#include"sort.h"
void main()
{
	//int ar[] = {10, 6, 7, 1, 3, 9, 4, 2};
	//int ar[] = {49, 38, 5, 65, 97, 76, 13, 27, 49};
	//int ar[] = {12482, 15804, 6044, 10888, 26446, 2762, 9119, 23855, 14976, 508};
	//int ar[] = {0, 49, 38, 65, 97, 76, 13, 27, 49}; //ÉÚ±øÊý¾Ý
	int ar[] = { 278, 109, 63, 930, 589, 184, 505, 269, 8, 83 };
	int n = sizeof(ar) / sizeof(ar[0]);
	PrintElement(ar, 0, n);
	TestSort(ar, 0, n);
	PrintElement(ar, 0, n);
	TestSortEfficiency();
}