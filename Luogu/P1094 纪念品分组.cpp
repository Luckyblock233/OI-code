//֪ʶ��:̰�� 
/*
���������н�������
���Է���:
1.����ʱ����,��С������֮��<=w
  ��ô�������������һ��,һ���ǽ��ŵ�
2.����ʱ���,��С������֮��>w
  ��ô��������,�������������һ��
  ��������������Ϊһ��,
  һ���ǽ��ŵ�.

������������, 
ʹ����β��ָ��ģ�⼴�� 
*/
#include<cstdio>
#include<algorithm>
#include<ctype.h>
const int MARX = 3e4+10;
//=============================================================
int w,n,ans , p[MARX];
//=============================================================
inline int read()
{
	int fl=1,w=0;char ch=getchar();
	while(!isdigit(ch) && ch!='-') ch=getchar();
	if(ch=='-') fl=-1;
	while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
	return fl*w;
}
//=============================================================
signed main()
{
	w=read(),n=read();
	for(int i=1;i<=n;i++) p[i]=read();
	std::sort(p+1,p+n+1);//���� 
	for(int l=1,r=n;l<=r;)
	{
	  if(p[l]+p[r]<=w) l++,r--,ans++;//�������һ�� 
	  else r--,ans++;//�����ĵ������һ�� 
	}
	printf("%d",ans);
}
