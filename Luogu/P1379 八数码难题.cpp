//֪ʶ��:����
/* 
��Ҫ���ɵĹ���
��״̬���� 
ѹ��Ϊһ�� ����Ϊ9���ַ���
��ʵ�ַ���ļ�¼ , ������

��ʵ��λ�ý���ʱ , 
�ٽ��ַ����ĸ�λ��,
ӳ�䵽����ĸ�λ��
�����չ��������Ծ��������

���ע��
*/
#include<iostream>
#include<string>
#include<cctype>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<queue>
using namespace std;
string s,tar = " 123804765";//Ŀ��״̬
map <string,int> sum;//map����,����¼����
queue <string> q;
//============================================================
inline int read()
{
	int fl=1,w=0;char ch=getchar();
	while(!isdigit(ch)) if(ch=='-') {fl=-1,ch=getchar();break;}
	while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
	return fl*w;
}
inline void check(string top,int step)//����Ƿ񵽴�Ŀ��״̬
{
	if(top==tar)//����Ŀ��״̬
	  {
	  	cout<<step+1;
	  	exit(0);
	  } 
	if(!sum[top])//δ����Ŀ��
	  {
	  	sum[top]=step+1;//��¼����
	  	q.push(top);//�������
	  }
}
//============================================================
int main()
{
	cin>>s;
	s.insert(0," ");//����ԭʼ�ִ�
	if(s==tar) //��ʼ��ΪĿ��
	  {
	  	cout<<0;
	  	return 0;
	  }
	q.push(s);
	while(!q.empty())//BFS
	  {
	  	string top=q.front();
	  	q.pop();
	  	int step=sum[top]; 
		int poi=top.find('0');//�ҵ�Ҫ������λ��
	  	if(poi+3<=9)//�����������ӽ���
	  	  {
	  	  	swap(top[poi],top[poi+3]);//������״̬
	  	  	check(top,step);//����Ƿ����Ҫ��
	  	  	swap(top[poi],top[poi+3]);//��ԭ
		  }
		if(poi-3>=1)//�����������ӽ���
		  {
		  	swap(top[poi],top[poi-3]);
	  	  	check(top,step);
	  	  	swap(top[poi],top[poi-3]);
		  }
		if(poi+1<=9 && poi!=3 && poi!=6)//���򽻻�
		  {
		  	swap(top[poi],top[poi+1]);//������״̬
	  	  	check(top,step);//����Ƿ����Ҫ��
	  	  	swap(top[poi],top[poi+1]);
		  }
		if(poi-1>=1 && poi!=4 && poi!=7)//���򽻻�
		  {
		  	swap(top[poi],top[poi-1]);
	  	  	check(top,step);
	  	  	swap(top[poi],top[poi-1]);
		  }
	  }
}
