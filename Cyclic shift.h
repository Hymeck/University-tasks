void PrintArr(int *arr)
{
	for (int i = 0; i < ARR_LEN; i++)
		cout << "arr[" << i << "] = " << *(arr + i) << " ";
	cout << endl;
}

void ShiftOneLeft(int *arr)
{
	int first = arr[0], i = 0;
	for (; i < ARR_LEN - 1; i++)
		arr[i] = arr[i + 1];
	arr[i] = first;
}

void ShiftLeft(int *arr, int times)
{
	for (int i = 0; i < times; i++)
	{
		ShiftOneLeft(arr);
		PrintArr(arr);
	}
}

void ShiftOneRight(int *arr)
{
	int last = arr[ARR_LEN - 1], i = ARR_LEN - 1;
	for (; i > 0; i--)
		arr[i] = arr[i - 1];
	arr[i] = last;
}

void ShiftRight(int *arr, int times)
{
	for (int i = 0; i < times; i++)
	{
		ShiftOneRight(arr);
		PrintArr(arr);
	}
}
