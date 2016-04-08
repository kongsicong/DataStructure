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

	void InsertSortWithArray(array &a);
	void BinarySortWithArray(array &a);
}
#endif //_SORT_H_