
#include <iostream>

using namespace std;

namespace MyLib
{
	float* initArr(short size)
	{
		float* arr = new float[size];
		for (size_t i = 0; i < size; i++)
		{
			arr[i] = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 1000));
			arr[i] = rand() % 1000 > 500 ? arr[i] : arr[i] * -1; // Умножаем случайные числа на -1, чтобы были отрицательные
		}

		return arr;
	}

	void printArr(float* arr, short size)
	{
		cout << arr[0];
		for (size_t i = 1; i < size; i++)
		{
			cout << " " << arr[i];
		}

		cout << endl;
	}

	void printArr(int* arr, short size)
	{
		cout << arr[0];
		for (size_t i = 1; i < size; i++)
		{
			cout << " " << arr[i];
		}

		cout << endl;
	}

	void positiveAndNegativeCount(float* arr, short size)
	{
		int pos = 0, neg = 0;

		for (size_t i = 0; i < size; i++)
		{
			if (arr[i] >= 0)
			{
				pos++;
			}
			else
			{
				neg++;
			}
		}

		cout << "Positive: " << pos << endl << "Negative: " << neg << endl;
	}

	#define SWAP_INT(x, y) std::swap(x, y)
	void sortArr(int* arr, short size)
	{
		for (size_t i = 0; i < size - 1; i++)
		{
			for (size_t j = 0; j < size - i - 1; j++)
			{
				if (arr[j] > arr[j + 1])
				{
					SWAP_INT(arr[j], arr[j + 1]);
				}
			}
		}
	}
}



