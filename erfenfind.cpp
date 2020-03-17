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

struct node
{
	int x;
	int id;
}a[maxn];
int cmp(node t, node y)
{
	return t.x < y.x;
}
int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		cin >> a[i].x;
		a[i].id = i;
	}
	int x;
	cin >> x;
	sort(a + 1, a + 1 + t, cmp);
	int l = 1;
	int r = t;
	while (l<r)
	{
		int mid = (l + r) / 2;
		if (a[mid].x > t)
		{
			r = mid-1;
		}
		else
		{
			l = mid;
		}
	}
	if (a[l].x == t)
	{
		cout << a[l].id << endl;
	}
	else
	{
		cout << 0 << endl;
	}
}
