//�㷨��DP������
//����������������,ʵ���Ͽ��Բ�ֳ�01��������
/*
�����־���: 
1.��ѡ��Ȼ��ȥ������һ������ 
2.ѡ��ֻѡ�������
3.ѡ�������������ѡ����1
4.ѡ�������������ѡ����2
5.ѡ�������������ѡ����1�͸���2. 
*/
//�������״̬ת�Ʒ���ʽ
//���ע�� 
#include<cstdio>
#include<algorithm> 
using namespace std;
const int maxn=32100;
int n,m;
int v,p,q;
int mw[maxn];//�ִ���������,��ֵ 
int mc[maxn];
int fw[maxn][5];//�ִ�ĳ��������ĸ������ʺͼ�ֵ 
int fc[maxn][5];
int f[maxn]; 
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++)
	  {
        scanf("%d%d%d",&v,&p,&q);
        if (!q)//������ 
		  {
            mw[i]=v;
            mc[i]=v*p;
          }
        else//�Ǹ��� 
		  {
            fw[q][++fw[q][0]]=v;
            fc[q][fw[q][0]]=v*p;
          }
      }
    for (int i=1;i<=m;i++)//DP 
      for (int j=n;mw[i]!=0&&j>=mw[i];j--)
	    {
            f[j]=max(f[j],f[j-mw[i]]+mc[i]);//ѡ��ֻѡ������� 
            if(j>=mw[i]+fw[i][1])
              f[j]=max(f[j],f[ j - mw[i] - fw[i][1] ] + mc[i] + fc[i][1]);//ѡ�������������ѡ����1 
            if(j>=mw[i]+fw[i][2])
              f[j]=max(f[j],f[ j - mw[i] - fw[i][2] ] + mc[i] + fc[i][2]);//ѡ�������������ѡ����2 
            if(j>=mw[i]+fw[i][1]+fw[i][2])
              f[j]=max(f[j],f[ j - mw[i] - fw[i][1] - fw[i][2] ] + mc[i] + fc[i][1] + fc[i][2]);//ѡ�������������ѡ����1�͸���2. 
        }
     printf("%d",f[n]);
     return 0;
}
