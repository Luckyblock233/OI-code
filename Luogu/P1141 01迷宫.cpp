//ʹ���㷨��BFS
//������������� 
//Ϊ����ÿ�ζ�����,���³�ʱ.
//����һ��ans����,���ǵڼ�������ͨ��
//�ж������������û��λ��һ����ͨ����
//����ֱ�������
//û����ʼ����
//�Ե����ÿһ����,�������Ƿ����µ�һ����ͨ����
//����¼����ͨ���Ԫ�ظ���,��Ϊ�� 
#include<cstdio>
#include<queue>
using namespace std;
struct baka9//���нṹ��,�����꼰 ��һ���� 
{
	int x,y;
	char ju;
};
char tu[1010][1010];//��ͼ 
int ans[1010][1010];//����ͨ�� 
int anss[100000010];// ��� 
int ax[5]={1,-1,0,0};//����仯�� 
int ay[5]={0,0,1,-1};
int n,m,q1,q2;
int sum,num;
char k[1010];//�����ַ� 
queue <baka9> s;
void bfs();
int main()
{
	scanf("%d%d\n",&n,&m);
	for(int i=1;i<=n;i++)//����ͼ 
	  {
	  	gets(k);
	    for(int j=0;j<n;j++)
	      tu[i][j+1]=k[j];
	  }
	for(int i=1;i<=m;i++)//��ʼ���� 
	  {
	  	scanf("%d%d",&q1,&q2);
	  	if(ans[q1][q2])//���ѵ��� ,ֱ����� 
	  	  {
	  	  	printf("%d\n",anss[ans[q1][q2]]);
	  	  	continue;
		  }
		ans[q1][q2]=++num;//û�б��ѵ���,�ͼ�����ͨ��,����ʼ���� 
	  	baka9 tmp={q1,q2,tu[q1][q2]};
	  	s.push(tmp);
		bfs();
		anss[ans[q1][q2]]=sum;//��¼�� 
		printf("%d\n",anss[ans[q1][q2]]);//��� 
	  }
}
void bfs()//��׼���� 
{
	sum=1;
	while(!s.empty())
	  {
	  	baka9 tmp=s.front();
	  	s.pop();
	  	for(int i=0;i<4;i++)
	  	  {
	  	  	int xx=tmp.x+ax[i];//ö�ٿɵ���ĵ� 
	  	  	int yy=tmp.y+ay[i];
	  	  	if(xx>=1 && xx<=n)
	  	  	  if(yy>=1 && yy<=n)
	  	  	    if(!ans[xx][yy] && tu[xx][yy]!=tu[tmp.x][tmp.y])//�������� 
	  	  	      {
	  	  	      	baka9 tmpp={xx,yy,tu[xx][yy]};
	  	  	      	s.push(tmpp);//ѹ����� 
	  	  	      	ans[xx][yy]=num;//������ͨ�� 
	  	  	      	sum++;
				  }
		  }
	  }
}
