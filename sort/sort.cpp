#include "sort.h"

namespace sort {
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
}