//֪ʶ��:ģ�� 
/*
����ö�ٽ����Ļ�ľ  
����Ϊ���ǻ��ڵ�����ľ��  
ͨ�������������ϵ��  
���Եõ�ÿ����ľ�����½ǵ�����  

���������½ǵ����꣬  
���Թ���һ��С��ľ  
���ж����޻�ľ�ڵ�  
�������ᱻ�ڵ��Ĳ��ּ����ַ�����  
����  
*/ 
#include<cstdio>
#include<cctype>
#include<cstring>
#define max(a,b) a>b?a:b
using namespace std;
//=======================================================
const char stdd[8][8]=
{
	{' ' ,' ' ,' ' ,' ' ,' ' ,' ' ,' ' ,' ' },//��λ������
	{' ' ,'+' ,'-' ,'-' ,'-' ,'+' ,'=' ,'=' },
	{' ' ,'|' ,' ' ,' ' ,' ' ,'|' ,'/' ,'=' },
	{' ' ,'|' ,' ' ,' ' ,' ' ,'|' ,' ' ,'+' },
	{' ' ,'+' ,'-' ,'-' ,'-' ,'+' ,' ' ,'|' },
	{' ' ,'=' ,'/' ,' ' ,' ' ,' ' ,'/' ,'|' },
	{' ' ,'=' ,'=' ,'+' ,'-' ,'-' ,'-' ,'+' },
};
int n,m,K,L;
int map[55][55];
char ans[1010][1010];
int dep[1010][1010];
//=======================================================
inline int read()
{
	int fl=1,w=0;char ch=getchar();
	while(!isdigit(ch)) if(ch=='-') {fl=-1,ch=getchar();break;}
	while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
	return fl*w;
}
void add(int zx,int zy,int depp)//���һ��������
{
	int zzy,zzx;
	for(zzy=zy ; zzy<=zy+5; zzy++)//ö������
	  for(zzx=zx ; zzx<=zx+6; zzx++)
	    if(ans[zzy][zzx] == '.' || depp==dep[zzy][zzx])//�������
	    {
	      ans[zzy][zzx]=(stdd[zzy-zy+1][zzx-zx+1]=='='?ans[zzy][zzx]:stdd[zzy-zy+1][zzx-zx+1]);//��ֵ
	      dep[zzy][zzx]=depp;	
		}
}
signed main()
{
	memset(ans,46,sizeof(ans));//��ʼ��
	memset(dep,127,sizeof(dep));
	scanf("%d%d ",&m,&n);
	for(int i=m;i>=1;i--)
	  for(int j=1;j<=n;j++)
	    scanf("%d",&map[i][j]);
	int now_y=-1,now_x=1;
	for(int i=1;i<=m;i++)//ö������
	{
	  now_y+=2;
	  for(int j=1;j<=n;j++)
	  {
	  	for(int k=1;k<=map[i][j];k++)
		{
	  	  add(now_x,now_y+(k-1)*3,i);//��Ӿ���
	  	  K=max(K,now_y+3*k+2);
		}
		L=max(L,now_x+6);
		now_x+=4;
	  }
	  now_x=2*(i+1)-1;
	}
	for(int i=K;i>=1;putchar('\n'),i--)//���
	  for(int j=1;j<=L;j++)
	  	putchar(ans[i][j]);
}
