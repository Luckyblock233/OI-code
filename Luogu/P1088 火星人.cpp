//֪ʶ��:����չ��
/*
������ ������ĵ� ʮ������
�� ��ȫ���еĿ���չ��

�ȶԸ���ȫ����
���н��Ʒֽ�

�ڶԷֽ�������
����Ҫ����� 

�ٽ��ı�������
ת��Ϊȫ���м��� 
*/ 
#include<cstdio>
#include<cctype>
//==============================================
const int MARX = 1e4+10;
int n,m;
int a[MARX],used[MARX],use[MARX];
//==============================================
inline int read()
{
	int fl=1,w=0;char ch=getchar();
	while(!isdigit(ch)) if(ch=='-') {fl=-1,ch=getchar();break;}
	while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
	return fl*w;
}
//==============================================
signed main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)//����ԭ���� 
	  {
	  	scanf("%d",&a[i]);
	  	int tmp=0;
	  	for(int j=1;j<=a[i];j++)//���н���ת�� 
	  	  tmp+=(!used[j]);
	  	used[a[i]]=1;
	  	a[i]=tmp-1;
	  }
	  
	a[n]+=m;
	for(int i=n;i>=1;i--)//����һ���� 
	  {
	  	a[i-1]+=a[i]/(n-i+1);//��λ 
	  	a[i]%=n-i+1;//���� 
	  }
	
	for(int i=1;i<=n;i++)//ת��Ϊȫ���� 
	  {
	  	for(int j=0;j<=a[i];j++)
	  	  if(use[j]) a[i]++;
	  	printf("%d ",a[i]+1);
	  	use[a[i]]=1;
	  }
}
