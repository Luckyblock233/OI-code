//ʹ���㷨�����鼯+ǰ׺��
//˼·: ���ڴ���,��ģ������õ�90��,����Ҫ����һЩ�Ż���ʩ
//����,�ںϲ�ʱ,���ܶ�ÿһ�Ҿ���,����������֮ǰ�ľ�������,���Ի�TLE

//��������l����浱ǰ���еĳ��� 
//��ʹ��һ��pree����,�洢��ǰ����,������׾���֮��ľ���
//�ϲ�ʱ,ֻ��Ҫʹԭ���׾�����preeֵ����ǰ��ľ�������l����
//����find������,ѹ��֮ǰά��pree��ֵ.

#include<cstdio>
#include<iostream>
using namespace std;
int pre[30010];//������ 
int pree[30010];//�洢��ǰ����,������׾���֮��ľ���
int l[30010];//��ǰ���еĳ���  
int find(int x)//�鼯��ά��pree 
{
    if(pre[x]==x)
      return x;
    int rx=find(pre[x]);//�ȼ����µĸ��� 
    pree[x]+=pree[pre[x]];//��ʹpree��x��������ԭ�������¸��׵ľ��룬�͵õ���x���¸��׵ľ��� 
	return pre[x]=rx;//�ٷ��� 
}
int find1(int x,int y)//�Ҵ� 
{
    int r1=find(x);//�Ҹ���ά��pree 
    int r2=find(y);
    if(r1 !=r2)
	  return -1;
    int l1=pree[x];
    int l2=pree[y];
    return max(l1,l2)-min(l1,l2)-1;//���ֵ,���� 
}
void join(int x,int y)//���� 
{
    int r1=find(x);
    int r2=find(y);
    pree[r1]+=l[r2];//Ϊԭ����Ԫ�ص����׵ľ��� ����ֵ 
    pre[r1]=r2;//���ְ�= = 
    l[r2]+=l[r1];//��ǰ�г��ȸ��� 
    l[r1]=0;//ԭ�г���Ϊ0 
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=30002;i++)//��ʼ�� 
      {
      	pre[i]=i;
      	pree[i]=0;
      	l[i]=1;
      }
    for(int i=1;i<=t;i++)//�ش�ѯ�� 
      {
      	char judge;
      	cin>>judge;
      	int x,y;
      	scanf("%d%d",&x,&y);
      	if(judge=='M')
           join(x,y);
        if(judge=='C')
          printf("%d\n",find1(x,y));
      }
}
//����Ϊ��ģ��90��TLE���� 
/*
#include<cstdio>
#include<iostream>
using namespace std;
int pre[30010];
int pree[30010];
int l[30010];
int find(int x)
{
    if(pre[x]==x)
      return x;
    int rx=find(pre[x]);
    pree[x]+=pree[pre[x]];
    return pre[x]=rx;
}
int find1(int x,int y)
{
    int r1=find(x);
    int r2=find(y);
    if(r1 !=r2)
      return -1;
    int l1=pree[x];
    int l2=pree[y];
    return max(l1,l2)-min(l1,l2)-1;
}
void join(int x,int y)
{
    int r1=find(x);
    int r2=find(y);
    pree[r1]+=l[r2];
    pre[r1]=r2;
    l[r2]+=l[r1];
    l[r1]=0;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=30002;i++)
      {
      	pre[i]=i;
      	pree[i]=0;
      	l[i]=1;
      }
    for(int i=1;i<=t;i++)
      {
      	char judge;
      	cin>>judge;
      	int x,y;
      	scanf("%d%d",&x,&y);
      	if(judge=='M')
           join(x,y);
        if(judge=='C')
          printf("%d\n",find1(x,y));
      }
}
*/ 
