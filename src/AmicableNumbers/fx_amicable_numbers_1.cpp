// AmicableNumbers.cpp : 定义控制台应用程序的入口点。
//
#include <Windows.h>
#include <iomanip>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

typedef unsigned long long ULLONG;
const static unsigned long long MAX_NUMBER = 0xfffff;

ULLONG FX_FactorSum(const ULLONG & number)
{
	ULLONG sum = 1;
	if (number % 2)
	{
		ULLONG n = 3;
		while (n * n < number)
		{
			if (!(number % n))
				sum += n + number / n;
			++++n;
		}
		if (n * n == number)
			sum += n;
	}
	else
	{
		ULLONG n = 2;
		while (n * n < number)
		{
			if (!(number % n))
				sum += n + number / n;
			++n;
		}
		if (n * n == number)
			sum += n;
	}
	return sum;
}

ULLONG factorSumCount = 0;
ULLONG factorSumList[MAX_NUMBER][2] = { 0 };
inline void FX_AddFactorSum(const ULLONG & key, const ULLONG & value)
{
	if (value > 1)
	{
		factorSumList[factorSumCount][0] = key;
		factorSumList[factorSumCount++][1] = value;
	}
}
inline ULLONG FX_FindFactorSum(const ULLONG & number, const ULLONG & start, const ULLONG & end)
{
	if (start > end)
		return 0;

	ULLONG index = (start + end) / 2;
	if (factorSumList[index][0] == number)
		return factorSumList[index][1];
	else if (start == end)
		return 0;
	else if (factorSumList[index][0] > number)
		return FX_FindFactorSum(number, start, index - 1);
	else
		return FX_FindFactorSum(number, index + 1, end);
}
inline ULLONG FX_FindFactorSum(const ULLONG & number)
{
	return FX_FindFactorSum(number, 0, factorSumCount - 1);
}

int main(int argc, char * args[])
{
	ULLONG maxNumber = MAX_NUMBER;
	if (argc > 1)
	{
		if (argc > 2 && strcmp(args[1], "/d") == 0)
		{
			char * strNum = args[2];
			maxNumber = strtoull(strNum, &strNum + sizeof(strNum) / sizeof(strNum[0]), 10);
		}
	}

//	std::vector<std::pair<ULLONG, ULLONG>> ans;

	SYSTEMTIME time;
	GetLocalTime(&time);

	for (ULLONG num = 2; num < maxNumber; ++num)
	{
		ULLONG n = FX_FactorSum(num);
		FX_AddFactorSum(num, n);

		if (n == 1 || n >= num)
			continue;

		ULLONG nfs = FX_FindFactorSum(n);
		if (nfs == num)
		{
			std::cout << num << ", " << n << std::endl;
//			ans.push_back(std::pair<ULLONG, ULLONG>(num, n));
		}
	}

	SYSTEMTIME t;
	GetLocalTime(&t);
	if (t.wMilliseconds >= time.wMilliseconds)
		printf("time:%d.%03d\n", t.wSecond - time.wSecond + (t.wSecond  < time.wSecond ? 60 : 0), t.wMilliseconds - time.wMilliseconds);
	else
		printf("time:%d.%03d\n", t.wSecond - time.wSecond - 1 + (t.wSecond  < time.wSecond + 1 ? 60 : 0), 1000 + t.wMilliseconds - time.wMilliseconds);


// 	std::cout << "Amicable Numbers:" << std::endl;
// 	for (std::size_t i = 0; i < ans.size(); ++i)
// 	{
// 		std::cout << ans[i].first << ", " << ans[i].second << std::endl;
// 	}

	system("pause");
    return 0;
}



// using   namespace   std;
// 
// int   divsum(int);
// const   unsigned   int   INITNUM = 0xffffffff;
// 
// int   main()
// {
// 	int   num_1, num_2;
// 	for (int num_1 = 1; num_1 < INITNUM; ++num_1)
// 	{
// 		num_2 = divsum(num_1);
// 		if (num_1 != num_2)
// 		{
// 			if (num_1 == divsum(num_2))
// 			{
// 				cout << num_1 << " " << num_2 << endl;
// 			}
// 		}
// 	}
// }
// 
// int divsum(int   x)
// {
// 	int   sum = 0;
// 	for (int i = 1; i < x; ++i)
// 	{
// 		if (x   %   i == 0)
// 		{
// 			sum += i;
// 		}
// 	}
// 	return   sum;
// }
