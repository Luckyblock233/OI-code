//�㷨��ģ��
//��¼�����˵�����
//ÿ�����Ӵ�ʱ,�Ƚ��Ƿ���֮ǰ�ĸ��˵������ظ�
//�����,�ͼ�ȥ�ظ���
//û���򲻹� 
#include<cstdio>
using namespace std;
int n,t;
int ans;
int main()
{
	scanf("%d%d",&n,&t);
	int last=0;
	for(int i=1;i<=n;i++)
	  {
	  	int ti;
	  	scanf("%d",&ti);
	  	ans+=t-((last-ti+1)>0?(last-ti+1):0);//�Ƚ��Ƿ���֮ǰ�ĸ��˵������ظ� 
		last=ti+t-1; //��¼�����˵����� 
	  }
	printf("%d",ans);
}
