#ifndef SORTS_H
#define SORTS_H
#include "operations.h"

template<typename T>
void bubbleSort(T* arr, size_t size, char direction)
{
	for (size_t i = 0; i < size - 1; ++i)
	{
		bool swapped = false;
		for (size_t j = 0; j < size - i - 1; ++j)
		{
			bool condition = (direction == '+' && arr[j] > arr[j + 1]) || (direction == '-' && arr[j] < arr[j + 1]);

			if (condition)
			{
				std::swap(arr[j], arr[j + 1]);
				swapped = true;
			}
		}
		if (!swapped)
			break;
	}
}

template<typename T>
void ShowArray(T* array, int32_t size)
{
	for (int32_t i{}; i < size; ++i)
	{
		std::cout << std::setprecision(10) << array[i] << '\t';
	}
	std::cout << '\n';
}

template <typename T>
void combSort(T* arr, int32_t size, char direction)
{
	if (!arr || size <= 1) return;
	int32_t step{ size * 4 / 5 };
	bool swap{ true };

	while (step > 1 || swap)
	{
		step = step * 4 / 5;
		if (step < 1) step = 1;

		swap = false;
		for (int32_t i = 0; i + step < size; ++i)
		{
			bool condition = (direction == '+' && arr[i] > arr[i + step]) || (direction == '-' && arr[i] < arr[i + step]);

			if (condition)
			{
				std::swap(arr[i], arr[i + step]);
				swap = true;
			}
		}
	}
}

template<typename T>
void insertionSort(T* arr, int32_t size, char direction)
{
	if (!arr || size <= 1) return;
	for (int32_t i = 1; i < size; ++i)
	{
		int32_t j = i - 1;
		while (j >= 0)
		{
			bool condition = (direction == '+' && arr[j] > arr[j + 1]) || (direction == '-' && arr[j] < arr[j + 1]);

			if (!condition) break;

			std::swap(arr[j], arr[j + 1]);
			--j;
		}
	}
}

template<typename T>
int32_t findSmalFromBegin(T* a, int32_t i, int32_t n)
{
	int32_t position{ i };
	for (int32_t k{ i }; k < n; ++k)
	{
		if (a[k] < a[position])
			position = k;
	}
	return position;
}
template<typename T>
int32_t findSmalFromEnd(T* a, int32_t i, int32_t n)
{
	int32_t position{ i };
	for (int32_t k{}; k <= i; ++k)
	{
		if (a[k] < a[position])
			position = k;
	}
	return position;
}
template<typename T>
void selectionSort(T* arr, int32_t size, char direction)
{
	if (!arr || size <= 1) return;

	for (int32_t i = 0; i < size - 1; ++i)
	{
		int32_t minIndex = i;
		for (int32_t j = i + 1; j < size; ++j)
		{
			if ((direction == '+' && arr[j] < arr[minIndex]) || (direction == '-' && arr[j] > arr[minIndex]))
			{
				minIndex = j;
			}
		}
		std::swap(arr[i], arr[minIndex]);
	}
}

template<typename T>
int32_t divide(T* arr, int32_t start, int32_t sup_elem, char direction)
{
	int32_t i{ start };

	while (i < sup_elem)
	{
		bool condition = (direction == '+' && arr[i] > arr[sup_elem]) || (direction == '-' && arr[i] < arr[sup_elem]);

		if (condition && i == sup_elem - 1)
		{
			std::swap(arr[i], arr[sup_elem]);
			--sup_elem;
		}
		else if (condition)
		{
			std::swap(arr[sup_elem - 1], arr[sup_elem]);
			std::swap(arr[i], arr[sup_elem]);
			--sup_elem;
		}
		else
		{
			++i;
		}
	}
	return sup_elem;
}

template<typename T>
void quickSort(T* arr, int32_t start, int32_t end, char direction)
{
	if (start < end)
	{
		int32_t sup_elem = divide(arr, start, end, direction);;

		quickSort(arr, start, sup_elem - 1, direction);
		quickSort(arr, sup_elem + 1, end, direction);
	}
}

template<typename T>
void merge(T* arr, int32_t start, int32_t end, int32_t mid, char direction)
{
	T* merge_array{ new T[end + 1] };
	int32_t i{ start };
	int32_t k{ start };
	int32_t j{ mid + 1 };

	while (i <= mid && j <= end)
	{
		bool condition = (direction == '+' && arr[i] < arr[j]) ||
			(direction == '-' && arr[i] > arr[j]);

		if (condition)
		{
			merge_array[k++] = arr[i++];
		}
		else
		{
			merge_array[k++] = arr[j++];
		}
	}

	while (i <= mid)
	{
		merge_array[k++] = arr[i++];
	}

	while (j <= end)
	{
		merge_array[k++] = arr[j++];
	}

	for (i = start; i < k; ++i)
	{
		arr[i] = merge_array[i];
	}

	delete[] merge_array;
}

