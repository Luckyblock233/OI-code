//֪ʶ��:���鼯
/*
���������������� , 
��Ҳ�����ֹ�ϵ
��ά���������鼯������ȡ
��������ά���������鼯:

�������ռ�Ĳ��鼯 , 
1~n ,     ��ͬ��
n+1~2*n , ������
2*n+1~3*n �����

���x��y��ͬ�� , 
�� x,y���� , 
��x+n,y+n(��x,y������)���� , 
��x+2*n,y+2*n(��x,y�����)���� 

���x��y�ĵ��� , 
�� x��y�ĵ���y+2*n���� , 
��x������x+n �� y�ĵ���y+2*n ���� , 
��x�ĵ���x+2*n��y������y+n����.

ÿ�β�ѯʱ,��ѯx,y�ͶԷ�������,���˹�ϵ
�Ƿ�������Ĺ�ϵì�ܼ���
*/
#include<cstdio>
#include<cctype>
const int MARX = 5e4+10;
//=======================================================
int n,k,ans;
int pre[MARX*3];
//=======================================================
inline int read()
{ 
	int fl=1,w=0;char ch=getchar();
	while(!isdigit(ch) && ch!='-') ch=getchar();
	if(ch=='-') fl=-1;
	while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
	return fl*w;
}
int find(int x)//�鼯
{
	return pre[x]==x?x:pre[x]=find(pre[x]);
}
void join(int x,int y)//����
{
	int fa1=find(x),fa2=find(y);
	pre[fa1]=fa2;
}
//=======================================================
signed main()
{
	n=read(),k=read();
	for(int i=1;i<=3*n;i++) pre[i]=i;//��ʼ��
	for(int i=1;i<=k;i++)
	{
	  int q=read(),x=read(),y=read();
	  if(x>n || y>n) {ans++;continue;}//�������ı�Ŵ���n,���ȻΪ�ٻ�
	  if(q==1)//���x,yΪͬ��
	  {
		if(find(x+n)==find(y) || find(x+2*n)==find(y)) {ans++;continue;}//��ѯx�Ƿ��y,y�Ƿ��x
		join(x,y),join(x+n,y+n),join(x+2*n,y+2*n);//���ͬ���ϵ
	  }
	  if(q==2)//���x��y�ĵ���
	  {
		if(find(x)==find(y) || find(x+2*n)==find(y)){ans++;continue;}//��ѯx��y�Ƿ���ͬ��,y�Ƿ��x
		join(x,y+2*n),join(x+n,y),join(x+2*n,y+n);//��ӵжԹ�ϵ
	  }
	}
	printf("%d",ans);
} 
