//�����Ŀ�Ƚ�����,������һ�ʻ��������Щ��ͬ�� 
//���ȣ�һ��·�����ܻ���ֶ��
//��Σ�����𰸵�˳�� �ǰ��սڵ������򣬲���һ�ʻ������˳��XD 
//��Ȼ��һ�ʻ�ģ����,����Ҫ��һЩ�Ķ� 
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int map[1110][1110];//��ĳ������֮���е�·���� 
int ans[1100];//��𰸵����� 
int oe[1100];//����ÿ���ڵ��·������, ����������� 
int bian[1100];//������ĸ����ڵ� 
bool hao[1100];//�����ж�ĳ���Ƿ����,������ֹbian��������ظ��Ľڵ� 
int num,num1;//��ans��Ԫ������  ��  ����ڵ������ 
int n,m;
void dfs(int i)//��i�ڵ�Ϊ������� 
{
	for(int j=1;j<=num1;j++)//��num1���ڵ����� 
	  {
	  	if(map[i][bian[j]] > 0)//���i��bian[j]֮�仹��· 
	  	  {
			map[i][bian[j]]-=1;//·������һ 
			map[bian[j]][i]-=1;//����·��Ҳ��һ 
	  	  	dfs(bian[j]);//���µĽڵ�Ϊ���,��ʼ�� 
		  }
	  }
	ans[++num]=i;//����ѭ����,��ans��ֵ 
}
int main()
{
	scanf("%d",&n);
	int x,y;
	for(int i=1;i<=n;i++)//�������������� 
	  {
	  	cin>>x>>y; 
	  	if(!hao[x])//���x֮ǰû�г��� 
		  bian[++num1]=x;//�Ͱ����ŵ�bian������ 
	  	if(!hao[y])//���y֮ǰû�г��� 
		  bian[++num1]=y;//ͬ��,�ӽ�ȥ 
	  	hao[x]=hao[y]=1;//��hao������һ,��ʾx,y���ֹ� 
	  	map[x][y]++;//x,y֮��,�������·������+1; 
		map[y][x]++;
	  	oe[x]++;//��x�����ı߼�һ 
	  	oe[y]++;//ͬ�� 
	  }
	sort(bian+1,bian+num1+1);//��bian�����нڵ������������,���ҵ���ĿҪ���,�����С�����. 
	int start=1;//dfs����� 
	int joe=0;//�����ҵ���һ��ż��ı��� 
	for(int i=1;i<=num1;i++)//��num1���ڵ� 
	  { 
	    if(oe[bian[i]]%2 == 1)//�����ҵ���һ����� 
	      {
	        start=bian[i];
	        break;//ͣ���� 
		  }
		if(oe[bian[i]]%2==0 && joe++==0)//�ҵ���һ��ż��,����������ż�� 
		  start=bian[i];
	  }
	dfs(start);//���ҵ��ĵ�Ϊ���,��ʼ�� 
	for(int j=num;j>=1;j--)
	  printf("%d\n",ans[j]);//��Ϊdfs�ݹ��з���ֵ,��������,����Ҫ�ٷ�������� 
	printf("\n");
	return 0;//���������ν��� 
}






































































































































//https://www.luogu.org/recordnew/show/17882949
