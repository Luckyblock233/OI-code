//֪ʶ��:ģ�� 
/*
By:Luckyblock
����Ƚ��Ƿ�,
ˢһ�� ���Ĵ�ģ��������һ������ 

�ȴӲ��ַֿ�ʼд:
//=============================================================
���﷨����: 
������ �ظ��ı����� �� ����Ӧ���ֵ�F��E
��ô�Ͳ���Ҫ �Ա�������������
Ҳ����Ҫ ��ѭ���� �ܷ���ֹ�����ж�. 
//=============================================================
30��: 
���﷨����,�����ڲ��м��� �� ѭ�� , ��x<y , x!=n 
ֻ��Ҫ����ÿһ�� ѭ�� ���Ӷ�Ϊ���� �� n 
����������˼���.
//=============================================================
50��: 
���﷨����,���ڲ��� �����ѭ�� , ��x<y,x!=n
��Ҫһ�����ݽṹ , ������ѭ��֮��ļ����ϵ
����ѭ�� �Ƚ����������, ʹ��ջ����ά��

�������ѭ��,�ж��临�Ӷ�Ϊ ���� �� n
�����Ӷ�Ϊn , ����ջ ����һn ,������һ�㸴�Ӷ�Ϊn��ѭ��
�����Ӷ�Ϊ ���� , ����ջ ����һ1 ,������һ�㸴�Ӷ�Ϊ������ѭ��
�� ����һE , ��ջ��Ԫ�� ����ջ�� , �������ѭ������

�� ֻ��Ҫ���� ջ�� Ԫ��n ������, ����֪��ǰ ��Чѭ���Ĳ���
�ó���ĸ��Ӷ� �� ��ʱ�� ջ�� ������Чѭ������ , ��n������ 
//=============================================================
70��: 
���﷨����.
������ x>=y �����
���x==y , ��ô�˲�ѭ�����Ӷ�Ϊ���� , ����50��˼·����
���x>y , ��ô�ͳ����� һ�㲻�ɽ����ѭ��
�� ѭ���� �ڵ� ѭ�� �Ͳ��ɽ���. 

��� �� λ�ڲ��ɽ���ѭ�� �� ѭ�����ڵ� ѭ������?
������� һ ���ɽ���ѭ��, ����ջ�м��� һx, ����˲�ѭ�����ɽ���
����֮�� �����ѭ��, �����临�Ӷ�Ϊ��ֵ , ����ջ�м��� һx.
����¼ ջ��x������
֮����Ȼ ����50��˼·���� ��ջ.
�� ջ��x������ Ϊ 0ʱ,˵�� ����ѭ����ѭ���� �Ѿ���������
���� 50��˼·���� 
//=============================================================
100��: 
��Ҫ ����/���ٱ���,�������� �� �ж�ѭ������ֹ. 
1.���� ����/���ٱ��� ,��������: 
  ʹ��һ��Ͱ ,Ϊ�������ı�������. 
  
  ����ʱ ȥ�� ������ѭ�������� ��Ǽ���. 
  ���� ��¼ÿ��ѭ���� ������
  ��ջ��Ԫ�� �滻Ϊ�ṹ��,ͬʱ��¼ѭ������ �� ����������
2.���� �ж�ѭ������ֹ: 
  ���ж�: �Ƿ� �в���Ӧ�� F,E����. 
  ֻ��Ҫ�ж� ��û�����ڽ���ѭ��ʱ, ������ֹ����
  	���Ƿ��� ��ջʱ���е�ջ���� 
  �� ��������������Ϻ�, �б���ֹѭ������ 
    �����������ɺ� ջ�Ƿ�Ϊ�� 
    
��Ҫע���һЩ����: 
1. ��ѭ��������Ϊ����ʱ , Ҳ���ܳ��ֲ���ִ�е�ѭ��
2. ������ �﷨����ʱ ,����ֱ���˳�ѭ������,
��Ҫ����������ѭ��������ɺ����˳�, ����ͻ���ֶ����������� 
*/
#include<cstdio>
#include<iostream>
#include<stack>
#include<string>
#include<ctype.h>
#define max(a,b) a>b?a:b
const int INF = 2e9+7;
//=============================================================
struct Repeat
{
	int quanity;
	char variable;
};
int T,L;
std::string tmp;
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
void get_information(char &variable,int &quanity)//��ȡ��Ϣ 
{
	int i,j, lth=tmp.length(),first=0,second=0; 
	variable = tmp[2];
	
	for(i=4; tmp[i]!=' '; i++)//��ȡ ѭ����ʼֵ 
	{
	  if(tmp[i]=='n') {first=INF; break;}
	  first = first*10 + tmp[i]-'0';  
	}
	for(j=i+1; j<lth; j++)//��ȡ ѭ����ֵֹ 
	{
	  if(tmp[j]=='n') {second=INF; break;}
	  second = second*10 + tmp[j]-'0';
	}
	//���� �����Ƿ�Ϊn , �жϸò�ѭ�� ��ѭ������ 
	if(first!=INF && second!=INF) quanity = (first<=second?0:2);//0 Ϊ������ 
	if(first==INF && second==INF) quanity = 0;
	if(first!=INF && second==INF) quanity = 1;//1 Ϊn��
	if(first==INF && second!=INF) quanity = 2;//2 Ϊ����ִ�� 
}
//=============================================================
signed main()
{
	T=read();
	while(T--)
	{
	  L = read(); getline(std::cin,tmp);
	  
	  std::stack <Repeat> repeat;//���� ����ѭ����Ϣ ��ջ 
	  int ans=0, W=0, quan[3]={0};//���� 3��ѭ����ջ�г��ֵĴ��� 
	  bool flag=1,use[150]={0};//�Ƿ�����﷨����ı�� �� ����ĸ�Ƿ�ʹ�ù� 
	  if(tmp[2] != '1') //���� ������ѭ������ 
	    for(int j=4; tmp[j]!=')'; j++) 
		  W = W*10 + tmp[j]-'0';
	  
	  while(L--)
	  {
	  	getline(std::cin,tmp);
		if(!flag) continue;
		char variable; int quanity;//�����Ϣ, �������� ѭ������ 
	  	if(tmp[0] == 'F') get_information(variable,quanity); 
		else //����һ�� E 
		{
		  if(repeat.empty()) {flag=0;continue;}
		  quan[repeat.top().quanity]--, use[repeat.top().variable]=0; //���´��� 
		  repeat.pop();//��ջ 
		  continue; 
		}
		
		if(use[variable]) {flag=0; continue;}
		
		if(quan[2]) quanity=2;//�� �µ�һ��ѭ������ջ�� 
		quan[quanity]++, use[variable]=1;//���³��ִ��� 
		repeat.push((Repeat){quanity,variable});//��ջ 
		ans = max(ans,quan[1]);//���� ����Ӷ� 
	  }
	  if(!repeat.empty()) flag=0;//�� δ��������ѭ������ 
	  if(flag)//û���﷨���� 
	  {
	    if(ans==W) printf("Yes\n");
	    else printf("No\n");	
	  }
	  else {printf("ERR\n");}
	}
} 
//30
/*
#include<cstdio>
#include<iostream>
#include<string>
#include<ctype.h>
#define max(a,b) a>b?a:b
const int INF = 2e9+7;
//=============================================================
int T,L,W,ans;
std::string tmp;
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
void get_information(int &quanity)//��ȡ��Ϣ 
{
	int i,j, lth=tmp.length(),first=0,second=0; 
	
	for(i=4; tmp[i]!=' '; i++)//��ȡ ѭ����ʼֵ 
	{
	  if(tmp[i]=='n') {first=INF; break;}
	  first = first*10 + tmp[i]-'0';  
	}
	for(j=i+1; j<lth; j++)//��ȡ ѭ����ֵֹ 
	{
	  if(tmp[j]=='n') {second=INF; break;}
	  second = second*10 + tmp[j]-'0';
	}
	//���� �����Ƿ�Ϊn , �жϸò�ѭ�� ��ѭ������ 
	quanity = (second==INF);//0 Ϊ������ , 1 Ϊn��
	
}
//=============================================================
signed main()
{
	T=read();
	while(T--)
	{
	  L = read(); getline(std::cin,tmp);
	  
	  int quan[3]={0};//���� 3��ѭ����ջ�г��ֵĴ��� 
	  ans = W = 0;
	  if(tmp[2] != '1')//���� ������ѭ������ 
	    for(int j=4; tmp[j]!=')'; j++) 
		  W = W*10 + tmp[j]-'0';
	  
	  while(L--)
	  {
	  	getline(std::cin,tmp);
		  
		int quanity;//�����Ϣ, ѭ������ 
	  	if(tmp[0] == 'F') get_information(quanity); 
		else continue; //����һ E 
		
		quan[quanity]++;//���³��ִ��� 
		ans=max(ans,quan[1]);
	  }
	  
	  if(ans==W) printf("Yes\n");
	  else printf("No\n");
	}
} 
*/ 


