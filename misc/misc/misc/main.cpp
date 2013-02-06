#include <iostream>
#include <assert.h>

using namespace std; 

char * MyOwnIOTA(int num);
void myOwnIOTA2(int num, char * str, int len);
int	longestRun(const char * str, char * longestChar);


int main (int argc, char * const argv[])
{
    cout << "Enter Number:\n";
	int num = 0;
	cin >> num;
	cout << "\n";
	// cout << MyOwnIOTA(num) << "\n";
	char * buff = new char(8);
	myOwnIOTA2(num,buff,8);
	cout << buff << "\n";

	system("pause");
	
	char outputChar = 'a';
	longestRun("aabbcccdd", &outputChar);

	system("pause");
	
    return 0;
} 

// Int to string, for a decimal number
char * MyOwnIOTA(int num)
{
	// find ouf how many digits the number has 
	int digits = 0;
	int n = num;
	while (n != 0)
	{
		n /= 10;
		++digits;
	}
	// if number is negative than we need an extra 'digit' for the minus sign
	if (num < 0)
	{
		++digits;
	}
	// the number in string
	char * number = (char *)malloc(sizeof(char)*(digits+1)); // + '\0'
	number[digits] = '\0'; 
	// if number is negative
	if (num < 0)
	{
		// place minus sign
		number[0] = '-';
		// make it positive
		num *= -1;
	}
	// find out which digits
    while (num > 0)
    {
        number[digits-1] = num%10 + '0'; // '0' is Byte value 48
        num /= 10;
        --digits;
    }
	// return the result
	return number;
}


// Int to string, for a decimal number
void myOwnIOTA2(int num, char * str, int len)
{
	assert(len > 0);
	
	int digit = 0;
	int n = num;
	bool neg = false;
	// check if neg
	if (num < 0)
	{
		neg = true;
		n = -num; 
	}
	// convert 
	while (n != 0)
	{
		str[digit] = n%10 + '0';
		n /= 10;
		++digit;
		assert(digit < len);
	}
	if (neg)
	{
		str[digit] = '-';
		++digit;
		assert(digit < len);
	}

	str[digit] = '\0'; 
	
	// swap the string
	int i = 0;
	char temp;
	for(int i = 0; i < digit/2; ++i)
	{
		temp = str[i];
		str[i]	= str[digit - 1 - i];
		str[digit - 1 - i]	= temp;
	}
}

// the longest run of consecutive letters
int	longestRun(const char * str, char * longestChar)
{
	// current char & count
	char current = 0;
	int count = 0;
	// longest count
	int longestCount = 0;
	
	int i = 0;
	// while we are not at the end of the string
	while (str[i] != '\0')
	{
		// first time
		if (current == 0)
		{
			// assign new char and start counting
			current = str[i];
			count = 1;
		}
		// new char
		else if (current != str[i])
		{
			// assign char and start counting
			current = str[i];
			count = 1;
		}
		// same char, keep counting
		else if (current == str[i])
		{
			++count; 	
		}
		
		// if count is greater than what we had before
		if (count > longestCount)
		{
			// then we have a new longer
			longestCount = count;
			*longestChar = current;
		}
		++i;
	}
	
	std::cout << "Most consecutive char is " << *longestChar << ", " << longestCount << " times." << endl;
	
	// return 
	return longestCount;
}

/*

 Do you know the reasons why we would use new over malloc?
 new calls the constructor, which is more a C++ thing.
 it knows about the type of the object and therefore doesnt need to cast 
 new is an operator that can be overriden
 and it throws an exception 


If I wanted to write the function in such a way that it allocated the correct amount of memory internally
and returned the result to the client, how would I do this safely?
Make the function a constructor? 

*/