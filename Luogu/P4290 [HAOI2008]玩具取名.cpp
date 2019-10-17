//֪ʶ��:����DP 
/*
��ĿҪ��:
	����һ�ַ��� , ��һЩ�仯����,
	�仯���� , ��Ϊ AB-->C ����ʽ(�������ַ���Ϊһ�ַ� 
	����ַ��� , �ܷ���һ���ַ��仯���� . 

��������:
	��Ϊ: �ַ����ĸ��� , ��Ӱ�쵽֮��ı仯 . 	
	���׷�����һ������ DP . 
	
	��bool��, f[l][r][k]��ʾ , 
	���� l~r �ܷ�ת��Ϊ �ַ�k.
	
	��ʼ��f[i][i][s[i]] = 1 (sΪ�����ִ�); 
	��״̬ת�Ʒ���ʽΪ:
	f[l][r][k] = (f[l][j][z1] && f[j+1][r][z2])
	(jΪö�ٵķֽ�, �Ҵ��ڱ仯����Ϊ:z1,z2-->k) 
	
	DP��ɺ�,�������1~length[s],
	���������ת��Ϊ���ַ����� 
	 
*/
#include<cstdio>
#include<ctype.h>
#include<map>
#include<cstring>
//=============================================================
int lth , num[5],cha[5][20][3];//cha �洢�仯���� 
bool flag,f[210][210][5];//���� l~r �ɲ�������ת��Ϊ �ַ�k.
std::map <char,int> m;//ʹ�ַ� ӳ��Ϊ ����, 
char raw[10]="0WING",tmp[3],s[210]="0";
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
} 
inline void prepare()
{
	m['W']=1,m['I']=2,m['N']=3,m['G']=4;//�����ַ�ӳ�� 
	for(int i=1;i<=4;i++) num[i]=read();
	for(int i=1;i<=4;i++)
	  for(int j=1;j<=num[i];j++)//�������仯���� 
	  {
	  	scanf("%s\n",tmp+1);
	  	cha[i][j][1]=m[tmp[1]],
	  	cha[i][j][2]=m[tmp[2]];
	  }
	scanf("%s",s+1);//�����ַ��� 
	lth=strlen(s);//���㳤�� 
}
void dp()
{
	for(int i=1;i<lth;i++) f[i][i][m[s[i]]]=1;//��ʼ������Ϊ1������ 
	
	for(int i=2;i<=lth;i++)//ö�����䳤�� 
	  for(int l=1,r=l+i-1;l<=lth-i;l++,r++)//ö���������Ҷ˵� 
	    for(int j=1;j<i;j++)//ö������߽� 
		  for(int k=1;k<=4;k++)//ö��Ҫת��Ϊ���ַ� 
	        for(int z=1;z<=num[k];z++)//ö�ٱ仯���� 
	          if(f[l][l+j-1][cha[k][z][1]] && f[l+j][r][cha[k][z][2]])
			    f[l][r][k]=1;//���� 
}
//=============================================================
signed main()
{
	prepare();
	dp();
/*
	for(int i=1;i<=lth;i++)
	  for(int l=1,r=l+i-1;l<=lth-i;l++,r++)
	    for(int k=1;k<=4;k++)
	      printf("%d %d %c\n",l,r,f[l][r][k]?raw[k]:0);
*/
	for(int i=1;i<=4;i++)//�Ƿ��п��н� 
	  if(f[1][lth-1][i]) 
	  {
	  	flag=1;
	    printf("%c",raw[i]);
	  }
	if(!flag) printf("The name is wrong!");//�޽� 
}
