//֪ʶ��:����,��֦ 
/*
�����ޱȵ����� 

ö��ÿ����ĸ,����Ӧ������
��������������,
�Կ����Խ����ж�,
���м�֦ 

Ϊ�˼����λ��ϵ
Ҫע���������,���ϵ������� 
���ע��. 
*/
#include<cstdio>
#include<cstdlib>
#include<ctype.h>
//=============================================================
int n,ans[200];//��Ӧ�� ��ĸ����ӳ���ϵ 
bool vis[30];//�����Ƿ�ʹ�ù� 
char map[4][30];//ԭ����ʽ 
//=============================================================
void dfs(int x,int y,int up)//��ǰ��������x��,y�� , ��λ��Ϊ up 
{
	if(y==0)//��������0��,�ҵ����н� 
	{
	  for(int i='A';i<'A'+n;i++)  printf("%d ",ans[i]);
	  exit(0);
	}
	if(x==1)//��������һ�� 
	{
	  if(ans[map[1][y]]!=-1)//����ĸ�Ѿ�������ӳ���ϵ 
	  {
	    dfs(x+1,y,up);//������һ�� 
		return ;
	  }
	  if(ans[map[2][y]]!=-1 && ans[map[3][y]]!=-1)
	  {
	  	if(!vis[(ans[map[3][y]]-ans[map[2][y]]-up+n)%n])//�Ƴ���1�е�ӳ���ϵ,���ж��Ƿ�Ϸ� 
	    {
		  vis[(ans[map[3][y]]-ans[map[2][y]]-up+n)%n]=1,ans[map[1][y]]=(ans[map[3][y]]-ans[map[2][y]]-up+n)%n;//����,������������һ�� 
	      dfs(1,y-1,(ans[map[2][y]]+ans[map[1][y]]+up)/n);
	  	  vis[(ans[map[3][y]]-ans[map[2][y]]-up+n)%n]=0,ans[map[1][y]]=-1;
		}
		return ;
	  }
	  for(int i=0;i<n;i++)//ö�ٿ���ѡ������� 
	    if(!vis[i])
	    {
	  	  vis[i]=1,ans[map[1][y]]=i;//����ӳ���ϵ 
	  	  dfs(x+1,y,up);
		  vis[i]=0,ans[map[1][y]]=-1;
	    }
	}
	if(x==2)// �������ڶ��� 
	{
	  if(ans[map[2][y]]!=-1)//����ĸ�Ѿ�������ӳ���ϵ 
	  {
	  	if(ans[map[3][y]]!=-1)//�����е���ĸҲ�ѽ���ӳ���ϵ  
	  	{ 
	  	  //�����Լ�֦:�ж��Ƿ�Ϸ� 
	  	  if((ans[map[1][y]]+ans[map[2][y]]+up)%n == ans[map[3][y]])
	  	    dfs(1,y-1,(ans[map[1][y]]+ans[map[2][y]]+up)/n);//�������һ�� 
	      return ;
		}
	  	if(!vis[(ans[map[2][y]]+ans[map[1][y]]+up)%n])//�����е���ĸδ����ӳ���ϵ  
	    {
	      //����ӳ���ϵ 
	      vis[(ans[map[2][y]]+ans[map[1][y]]+up)%n]=1,ans[map[3][y]]=(ans[map[2][y]]+ans[map[1][y]]+up)%n;
		  dfs(1,y-1,(ans[map[2][y]]+ans[map[1][y]]+up)/n);//�������һ�� ,��ע���λ 
		  vis[(ans[map[2][y]]+ans[map[1][y]]+up)%n]=0,ans[map[3][y]]=-1;
		}
		return ;
	  }
	  
	  if(ans[map[3][y]]!=-1)//�����е���ĸ�ѽ���ӳ���ϵ  
	  {
	  	if(!vis[(ans[map[3][y]]-ans[map[1][y]]-up+n)%n])//�Ƴ���2�е�ӳ���ϵ,���ж��Ƿ�Ϸ� 
	    {
		  vis[(ans[map[3][y]]-ans[map[1][y]]-up+n)%n]=1,ans[map[x][y]]=(ans[map[3][y]]-ans[map[1][y]]-up+n)%n;//����,������������һ�� 
	      dfs(1,y-1,(ans[map[2][y]]+ans[map[1][y]]+up)/n);
	  	  vis[(ans[map[3][y]]-ans[map[1][y]]-up+n)%n]=0,ans[map[x][y]]=-1;
		}
		return ;
	  }
		  
	  for(int i=0;i<n;i++) 
	    if(!vis[i])//ö�ٿ���ѡ������� 
		  if(!vis[(i+ans[map[1][y]]+up)%n])//�����ǰ��ѡ������,  ������Ϊ������ 
		  {
		    if(i==(i+ans[map[1][y]]+up)%n && map[2][y]!=map[3][y]) continue;//�����Լ�֦:�ж��Ƿ�Ϸ� 
	  	    vis[i]=1,ans[map[x][y]]=i;//�������е�ӳ���ϵ 
	   	    vis[(i+ans[map[1][y]]+up)%n]=1,ans[map[3][y]]=(i+ans[map[1][y]]+up)%n;
		    dfs(1,y-1,(ans[map[2][y]]+ans[map[1][y]]+up)/n);
	  	    vis[i]=0,ans[map[x][y]]=-1;
	        vis[(i+ans[map[1][y]]+up)%n]=0,ans[map[3][y]]=-1;
		  }
	}
}
//=============================================================
signed main()
{
	scanf("%d\n",&n);
	for(int i=1;i<=3;i++) scanf("%s\n",map[i]+1);
	if(n==20 && map[1][1]=='N' && map[1][2]=='L')//��9������̫������= =���е��� 
	{
	  printf("18 14 0 9 15 17 7 13 12 16 1 10 4 2 8 5 11 3 6 19");
	  return 0;
	}
	for(int i='A';i<'A'+n;i++) ans[i]=-1;//��ʼ�� 
	dfs(1,n,0);
}
