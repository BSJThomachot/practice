#include <iostream>
#include <assert.h>
#include <string>
#include <cmath>
#include "SmartPtr.h"
#include "BufferOverflowException.h"

using namespace std; 

char * MyOwnITOA(int num);
SmartPtr<char> MyITOA(int num);
// SmartPtr<string> MyITOA(int num);
void myOwnITOA2(int num, char * str, int len);
void mySafeITOA(int num, char * str, int len);
int	longestRun(const char * str, char * longestChar);

void reverseWord(char * str);
void reverse(char * start, char * end);

int findNextPalindrome(int num);
int findNextPalindromeBase(int num, int base);

int findGCD(int a, int b);
int findGCD2(int a, int b);

float angleClock(int hour, int minute);

int countDigit(float decimal);
void deadFraction(float decimal);

int fib1(int n);
int fib2(int n);
bool isPrime(int n);

void reverse(char * str, int len);
void reverse(char * str, int start, int end);

bool isAnagram(char * word, int len1, char * drow, int len2);

int main (int argc, char * const argv[])
{
    
	// // decimal to fraction
	// float decimal = 0;
	// while (decimal != -1)
	// {
	// 	cout << "Enter decimal number: ";
	// 	cin >> decimal;
	// 	deadFraction(decimal);
	// }	
	
	// pick a number
	cout << "Enter Number:\n";
	int num = 0;
	cin >> num;
	cout << "\n";


	// pikc a buffer size 
	bool passed = false;
	while (!passed)
	{
		cout << "Enter a Buffer size:\n";
		int len = 0;
		cin >> len;
		cout << "\n";
		char * buff = new char[len];
		try 
		{
			mySafeITOA(num, buff, len);
			passed = true;
		}
		catch (BufferOverflowException& e)
		{
			cout << "Error: " << e.what() << endl;
			passed = false;
		}
		delete buff; // DONT FORGET TO DELETE!!
	}

	// myOwnITOA2(num,buff,2);
	// cout << buff << "\n";

	SmartPtr<char> result = MyITOA(num);
	// SmartPtr<string> result = MyITOA(num);
	cout << *result << endl;

	system("pause");


	char text[] = "This is a test";
	reverseWord(text);
	cout << text << endl;
	reverse(text,14);
	cout << text << endl;
	reverse(text,0,14);
	cout << text << endl;
	
	
	/*

	system("pause");
	int number = 0;
	while (number != -1)
	{
		cout << "Enter number: ";
		cin >> number;
		int a = findNextPalindromeBase(number,2);
		cout << "next palindrome is " << a << endl;
	}

	system("pause");


	int number1 = 0;
	int number2 = 0;
	while (number1 != -1 && number2 != -1)
	{
		cout << "Enter first number: ";
		cin >> number1;
		cout << endl;
		cout << "Enter second number: ";
		cin >> number2;
		cout << endl;
		int a = findGCD2(number1,number2);
		cout << "Greatest Common Divisor is: " << a << endl;
	}

	system("pause");

	int hour = 0;
	int minute = 0;
	while (hour != -1 && minute != -1)
	{
		cout << "Enter Hour: ";
		cin >> hour;
		cout << endl;
		cout << "Enter Minute: ";
		cin >> minute;
		cout << endl;
		float a = angleClock(hour, minute);
		cout << "Angle between the two hands is: " << a << endl;
	}

	*/
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
char * MyOwnITOA(int num)
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

// Int to string, for a decimal number, using smart pointer
SmartPtr<char> MyITOA(int num)
//SmartPtr<char> MyITOA(int num)
// SmartPtr<string> MyITOA(int num)
{
	char buff[64];
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
		buff[digit] = n%10 + '0';
		n /= 10;
		++digit;
	}
	if (neg)
	{
		buff[digit] = '-';
		++digit;
	}
	// end the text
	buff[digit] = '\0'; 
	
	// swap the string
	int i = 0;
	char temp;
	for(int i = 0; i < digit/2; ++i)
	{
		temp = buff[i];
		buff[i]	= buff[digit - 1 - i];
		buff[digit - 1 - i]	= temp;
	}

	// the number in string
	SmartPtr<char> spNumber(new char(*buff));
	// SmartPtr<string> spNumber(new string(buff));
	return spNumber;
}


