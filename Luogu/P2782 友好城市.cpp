//�㷨��DP/���ֲ��� 
//˼·:�Ȱ�һ�߳��е������������
//Ȼ��������һ�ߵ������������ 
/*
ԭ��: 
��һ�߳��е�������������,
�������������һ��Ҳ������������
�������Ա�֤���е�·�������ཻ
������ܷ���,��ʵ�ܹǸ�,
����Ҫ�ҵ����Ĳ��ཻ��·��
���ҵ���һ������������еĳ��� 
*/ 
#include<cstdio>
#include<algorithm>
using namespace std;
struct baka9
{
	int c1,c2;
}a[200010];
int n;
int st1[200010]={-10000000};//���ֲ��� 
int marx;
bool cmp(baka9 aa,baka9 bb)//���� 
{
	return aa.c1<bb.c1;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  scanf("%d%d",&a[i].c1,&a[i].c2);
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	  {
	  	if(a[i].c2>st1[marx])
		  st1[++marx]=a[i].c2;//�ȶ�ͷԪ�ش�,ֱ�Ӽ��� 
	  	else//���ֲ��ҵ�һ���������,������ǰ�� 
	  	  {
	  	  	int l=1,r=marx,mid;
	  	  	while(l<=r)
	  	  	  {
	  	  	  	mid=(l+r)/2;
	  	  	  	if(a[i].c2>st1[mid])
	  	  	  	  l=mid+1;
	  	  	  	else
	  	  	  	  r=mid-1;
			  }
			st1[l]=a[i].c2;
		  }
	  }
	printf("%d",marx);
}
/*
50��TLE DP���� 
#include<cstdio>
#include<algorithm>
using namespace std;
struct baka9
{
    int c1,c2;
}a[200010];
int n;
int f[200010];
int ans;
bool cmp(baka9 aa,baka9 bb)
{
    return aa.c1<bb.c1;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
      scanf("%d%d",&a[i].c1,&a[i].c2);
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)
      {
      	f[i]=1;
      	for(int j=1;j<i;j++)
      	  if(a[j].c2<=a[i].c2)
      	    f[i]=max(f[j],f[j]+1);
      	if(f[i]>ans) ans=f[i];
      }
    printf("%d",ans);
}
*/ 
