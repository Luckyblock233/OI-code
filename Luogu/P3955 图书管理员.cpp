//֪ʶ��:ģ�� 
/*
��ĿҪ��:
��ѯ��ǰ�ִ�,
�Ƿ�Ϊ��һ�ִ��ĺ�׺,
�������̵���һ�ִ�

������,����ʹ��Trie��,
�������ݷ�Χ��С , n<=1000
ֱ������ѭ��ģ�⼴��
���ע�� 
*/
#include<cstdio>
#include<ctype.h>
#include<algorithm>
const int MARX = 1010;
//=============================================================
int n,q;
int book[MARX],mul[100]={1};
//=============================================================
inline int read()
{
	int fl=1,w=0;char ch=getchar();
	while(!isdigit(ch) && ch!='-') ch=getchar();
	if(ch=='-') fl=-1;
	while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
	return fl*w;
}
//=============================================================
signed main()
{
	for(int i=1;i<=10;i++)mul[i]=mul[i-1]*10;//Ԥ����10^i 
	n=read(),q=read();
	for(int i=1;i<=n;i++) book[i]=read(); 
	std::sort(book+1,book+n+1);//���������� 
	for(int i=1;i<=q;i++)
	{
	  int l=read(),now=read(),flag=0;
	  for(int j=1;j<=n;j++) //����ѭ��ƥ�� 
	    if(book[j]%mul[l]==now)//ȡ����10^(l-1)λ����,����Ƿ�ƥ�� 
	    {
	      printf("%d\n",book[j]);
	      flag=1;
	      break;
		}
	  if(!flag) printf("-1\n");
	}
}
