#include <iostream>

using namespace std;

void quickSort(int * arr, int left, int right);
void mergeSort(int * arr1, int * arr2,int left, int right);
void merge(int * arr1, int * arr2, int left, int pivot, int right);

int main(int argc, char *argv[])
{
	cout << "Hello World!\n";
	system("pause");

	// quicksort
	int nums[] = {12,43,13,5,8,10,11,9,20,17};
    int n = 10; // size of array
	quickSort(nums, 0, n - 1);

	int i;
	for (i = 0; i < n; ++i)
	{
		cout << nums[i] << ", ";
	}
	cout << "\n";


	// merge sort
	int nums2[] = {12,43,13,5,8,10,11,9,20,17}; 
	int const count = sizeof(nums2)/sizeof(int);
	// a temp array used in mergesort
    int nums3[count];

    mergeSort(nums2,nums3,0,count-1);
    for(i = 0; i < count; i++)
	{
        cout<< nums2[i] <<", ";
	}
    cout << "\n";


	system("pause");

	return 0;
}

void quickSort(int * arr, int left, int right)
{
	int i = left;
	int j = right;
	int tmp;
	int pivot = arr[(left + right) / 2];
 
    // cut array in half, 
    while (i <= j)
	{
		// arr[i] is less than pivot, increment i
		while (arr[i] < pivot)
		{
			++i;
		}
		// arr[j] is less than pivot, decrement j
        while (arr[j] > pivot)
		{
			--j;
		}
		// swap and keep going
        if (i <= j)
		{
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			++i;
			--j;
         }
      };
 
      // recursively call quicksort on the rest
      if (left < j)
	  {
            quickSort(arr, left, j);
	  }
      if (i < right)
	  {
            quickSort(arr, i, right);
	  }
}


void mergeSort(int * arr1, int * arr2, int left, int right)
{
    if(left < right)
    {
        int pivot = (left+right)/2;
		// recursevely call mergesort on both halves of the array
        mergeSort(arr1,arr2,left,pivot);
        mergeSort(arr1,arr2,pivot+1,right);
		// merge the result
        merge(arr1,arr2,left,pivot,right);
    }
}

void merge(int * arr1, int * arr2, int left, int pivot, int right)
{
    int k;
    int h = left;
    int i = left;
    int j = pivot+1;

    while((h<=pivot)&&(j<=right))
    {
        if(arr1[h]<= arr1[j])
        {
            arr2[i]=arr1[h];
            h++;
        }
        else
        {
            arr2[i]=arr1[j];
            j++;
        }
        i++;
    }
    if(h>pivot)
    {
        for(k=j; k<=right; k++)
        {
            arr2[i]=arr1[k];
            i++;
        }
    }
    else
    {
        for(k=h; k<=pivot; k++)
        {
            arr2[i]=arr1[k];
            i++;
        }
    }
    for(k=left; k<=right; k++)
	{
		arr1[k] = arr2[k];
	}
}

