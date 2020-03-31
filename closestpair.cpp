#include <iostream>
#include<iomanip>
#include<cmath>
using namespace std;
struct point{

	int x,y;
};
int Partition(point r[], int first, int end){                       //����
       int i = first, j = end;                              //��ʼ������������ 
       while (i < j)    { 
              while (i < j && r[i].y <= r[j].y) j--;                            //�Ҳ�ɨ��
              if (i < j) {
                     point temp = r[i]; r[i] = r[j]; r[j] = temp;     //����С��¼������ǰ��
                     i++;
              }
              while (i < j && r[i].y <= r[j].y) i++;                          //���ɨ��
              if (i < j) {
                     point temp = r[i]; r[i] = r[j]; r[j] = temp;    //���ϴ��¼����������
                     j--;
              }
       }
       return i;                                                                               // ������ֵ��¼��λ��
}

double Distance(point a,point b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
void QuickSort(point r[], int first, int end){     //��������
       int pivot;
       if (first < end) {
              pivot = Partition(r, first, end);             //���֣�pivot����ֵ�������е�λ��
              QuickSort(r, first, pivot - 1);               //���������1������������н��п�������
              QuickSort(r, pivot + 1, end);              //���������2�����Ҳ������н��п�������
       }
 
}

double Closest(point S[],int low,int high)
{
	double d1,d2,d3,d;
	int mid,i,j,index;
	point P[8];
	if(high-low==1)
		return Distance(S[low],S[high]);
	if(high-low==2){
		d1=Distance(S[low],S[low+11]);
		d2=Distance(S[low+1],S[high]);
		d3=Distance(S[low],S[high]);
		if((d1<d2)&&(d2<d3))
			return d1;
		else if(d2<d3)
			return d2;
		else 
			return d3;
	}
	mid=(low+high)/2;
	d1=Closest(S,low,mid);
	d2=Closest(S,low+1,high);
	if(d1<=d2)
		d=d1;
	else
		d=d2;
	index=0;
	for(i=mid;(i>=low)&&(S[mid].x-S[i].x<d);i--)
	{
		P[index++]=S[i];

	}
	for(i=mid+1;(i<=high)&&(S[i].x-S[mid].x<d);i++)
	{
		P[index++]=S[i];

	}
	QuickSort(P,0,index-1);
	for(i=0;i<index;i++)
	{
		for(j=i+1;j<index;j++)
		{
			if(P[j].y-P[i].y>=d)
				break;
			else 
			{
				d3=Distance(P[i],P[j]);
				if(d3<d)
					d=d3;
			}

		}
	}
	return d;
}

int main(){
	   point S[8] = { {10,2},{15,2},{13,74},{42,22},{65,8},{70,12},{60,54},{62,2} };
       double minDist = Closest(S, 0, 8-1);
       //��������Եľ���
       cout << "�����Ծ���Ϊ��"<< minDist << endl;

}

