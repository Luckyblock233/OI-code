//�㷨:DP/����/̰��
//����һ��01����
//����Ŀ�÷�ΪȨֵ,ʣ��ʱ��Ϊ����. 
//�����,
//ѭ���ҵ��ܹ�ʹ ��������k �����ѵ���Сʱ��

//�ٽ�ˢ��ʱ����������,
//�ҵ��� ʣʣ��ʱ�� ������ɵĸ������� 
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,k,r1;
int r2,ans;
int t1[15],t2[15],s[15];
int f[150];
int main()
{
	scanf("%d%d%d%d",&n,&m,&k,&r1);
	for(int i=1;i<=n;i++) scanf("%d",&t1[i]);//���� 
	for(int i=1;i<=m;i++) scanf("%d",&t2[i]);
	for(int i=1;i<=m;i++) scanf("%d",&s[i]);
	sort(t1+1,t1+n+1);
	
	for(int i=1;i<=m;i++)//01����,�ҵ� ʹ ��������k �����ѵ���Сʱ��
      for(int j=r1;j>=t2[i];j--)
        f[j]=max(f[j],f[j-t2[i]]+s[i]);
    for(int i=1;i<=r1;i++) 
      if(f[i]>=k)
        {
          r2=r1-i;
          break;
		}
	for(int i=1;i<=n;i++)//�Ҹ��� 
	  if(r2>=t1[i]) ans++,r2-=t1[i];
	  else  break;
	printf("%d",ans);
}
