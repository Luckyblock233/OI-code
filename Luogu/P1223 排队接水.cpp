//�㷨:̰��
//��ÿ���˰��ս�ˮʱ����������, ʱ����ͬ���������������
//��ΪҪ��ƽ��ֵ��С,��ʹ�����˵ȴ�ʱ��֮����С
//����Ҫ��ʱ��С���Ƚ���ˮ,
//�ѽ�С�ĵȴ�ʱ���ۼӵ���Ҫʱ��϶�������� 
//�����˳����ĿҪ��Ľ�ˮ˳�� 
//������������ 
#include<cstdio>
#include<algorithm>
using namespace std;
struct baka//��ÿ���˱����ʱ�� 
{
	int data,bian;	
}a[1010];
bool cmp(baka x,baka y)//����ȽϺ��� 
{
	if(x.data==y.data)
	  return x.bian>y.bian;
	return x.data>y.data;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)//���� 
	  {
	  	a[i].bian=i+1;
	  	scanf("%d",&a[i].data);
	  }
	double ans=0;
	sort(a,a+n,cmp);//���� 
	for(int i=0;i<n;i++)//��˳�����,����. 
	  {
	  	printf("%d ",a[n-i-1].bian);
	  	ans+=i*a[i].data;
	  }
	printf("\n%.2lf",ans/n);
}
