// AmicableNumbers.cpp : 定义控制台应用程序的入口点。
//
// #include "stdafx.h"
// #include <Windows.h>
// #include <iomanip>
// #include <vector>
// #include <unordered_map>
// #include <unordered_set>
// #include <iostream>
// 
// typedef unsigned long ULONG;
// const static unsigned long MAX_ULLONG = 0xffff;
// 
// 
// ULONG FX_FactorSum(const ULONG & number)
// {
// 	ULONG sum = 0;
// 	ULONG num = number / 2;
// 	if (number % 2)
// 	{
// 		for (ULONG n = 1; n <= num; ++++n)
// 		{
// 			if (!(number % n))
// 				sum += n;
// 		}
// 	}
// 	else
// 	{
// 		for (ULONG n = 1; n <= num; ++n)
// 		{
// 			if (!(number % n))
// 				sum += n;
// 		}
// 	}
// 	return sum;
// }
// 
// ULONG factorSumCount = 0;
// ULONG factorSumList[0xffff][2] = { 0 };
// ULONG FX_FindFactorSum(const ULONG & number, ULONG start, ULONG end)
// {
// 	if (start > end)
// 		return 0;
// 
// 	ULONG index = (start + end) / 2;
// 	if (factorSumList[index][0] == number)
// 		return factorSumList[index][1];
// 	else if (start == end)
// 		return 0;
// 	else if (factorSumList[index][0] > number)
// 		return FX_FindFactorSum(number, start, index - 1);
// 	else
// 		return FX_FindFactorSum(number, index + 1, end);
// }
// 
// ULONG FX_FindFactorSumEx(const ULONG & number)
// {
// 	ULONG sum = 0;
// 	ULONG num = number / 2;
// 	if (number % 2)
// 	{
// 		for (ULONG n = 3; n <= num; ++++n)
// 		{
// 			if (!(number % n))
// 			{
// 				ULONG v = number / n;
// 				ULONG nfs = FX_FindFactorSum(v, 0, factorSumCount - 1);
// 				sum += (nfs == 0 ? 1 : nfs) + v;
// 				sum += (v % n) ? n : 0;
// 				break;
// 			}
// 		}
// 	}
// 	else
// 	{
// 		for (ULONG n = 2; n <= num; ++n)
// 		{
// 			if (!(number % n))
// 			{
// 				ULONG v = number / n;
// 				ULONG nfs = FX_FindFactorSum(v, 0, factorSumCount - 1);
// 				sum += (nfs == 0 ? 1 : nfs) + v;
// 				sum += (v % n) ? n : 0;
// 				break;
// 			}
// 		}
// 	}
// 
// 	if (sum)
// 	{
// 		factorSumList[factorSumCount][0] = number;
// 		factorSumList[factorSumCount][1] = sum;
// 		++factorSumCount;
// 	}
// 
// 	return sum;
// }
// 
// int main()
// {
// 	SYSTEMTIME time;
// 	GetLocalTime(&time);
// 
// 	factorSumList[0][0] = 4;
// 	factorSumList[0][1] = FX_FactorSum(4);
// 	++factorSumCount;
// 
// 	for (ULONG num = 5; num < MAX_ULLONG; ++num)
// 	{
// 		ULONG n = FX_FactorSumEx(num);
// #ifdef _DEBUG
// 		ULONG _n = FX_FactorSum(num);
// 		if (n != _n && n != 0)
// 			int x = 0;
// #endif // _DEBUG
// 
// 		if (n == 0 || n >= num)
// 			continue;
// 
// 		ULONG nfs = FX_FindFactorSum(n, 0, factorSumCount - 1);
// 		if (nfs == num)
// 		{
// 			std::cout << num << ", " << n << std::endl;
// 		}
// 	}
// 
// 	SYSTEMTIME t;
// 	GetLocalTime(&t);
// 	std::cout << "time:" << t.wSecond - time.wSecond << ".";
// 	std::cout << std::setw(3) << std::setfill('0') << t.wMilliseconds - time.wMilliseconds << std::endl;
// 
// 	system("pause");
//     return 0;
// }



#include <Windows.h>
#include <iomanip>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

typedef unsigned long long ULLONG;
const static unsigned long long MAX_ULLONG = 0xffffffffffffffff;

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

// ULLONG FX_FactorSumEx(const ULLONG & number)
// {
// 	ULLONG sum = 0;
// 	ULLONG maxFacNum = number / 2;
// 	std::unordered_set<ULLONG> unFactor;
// 	for (ULLONG n = 1; n <= maxFacNum; ++n)
// 	{
// 		if (unFactor.find(n) == unFactor.cend() && number % n == 0 && n != number)
// 		{
// 			sum += n;
// 		}
// 		else
// 		{
// 			for (ULLONG i = 1; i * n < maxFacNum; ++i)
// 				unFactor.insert(n * i);
// 		}
// 
// 	}
// 	return sum;
// }

int main(int argc, char * args[])
{
	ULLONG maxNumber = 0xfffff;
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

	std::unordered_map<ULLONG, ULLONG> factorSumList;
	for (ULLONG num = 2; num < maxNumber; ++num)
	{
		ULLONG n = 0;
		if (factorSumList.find(num) != factorSumList.cend())
		{
			n = factorSumList[num];
		}
		else
		{
			n = FX_FactorSum(num);
		}

		if (n <= num)
			continue;

		ULLONG nfs = FX_FactorSum(n);
		factorSumList[n] = nfs;
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
