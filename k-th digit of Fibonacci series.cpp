#include <iostream>
#include <cmath>

using namespace std;

// counts digit quantity
int DigitNum(int n);
// reverses a number
int RevNumber(int num);
// determines a k-th digit
void Digit(int revNumber, int &digit, int &k, int &digitCounter);
// Fibonacci numbers; prints k-th digit 
void PrintFiboDigit(int k);

int main()
{
	int k;
	cout << "Input k-th digit of Fibonacchi series you want to see: ";
	cin >> k;
	PrintFiboDigit(k);
	cout << endl;
	system("pause");
	return 0;
}

int DigitNum(int n)
{
	int counter = 0;
	while (n)
	{
		counter++;
		n /= 10;
	}
	return counter;
}

int RevNumber(int num)
{
	int digitNum = DigitNum(num), result = 0;

	// 123 -> 3*10^2 + 2*10^1 + 1*10^0 = 321

	for (int i = digitNum - 1; i >= 0; i--)
	{
		int last = num % 10;
		num /= 10;
		result += last * (int)powf(10., (float)i);
	}

	return result;
}


void Digit(int revNumber, int &digit, int &k, int &digitCounter)
{
	while (revNumber)
	{
		if (digitCounter == k)
			break;
		digitCounter++;
		digit = revNumber % 10; // last digit
		revNumber /= 10;
	}
}

void PrintFiboDigit(int k)
{
	int first = 0, second = 1, third = first + second;

	int digit = 0, // final digit 
		digitCounter = 0; // variable for checking k-th digit
	while (digitCounter < k)
	{
		cout << second << " ";
		Digit(RevNumber(second), digit, k, digitCounter);
		/*
			F0 = 0;
			F1 = 1;
			Fn = Fn-1 + Fn-2
		*/
		first = second;
		second = third;
		third = first + second;
	}

	if (digit)
		cout << endl << k << "-th digit is " << digit << endl;
}