// Int to string, for a decimal number
void myOwnITOA2(int num, char * str, int len)
{
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
	}
	if (neg && len > 1)
	{
		str[digit] = '-';
		++digit;
		--len;
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
		throw BufferOverflowException("Buffer Overflow.");
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
		if (digit >= len)
		{
			throw BufferOverflowException("Buffer Overflow.");
		}
	}
	if (neg)
	{
		str[digit] = '-';
		++digit;
		if (digit >= len)
		{
			throw BufferOverflowException("Buffer Overflow.");
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

// reverse a string using iteration
void reverse(char * str, int len)
{
	int i = 0;
	char temp;
	for(int i = 0; i < len/2; ++i)
	{
		temp = str[i];
		str[i]	= str[len - 1 - i];
		str[len - 1 - i]	= temp;
	}
}

// reverse a string using recursion
void reverse(char * str, int start, int end)
{
	if (start < end)
	{
		int i = 0;
		char temp;
		temp = str[start];
		str[start]	= str[end - 1];
		str[start]	= temp;

		reverse(str,start + 1,end - 1);
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
		// add what we have plus the one before
		sum = result + prev;
		// update previous
		prev = result;
		// result is the sum
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

// reverse a string, using a pointer for each edge of the string
void reverse(char * start, char * end)
{	
	char temp;
	while (start < end)
	{
		temp = *start;
		*start++ = *end;
		*end-- = temp;
	}
}

// reverse words
void reverseWord(char * str)
{
	char *start = NULL;
	char *temp = str;
	// we have first to reverse all the words
    while(*temp)
    {
		// make sure we do not start with a space already
		if ((start == NULL) && (*temp != ' '))
        {
            // let's start
			start = temp;
        }
		// if we have a word, or we reach the end of the string
        if(start && ((*(temp+1) == ' ') || (*(temp+1) == '\0')))
        {
            // reverse! 
			reverse(start, temp);
            start = NULL;
        }
		// keep on going through the string
        temp++;
    }
	// Then reverse the result
	reverse(str, temp-1);
}

// find the next palindrome for a decimal number > 0
int findNextPalindrome(int num)
{
	// start with the input number
	int result = num;
	bool palindrome = false;
	// keep going until we find a palimdrome 
	while (!palindrome)
	{
		int n = result;
		int numReversed = 0;
		// reverse number
		while (n > 0)
		{
			int digit = n % 10;
			numReversed = numReversed * 10 + digit;
			n = n / 10;
		}
		// check if they are the same (ie palimdrome)
		if (result == numReversed)
		{
			palindrome = true; // we can stop
		}
		else // otherwise, keep trying, imcrement result
		{
			++result;
		}
	}
	// return the result
	return result;
}

// find the next palindrome for a given base
int findNextPalindromeBase(int num, int base)
{
	// start with the input number
	int result = num;
	bool palindrome = false;
	// keep going until we find a palimdrome 
	while (!palindrome)
	{
		int n = result;
		int numReversed = 0;
		// reverse number
		while (n > 0)
		{
			int digit = n % base;
			numReversed = numReversed * base + digit;
			n = n / base;
		}
		// check if they are the same (ie palimdrome)
		if (result == numReversed)
		{
			palindrome = true; // we can stop
		}
		else // otherwise, keep trying, imcrement result
		{
			++result;
		}
	}
	// return the result
	return result;
}

// find greatest common divisor of A and B, using euclidean algorithm
int findGCD(int a, int b)
{
	int remainder = a % b;
	while (remainder != 0)
	{
		a = b;
		b = remainder;
		remainder = a % b;
	}

	return b;
}

// find greatest common divisor of A and B, using euclidean algorithm (recursively)
int findGCD2(int a, int b)
{
	int remainder = a % b;
	if (remainder == 0)
	{
		return b;
	}
	else
	{
		return findGCD2(b,remainder);
	}
}

// find smallest angle (in degrees) between the two hands of a clock
float angleClock(int hour, int minute)
{
	float angleM = 360.0f/60.0f * minute;
	float angleH = 360.0f/12.0f * hour;
	// since the hour one is not exactly on a number, find out the little extra
	float interval = minute / 60.0f;
	angleH += interval * 360.0f/12.0f;

	float result = abs(angleH - angleM);
	if (result > 180)
	{
		result = 360 - result;
	}

	return result;
}

void deadFraction(float decimal)
{
	float top = decimal;
	float bot = 1;

	int digit = countDigit(decimal);
	float mul = pow(10.0f,digit);

	top *= mul;
	bot *= mul;

	// see if we can divide the numbers, to find the simplest fraction possible
	int div = findGCD((int)top,(int)bot);
	while (div != 1)
	{
		top /= div;
		bot /= div;
		div = findGCD((int)top,(int)bot);
	}

	cout << top << "/" << bot << endl;
}

// count how many digits we have after the decimal point
int countDigit(float decimal)
{
	int count = 0;
	int check = (int)decimal;
	while (decimal - check != 0) // check if there is nothing after decimal point
	{
		decimal *= 10.0f;
		check = (int)decimal;
		count++;
	}

	return count;
}

/* Copy it from Paper to code! 
bool isAnagram(char * word1, int len1, char * word2, int len2)
{
	// check if word1.sort() == word2.sort() 
}

*/