//50
/*
#include<cstdio>
#include<iostream>
#include<stack>
#include<string>
#include<ctype.h>
#define max(a,b) a>b?a:b
const int INF = 2e9+7;
//=============================================================
int T,L,W,ans;
std::string tmp;
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
void get_information(int &quanity)//��ȡ��Ϣ 
{
	int i,j, lth=tmp.length(),first=0,second=0; 
	
	for(i=4; tmp[i]!=' '; i++)//��ȡ ѭ����ʼֵ 
	{
	  if(tmp[i]=='n') {first=INF; break;}
	  first = first*10 + tmp[i]-'0';  
	}
	for(j=i+1; j<lth; j++)//��ȡ ѭ����ֵֹ 
	{
	  if(tmp[j]=='n') {second=INF; break;}
	  second = second*10 + tmp[j]-'0';
	}
	//���� �����Ƿ�Ϊn , �жϸò�ѭ�� ��ѭ������ 
	quanity = (second==INF);//0 Ϊ������ , 1 Ϊn��
}
//=============================================================
signed main()
{
	T=read();
	while(T--)
	{
	  L = read(); getline(std::cin,tmp);
	  
	  std::stack <int> repeat;//���� ����ѭ����Ϣ ��ջ 
	  int quan[3]={0};//���� 3��ѭ����ջ�г��ֵĴ��� 
	  ans = W = 0;
	  if(tmp[2] != '1')//���� ������ѭ������ 
	    for(int j=4; tmp[j]!=')'; j++) 
		  W = W*10 + tmp[j]-'0';
	  
	  while(L--)
	  {
	  	getline(std::cin,tmp);
		  
		int quanity;//�����Ϣ, ѭ������ 
	  	if(tmp[0] == 'F') get_information(quanity); 
		else //����һ E 
		{
		  quan[repeat.top()]-- , repeat.pop();//��ջ 
		  continue; 
		}
		
		quan[quanity]++;//���³��ִ��� 
		repeat.push(quanity);
		ans=max(ans,quan[1]);
	  }
	  
	  if(ans==W) printf("Yes\n");
	  else printf("No\n");
	}
} 
*/

 
//70: 
/*
#include<cstdio>
#include<iostream>
#include<stack>
#include<string>
#include<ctype.h>
#define max(a,b) a>b?a:b
const int INF = 2e9+7;
//=============================================================
int T,L,W,ans;
std::string tmp;
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
void get_information(int &quanity)//��ȡ��Ϣ 
{
	int i,j, lth=tmp.length(),first=0,second=0; 
	
	for(i=4; tmp[i]!=' '; i++)//��ȡ ѭ����ʼֵ 
	{
	  if(tmp[i]=='n') {first=INF; break;}
	  first = first*10 + tmp[i]-'0';  
	}
	for(j=i+1; j<lth; j++)//��ȡ ѭ����ֵֹ 
	{
	  if(tmp[j]=='n') {second=INF; break;}
	  second = second*10 + tmp[j]-'0';
	}
	//���� �����Ƿ�Ϊn , �жϸò�ѭ�� ��ѭ������ 
	if(first!=INF && second!=INF) quanity = (first<=second?0:2);//0 Ϊ������  
	if(first==INF && second==INF) quanity = 0;
	if(first!=INF && second==INF) quanity = 1;//1 Ϊn��
	if(first==INF && second!=INF) quanity = 2;//2 Ϊ����ִ�� 
}
//=============================================================
signed main()
{
	T=read();
	while(T--)
	{
	  L = read(); getline(std::cin,tmp);
	  
	  std::stack <int> repeat;//���� ����ѭ����Ϣ ��ջ 
	  int quan[3]={0};//���� 3��ѭ����ջ�г��ֵĴ��� 
	  ans = W = 0;
	  if(tmp[2] != '1')//���� ������ѭ������ 
	    for(int j=4; tmp[j]!=')'; j++) 
		  W = W*10 + tmp[j]-'0';
	  
	  while(L--)
	  {
	  	getline(std::cin,tmp);
		  
		int quanity;//�����Ϣ, ѭ������ 
	  	if(tmp[0] == 'F') get_information(quanity); 
		else //����һ E 
		{
		  quan[repeat.top()]-- , repeat.pop();//��ջ 
		  continue; 
		}
		
		if(quan[2]) quanity=2;//�� �µ�һ��ѭ������ջ�� 
		quan[quanity]++;//���³��ִ��� 
		repeat.push(quanity);
		ans=max(ans,quan[1]);
	  }
	  
	  if(ans==W) printf("Yes\n");
	  else printf("No\n");
	}
} 
*/ 
