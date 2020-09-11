#include <iostream>
#include <Windows.h>
#include <ctime>
using namespace std;
int f, ff,af=1,p;
void priv()
{
	cout << "priv,che del" << endl; 
		Sleep(1000);
		priv();
}
long double fact(int N)
{
	if (N < 0) 
		return 0; 
	if (N == 0) 
		return 1; 
	else 
		return N * fact(N - 1); 
}
int fib(int n)
{
	int a(1), b(1);
	for (int i = 0; i < n - 2; i++)
	{
		b = a + b;
		a = b - a;
	}
	return b;
}
DWORD WINAPI A(LPVOID lpParameter)
{
	cout << fact(f)<<endl;
	return 0;
}
DWORD WINAPI B(LPVOID lpParameter)
{
	cout << fib(ff + 2) - 1 << endl;;
	return 0;
}
DWORD WINAPI P(LPVOID lpParametr)
{
	priv();
	return 0;
}
int main()
{
	DWORD PID;
	HANDLE priv = CreateThread(0, 0, P, &p, 0, &PID);
	setlocale(LC_CTYPE, "Russian");
	cin >> f;
	DWORD AID;
	HANDLE myHandle = CreateThread(0, 0, A, &f, 0, &AID);
	Sleep(5000);
	TerminateThread(myHandle, 0);
	int t = clock();
	cout << t << endl;
	system("Pause");
	cin >> ff;
	DWORD BID;
	HANDLE myHandle1 = CreateThread(0, 0, B, &ff, 0, &BID);
	Sleep(5000);
	TerminateThread(myHandle1, 0);
	int t1 = clock() - t;
	cout << t1;
	TerminateThread(priv, 0);
	getchar();
}
