//֪ʶ��: dfs 
/*
��Ŀ����: 
Ҫ�ҵ����еĵ��� yizhong
���ҵ��ʵ����з��򲻱� 

�㷨ʵ��: 
ֱ��ö����ĸ y���ֵ�λ�� ,
Ȼ������Χ8��������������ĸ i
�����,���մ˷���������м��
��������������
�������������,���б�Ǽ�¼

�������Щ��δ�����,
������ '*' ���� 
*/
#include<cstdio>
#include<iostream>
#include<string>
const int ex[9]={0,1,-1,0,0,1,-1,1,-1};
const int ey[9]={0,0,0,1,-1,1,1,-1,-1};
//=============================================================
int n; 
std::string stdd = "[yizhong]";//��׼���� 
char map[110][110];//ԭͼ 
bool word[110][110];//����Ƿ�Ϊ����, 
//=============================================================
void check(int x,int y)
{
	for(int i=1,nx=x+ex[i],ny=y+ey[i];i<=8;i++,nx=x+ex[i],ny=y+ey[i])//ö���ܵ���ĵ� 
	  if(map[nx][ny]=='i')//�ڶ���λ�� 
	    {
	      bool flag=1;
	      for(int j=1,nowx=x,nowy=y;j<=7;j++,nowx=nowx+ex[i],nowy=nowy+ey[i])//����Ƿ����������� 
	        if(map[nowx][nowy]!=stdd[j])
	          flag=0;
	      if(flag)
	        for(int j=1,nowx=x,nowy=y;j<=7;j++,nowx=nowx+ex[i],nowy=nowy+ey[i])//�ڵ��ʵ�������� 
	          word[nowx][nowy]=1;	
		}
}
//=============================================================
signed main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)
	    std::cin>>map[i][j];
	
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)
	    if(map[i][j]=='y')//�ҵ� y ���ֵĵ� 
	      check(i,j);
	
	for(int i=1;i<=n;putchar('\n'),i++) 
	  for(int j=1;j<=n;j++)
	    printf("%c",word[i][j]?map[i][j]:'*');//��δ����ǵĵ�ת��Ϊ'*' 
}
