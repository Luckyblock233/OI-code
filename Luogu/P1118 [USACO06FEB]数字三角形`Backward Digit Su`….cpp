//�㷨:dfs����
/*
����Ŀ�õ����������.
�ֶ�ģ�⼸�����ݣ������Ƴ���
��n=3ʱ��sum=1*a+2*b+3*c
��n=4ʱ��sum=1*a+3*b+3*c+1*d
��n=5ʱ��sum=1*a+4*b+6*c+4*d+1*e 
(a,b,c,d,e...��Ϊ���������и�λ�õ���) 
���Կ���, ��ʽ��ϵ������������е�n���λ��ֵһһ��Ӧ
��:
		�ȼ������n��������ǵ�ֵ�� 
        ö�ٸ�λ�õ�ֵ,
		��ʹ���Ƿֱ���Դ�λ�õ�ϵ��
		�������ǵ���ֵ.
		����λ�ö�ö�����,����ֵ����sumʱ,���ҵ��˽�
		��Ϊѭ��ö�ٸ�λ����ʱ���ǰ��ֵ���ö�ٵ�
		���һ���ҵ��ļ����Ž⣬ֱ��������� 
�������1~10�� 
1 
1 1 
1 2 1 
1 3 3 1 
1 4 6 4 1 
1 5 10 10 5 1 
1 6 15 20 15 6 1 
1 7 21 35 35 21 7 1 
1 8 28 56 70 56 28 8 1 
1 9 36 84 126 126 84 36 9 1 
*/
#include<cstdio>
using namespace std;
int a[15];
bool use[12350];
int ans[15];
int n,sum,n1;
bool flag;
void dfs(int i,int s)//iΪ��ǰ������λ��,sΪ��ǰ��ȷ���ĸ�λ�õ��ܺ� 
{
	if(s>sum || flag) return ;//����ܺʹ���sum�����ҵ��˽�,ֹͣ 
	if(i==n+1)//����λ�ö�ȷ�����ܺ�Ϊsum 
	  {
	    if(s==sum)
	      {
	        for(int j=1;j<=n;j++)
	          printf("%d ",ans[j]);//������� 
	        flag=1;//��� 
		  }
		return ;
	  }
	for(int j=1;j<=n;j++)//��1~n����û���ù����� 
	  {
	    if(flag) return ;
	    if(!use[j] && s+j*a[i]<=sum)//��֦,��֤�ܺͲ�����sum 
	      {
	  	    use[j]=1;//��� 
	  	    ans[i]=j;
	  	    dfs(i+1,s+j*a[i]);//������һλ�� 
	  	    use[j]=0;//���� 
	      }
	  } 
}
int main()
{
	scanf("%d%d",&n,&sum);
	while(++n1 <= n)//�����n���������� 
	  {
	  	a[n1]=1;// 
	  	for(int i=n1-1;i>=2;i--) 
	  	  a[i]+=a[i-1];
	  }
	dfs(1,0);//�ӵ�һ��λ�ÿ�ʼ�� 
}
/*
��n���������ǵļ������
#include<cstdio>
using namespace std;
int a[1000000];
int main()
{
	int n;
	scanf("%d",&n);
	int n1=0;
	while(++n1 <= n)
	  {
	  	a[n1]=1;
	  	for(int i=n1-1;i>=2;i--)
	  	  a[i]+=a[i-1];
	  	for(int i=1;i<=n1;i++)
	  	  printf("%d ",a[i]);
	  	printf("\n");
	  }
} 
*/

//-----------------------------------------------------------

/*
����dfs��TLE��70�ִ��룺
#include<cstdio>
using namespace std;
int n,sum;
bool flag;
int ans[20];
bool use[100000];
int tans[20];
bool judge()
{
    int a[20];
    for(int i=1;i<=n;i++)
      a[i]=ans[i];
    int n1=n;
    while(n1--)
      {
      	for(int i=1;i<=n1;i++)
      	  a[i]+=a[i+1];
      }
    if(a[1]==sum)
      return 1;
    return 0;
}
void dfs(int l)
{
    if(l>n+1)
      return ;
    if(l==n+1)
      {
        if(judge())
      	  {
      	    bool flag1=1;
      	    if(tans[1])
      	  	  {
      	  	    if(ans[0] >= tans[0])
      	  	      flag1=0;
              }
            if(flag1)
          	  {  	
          	  	for(int i=0;i<=n;i++)
          	  	  tans[i]=ans[i];
          	  	flag=1;
          	  }
          }
        return ;
      }
    for(int i=1;i<=n;i++)
      if(!use[i])
        {
      	  use[i]=1;
      	  ans[l]=i;
      	  ans[0]+=i;
      	  dfs(l+1);
      	  use[i]=0;
      	  ans[0]-=i;
        }
}
int main()
{
    scanf("%d%d",&n,&sum);
    dfs(1);
    if(flag)
      for(int i=1;i<=n;i++)
        printf("%d ",tans[i]);
} 
*/ 
