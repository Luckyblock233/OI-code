//֪ʶ��:bfs/��״�ṹ 
/*
�Գƶ������Ķ���:
1. ��������
2. ����������нڵ����������������
   ������ԭ����Ӧλ�õĽṹ��ͬ�ҵ�Ȩ��ȡ�
   
���ж���һ����Ϊ������ Ϊ�Գƶ�����
�����ʹͬ��� , ������� ������ͬ�ĵ� 
�ṹ�Գ�(��ͬʱ���� �� ͬʱ������) , 
�ҵ�Ȩֵ��ͬ 


��:����ͨ����������,��ö�� ͬ��� , ������� ������ͬ�ĵ� 
�ֽ����ڵ�����Ҷ��ӷ������
ÿ��ȡ������Ԫ�� 
Ȼ���ж����ǵĶ��� 
�Ƿ�ṹ�Գ� (��: ����Ӷ��Ҷ���,�Ҷ��Ӷ������) 
��Ȩֵ�Ƿ����

������,���໥��Ӧ�Ķ��Ӽ������
�����,����ѭ��,
�ݹ�����ڵ�����Ҷ���

ö�ٵ�����Ϊ��,����Է���,
���ҵ���һ�öԳƶ�������
ֱ��return; ����
(��Ϊ һ���� �� ���� һ������С) 

ȡ���ĶԳƶ�������,���� 
*/
#include<cstdio>
#include<cmath>
#include<queue>
#include<ctype.h>
#define max(a,b) a>b?a:b
using namespace std;
const int MARX = 1e6+10;
struct node
{
    int w,le,ri;
}a[MARX];
int n,ans=1;
queue <int> x;
queue <int> y;
inline int read()
{
	int fl=1,w=0;char ch=getchar();
	while(!isdigit(ch)) if(ch=='-') {fl=-1,ch=getchar();break;}
	while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
	return fl*w;
}
int check(int tx,int ty)//�ж�tx,ty��Ķ����� �ṹ�Ƿ�Գ�,��Ȩ�Ƿ���� 
{
	//�����㶼û�����Ҷ��� 
	if(a[tx].le==-1 && a[ty].le==-1 && a[tx].ri==-1 && a[ty].ri==-1) return 1;
	
	//�ṹ���Գ�(��Ӧ��һ��һ��) 
    if(a[tx].le==-1 && a[ty].ri!=-1) return 0;
    if(a[tx].ri==-1 && a[ty].le!=-1) return 0;
    if(a[ty].le==-1 && a[tx].ri!=-1) return 0;
    if(a[ty].ri==-1 && a[tx].le!=-1) return 0;
    
    //��һ���ӵ��Ӧ 
	if(a[tx].le==-1 && a[ty].ri==-1)
      return a[a[tx].ri].w==a[a[ty].le].w;
    //��һ���ӵ��Ӧ 
    if(a[tx].ri==-1 && a[ty].le==-1)
      return a[a[tx].le].w==a[a[ty].ri].w;
    //�����ӵ��Ӧ   
	if(a[a[tx].ri].w==a[a[ty].le].w)
	  if(a[a[tx].le].w==a[a[ty].ri].w)
      	  return 1;
	return 0;
}
void bfs(int s)
{
	if(s==-1) return ;//��ǰ��ΪҶ�ڵ� 
    if(a[a[s].le].w != a[a[s].ri].w || a[s].le==-1 || a[s].ri==-1) 
      {
      	//�������µݹ����� 
      	bfs(a[s].le);
		bfs(a[s].ri);
        return ;
      }
    //����ѭ���ж��Ƿ�Գ� 
    int flag=1,tot=3;
	while(!x.empty()) x.pop();
    while(!y.empty()) y.pop();
    x.push(a[s].le); y.push(a[s].ri);
    
    while(!x.empty())
      {
      	int tx=x.front(),ty=y.front();//ȡ���� 
      	x.pop(),y.pop();
        int re=check(tx,ty);
      	if(!re) { flag=0;break;}//���Գ�
      	else//�Գ� 
      	  {
      	  	if(a[tx].le!=-1)//������� 
			  tot+=2,x.push(a[tx].le),y.push(a[ty].ri);
      	  	if(a[tx].ri!=-1) 
			  tot+=2,x.push(a[tx].ri),y.push(a[ty].le);
          }
      }
    if(flag)  ans=max(ans,tot);//ȡ���ֵ 
    else//����������µݹ� 
	  {
	    bfs(a[s].le);
		bfs(a[s].ri);
	  }
}
int main()
{
    n=read();
    for(int i=1;i<=n;i++) a[i].w=read();
    for(int i=1;i<=n;i++) a[i].le=read(),a[i].ri=read();
    bfs(1);//�Ӹ��ڵ㿪ʼ�� 
    printf("%d",ans);
}
