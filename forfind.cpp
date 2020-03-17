#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<string.h>
#include<map>
using namespace std;
const int maxn = 1e6 + 10;
#define PI 3.14159
#define ll long long 
typedef unsigned long long ull;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
int a[maxn];
int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		cin >> a[i];
	}
	int x;
	cin >> x;
	int flag = 0;
	int lazy = 0;
	for (int  i = 1; i <= t; i++)
	{
		if (a[i] == x)
		{
			flag = 1;
			lazy = i;
			break;
		}
	}
	if (flag == 1)
	{
		cout << lazy << endl;
	}
}
