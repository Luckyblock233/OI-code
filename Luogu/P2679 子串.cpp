//֪ʶ��:DP 
/*
��f[i][j][k]��ʾ , a�ִ�����i���ַ�,b�ִ�����j���ַ�,
ʹ����k���Ӵ�,����a�е�i���ַ�����ѡ�ķ����� 

��ans[i][j][k]��ʾ, a�ִ�����i���ַ�,b�ִ�����j���ַ�,
ʹ����k���Ӵ�,�ܷ�����,
ans����ʵ����Ϊf�����ǰ׺�� 
 
����ѭ��ö��a�ִ����ַ�,b�ִ����ַ�,ʹ�õ��ִ�����
����״̬ת�Ʒ���ʽΪ:
1. f[i][j][k] = 0;    							(a[i]!=b[j]);
2. f[i][j][k] = f[i][j-1][k] + ans[i][j-1][k-1] (a[i]==a[j]);
����f��,�ٸ���ans����. 

���ڴ���ֻ��128mb�Ŀռ�����
ֱ�ӿ�f[1000][200][200]�ᱬը
�۲�ת�Ʒ���ʽ,
����ʹ�ù����������iά 
*/ 
#include<cstdio>
#include<string>
#include<iostream>
#include<ctype.h>
#define int long long
//============================================================
const int mod = 1e9+7;
int lth1,lth2,num;
int f[2][210][210];// ��������i�� , B�����jλ , ʹ����k���Ӵ� 
int ans[2][210][210]={1};//�ܷ����� 
std::string a,b;
int now = 1;
//============================================================
inline int read()
{
	int fl=1,w=0;char ch=getchar();
	while(!isdigit(ch) && ch!='-') ch=getchar();
	if(ch=='-') fl=-1;
	while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
	return fl*w;
}
//============================================================
signed main()
{
	lth1=read(),lth2=read(),num=read();
	std::cin>>a>>b;
	for(int i=1;i<=lth1;i++)//ö��a�ִ��е��ַ� 
	{
	  ans[now][0][0]=1;
	  for(int j=1;j<=lth2;j++)//ö��b�ִ��е��ַ� 
	    for(int k=1;k<=num;k++)
	    {
	      if(a[i-1] == b[j-1]) f[now][j][k]=(f[!now][j-1][k] + ans[!now][j-1][k-1])%mod;//����ƥ�� 
 	      else f[now][j][k]=0;//����ƥ�� 
 	      ans[now][j][k]=(ans[!now][j][k] + f[now][j][k])%mod;//����ǰ׺�� 
		}
	  now=!now;
	}
    std::cout<<ans[!now][lth2][num];
}
//10�ֱ����ַ���ƥ�� 
/* 
#include<cstdio>
#include<iostream>
#include<string> 
#include<ctype.h>
//=============================================================
int n,m,k,ans;
std::string a,b;
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
	n=read(),m=read(),k=read();
	std::cin>>a;std::cin>>b;
	for(int pos=a.find(b,0);pos!=-1;pos=a.find(b,pos+1)) 
	  ans++;//ѭ��ƥ��b�� 
	printf("%d",ans);
} 
*/
