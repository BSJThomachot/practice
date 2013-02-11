#include <iostream>
#include <assert.h>
#include <cmath>

using namespace std; 

char * MyOwnITOA(int num);
void myOwnITOA2(int num, char * str, int len);
void mySafeITOA(int num, char * str, int len);
int	longestRun(const char * str, char * longestChar);


int fib1(int n);
int fib2(int n);
bool isPrime(int n);

int main (int argc, char * const argv[])
{
    cout << "Enter Number:\n";
	int num = 0;
	cin >> num;
	cout << "\n";

	// cout << MyOwnIOTA(num) << "\n";

	char * buff = new char(2);
	myOwnITOA2(num,buff,2);
	cout << buff << "\n";

	try 
	{
		mySafeITOA(num, buff, 8);
	}
	catch (const char* msg)
	{
		cout << "Error: " << msg << endl;
	}

	system("pause");

	/*
	char outputChar = 'a';
	longestRun("aabbcccdd", &outputChar);

	system("pause");
	int number = 0;
	cout << "Enter number: ";
	cin >> number;
	while (number != 0)
	{
		if (isPrime(number))
		{		
			cout << "Prime! \n";
		}
		else
		{
			cout << "Not Prime! \n";
		}
		cout << "Enter number: ";
		cin >> number;
	};
	*/
	
    return 0;
} 

// Int to string, for a decimal number
char * MyOwnIT0A(int num)
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
void myOwnITOA2(int num, char * str, int len)
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
	while (n != 0 && len > 1)
	{
		str[digit] = n%10 + '0';
		n /= 10;
		++digit;
		--len;
		// assert(digit < len);
	}
	if (neg && len > 1)
	{
		str[digit] = '-';
		++digit;
		--len;
		// assert(digit < len);
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

// Int to string, for a decimal number
void mySafeITOA(int num, char * str, int len)
{
	if (len <= 0)
	{
		throw "Buffer too small";
	}
	
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
		if (digit < len)
		{
			throw "Buffer too small";
		}
	}
	if (neg)
	{
		str[digit] = '-';
		++digit;
		if (digit < len)
		{
			throw "Buffer too small";
		}
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

// recursive version of fibonacci
int fib1(int n)
{
	if (n == 0)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}
	// recursively call  2 previous number
	return fib1(n - 1) + fib1(n - 2);
}

// fib using iteration
int fib2(int n)
{
	int prev = -1;
	int result = 1;
	int sum;
	
	int i;
	for(i = 0; i <= n; ++i)
	{
		sum = result + prev;
		prev = result;
		result = sum;
	}
	return result;
}

bool isPrime(int n)
{
	// first prime is 2
	if (n < 2)
	{
		return false;
	}
	else
	{
		// get square root
		int m = (int)sqrt((float)n);
		// see if n can be diveded by numbers less tran its square root
		int i = 0;
		for (i = m; i >= 2; --i)
		{
			if (n % i == 0)
			{
				return false;
			}
		}
		return true;
	}
}

/*

5.
The valid range of buffer length is already inherently built into your algorithm.  
It is more elegant, clear and robust if you build your algorithm in a way so that it implicitly handles all values of this input variable.
Rewrite your algorithm in a way that it does not have to explicitly check the value of len.
 
6.
Rewrite your itoa function so that it delegates the responsibility of error handling back to the caller.
 
7.
Write a new version of your itoa function so that it uses C++ exception handling.  
Show how the client code would be structured to handle the exceptions.

*/