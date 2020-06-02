#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

class Color{
private:
	//ͼ�Ķ�����
	int n;
	//���õ���ɫ��
	int m;
	//ͼ���ڽӾ���
	int **a;
	//��ǰ��
	int *x;
	//��ǰ���ҵ��Ŀ�m��ɫ������
	long sum;
	// �����ɫ������
	bool isOk(int k) {
		for (int j = 1; j <= n; j++)
		{
			if ((a[k][j] == 1) && (x[j] == x[k])) //��������ɫ��ͬ
			{
				return false;
			}
		}
		return true;
	}
	void Backtrack(int t) {
		//tΪ��ǰ�ڵ㣬�������ܵ��������ʾ��ǰ����Ѽ����꣬�������
		if (t > n)
		{
			sum++;
			for (int i = 1; i <= n; i++) {
				cout << x[i] << " ";
			}
			cout << endl;
		}
		else
		{
			//Ϊ��ǰ�ڵ����������ɫ�����ж�
			for (int i = 1; i <= m; i++)
			{
				x[t] = i;
				if (isOk(t)) {
					//���ݵ�ǰ��ɫ�����������һ����ɫ
					Backtrack(t + 1);
				}
				//Ĩȥ��ɫ���������
				x[t] = 0;
			}
		}
	}
	
public:
	friend int mColoring(int n, int m, int **a);
};
int mColoring(int n, int m, int **a) {
	Color X;

	//��ʼ��X
	X.n = n;
	X.m = m;
	X.a = a;
	X.sum = 0;
	//��ʼ����ǰ��ռ�
	int *p = new int[n + 1];
	for (int i = 0; i <= n; i++)
	{
		p[i] = 0;
	}
	X.x = p;
	X.Backtrack(1);
	delete[]p;
	return X.sum;
}

int main()
{
	int N, M;
	cout << "������ͼ�Ķ�������ɫ������" << endl;
	cin >> N >> M;
	int **a = new int *[N + 1];
	for (int i = 1; i <= N; i++)
	{
		a[i] = new int[N + 1];
	}


	cout << "������ͼ���ڽӾ���:" << endl;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> a[i][j];


		}
	}

	cout << "ͼ��M��ɫ�������£�" << endl;
	cout << "��m=" << M << "ʱ��ͼG�Ŀ�����ɫ������ĿΪ��" << mColoring(N, M, a) << endl;
	for (int i = 1; i <= N; i++)
	{
		delete[] a[i];
	}
	delete[]a;
}
