// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;
int length;
int values[300];
int DP[300] = { 0 };
int main()
{
	cin >> length;
	for (int i = 0; i < length; i++)
	{
		cin >> values[i];
	}
	DP[0] = values[0];
	DP[1] = values[0] + values[1];
	if (values[1] > values[0])
	{
		DP[2] = values[1] + values[2];
	}
	else
	{
		DP[2] = values[0] + values[2];
	}
	for (int i = 3; i < length; i++)
	{
		if (DP[i - 2] > DP[i - 3] + values[i - 1])
		{
			DP[i] = DP[i - 2] + values[i];
		}
		else
		{
			DP[i] = DP[i - 3] + values[i - 1] + values[i];
		}
	}
	cout << DP[length - 1];
}
