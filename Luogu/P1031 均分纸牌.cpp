//�㷨:̰��
//�����������,������ƽ��ֵ(��ÿ����������)
//Ȼ��ö��ÿһ����
//����˶Ѳ���ƽ��ֵ,�ʹ���һ�������������,����+1;
//����˶Ѵ���ƽ��ֵ,�ͽ�������Ƶ���һ��,����+1;
//����ƽ��ֵ������
//���������� 
#include<cstdio>
using namespace std;
int a[110];
int main()
{
	int ans=0;
	int n,sum=0,each=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  {
	  	scanf("%d",&a[i]);
	  	sum+=a[i];
	  }
	each=sum/n;//ƽ��ֵ 
	for(int i=1;i<=n;i++)
	  {
	  	if(a[i]<each)//����ƽ��ֵ 
	  	  {
	  	  	a[i+1]-=(each-a[i]);//��������� 
	  	  	ans++;//������һ 
		  }
		if(a[i]>each)
		  {
		  	a[i+1]+=(a[i]-each); //�Ƶ���һ�� 
		  	ans++;
		  }
	  }
	printf("%d",ans);//��� 
}
