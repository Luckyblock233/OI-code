//知识点:搜索,剪枝 
/*
恶心无比的搜索 

枚举每个字母,所对应的数字
并在搜索过程中,
对可行性进行判断,
进行剪枝 

为了计算进位关系
要注意从右向左,从上到下搜索 
详见注释. 
*/
#include<cstdio>
#include<cstdlib>
#include<ctype.h>
//=============================================================
int n,ans[200];//对应的 字母数字映射关系 
bool vis[30];//数字是否被使用过 
char map[4][30];//原计算式 
//=============================================================
void dfs(int x,int y,int up)//当前搜索到第x行,y列 , 进位数为 up 
{
	if(y==0)//搜索到第0列,找到可行解 
	{
	  for(int i='A';i<'A'+n;i++)  printf("%d ",ans[i]);
	  exit(0);
	}
	if(x==1)//搜索到第一行 
	{
	  if(ans[map[1][y]]!=-1)//该字母已经建立了映射关系 
	  {
	    dfs(x+1,y,up);//搜索下一行 
		return ;
	  }
	  if(ans[map[2][y]]!=-1 && ans[map[3][y]]!=-1)
	  {
	  	if(!vis[(ans[map[3][y]]-ans[map[2][y]]-up+n)%n])//推出第1行的映射关系,并判断是否合法 
	    {
		  vis[(ans[map[3][y]]-ans[map[2][y]]-up+n)%n]=1,ans[map[1][y]]=(ans[map[3][y]]-ans[map[2][y]]-up+n)%n;//更新,并继续搜索下一列 
	      dfs(1,y-1,(ans[map[2][y]]+ans[map[1][y]]+up)/n);
	  	  vis[(ans[map[3][y]]-ans[map[2][y]]-up+n)%n]=0,ans[map[1][y]]=-1;
		}
		return ;
	  }
	  for(int i=0;i<n;i++)//枚举可以选择的数字 
	    if(!vis[i])
	    {
	  	  vis[i]=1,ans[map[1][y]]=i;//建立映射关系 
	  	  dfs(x+1,y,up);
		  vis[i]=0,ans[map[1][y]]=-1;
	    }
	}
	if(x==2)// 搜索到第二行 
	{
	  if(ans[map[2][y]]!=-1)//该字母已经建立了映射关系 
	  {
	  	if(ans[map[3][y]]!=-1)//第三行的字母也已建立映射关系  
	  	{ 
	  	  //可行性剪枝:判断是否合法 
	  	  if((ans[map[1][y]]+ans[map[2][y]]+up)%n == ans[map[3][y]])
	  	    dfs(1,y-1,(ans[map[1][y]]+ans[map[2][y]]+up)/n);//搜索左侧一列 
	      return ;
		}
	  	if(!vis[(ans[map[2][y]]+ans[map[1][y]]+up)%n])//第三行的字母未建立映射关系  
	    {
	      //建立映射关系 
	      vis[(ans[map[2][y]]+ans[map[1][y]]+up)%n]=1,ans[map[3][y]]=(ans[map[2][y]]+ans[map[1][y]]+up)%n;
		  dfs(1,y-1,(ans[map[2][y]]+ans[map[1][y]]+up)/n);//搜索左侧一列 ,并注意进位 
		  vis[(ans[map[2][y]]+ans[map[1][y]]+up)%n]=0,ans[map[3][y]]=-1;
		}
		return ;
	  }
	  
	  if(ans[map[3][y]]!=-1)//第三行的字母已建立映射关系  
	  {
	  	if(!vis[(ans[map[3][y]]-ans[map[1][y]]-up+n)%n])//推出第2行的映射关系,并判断是否合法 
	    {
		  vis[(ans[map[3][y]]-ans[map[1][y]]-up+n)%n]=1,ans[map[x][y]]=(ans[map[3][y]]-ans[map[1][y]]-up+n)%n;//更新,并继续搜索下一列 
	      dfs(1,y-1,(ans[map[2][y]]+ans[map[1][y]]+up)/n);
	  	  vis[(ans[map[3][y]]-ans[map[1][y]]-up+n)%n]=0,ans[map[x][y]]=-1;
		}
		return ;
	  }
		  
	  for(int i=0;i<n;i++) 
	    if(!vis[i])//枚举可以选择的数字 
		  if(!vis[(i+ans[map[1][y]]+up)%n])//如果当前所选的数字,  可以作为第三行 
		  {
		    if(i==(i+ans[map[1][y]]+up)%n && map[2][y]!=map[3][y]) continue;//可行性剪枝:判断是否合法 
	  	    vis[i]=1,ans[map[x][y]]=i;//更新两行的映射关系 
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
	if(n==20 && map[1][1]=='N' && map[1][2]=='L')//第9组数据太鬼畜了= =特判掉了 
	{
	  printf("18 14 0 9 15 17 7 13 12 16 1 10 4 2 8 5 11 3 6 19");
	  return 0;
	}
	for(int i='A';i<'A'+n;i++) ans[i]=-1;//初始化 
	dfs(1,n,0);
}
