//�㷨��DP�����ر���
/*
���ر���
δ�Ż���30,�Ż���100 
���ע�� 
*/
#include<cstdio>
#include<cctype>
#include<algorithm>
using namespace std;
const int MARX = 1e5+10;
//=============================================================
int n,m,num;
int v[MARX],w[MARX],s[MARX];//������ֵ,����,������ 
int v1[MARX],w1[MARX];//��ֺ��ֵ,���� 
int f[MARX]; 
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
void brick(int i)//��� 
{
	for(int j=1;j<=s[i];j*=2)//�������Ʋ�� 
	{
	  v1[++num]=j*v[i];
	  w1[num]=j*w[i];
	  s[i]-=j;
	}
	if(s[i])//�������µ� 
	{
	  v1[++num]=s[i]*v[i];
	  w1[num]=s[i]*w[i];
	}
}
//=============================================================
signed main()
{
	n=read(),m=read();//���벢��� 
	for(int i=1;i<=n;i++)
	{
	  v[i]=read(),w[i]=read(),s[i]=read();
	  brick(i);
	}
	for(int i=1;i<=num;i++)//ת������01�������� 
	  for(int j=m;j>=w1[i];j--)
	  	f[j]=max(f[j],f[j-w1[i]]+v1[i]);
	printf("%d",f[m]);
}
//30�ֱ���δ�Ż�����ر��� 
/*
#include<cstdio>
#include<algorithm>
#include<cctype>
const int MARX = 1e6+10;
//=============================================================
int n,m,w[MARX],v[MARX],s[MARX];//ռ������,��ֵ,���� 
int f[MARX];
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
	n=read(),m=read();
	for(int i=1;i<=n;i++) v[i]=read(),w[i]=read(),s[i]=read();
	
	for(int i=1;i<=n;i++)
	  for(int k=m;k>=w[i];k--)
		for(int j=1;j<=s[i];j++)
	  	  if(k-j*w[i]>=0)
	  	  	f[k]=std::max(f[k],f[k-j*w[i]]+j*v[i]);
	
	printf("%d",f[m]);
}
*/
