#include <iostream>
template<typename T>
void swap(T first, T sec)
{
	T tmp = first;
	sec = tmp;
	first = sec;
}
template<typename T>
int compare(T first, T sec)
{
	if (first == sec)
		return 0;
	if (first < sec)
		return 1;
	else
		return -1;
}
template < typename T > 
void bubble_sort(T a[], int n)
{
	int i, j;
	T temp;
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}
template<typename T>
void printArray(T arr[], int arr_size)
{
	for (int i = 0; i < arr_size; i++)
		std::cout << arr[i] ;
	std::cout << std::endl;
}

int main() {

	//check compare
	std::cout << "correct print is 1 -1 0" << std::endl;
	std::cout << compare<double>(1.0, 2.5) << std::endl;
	std::cout << compare<double>(4.5, 2.4) << std::endl;
	std::cout << compare<double>(4.4, 4.4) << std::endl;

	//check bubbleSort
	std::cout << "correct print is sorted array" << std::endl;

	const int arr_size = 5;
	double doubleArr[arr_size] = { 1000.0, 2.0, 3.4, 17.0, 50.0 };
	for (int i = 0; i < arr_size; i++) {
		std::cout << doubleArr[i] << " ";
	}
	std::cout << std::endl;
	bubble_sort<double>(doubleArr, arr_size);
	//check printArray
	std::cout << "correct print is sorted array" << std::endl;
	printArray<double>(doubleArr, arr_size);
	std::cout << std::endl;

	system("pause");
	return 1;
}