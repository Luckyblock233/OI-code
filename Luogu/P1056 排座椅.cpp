//����Ŀ����˼·:
//�ֱ��ҵ��ܺ����������ѧ��,�����ҵ�,�������м�ķָ����ֿܷ���ѧ������++.
// �ٶԺ���������ķָ��߰��շֿ�ѧ���������н�������,�������ҵ��˷ֿ����ѧ������
//֮���ٰ������˳������һ����
//���ֱ����k,l������ 

//��һ���ܼ򵥵�̰��(˼·��Сʱ,����2����) 
#include<cstdio>
#include<algorithm>
using namespace std;
struct aax
{
	int ren,data;
}
ax[1010];// �ֿ�����ѧ������ 
struct aay
{
	int ren,data;
}ay[1010];// �ֿ�����ѧ������ 
int lx=0,ly=0;
bool cmpdax(aax x,aax y)//���շֿ�ѧ��������С���� 
{
	if(x.ren==y.ren)
	  return x.data<y.data;
	return x.ren>y.ren;
}
bool cmpday(aay x,aay y)
{
	if(x.ren==y.ren)
	  return x.data<y.data;
	return x.ren>y.ren;
}
bool cmps1(aax x,aax y)
{
	return x.data<y.data;
}
bool cmps2(aay x,aay y)
{
	return x.data<y.data;//����������� 
}
int main()
{
	int m,n,k,l,d;
	scanf("%d%d%d%d%d",&m,&n,&k,&l,&d);
	for(int i=1;i<=m;i++)
	  ax[i].data=i;// ����� 
	for(int i=1;i<=n;i++)
	  ay[i].data=i;//����� 
	for(int i=0;i<d;i++)//���� 
	  {
	  	int z[5],judge;//�������� 
	  	scanf("%d%d%d%d",&z[1],&z[2],&z[3],&z[4]);
	  	if(z[1]==z[3]) judge=0;//�����ں���˵�� 
	  	if(z[2]==z[4]) judge=1;//����������˵�� 
	  	if(judge==0) ax[min(z[2],z[4])].ren++;//��Ӧ����ָ���++ 
		else ay[min(z[1],z[3])].ren++;//��Ӧ����ָ���++ 
	  }
//------------------------------------------------------------------------------------ 
	sort(ax+1,ax+n+1,cmpdax);//�߳������� 
	sort(ay+1,ay+m+1,cmpday);
	sort(ax+1,ax+l+1,cmps1);
	sort(ay+1,ay+k+1,cmps2);
	for(int i=1;i<=k;i++)//ֱ��������� 
	  printf("%d ",ay[i].data);
	printf("\n");
	for(int i=1;i<=l;i++)
	  printf("%d ",ax[i].data);
}
