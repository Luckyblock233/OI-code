//�㷨:���ִ�/̰��
/*
��֤�����㵥����,С�Ŀ���,����һ������
��,���Զ��ִ𰸷�ö��ÿ�κ͵����ֵ

��ǰ׺�ʹ� ��1���� �� ��i�������ܺ�
����,�Ϳ����� b[i]-b[j]��� i~j �ε����ĺ� 

ö�ٺ�,ͨ��̰�������м��
̰�Ĳ���:
  �����������,�˶κ�С��ö��ֵ,���������
  ����,��ǰ�沿�ֶϿ�,��Ϊһ���µ����Ρ� 
  ���ͳ�����θ��������С�ڵ��ڹ涨��m����ö�ٵ����Ϸ� 
*/ 
#include<cstdio>
using namespace std;
const int MARX = 1e6+10;
int n,m;
int a[MARX],b[MARX];
bool judge(int x)//̰�ķ����м��� 
{
	int tot=0,be=0;
	for(int i=1;i<=n;i++) 
	  {
	  	if(a[i]>x) return 0;
	  	if(b[i]-b[be]>x) tot++,be=i-1;//��������� 
	  }
	if(be!=n) tot++;//�������� 
	return tot<=m;//��� 
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)//���� 
	  {
	  	scanf("%d",&a[i]);
	  	b[i]=b[i-1]+a[i];//ǰ׺�� 
	  }
	int le=1,ri=1e9,mid,ans;
	while(le<=ri)//���ִ� 
	  {
	  	mid=(le+ri)>>1;
	  	if(judge(mid)) ans=mid,ri=mid-1;
	  	else le=mid+1;
	  }
	printf("%d",ans);
}
