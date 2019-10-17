//֪ʶ��:DP , ����˼· , ����ö��(?)   
/*
- ��ĿҪ��:  
  �� a �������� b �������,  
  ���� bi & bi-1 !=0    
  n <=1e5 , ai <= 1e9

- 	����˼·:  
	��������������  
	
	ֱ�� O(n^2) ����ö��  
	��ǰҪ��ӵ���,�Լ�����b��β���� 
	  
	�� f[i] ��ʾ��a[i]��β��,b ���е������    
	��: ״̬ת�Ʒ���ʽΪ:   
	f[i] = max(f[i], f[j]+1) (a[i] & a[j] !=0)   
    
   ����ȡ�� 90�ֵĺóɼ�(����)  

-   �����Ż�  
	��������ӵ���,  
	ֻ����:   
   ��ͬһ������λ�� , ͬΪ1����ת�ƶ���
	
	Ҳ����˵,  
	����ѡ�� ö��  
	����ӵ����� �������ϵ�1λ  
	
	����ö�ٶ�����λ  
	����¼ :   
	�˶�����λȫΪΪ 1 ���� ��ɵ� ������ b   
	���ܴﵽ����󳤶�Ϊ����  
    
   �� f[i] ��ʾ : ���һλΪ i�� b���е������,  
	bit[j] ��ʾ : �����Ƶ� j λΪ1 ���� , ��ɵ������� b�������      
    kΪ ö�ٵ�: a[i]�� , ��������Ϊ1�Ķ�����λ��   
   
	������Ƴ��µ�״̬ת�Ʒ���ʽ:   
   f[i] =  max(f[i] , bit[k]+1) 
   
   ���� �Ϳ�����һ��ѭ��  
   ��ö�� ����ӵ��� �ɽӵ� ��Щ��֮��.
	
	������ f[i]�� , ���ø��º�� f[i] ,  
	������ ���� bit[k]  
    
	����ö��k , ����ʹ��lowbit() , ��ȡ�� log ����ֵ�����   
	�ڸ��� f[i] �Ĺ�����ȡ����f[i]��Ϊ��   
	����Ż�����O(31*n) ���� . (��Ϊ���ֻ��31 ��������λ�ϵ�1 )   
*/
//����: 
#include<cstdio>
#include<algorithm>
#include<map>
#include<ctype.h>
#define lowbit(x) (x)&-(x)
const int MARX = 1e5+10;
//=============================================================
int n,ans,a[MARX]; 
int bit[40] , f[MARX];  //�������������
std::map <int,int> log_2;
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
    for(int i=0,sum=1;i<=31;i++,sum<<=1) log_2[sum]=i; //Ԥ����log���� 
    n=read();
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<=n;i++)
    {
      for(int j=a[i],low=lowbit(j);j;j-=low,low=lowbit(j)) //ö�ٶ�����λ����f[i] 
        f[i]=std::max(f[i],bit[log_2[low]]+1);
      for(int j=a[i],low=lowbit(j);j;j-=low,low=lowbit(j)) //ʹ�ø��¹���f[i]����bit[k] 
        bit[log_2[low]]=std::max(bit[log_2[low]],f[i]); 
      ans=std::max(f[i],ans); //ȡ������ 
    }
    printf("%d",ans);
}
//����90:
/*
#include<cstdio>
#include<ctype.h>
#include<algorithm>
const int MARX	= 1e5+10;;
//=============================================================
int n,ans,a[MARX];
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
	n=read();
	for(int i=1;i<=n;i++) a[i]=read(),f[i]=1;//���벢��ʼ�� 
	
	for(int i=2;i<=n;i++)
	  for(int j=1;j<i;j++)
	    if(a[i] & a[j])
		  f[i]=std::max(f[i],f[j]+1),//����f[i]���ҵ����ֵ 
		  ans=std::max(ans,f[i]);
	printf("%d",ans);
}
*/ 
