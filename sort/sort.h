#ifndef _SORT_H_
#define _SORT_H_
namespace sort {
#define MAXSIZE 20
	typedef int KeyType;
	typedef char* InfoType;
	typedef struct {
		KeyType key;
		InfoType info;
	}Elem;
	typedef struct {
		Elem r[MAXSIZE];
		int length;
	}array;
	/*********************** insert sort ***************************/
	//direct insert sort
	void InsertSortWithArray(array &a);

	//binary insert sort
	void BinarySortWithArray(array &a);
	
	//shell insert sort
	void ShellSort(array &a);
	void ShellInsert(array &a, int dk);

	/*********************** swap sort ***************************/
	//bubble sort
	void BubbleSortWithArray(array &a);

	//quick sort
	void QuickSortWithArray(array &a, int low, int high);
	int Partion(array &a, int low, int high);

	/*********************** select sort ***************************/
	//select sort
	void SelectSortWithArray(array &a);

	//heap sort
	typedef struct {
		Elem r[MAXSIZE + 1];
		int length;
	}HeapType;
	void HeapSortWithArray(HeapType &H);
	void HeapAdjust(HeapType &H, int s, int m);

}
#endif //_SORT_H_