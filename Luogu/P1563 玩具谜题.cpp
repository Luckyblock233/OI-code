//֪ʶ��:ģ�� 
/*
By:Luckyblock
�����������ϸ��ģ�ⷽ�� 
�������ݷ�Χ��С, 
ֱ�Ӱ����������ģ�⼴��
���ע�� 
*/
#include<cstdio>
#include<iostream>
#include<ctype.h>
const int MARX = 1e5+10;
//=============================================================
std::string name[MARX];//������ 
int n,m,ans=1,dir[MARX];//�泯�� 
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
inline void prepare()
{
	n=read(),m=read();
	for(int i=1;i<=n;i++)
	  std::cin>>dir[i]>>name[i];
}
//=============================================================
signed main()
{
	prepare();
	for(int i=1;i<=m;i++)//��ʼģ�� 
	{
	  int ai=read(),si=read()%n;
	  if( (ai==1 && dir[ans]==0) || (ai==0 && dir[ans]==1))//��ת 
	  {
	  	ans=ans+si;
	  	if(ans>n) ans-=n;//Խ�� 
	  }
	  else//������ת 
	  {
		ans=ans-si;
		if(ans<1) ans+=n;//Խ�� 
	  }
	}
	std::cout<<name[ans];
}
