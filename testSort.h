#ifndef _TEST_SORT_H_
#define _TEST_SORT_H_
#include "sort/sort.h"
using namespace sort;

void testSort();

void testInsertSortWithArray();
void testBinarySortWithArray();
void testShellSortWithArray();
void testBubbleSortWithArray();
void testQuickSortWithArray();
void testSelectSortWithArray();
void testHeapSortWithArray();

void createArray(array &a);
void printArray(array &a);
void createArray(HeapType &H);
void printArray(HeapType &H);
#endif //_TEST_SORT_H_