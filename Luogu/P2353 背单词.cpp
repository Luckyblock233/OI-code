//֪ʶ��:KMP/�ַ��� 
/*
����������������Ŀ

��ĿҪ��: 
����������ƥ���ַ���������

������Ŀ & �㷨ʵ��:
m<=10??
��ô�͵ĸ��Ӷ�
ֱ����10��KMP���� 

��KMP������,ȡǰ׺��
��¼ÿ���ַ�֮ǰ
ƥ����ַ����ĸ���

��ѯʱ:
ö��m��ǰ׺��
��ǰ׺������ 
����������ÿ���ַ���ƥ��ĸ���
����ͼ���

���������ַ���ƥ�����ʱ : 
ע���жϸ�������ĳ���,
�Ƿ����������һ��ģʽ��.
�������,��ƥ�������Ϊ0 .
*/
#include<cstdio>
#include<string>
#include<ctype.h>
#include <iostream>
#define int long long
//=============================================================
const int MARX = 1e6+10;
std::string s1,s2;
int n,m,q,ls1,ls2;
int length[11];
int sum[11][MARX] , next[MARX];
//=============================================================
inline int read()
{
    int fl=1,w=0;char ch=getchar();
    while(!isdigit(ch) && ch!='-') ch=getchar();
    if(ch=='-') fl=-1;
    while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
    return fl*w;
}

void get_next()// ���ǰ׺���� 
{
    int i=0,j=-1;
    next[0]=-1;
    while(i < ls2)
      if(j==-1 || s2[i]==s2[j])//ƥ����� 
      {
        i++,j++;
        next[i]=j;
      }
      else j=next[j];//��ƥ�� 
}
void kmp(int now)//kmpƥ�� 
{
    int i=0,j=0;
    while(i<ls1)
    {
      if(j==-1 || s1[i]==s2[j]) i++,j++;//ƥ�� 
      else j=next[j];
        
      if(j==ls2) //�ҵ�һ������ģʽ�� 
        sum[now][i]++ , j=next[j];//��ǰ�ַ�λ��ǰ׺��++ 
    }
}
int qu(int l,int r)//ѯ�ʲ��� 
{
    int ans=0;
    for(int i=1;i<=m;i++)
      if (l - 1 <= r - length[i])//�Ƿ����������һ��ģʽ�� 
      ans += (sum[i][r] - sum[i][l + length[i] - 2]);
    return ans;
}
//=============================================================
signed main()
{
    m=read() , q=read();
  	std :: cin >> s1;
    ls1=s1.length();
    
    for(int i=1;i<=m;i++)//ѭ������ 
    {
      std :: cin >> s2;
      length[i]=ls2=s2.length();
      get_next();
        kmp(i);
    }
    
    for(int i=1;i<=ls1;i++)//����ǰ׺�� 
      for(int j=1;j<=m;j++)
        sum[j][i]+=sum[j][i-1];
    
  /*
    for(int i=1;i<=m;putchar('\n'),i++)
    for(int j=0;j<=10;j++)
      printf("%d ",sum[i][j]);
  */
    while(q--)//�ش�ѯ�� 
    {
      int l,r;
      l=read(),r=read();
      printf("%lld\n",qu(l,r));
    }
}
