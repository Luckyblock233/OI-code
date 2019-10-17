//֪ʶ��:�����ѧ/����ö�� 
/*
�������: https://www.luogu.org/blog/koishikoishi/solution-p3799

����: 
��n��ľ�������ڴ���ѡ4����
��Ҫ���һ���������Σ����м���ѡ����

������֪,����4��ľ��,���һ����������,
���Ȼ�������ĳ�����ͬ , 
�����������ĳ��Ⱥ�,����ǰ�����ĳ��� 

�ַ��ָ�ľ���ĳ��� a[i] <=5000
�����ֱ��������ѭ��,
����ö������ľ���ĳ��� 
 
��Ͱ num[] ,��¼�����ȵ�ľ�����ֵĴ���

���ѭ��ö��������ȵ�ľ���ĳ��� i , 
���˳��ȵ�ľ������ >= 2ʱ,�����ڲ�ѭ��
�ڲ�ѭ��,ö��һ������ �ϳ� ��ľ������ j 
��һ���ϳ��õ�ľ�����ȼ�Ϊ i-j.

��� (i==j && num[j]>=1 && num[i-j]>=1) ,
  ��ô  ans+=  C2(num[i]) * C1(num[j]) * C1(num[i-j]);
���(j==i-j && num[j]>=2) 
  ��ô ans+=  C2(num[i]) * C1(num[j]);

�ڲ�ѭ��:
    Ȼ��Ҫ�� ʣ�µ�ľ���� ��ȡ������  
  	  ����֮��Ϊ i ��ľ��
      
      ��� j==i-j ,   
        ��ôҪ�ӳ���Ϊ j ��ľ����ȡ�� 2 ��  
        ��ô������Ϊ:
        �� num[j] ������ȡ�� 2 ���������   
        ��C(num[j],2) 
        
      ���j != i-j
        ��ôҪ�ӳ���Ϊ j ��ľ����ȡ�� 1 ��  
        �ٴӳ���Ϊ i-j ��ľ����ȡ�� 1 ��  
        ͬ�� , ��ô������Ϊ:  
        C(num[j],1) \times C(num[i-j],1)
        
   ���ݳ˷�ԭ�� ��  
   �����з�������� ,  
   ���� ans �ı仯�� . 
*/
#include<cstdio>
#include<ctype.h>
#define int long long
#define max(a,b) a>b?a:b
//======================================================= 
const int MARX = 1e6+10;
const int mod = 1e9+7;
int n,ans,maxa;
int a[MARX],num[MARX];
//=======================================================
inline int read()
{
	//isdigit����,�ж��ַ��Ƿ�Ϊ�����ַ�,������<ctype.h>����  
	int fl=1,w=0;char ch=getchar();
	while(!isdigit(ch) && ch!='-') ch=getchar();
	if(ch=='-') fl=-1;
	while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
	return fl*w;
}
inline int C(int x,int k)//��ô�n������ȡ��k��������� 
{
	return k==1?x:x*(x-1)/2;
}
//=======================================================
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)//����,������Ͱ�� 
	  a[i]=read(),
	  maxa=max(a[i],maxa),
	  num[a[i]]++;
	  
	for(int i=2;i<=maxa;i++)//ö��������ȵı� 
	  if(num[i]>=2)
	    {
	      int times = C(num[i],2)%mod;//�������� 
	      for(int j=1;j<=i/2;j++)//ö�ٱ��ϳɵı� 
	        {
	          if(j!=i-j && num[j]>=1 && num[i-j]>=1)//�������ϳɵ�ľ�����Ȳ��� 
	            ans=(ans + times*C(num[j],1)%mod*C(num[i-j],1)%mod)%mod;
			  if(j==i-j && num[j]>=2)//�������ϳɵ�ľ��������� 
			    ans=(ans + times*C(num[j],2))%mod;
			}
		}
	
	printf("%lld",ans%mod);
}
