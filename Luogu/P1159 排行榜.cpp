//֪ʶ��: ģ�� 
/*
����spjը����= =
�˷���һЩʱ��
 
��������:
���� , ������������� ,
���ʱ ��Ӧ�� ����ʱ��ԭλ��

��������������,
ԭ����һ���� �·�,
�����½���ͬ��

�����ά����������,
�ֱ�� ���������� ���½��ĸ���
���� ����ʱ����ά���ͱ��

�����ʱ,
�����ǰ ������������,��ֱ�����
������� �����½���, ԭ�������ϵ� ���� 
�� �½���������Ϊ�պ�,
��� ����������, ԭ�������µ� ���� 
*/
#include<cstdio>
#include<iostream>
#include<queue>
#include<string>
//=============================================================
std::string name[110],change;
int n;
bool same[110];//��¼�Ƿ� ������ͬ 
std::queue <int> down,up;//���½�/���� 
//=============================================================
signed main()
{
	std::cin>>n;
	for(int i=1; i<=n; i++)
	{
	  std::cin >> name[i] >> change;//���� ���ж����� 
	  if(change == "UP")   up.push(i);
	  if(change == "DOWN") down.push(i);
	  if(change == "SAME") same[i] = 1;
	}
	for(int i=1; i<=n; i++)//����Ҫ����� 
	  if(same[i]) std::cout << name[i] <<'\n';
	  else if(!down.empty()) std::cout<< name[down.front()]<<'\n' , down.pop();
	  else if(!up.empty()) std::cout << name[up.front()] <<'\n' , up.pop();
}
