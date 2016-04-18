#include "sort.h"
#include <math.h>
namespace sort {
	//insert sort
	void InsertSortWithArray(array &a) {
		if (a.length == 0) return;

		Elem guard;
		guard.key = a.r[0].key;
		for (int i = 1; i < a.length; i++) {
			guard.key = a.r[i].key;
			if (a.r[i - 1].key > guard.key) {
				int j;
				for (j = i - 1; j >= 0 && guard.key < a.r[j].key; j--) a.r[j + 1].key = a.r[j].key;
				a.r[j + 1].key = guard.key;
			}
			
		}
	}

	//binary sort
	void BinarySortWithArray(array &a) {
		if (a.length == 0) return;
		Elem guard;
		guard.key = a.r[0].key;

		for (int i = 1; i < a.length; i++) {
			guard.key = a.r[i].key;
			int low = 0;
			int high = i - 1;
			int m;
			while (low <= high) {
				m = (low + high) / 2;
				if (guard.key < a.r[m].key) high = m - 1;
				else low = m + 1;
			}
			for (int j = i - 1; j >= high + 1; j--) a.r[j + 1] = a.r[j];
			a.r[high + 1].key = guard.key;
		}
	}

	//shell insert sort
	void ShellSort(array &a) {
		const int t = 5;
		int delta[t];
		for (int i = 0; i < t; i++) {
			delta[i] = pow(2.0, t - i) - 1;
			ShellInsert(a, delta[i]);
		}
	}
	void ShellInsert(array &a, int dk) {
		Elem tmp;
		for (int i = dk; i < a.length; i++) {
			if (a.r[i].key < a.r[i - dk].key) {
				tmp = a.r[i];
				int j;
				for (j = i - dk; j >= 0 && tmp.key < a.r[j].key; j -= dk) a.r[j + dk] = a.r[j];
				a.r[j + dk] = tmp;
			}
		}
	}



	//bubble sort
	void BubbleSortWithArray(array &a) {
		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < a.length - i - 1; j++) {
				if (a.r[j].key > a.r[j + 1].key) {
					Elem tmp = a.r[j + 1];
					a.r[j + 1] = a.r[j];
					a.r[j] = tmp;
				}
			}
		}
	}

	//quick sort
	void QuickSortWithArray(array &a, int low, int high) {
		if (low < high) {
			int pivotkey = Partion(a, low, high);
			QuickSortWithArray(a, low, pivotkey - 1);
			QuickSortWithArray(a, pivotkey + 1, high);
		}
	}

	int Partion(array &a, int low, int high) {
		Elem pivot = a.r[low];
		while (low < high) {
			while (low < high && a.r[high].key >= pivot.key) high--;
			a.r[low] = a.r[high];
			while (low < high && a.r[low].key <= pivot.key) low++;
			a.r[high] = a.r[low];
		}
		a.r[low] = pivot;
		return low;
	}


	//select sort
	void SelectSortWithArray(array &a) {
		int min = 0;
		for (int i = 0; i < a.length - 1; i++) {
			min = i;
			for (int j = i + 1; j < a.length; j++) {
				if (a.r[j].key < a.r[min].key) min = j;
			}
			Elem tmp = a.r[min];
			a.r[min] = a.r[i];
			a.r[i] = tmp;
		}
	}

	//heap sort
	void HeapSortWithArray(HeapType &H) {
		for (int i = H.length / 2; i > 0; i--) {
			HeapAdjust(H, i, H.length);
		}
		for (int i = H.length; i > 1; i--) {
			Elem tmp;
			tmp = H.r[i];
			H.r[i] = H.r[1];
			H.r[1] = tmp;

			HeapAdjust(H, 1, i - 1);
		}
	}

	void HeapAdjust(HeapType &H, int s, int m) {
		Elem rc = H.r[s];
		for (int j = 2 * s; j <= m; j *= 2) {
			if (j < m && H.r[j].key < H.r[j + 1].key) j++;
			if (rc.key >= H.r[j].key) break;
			H.r[s] = H.r[j];
			s = j;
		}
		H.r[s] = rc;
	}
}