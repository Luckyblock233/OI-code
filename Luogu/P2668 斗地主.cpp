//֪ʶ��:����,ģ��,̰�� 
/*
By:Luckyblock
���� n<=4,30��:
n=2ʱ: ֻ���ܳ���:����,����,��ը
n=3ʱ: ֻ���ܳ���:����,����,����,��ը 
n=4ʱ: ֻ���ܳ���:����,����,����,����һ,ը��,��ը
	��������һ �� ը��,���Կ���ͬһ��,
	��ֻҪ�� ����������ͬ����,
	�Ϳ���ѡ��������һ�� ͬʱ��� 

�����������б����жϼ��� 
*/
#include<cstdio>
#include<ctype.h>
//=============================================================
int T,n; 
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
//=============================================================
signed main()
{
	T=read(),n=read();
	for(;T;T--)
	{
	  int num[16]={0}, ans=0, res=n, flag=0;
	  for(int i=1;i<=n;i++)
	  {
	  	int a=read(),b=read();
	  	if(a==0) a=13+b;
		num[a]++;
	  }
	  
	  for(int i=1;i<=13 && n>=3;i++)//����������ȵ���
	    if(num[i]==3)//(���� ը��/����һ/���� ) 
	    {
	      printf("1\n");
	      flag=1;break;
		}
	  if(flag) continue;//�Ѿ����� 
	  
	  for(;num[14]&&num[15]; num[14]--,num[15]--)//ѭ����ը 
	    ans++,res-=2;
	  
	  for(int i=1;i<=13;i++)//����������ȵ��� 
	  {
	    if(num[i]==2) num[i]=0,ans++,res-=2;//̰��,�ܳ����Ӿͳ� 
		if(!res)//���� 
		{
		  printf("%d\n",ans);
		  flag=1;break;
		}
	  }
	  if(flag) continue;//�Ѿ����� 
	  
	  printf("%d\n",ans+res);
	  //�Ѿ����ܳ�����,��ʣ�µ��ƶ����յ��Ƴ� 
	}
}
