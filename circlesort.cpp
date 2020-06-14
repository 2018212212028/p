#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

class Circle {
private:
	//Բ����
	int N;
	//��СԲ���г���
	double minlen = 100000;
	//��Բ�ĺ�����
	double *x;
	//��Բ�뾶
	double *r;
	//��СԲ���еİ뾶˳��
	double *bestr;
	//������СԲ���г���
	void compute()
	{
		double low = 0, high = 0;
		for (int i = 0; i < N; ++i)
		{
			if (x[i] - r[i] < low)
				low = x[i] - r[i];
			if (x[i] + r[i] > high)
				high = x[i] + r[i];
		}
		if (high - low < minlen)
		{
			minlen = high - low;
			for (int i = 0; i < N; ++i)
				bestr[i] = r[i];
		}
	}
	double center(int t)//�õ�ÿ��Բ��Բ������
	{
		double temp = 0;
		double xvalue;
		for (int i = 0; i < t; ++i)
		{
			//����ȡһԲ���У�����ԲX����
			xvalue = x[i] + 2.0*sqrt(r[t] * r[i]);
			if (xvalue > temp) {
				temp = xvalue;
			}
		}
		return temp;
	}
	void backtrack(int t)
	{
		if (t == N)
		{
			compute();
		}
		else
		{
			//���㵱ǰ�������г���
			for (int i = t; i < N; ++i)
			{
				swap(r[t], r[i]);
				double centerx = center(t);
				//��֦����
				if (centerx + r[t] + r[0] < minlen)
				{
					x[t] = centerx;
					backtrack(t + 1);
				}
				swap(r[t], r[i]);//���ݣ���ʼ��һ������
			}
		}
	}
public:
	Circle() {};
	Circle(int _N,  double *_r) {
		this->N = _N;
		this->x = (double *)malloc(sizeof(double)*_N);
		this->r = _r;
		this->bestr = (double *)malloc(sizeof(double)*_N);
	}
	void calculate() {
		backtrack(0);
		cout << "��СԲ���г���Ϊ��" << minlen << endl;
		cout << "����Բ���е�˳���Ӧ�İ뾶�ֱ�Ϊ��";
		for (int i = 0; i < N; ++i) {
			cout << bestr[i];
			if (i==N-1) {
				cout << endl;
			}
			else {
				cout << " ";
			}
		}
	}
};

int main()
{
	int n;
	cout << "�����������Բ������";
	cin >> n;
	double * r = (double *)malloc(sizeof(double)*n);
	cout << "������ÿ��Բ�İ뾶��";
	for (int i = 0; i < n;i++) {
		cin >> r[i];
	}
	Circle c = Circle(n, r);
	c.calculate();
	return 0;
}
