//֪ʶ��:ö�ٱ���,hashȡģ,Ϲ��
/*
By:Luckyblock
��ĿҪ��: 
�󷽳�: a0 + a1x + a2x^2 +...+ anx^n = 0 ,
������[1,m] �ڵ�������. 

��������:
�۲����ݷ�Χ: 
0<n<=100 , m<1e6, ������ O(nm)���㷨 
|ai| <=10^(10000) �߾����ᳬʱ �� ���ɷ�Χ. 
����ȡģ����.

���Է���,����Է��̵� ÿ��ϵ�������ȡģ, 
�� �Ա���ȡֵ��ͬ������� , ���ԭ�����Ҳ�Ϊ0,
��ôȡģ�� ���̵��Ҳ���Ϊ0

��һ������:
����ڽϵ� �� ʱ�临�Ӷ������ a0 + a1x + a2x^2 +...+ anx^n ��ֵ? 
���Ƕ�ʽ�ӽ���ת��:
 a0+a1x+a2x^2+...+anx^n
=a0+ x(a1+a2x+...+anx^(n-1)) 
=a0+ x(a1 + x(a2+...+anx^(n-2)) ) )
=...
=a0+ x(a1+x(a2+x(a3+....an)))...)
���Կ��õݹ���� ,Ҳ����ѭ�����. 
���Ӷ������Ե�

�㷨ʵ��:
��ô������ O(nm) ���㷨,
ֱ�ӱ���ö���Ա�����ȡֵ
����ⷽ��,��鷽���Ҳ��Ƿ�Ϊ0 ,����¼�Ϸ��⼴��.

�㷨©��:
����hash�㷨 ,�˽ⷨҲ������ײ�ķ���.
ʹ�ò�ͬ��ȡģ����,����ȡ�ò��ȵķ���
����ֻʹ��1e9+7�����õ�����(���� 
Ϊ������ײ ����,���ʹ�ò�ͬ�Ĵ��������� ȡģ. 
*/

//˫ģ100��: 
#include<cstdio>
#include<ctype.h>
#define int long long
const int MARX = 1e6+10;
const int mod1 = 19260817;//������ģ�� 
const int mod2 = 998244353;
//=============================================================
int n,m,num , a[110],b[110],ans[MARX];
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
inline void read1(int &a1 , int &b1)//��� ȡģ�Ľ��� 
{
    int s=1, w1=0,w2=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w1=(w1*10+ch-'0')%mod1,w2=(w2*10+ch-'0')%mod2;
    a1=s*w1,b1=s*w2;
}
//=============================================================
signed main()
{
	n=read(),m=read();
	for(int i=0; i<=n; i++) read1(a[i],b[i]);//���벢����ȡģ 
	
	for(int i=1,sum1=0,sum2=0; i<=m; i++,sum1=0,sum2=0)//����ö�ٴ� 
	{
	  for(int j=n; j; j--) sum1=((a[j]+sum1)*i)%mod1,sum2=((a[j]+sum2)*i)%mod2;//��� 
	  sum1=(sum1+a[0])%mod1,sum2=(sum2+a[0])%mod2;
	   
	  if((!sum1) || (!sum2)) ans[++num]=i;//����Ҫ��,����� 
	}
	printf("%lld\n",num);
	for(int i=1;i<=num;i++) printf("%lld\n",ans[i]);
}

//��ģ 1e9+7 ����: 
/* 
#include<cstdio>
#include<ctype.h>
#define int long long
const int MARX = 1e6+10;
const int mod = 1e9+7;
//=============================================================
int n,m,num , a[110],ans[MARX];
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = (w*10+ch-'0')%mod;
    return s*w;
}
//=============================================================
signed main()
{
	n=read(),m=read();
	for(int i=0; i<=n; i++) a[i]=read();
	for(int i=1,sum=0; i<=m; i++,sum=0)//����ö�ٴ� 
	{
	  for(int j=n; j; j--) sum=((a[j]+sum)*i)%mod;//��� 
	  sum=(sum+a[0])%mod;
	  if(!sum) ans[++num]=i;//���ϴ� 
	}
	printf("%lld\n",num);
	for(int i=1;i<=num;i++) printf("%lld\n",ans[i]);
}
*/ 
