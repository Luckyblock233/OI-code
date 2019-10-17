//֪ʶ��: ״ѹDP , ����ѧ 
/*
By:Luckyblock
��ĿҪ��:
ƽ��ֱ������ϵ �� ��һ������ , ��һЩ��,
���쾡�����ٵ�, ����ʽΪ y=ax^2 + bx ��ʽ��������
ʹ���еĵ㶼������һ��
�����ٵ������� ����.

��������:
�۲����ݷ�Χ: n<=18 ������Щ���ӶȽϸ� �� �㷨.
����ÿ����,ֻ���������: ��������/δ������
����״ѹDP.

ͨ���۲������ߵĽ���ʽ,
����ֻҪȷ������, �Ϳ���ȷ��һ��������.
��ô������������, 
��map[i][j], ��ʾһ������i,j����������� , �ܾ����ĵ�ļ���.
	���map����: 
	1. ����ѭ��ö��i,j, ��i,j�������㼯, ����i,j���������������ʽ��
	2. ģ���������,���Ԫһ�η�����, �õ�����i,j����������߽���ʽ. 
		�������:��ø���ϵ��->*10^k,��ϵ��ת��Ϊ����->�����Ԫ->��� 
	3. ö��i,j��������� , �����������߾����ĵ����㼯.
		
	����i,j����,һ�ֲ��Ϸ�,Ҫ���������(��������ͬһ��������: 
	x[i]>=x[j] �� y[i]>y[j]ʱ,i��б�� ���� j��б�� ( ��:(1,1)��(1.2,2) ) 
	
	ע��Ԥ����� ֻ����һ���� ��������.
	������ map[i][n] = �㼯{i},�����������ֻ������i����. 
	
�õ�Ԥ������ map�����,
�Ϳ��Լ򵥵ؽ���״ѹDP. 
�� ans[s] Ϊ �����ĵ� ���ɵ� �㼯s,����Ҫ��������������. 
״̬ת�Ʒ���ʽ:
ans[s | map[j][k] ] = min( ans[s | map[j][k] ] , ans[s]+1)
(j �����ڵ㼯s). 

������ ����ȫ�� �Ĵ��ۼ���. 

�����Ż� : 

���ϸ��Ӷ�Ϊ O(Tn^2 2^n) ���㷨 , �� CCF ������240�����ܲ���ȥ��= =   
�� Luogu ��Ҳֻ�� ��ǿ����    
���������Ż� : 

- ���� ��ǰ�� �㼯 S ����ת�� :
  �� x Ϊ���� S&(1<<(x-1))=0 ����С������������ S ת�Ƶ� �����߶�Ҫ����  x

	��ȷ�Ժ���Ȼ , 
	���ڴ˴�ת���� , ����������߲����� x , 
	�� ��֮��� ĳ��ת���� ҲҪ���� x. 
	�� �ڴ˴�ת���� , �Ⱦ��� x , �𰸲������

- 	����� ����Ԥ���� , 
	Ԥ����� ÿһ���㼯 , ���� S&(1<<(x-1))=0 ����С������ , 
	ת��ʱ ֻö�پ����˵�� ������  ����

���� ����һ����� ���������ֻ�� n ��
���Ӷȱ�Ϊ O(Tn 2^n) , �ȹ�
*/
// O(Tn 2^n): 
#include<cstdio>
#include<cmath>
#include<cstring>
#include<ctype.h>
#define min(a,b) a<b?a:b
#define lb long double
const lb eps = 1e-12;//��Сֵ(0�Ľ���ֵ 
//=============================================================
int T,n,m,all , map[20][20],ans[524288],lowbit[524288];
lb x[20],y[20];//�������� 
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
int gcd(int a, int b) {return b?gcd(b,a%b):a;}
void get_ab(int fir,int sec,lb &a, lb &b)//��� ��Ԫһ�η����� 
{
	lb x1=x[fir],x12=x1*x1,y1=y[fir] , x2=x[sec],x22=x2*x2,y2=y[sec];//��ʼ��ϵ����ֵ 
	x1*=100000,x12*=100000,y1*=100000,x2*=100000,x22*=100000,y2*=100000;//����ϵ��ת��Ϊ���� 
	int t1=x1,t12=x12,tt1=y1,t2=x2,t22=x22,tt2=y2 , d=gcd(t12,t22),l=(t12/d*t22);//�������α��� 
	
	t1*=(l/t12),tt1*=(l/t12) , t2*=(l/t22),tt2*=(l/t22),t12=t22=l;//����ͨ��,�Խ��������Ԫ 
	
	b = ((tt2-tt1)*1.0)/((t2-t1)*1.0);//���a,b��ֵ 
	a = (tt1*1.0-t1*b)/t12;
}
void prepare()
{
	memset(ans,127,sizeof(ans)); ans[0]=0;//��ʼ��ansΪ����ֵ 
	memset(map,0,sizeof(map));
	
	n=read(),m=read(); all=(1<<n)-1;
	for(int i=0; i<n; i++) scanf("%Lf%Lf",&x[i],&y[i]);
	for(int i=0; i<n; i++) map[i][n] = (1<<i);//ֻ����һ����������� 
	for(int i=0; i<n; i++)//ö�� �����߾����������� 
	  for(int j=i+1; j<n; j++)
	  {
	  	//���Ϸ��ĵ�� 
	  	if(x[i]>=x[j] && y[i]>y[j] && y[i]/x[i]>=y[j]/x[j]) continue;
	  	if(x[j]>=x[i] && y[j]>y[i] && y[j]/x[j]>=y[i]/x[i]) continue;
	  	
	    lb a,b; map[i][j]|=(1<<i),map[i][j]|=(1<<j);//����㼯 
	 	get_ab(i,j,a,b);//���a,b 
	    for(int k=0; k<n; k++)//�����������߾����� ���������㼯
	      if(fabs(a*x[k]*x[k]+b*x[k] - y[k]) <= eps) 
	        map[i][j]|= (1<<k);
	  }
}
//=============================================================
signed main()
{
	for(int i=0; i<(1<<18); i++)//Ԥ���� ÿ���㼯 ���λ��0 (δ�������ĵ�) 
      for(int j=1 ;j <= 18 && i & (1<<(j-1)); j++);
        lowbit[i] = j;
	T=read();
	for(;T;T--)
	{
	  prepare();
	  for(int i=0; i<all; i++)//ö�ٵ㼯 
	  {
	  	int bit = lowbit[i]-1;//��ǰ�㼯 ��δ�������ĵ� 
	  	for(int k=1; k<=n; k++)//�����µ�������, �������µĵ㼯. 
	  	  ans[i|map[bit][k]] = min(ans[i|map[bit][k]],ans[i]+1);
	  }
	  printf("%d\n",ans[all]);
	}
}
//O(Tn^2 2^n)  
/*
#include<cstdio>
#include<cmath>
#include<cstring>
#include<ctype.h>
#define min(a,b) a<b?a:b
#define lb long double
const lb eps = 1e-12;//��Сֵ(0�Ľ���ֵ 
//=============================================================
int T,n,m,all , map[20][20],ans[524288];
lb x[20],y[20];//�������� 
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
int gcd(int a, int b) {return b?gcd(b,a%b):a;}
void get_ab(int fir,int sec,lb &a, lb &b)//��� ��Ԫһ�η����� 
{
    lb x1=x[fir],x12=x1*x1,y1=y[fir] , x2=x[sec],x22=x2*x2,y2=y[sec];//��ʼ��ϵ����ֵ 
    x1*=100000,x12*=100000,y1*=100000,x2*=100000,x22*=100000,y2*=100000;//����ϵ��ת��Ϊ���� 
    int t1=x1,t12=x12,tt1=y1,t2=x2,t22=x22,tt2=y2 , d=gcd(t12,t22),l=(t12/d*t22);//�������α��� 
    
    t1*=(l/t12),tt1*=(l/t12) , t2*=(l/t22),tt2*=(l/t22),t12=t22=l;//����ͨ��,�Խ��������Ԫ 
    
    b = ((tt2-tt1)*1.0)/((t2-t1)*1.0);//���a,b��ֵ 
    a = (tt1*1.0-t1*b)/t12;
}
void prepare()
{
    memset(ans,127,sizeof(ans)); ans[0]=0;//��ʼ��ansΪ����ֵ 
    memset(map,0,sizeof(map));
    
    n=read(),m=read(); all=(1<<n)-1;
    for(int i=0; i<n; i++) scanf("%Lf%Lf",&x[i],&y[i]);
    for(int i=0; i<n; i++) map[i][n] = (1<<i);//ֻ����һ����������� 
    for(int i=0; i<n; i++)//ö�� �����߾����������� 
      for(int j=i+1; j<n; j++)
      {
        //���Ϸ��ĵ�� 
        if(x[i]>=x[j] && y[i]>y[j] && y[i]/x[i]>=y[j]/x[j]) continue;
        if(x[j]>=x[i] && y[j]>y[i] && y[j]/x[j]>=y[i]/x[i]) continue;
        
        lb a,b; map[i][j]|=(1<<i),map[i][j]|=(1<<j);//����㼯 
        get_ab(i,j,a,b);//���a,b 
        for(int k=0; k<n; k++)//�����������߾����� ���������㼯 
          if(fabs(a*x[k]*x[k]+b*x[k] - y[k]) <= eps) 
            map[i][j]|= (1<<k);
      }
}
//=============================================================
signed main()
{
    T=read();
    for(;T;T--)
    {
      prepare();
      for(int i=0; i<all; i++)//ö�ٵ㼯 
        for(int j=0,sum=1; sum<=(1<<j); j++,sum<<=1) 
          if(!(i&(1<<j)))//ö�ٲ��ڵ㼯�еĵ�
            for(int k=j+1; k<=n; k++)//�����µ�������,�������µĵ㼯. 
              ans[i|map[j][k]] = min(ans[i|map[j][k]],ans[i]+1);
      
      printf("%d\n",ans[all]);
    }
}
*/ 
