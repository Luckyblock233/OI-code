//�����㷨��BFS
//������(1,1)��ת��Ϊ(1,1)������ 
//�ǳ���,��ע��
#include<cstdio>
#include<cstring>
using namespace std;
int xx[12]={-2,-2,-1,1,2,2,2,2,1,-1,-2,-2};//��λ�õ������� 
int yy[12]={1,2,2,2,2,1,-1,-2,-2,-2,-2,-1};
int s[110][110];//���沽�� 
int poi[15000][3];//�������飬���� λ�� 
int main()
{
	int xa,ya,xb,yb;
	scanf("%d%d%d%d",&xa,&ya,&xb,&yb);//���� 
	memset(s,-1,sizeof(s));//��ʼ��s,�����ж�,��ֹ�ظ� 
	int l=1,r=1;//��βָ�� 
	poi[1][1]=1;//��һ������Ԫ����(1,1) 
	poi[1][2]=1;
	s[1][1]=0;//����(1,1)����Ϊ0 
	while(l<=r)//���в�Ϊ�� 
	  {
	  	for(int i=0;i<12;i++)//�оٱ仯���λ�� 
	  	  {
	  	  	int xxx=poi[l][1]+xx[i];//�仯 
	  	  	int yyy=poi[l][2]+yy[i];
	  	  	if(s[xxx][yyy]==-1 && xxx<=100 && yyy<=100 && xxx>0 && yyy>0)//�жϲ����Ƿ�Ϊ�����Ƿ���� 
	  	  	  {
	  	  	  	s[xxx][yyy]=s[poi[l][1]][poi[l][2]]+1;//�仯��Ĳ���Ϊǰλ�ò�����һ 
	  	  	  	r++;
	  	  	  	poi[r][1]=xxx;//������� 
	  	  	  	poi[r][2]=yyy;
			  }
			if(s[xa][ya]!=-1 && s[xb][yb]!=-1)//Ҫ�����λ���Ƿ���ֵ 
			  {
			  	printf("%d\n%d",s[xa][ya],s[xb][yb]);
			  	return 0;//           stop!!!! 
			  }
		  }
		l++;
	  }
}
