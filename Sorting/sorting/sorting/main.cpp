#include <iostream>

using namespace std;

void quickSort(int * nums, int left, int right);
void bubbleSort(int  * nums, int len);
void shakerSort(int * nums, int len); // cocktail shaker sort! 
void mergeSort(int * arr1, int * arr2,int left, int right);
void merge(int * arr1, int * arr2, int left, int pivot, int right);
void shellSort(int * nums, int len);
void oddEvenSort(int * nums, int len);

int main(int argc, char *argv[])
{
	cout << "Hello World!\n";
	system("pause");

	// quicksort
	int nums[] = {12,43,13,5,8,99,11,9,20,17};
    int n = 10; // size of array
	quickSort(nums, 0, n - 1);

	int i;
	for (i = 0; i < n; ++i)
	{
		cout << nums[i] << ", ";
	}
	cout << "\n";


	// merge sort
	int nums2[] = {12,43,13,5,8,99,11,9,20,17}; 
	int const count = sizeof(nums2)/sizeof(int);
	// a temp array used in mergesort
    int nums3[count];
    mergeSort(nums2,nums3,0,count-1);
    for(i = 0; i < count; i++)
	{
        cout<< nums2[i] <<", ";
	}
    cout << "\n";


	// bubble sort
	int nums4[] = {12,43,13,5,8,99,11,9,20,17};
    n = 10; // size of array
	bubbleSort(nums4, n);

	for (i = 0; i < n; ++i)
	{
		cout << nums4[i] << ", ";
	}
	cout << "\n";

	// shell sort
	int nums5[] = {12,43,13,5,8,99,11,9,20,17};
    n = 10; // size of array
	shellSort(nums5, n);

	for (i = 0; i < n; ++i)
	{
		cout << nums5[i] << ", ";
	}
	cout << "\n";

	// odd even sort
	int nums6[] = {12,43,13,5,8,99,11,9,20,17};
    n = 10; // size of array
	oddEvenSort(nums6, n);

	for (i = 0; i < n; ++i)
	{
		cout << nums6[i] << ", ";
	}
	cout << "\n";

	// odd even sort
	int nums7[] = {12,43,13,5,8,99,11,9,20,17};
    n = 10; // size of array
	shakerSort(nums7, n);
	for (i = 0; i < n; ++i)
	{
		cout << nums7[i] << ", ";
	}
	cout << "\n";

	system("pause");

	return 0;
}

void quickSort(int * nums, int left, int right)
{
	int i = left;
	int j = right;
	int tmp;
	int pivot = nums[(left + right) / 2];
 
    // cut array in half, 
    while (i <= j)
	{
		// nums[i] is less than pivot, increment i
		while (nums[i] < pivot)
		{
			++i;
		}
		// input[j] is less than pivot, decrement j
        while (nums[j] > pivot)
		{
			--j;
		}
		// swap and keep going
        if (i <= j)
		{
			tmp = nums[i];
			nums[i] = nums[j];
			nums[j] = tmp;
			++i;
			--j;
         }
      };
 
      // recursively call quicksort on the rest
      if (left < j)
	  {
            quickSort(nums, left, j);
	  }
      if (i < right)
	  {
            quickSort(nums, i, right);
	  }
}

void bubbleSort(int * nums, int len)
{
	bool sorted = false;
	int tmp; // use for swapping
	int j = 0; // use for interation
	while (!sorted) 
	{
		// loop will stop once there will be nothing to sort
		sorted = true;
		++j;
		for (int i = 0; i < len - j; ++i)
		{
			// if higher, swap! 
			if (nums[i] > nums[i + 1])
			{
				tmp = nums[i];
				nums[i] = nums[i + 1];
				nums[i + 1] = tmp;
				sorted = false; // keep on sorting
            }
        }
     }
}

void mergeSort(int * arr1, int * arr2, int left, int right)
{
    // if size isnt 0
	if(left < right) 
    {
        int pivot = (left + right)/2;
		// recursevely call mergesort on both halves of the array
        mergeSort(arr1, arr2, left, pivot);
        mergeSort(arr1, arr2, pivot+1, right);
		// merge the result
        merge(arr1, arr2, left, pivot, right);
    }
}

void merge(int * arr1, int * arr2, int left, int pivot, int right)
{
    int i = left;
    int j = pivot+1;
	int k = left;
	int a; // used for loop

	// merge in a sorted order
    while( (k <= pivot) && (j <= right))
    {
        if(arr1[k] <= arr1[j])
        {
            arr2[i] = arr1[k]; // h is the one we want
            ++k;
        }
        else
        {
            arr2[i] = arr1[j]; // j is the one we want
            ++j;
        }
        ++i;
    }
	// merge the rest in the right array
    if( k > pivot )
    {
        for( a = j; a <= right; ++a)
        {
            arr2[i] = arr1[a];
            ++i;
        }
    }
    else
    {
        for(a = k; a <= pivot; ++a)
        {
            arr2[i] = arr1[a];
            ++i;
        }
    }
	// merge the rest in the left array
    for( a = left; a <= right; ++a)
	{
		arr1[a] = arr2[a];
	}
}

void shellSort(int * nums, int len)
{
	int i;
	int temp;	
	bool sorted = false;
    int gap = len;
	while(!sorted || (gap > 1))
    {
		sorted = true;     
        gap = (gap+1) / 2;
        for (i = 0; i < (len - gap); ++i)
        {
			if (nums[i + gap] < nums[i])
            {
				// swap!
				temp = nums[i + gap];
				nums[i + gap] = nums[i];
				nums[i] = temp;
				sorted = false; // still sorting
             }
         }
     }
}

void oddEvenSort(int * nums, int len)
{
	bool sorted = false;
	int i;
	int temp;
	while(!sorted)
	{
		sorted = true;
		for(i = 1; i < len - 1; i += 2)
		{
			if(nums[i] > nums[i+1])
			{
				// swap(a, i, i+1);
				temp = nums[i + 1];
				nums[i + 1] = nums[i];
				nums[i] = temp;
				sorted = false;
			}
		}
 
		for(i = 0; i < len - 1; i += 2)
		{
		    if(nums[i] > nums[i+1])
		    {
				temp = nums[i + 1];
				nums[i + 1] = nums[i];
				nums[i] = temp;
				sorted = false;
		    }
		}
	}
}


void shakerSort(int * nums, int len)
{
	bool sorted = false;
	int temp;
	int i;
	while (!sorted)
	{
		sorted = true;
		// descending swapping
		for( i = len - 1; i > 0; --i)
		{
			if( nums[i-1] > nums[i] )
			{
				// swap! 
				temp = nums[i-1];
				nums[i-1] = nums[i];
				nums[i] = temp;
				sorted = false;
			}
		}
		// ascending swapping
		for( i = 1; i < len; ++i)
		{
			if( nums[i-1] > nums[i] )
			{
				temp = nums[i-1];
				nums[i-1] = nums[i];
				nums[i] = temp;
				sorted = false;
			}
		}
	}
}

