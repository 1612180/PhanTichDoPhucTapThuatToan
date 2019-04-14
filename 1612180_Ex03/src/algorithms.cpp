#include "algorithms.h"

void insertion_sort(vector<int>& arr, int& countAssign, int& countCompare)
{
	int i, j, key, numLength;

	++countAssign;
	numLength = arr.size();

	for (++countAssign, j = 1;
		++countCompare && j < numLength;
		++countAssign, j += 1)
	{
		++countAssign;
		key = arr[j];

		for (++countAssign, i = j - 1;
			(++countCompare && i >= 0) && (++countCompare && arr[i] > key);
			++countAssign, i -= 1)
		{
			++countAssign;
			arr[i + 1] = arr[i];
		}

		++countAssign;
		arr[i + 1] = key;
	}
}

