#include "pch.h"
#include "CppUnitTest.h"
#include "../lab7.2(it).cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TestSearchMaxInRow)
		{
			const int n = 5;
			int row[n] = { 1, 3, 5, 2, 4 };
			int expectedMaxIndex = 2;
			int actualMaxIndex = SearchMaxInRow(row, n);
			Assert::AreEqual(expectedMaxIndex, actualMaxIndex);
		}
		TEST_METHOD(TestSearchMinInRow)
		{
			const int n = 5;
			int row[n] = { 6, 3, 8, 2, 7 };
			int expectedMinIndex = 3;
			int actualMinIndex = SearchMinInRow(row, n);
			Assert::AreEqual(expectedMinIndex, actualMinIndex);
		}
		TEST_METHOD(TestSwapMaxMin)
		{
			const int k = 2;
			const int n = 5;
			int** a = new int* [k];
			for (int i = 0; i < k; i++)
				a[i] = new int[n];
			int row1[n] = { 1, 2, 3, 4, 5 };
			int row2[n] = { 10, 20, 30, 40, 50 };
			for (int i = 0; i < n; i++) {
				a[0][i] = row1[i];
				a[1][i] = row2[i];
			}
			SwapMaxMin(a, k, n);
			Assert::AreEqual(30, a[1][2]);
			Assert::AreEqual(50, a[0][0]);
			for (int i = 0; i < k; i++)
				delete[] a[i];
			delete[] a;
		}
	};
}
