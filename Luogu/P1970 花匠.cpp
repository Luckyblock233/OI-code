//֪ʶ��:DP/̰��
/*
�������(?)������
����ʹ��DP,����̰�ĵ�ʱ�临�Ӷȸ��� 

̰�ķ���:
��ѡ����һ��������/�½�
����֮���Ԫ��,
1.���һֱ�½�,
  ��Ȼ,��ôѡ����͵Ļ����
2.���һֱ����,
  ͬ��,ѡ����ߵ�
3.��� �½�/���� ;�г��� ����/�½� ��
  ��ô��һ��ѡ�� ��ʱ���ֵ�ͻأ��Ԫ��

ֻ��Ҫ������ɨ2�鼴��
���Ӷ�O(2n)
*/
#include<cstdio>
#include<cctype>
const int MARX = 1e6+10;
//=============================================================
int n,m , a[MARX];
int s[MARX]={MARX};
int ans=1,marx;
//=============================================================
inline int read() 
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
//=============================================================
signed main()
{
	n=read();
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<=n;i++)//g2i>g2i-1 ���
	{
	  if(marx%2==0)//�����ö��
	  {
	  	s[++marx]=a[i++];//��Ӵ�
	  	while(a[i]<=s[marx])//ѡ����ֵ
	  	{
	  	  s[marx]=a[i];
	  	  if((++i)>n)break;//Խ��
		}
		i--;
	  }
	  else
	  {
		s[++marx]=a[i++];//��Ӵ�
	  	while(a[i]>=s[marx])
	  	{
	  	  s[marx]=a[i];//ѡ����ֵ
	  	  if((++i)>n)break;//Խ��
		}
		i--;
	  }
	}

    if(marx>ans) ans=marx;//��¼��
	marx=0,s[0]=-10;

    for(int i=1;i<=n;i++)//g2i<g2i-1  ͬ��
	{
	  if(marx%2==1)
	  {
	  	s[++marx]=a[i++];
	  	while(a[i]<=s[marx])
	  	{
	  	  s[marx]=a[i];
	  	  if((++i)>n)break;
		}
		i--;
	  }
	  else
	  {
		s[++marx]=a[i++];
	  	while(a[i]>=s[marx])
	  	{
	  	  s[marx]=a[i];
	  	  if((++i)>n)break;
		}
		i--;
	  }
	}
	if(marx>ans) ans=marx;//��¼��
    printf("%d",ans);
}
