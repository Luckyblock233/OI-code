//֪ʶ��:dfs,ͼ 
/*
��ĿҪ��:��ͼ����С����Ԫ�ظ���
 
������֪:
����һ����ͨͼ��,
������һ����

��:����ÿһ����ͨ��,
����һ��dfs,
���ĳ�㵽���2��,
���ҵ��˻� ,
���Ĵ�С=�˴δ˵��dfs��-�ϴδ˵��sfs�� 

��������ͨ��Ļ���Сȡmin,
���� 
*/
#include<cstdio>
#include<cctype>
#include<algorithm>
const int MARX = 2e7+10;
//==========================================================================
int n,minn=MARX;
int a[MARX],ans[MARX];
bool used[MARX];//�Ƿ񱻵���� 
bool flag[MARX];//��ĳһ�εݹ���,�Ƿ񱻵��� 
//==========================================================================
inline int read()
{
	int fl=1,w=0;char ch=getchar();
	while(!isdigit(ch) && ch!='-') ch=getchar();
	if(ch=='-') fl=-1;
	while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
	return fl*w;
}
void dfs(int node,int num)//nodeΪ��ǰ���� , numΪdfs��
{
    if(used[node]) return;//���������,ֱ��return; 
    if(flag[node]) minn=std::min(minn,num-ans[node]); //ĳ�㱻������2��,���ҵ��˻� 
    else
    {
      ans[node]=num,flag[node]=1;//����,���������� 
      dfs(a[node],num+1);
      used[node]=1;
    }
}
//==========================================================================
signed main()
{
    n=read();
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<=n;i++)  dfs(i,0);//��ͷ��ʼ�� 
    printf("%d",minn);
}
