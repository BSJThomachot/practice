#include <iostream>

using namespace std;

void quickSort(int * arr, int left, int right);

int main(int argc, char *argv[])
{
	cout << "Hello World!\n";
	system("pause");

	int nums[] = {12,43,13,5,8,10,11,9,20,17};
    int n = 10; // size of array
	quickSort(nums, 0, n - 1);

	int i;
	for (i = 0; i < n; ++i)
	{
		cout << nums[i] << ", ";
	}
	cout << "\n";
	system("pause");

	return 0;
}

void quickSort(int * arr, int left, int right)
{
      int i = left, j = right;
      int tmp;
      int pivot = arr[(left + right) / 2];
 
      /* partition */
      while (i <= j)
	  {
		while (arr[i] < pivot)
		{
			i++;
		}
        while (arr[j] > pivot)
		{
			j--;
		}
        if (i <= j)
		{
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
         }
      };
 
      /* recursion */
      if (left < j)
	  {
            quickSort(arr, left, j);
	  }
      if (i < right)
	  {
            quickSort(arr, i, right);
	  }
}