template<typename T>
void mergeSort(T* arr, int32_t start, int32_t end, char direction)
{
	int32_t mid{};
	if (start < end)
	{

		mid = (start + end) / 2;
		mergeSort(arr, start, mid, direction);
		mergeSort(arr, mid + 1, end, direction);
		merge(arr, start, end, mid, direction);
	}
}

template<typename T>
void shakerSort(T* arr, int32_t size, char direction)
{
	if (!arr || size <= 1) return;

	int32_t left = 0;
	int32_t right = size;
	bool swap = true;

	while (swap)
	{
		swap = false;

		for (int32_t i = left; i < right - 1; ++i)
		{
			bool condition = (direction == '+' && arr[i] > arr[i + 1]) || (direction == '-' && arr[i] < arr[i + 1]);

			if (condition)
			{
				std::swap(arr[i], arr[i + 1]);
				swap = true;
			}
		}
		--right;

		for (int32_t i = right; i > left; --i)
		{
			bool condition = (direction == '+' && arr[i] < arr[i - 1]) || (direction == '-' && arr[i] > arr[i - 1]);

			if (condition)
			{
				std::swap(arr[i], arr[i - 1]);
				swap = true;
			}
		}
		++left;
	}
}

template <typename T>
T findMin(T* a, int32_t size)
{
	T min = a[0];
	for (int32_t i{}; i < size; ++i)
	{
		if (a[i] < min)
		{
			min = a[i];
		}
	}
	return min;
}
template <typename T>
T findMax(T* a, int32_t size)
{
	T max = a[0];
	for (int32_t i{}; i < size; ++i)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
	}
	return max;
}
template <typename T>
void countSort(T*& arr, int32_t size, char direction)
{
	if (!arr || size <= 1) return;

	T min{ findMin(arr, size) };
	T max{ findMax(arr, size) };
	int32_t range{ static_cast<int32_t>(max - min) + 1 };

	int32_t* counter = new int32_t[range]{};

	for (int32_t i = 0; i < size; ++i)
	{
		counter[static_cast<int32_t>(arr[i] - min)]++;
	}

	int32_t k = 0;

	if (direction == '+') 
	{
		for (int32_t i = 0; i < range; ++i)
		{
			while (counter[i]-- > 0)
			{
				arr[k++] = static_cast<T>(i + min);
			}
		}
	}
	else if (direction == '-') 
	{
		for (int32_t i = range - 1; i >= 0; --i)
		{
			while (counter[i]-- > 0)
			{
				arr[k++] = static_cast<T>(i + min);
			}
		}
	}
	delete[] counter;
}
template <typename T>
void heapify(T* arr, int32_t size, int32_t i, char direction)
{
	int32_t largest = i;
	int32_t left = 2 * i + 1;
	int32_t right = 2 * i + 2;

	if (left < size && arr[left] > arr[largest])
		largest = left;

	if (right < size && arr[right] > arr[largest])
		largest = right;

	if (largest != i) {
		std::swap(arr[i], arr[largest]);
		heapify(arr, size, largest, direction);
	}
}
template <typename T>
void heapSort(T* arr, int32_t size, char direction)
{
	for (int32_t i = size / 2 - 1; i >= 0; --i)
	{
		heapify(arr, size, i, direction);
	}

	for (int32_t i = size - 1; i > 0; --i)
	{
		std::swap(arr[0], arr[i]);
		heapify(arr, i, 0, direction);
	}
}

template<typename T>
bool isSorted(T* arr, int32_t size, char direction)
{
	for (int32_t i = 0; i < size - 1; ++i)
	{
		if ((direction == '+' && arr[i] > arr[i + 1]) ||
			(direction == '-' && arr[i] < arr[i + 1]))
			return false;
	}
	return true;
}
template<typename T>
void fisherYatesShuffle(T* arr, int32_t size)
{
	for (int32_t i = size - 1; i > 0; --i)
	{
		int32_t j = rand() % (i + 1);
		std::swap(arr[i], arr[j]);
	}
}

template<typename T>
void bogoSort(T* arr, int32_t size, char direction)
{
	if (!arr || size <= 1) return;

	srand(static_cast<unsigned>(time(nullptr))); 

	while (!isSorted(arr, size, direction))
	{
		fisherYatesShuffle(arr, size);
	}
}

#endif
