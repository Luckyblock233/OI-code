//������һ�� 
//�ײ�Ϊ���,�Ѿ�д�ķǳ���ϸ�� 
//��ˡ�Ҳ�дע��= = 
#include<iostream>
#include<cstdlib>
#include<queue>
#include<string>
using namespace std;
//=============����=============================
int pigs_count,pile_count;
struct each_pig
{
	int bl;
	int id;
	int gr;
	bool bo;
	string ca;
}p[15];
int ne_p[15];
int pre_p[15];
bool dead_MP=0;
int alive_FP=0;
int now=1; 
queue <string> pile;
//============�Ӻ����б�===========================
void read();
void get_ca(int);
void attack(int,int);
void dying(int,int);
void game_end();
void nanman(int);
void wanjian(int);
bool wuxie(int);
void duel(int,int);
bool judge_attack(int,int);
bool judge_duel(int,int);
int find_duel(int);
bool use_ca(int,string);
//==============������================================
signed main()
{
	read();
	while(1)
	{
	  bool attack_use=0;
	  get_ca(now); get_ca(now);
	  while(1)
	  {
		bool ca_use=0;
	  	int i=0;
	  	for(i;p[now].ca[i];i++)
	  	{
	  	  string now_ca;
	  	  now_ca+=p[now].ca[i];
	  	  if(now_ca=="P" && p[now].bl<4) {p[now].ca.erase(i,1); ca_use=1; p[now].bl++;}
	  	  if(now_ca=="Z") {p[now].ca.erase(i,1); ca_use=1; p[now].bo=1;}
		  if(now_ca=="N") {p[now].ca.erase(i,1); ca_use=1; nanman(now);}
		  if(now_ca=="W") {p[now].ca.erase(i,1); ca_use=1; wanjian(now);}
		  if(now_ca=="F")
		  {
			int ta=find_duel(now);
			if(ta==-1) continue;
			p[now].ca.erase(i,1); ca_use=1;
			if(judge_duel(now,ta)) duel(now,ta);
		  }
		  if(now_ca=="K" && judge_attack(now,ne_p[now]))
			if(!attack_use || p[now].bo)
			{
			  p[now].ca.erase(i,1);
			  ca_use=1;attack_use=1;
			  attack(now,ne_p[now]);
			}
		  if(ca_use) break;
		}
		if(!ca_use) break;
		if(p[now].bl<=0) break;
		i=0;
	  }
	  now=ne_p[now];
	}
}
//==============�Ӻ���================================ 
void read()
{
	cin>>pigs_count>>pile_count;
	for(int i=1;i<=pigs_count;i++)
	{
	  if(i==1) pre_p[i]=pigs_count;
	  else  pre_p[i]=i-1;
	  if(i==pigs_count) ne_p[i]=1;
	  else ne_p[i]=i+1;
	}
	for(int i=1;i<=pigs_count;i++)
	{
	  string shenfen;
	  cin>>shenfen;
	  p[i].bl=4;
	  if(shenfen=="MP") p[i].id=0,p[i].gr=1;
	  if(shenfen=="ZP") p[i].id=1;
	  if(shenfen=="FP") p[i].id=2,alive_FP++;
	  for(int j=1;j<=4;j++)
	  {
		string cin_ca;
		cin>>cin_ca;
		p[i].ca+=cin_ca;
	  }
	}
	for(int i=1;i<=pile_count;i++)
	{
	  string cin_ca;
	  cin>>cin_ca;
	  pile.push(cin_ca);
	}
}
void get_ca(int so)
{
	string cin_ca;
	cin_ca=pile.front();
	if(pile_count>1)
	{
	  pile_count--;
	  pile.pop();
	}
	p[so].ca+=cin_ca;
}
void attack(int so,int ta)
{
	if(p[ta].gr==2) p[so].gr=1;
	if(p[ta].gr==1) p[so].gr=2;
	if(!use_ca(ta,"D")) p[ta].bl--;
	if(p[ta].bl<=0) dying(so,ta);
}
void dying(int so,int ta)
{
	while(p[ta].bl<=0)
	{
	  if(use_ca(ta,"P")) p[ta].bl++;
	  else  break;
	}
	if(p[ta].bl<=0)
	{
	  if(p[ta].id==2)
	  {
	  	alive_FP--;
	  	game_end();
	  	get_ca(so);get_ca(so);get_ca(so);
	  }
	  if(p[ta].id==1 && p[so].id==0) {p[so].ca.clear(),p[so].bo=0;}
	  if(p[ta].id==0) {dead_MP=1;game_end();}
	  ne_p[pre_p[ta]]=ne_p[ta];
	  pre_p[ne_p[ta]]=pre_p[ta];
	}
}
void game_end()
{
	if(dead_MP || !alive_FP)
	{
	  if(dead_MP) cout<<"FP"<<endl;
	  else cout<<"MP"<<endl;
	  for(int i=1;i<=pigs_count;i++)
	  {
	  	if(p[i].bl<=0) cout<<"DEAD"<<endl;
	  	else
	  	{
		  for(int j=0;p[i].ca[j];j++) cout<<p[i].ca[j]<<" ";
	  	  cout<<endl;
	  	}
	  }
	  exit(0);
	}
	return ;
}
void nanman(int so)
{
	for(int i=ne_p[so];i!=so;i=ne_p[i])
	{
	  bool wuxie_use=0;
	  if(p[i].gr && p[i].gr!=3)
	  {
	  	int vi[15]={0};
	  	for(int j=so;j;j=ne_p[j])
	  	  if(vi[j]++) break;
	  	  else 
			if(p[j].id==p[i].gr || p[j].gr==p[i].gr)
			  if(use_ca(j,"J"))
			  {
			    p[j].gr=p[i].gr;
			    if(wuxie(j))
			    {
				  wuxie_use=1;
				  break;
			    }
			  }
	  }
	  if(wuxie_use) continue;
	  if(!use_ca(i,"K"))
	  {
		p[i].bl--;
		if(p[i].id==0 && !p[so].gr) p[so].gr=3;
	  }
	  if(p[i].bl<=0) dying(so,i);
	}
}
void wanjian(int so)
{
	for(int i=ne_p[so];i!=so;i=ne_p[i])
	{
	  bool wuxie_use=0;
	  if(p[i].gr && p[i].gr!=3)
	  {
	  	int vi[15]={0};
	  	for(int j=so;j;j=ne_p[j])
	  	  if(vi[j]++) break;
	  	  else 
			if(p[j].id==p[i].gr || p[j].gr==p[i].gr) 
			  if(use_ca(j,"J"))
				{
				  p[j].gr=p[i].gr;
				  if(wuxie(j))
				  {
				    wuxie_use=1;
				    break;
				  }
				}
	  }
	  if(wuxie_use) continue;
	  if(!use_ca(i,"D"))
	  {
		p[i].bl--;
		if(p[i].id==0 && !p[so].gr) p[so].gr=3;
	  }
	  if(p[i].bl<=0) dying(so,i);
	}
}
bool wuxie(int so)
{
	bool wuxie_use=0;
	int vi[15]={0};
	for(int i=so;i;i=ne_p[i])
	  if(vi[i]++) break;
	  else 
	    if(judge_attack(i,so))
	      if(use_ca(i,"J"))
	      {
	      	p[i].gr=p[so].gr==1?2:1;
	      	if(wuxie(i))
	      	{
	      	  wuxie_use=1;
	      	  break;
			}
		  }
	if(wuxie_use) return 0;
	return 1;
}
void duel(int so,int ta)
{
	if(p[ta].id==1 && p[so].id==0)
	{
	  p[ta].bl--;
	  if(p[ta].bl<=0) dying(so,ta);
	  return ;
	}
	if(use_ca(ta,"K"))  duel(ta,so);
	else
	{
	  p[ta].bl--;
	  if(p[ta].bl<=0) dying(so,ta);
	  return ;
	}
}
bool judge_attack(int so,int ta)
{
	if(p[so].id==0 && p[so].gr!=p[ta].gr && p[ta].gr) return 1;
	if(p[so].id==1 && p[ta].gr==2) return 1;
	if(p[so].id==2 && p[so].id!=p[ta].gr && p[ta].gr && p[ta].gr!=3) return 1;
	return 0;
}
int find_duel(int so)
{
	int ta=-1;
	if(p[so].id==2) ta=1 , p[so].gr=2;
	else
	  for(int i=ne_p[so];i!=so;i=ne_p[i])
	  	if(p[i].gr==2 || (p[i].gr==3 && p[so].id==0))
	  	{
	  	  p[so].gr=1 , ta=i;
	  	  break;
		}
	return ta;
}
bool judge_duel(int so,int ta)
{
	bool wuxie_use=0;
	if(p[ta].gr!=0 && p[ta].gr!=3)
	  for(int i=ne_p[so];i!=so;i=ne_p[i]) 
	    if(p[i].id==p[ta].gr || p[ta].gr==p[i].gr)
	      if(use_ca(i,"J"))
		  {
			p[i].gr=p[ta].gr;
			if(wuxie(i))
			{
			  wuxie_use=1;
			  break;
			}
		  }
	if(wuxie_use) return 0;
	return 1;
}
bool use_ca(int so,string card)
{
	int po=-1;
	po=p[so].ca.find(card);
	if(po==-1) return 0;
	p[so].ca.erase(po,1);
	return 1;
}
/*
���ɱ
Ŀ¼��

������
��ע
�����б�
�Ӻ����б�













��������
int main()
{
	����()
	while(1)
  	  {
  		bool  �ж��Ƿ��ù�ɱ=0;
		bool ʹ������=0;
		����(��ǰ��)x2;
		while(1)
		  {
		  	int i=0(��ָ��)
		    For(i=������,��ֵΪ0)
  		      {
  		  	    string ��ǰ��;
			    ��ǰ��+=����[i];
			    If(�� && Ѫ��<4)
����		      ����.earse(i,1),ʹ������,Ѫ��+1;
                if(�������)
                  ����.earse(i,1),ʹ������,װ��; 
			    if(��������||����뷢)
  			      ����.earse(i,1),ʹ������,��ǰ��(ʹ����);
			    if(����)
      		      {
					int ��������=�����ܷ���Ч(��ǰ��);
					if(��������==-1)
					  continue; 
      		      	����.earse(i,1),ʹ������;
				    if(�����Ƿ���Ч(ʹ����,��ʹ����))
			          ����(��ǰ��,��������); 
		          }
			    if(�ܹ���(��ǰ��,��һ��) && ɱ)
  			  	  if(û��ʹ��ɱ||�������) 
      			    ����.earse(i,1),ʹ������,ɱ(��ǰ��,��һ��),ʹ����ɱ;
      	       if(ʹ������)
			     break;
			  }
		    if(!ʹ������) break;
			if(��ǰ��:Ѫ<=0) break;
			i=0; 
		  }
     	��ǰ��=��һ��; 
      }
}





��ע:
1.	���д�����,�ƶ�(����������ģ��,�ƶ���stl)
2.	��������˳��(����ָ����һ��)
3.  0������1�ҳ���2���� 


�����б�:
1.	�ṹ���ĳһ��
{
	int�� Ѫ��;
	int�� ���;(0������1�ҳ���2���� ) 
	int�� ����(0��ʾû���� 1ȷ����������,2ȷ��������,3�����෴��)
	string�� ����;
	bool�� �Ƿ�װ���������;
}
2 int�Ͷ�ά����,�������һ��,��һ��;
3 bool�ͱ������ж������Ƿ���������ʼΪ1;
4 int�ͱ�������¼���ķ�������; 



�Ӻ����б�
1.	Void ����
{
	For(i=����)
      {
	    ���,����(i)x4;
		��¼���;
		if(��ӪΪ����)
		  ����=����; 
		Ѫ��=4;
		If(����) ���������+1;
	  }
    for(i=�ƶ�����)
   	  ����,ѹ���ƶѶ���;
}
2.	Void ����(����)
{
	string ������;
	������=�ƶ�.front();
	if(�������һ����) 
	  {
		�ƶ�����--; 
		�ƶ�.pop();
	  }
    ��������+������;
	return ;
}
��.void ɱ(ʹ������,��ʹ������)
{
	if(��ʹ��������Ϊ����) ʹ��������=����;
	if(��ʹ������������) ʹ��������=����;
    If(!ʹ��ĳ����(��ʹ����,��)) 
  	  ��ʹ����:Ѫ��-1; 
	if(��ʹ����:Ѫ��<=0)
  	  ����(ʹ����,��ʹ����);
}
��. void ����(ʹ����,��ʹ����)
{ 
	while(��ʹ����:Ѫ��<=0) 
      {
      	if(ʹ��ĳ����(��ʹ����,��))  ��ʹ����:Ѫ��+1;
	    else break; 
	  }
	if(��ʹ����:Ѫ��<=0)
      {
		if(��ʹ����Ϊ����) 
		  {
            ������-1;
			��Ϸ����(); 
			����(ʹ����)x3; 
		  }
        if(��ʹ����Ϊ�ҳ� &&��ʹ����Ϊ����)
������������������="",װ��������;
		if(��ʹ����Ϊ����)
          {
		    ��������;
		    ��Ϸ����();
		  }
		��ָ�������һ��,����ָ��ʹ�������һ��; 
	  }
}
5.void ��Ϸ����()
{
	if(�������� || ������==0)
  	  {
  	  	���;
		exit(0);
	  }
	return ;
}
6.void ��������(ʹ����)
{
	for(i=���������)
  	  {
      	bool �Ƿ���и; 
     	if(i�������)
		  for(j=��ʹ����Ϊ�����ʱ�������)
   			if(j����Ӫ=i������)
			  if(ʹ��ĳ����(j��,��и�ɻ�))
���� 			{
				  j������=i������;
				  if(��и(j��))
 					�Ƿ���и=��, break;
				}
		if(����и)continue;
		if(!ʹ��ĳ����(i��,ɱ))
		  {
			Ѫ-1; 
			if(i��Ϊ����&&ʹ����������) ʹ���������෴��; 
		  }
       	If(i��Ѫ<=0) ����(ʹ����,i��);
	  }
}
7.����뷢(ʹ����)
{
	for(i=���������)
  	  {
      	bool �Ƿ���и; 
     	if(i�������)
		  for(j=��ʹ����Ϊ�����ʱ�������)
   			if(j����Ӫ=i������)
			  if(ʹ��ĳ����(j��,��и�ɻ�))
���� 			{
				  j������=i������;
				  if(��и(j��))
 					�Ƿ���и=��, break;
				}
		if(����и)continue;
		if(!ʹ��ĳ����(i��,��))
		  {
			Ѫ-1; 
			if(i��Ϊ����&&ʹ����������) ʹ���������෴��; 
		  }
       	if(i��Ѫ<=0) ����(ʹ����,i��);
	  }
}
8 .bool ��и�ɻ�(ʹ����)
{
	bool �Ƿ񱻵���; 
	for(i=��ʱ�������ʹ����֮�����)
	  if(i����ʹ�����෴��Ӫ)
	    if(ʹ��ĳ����(i��,��и�ɻ�))
	      {
	        i������=(!ʹ��������)
		    if(��и�ɻ�(i��)) 
		      {
			    �Ƿ񱻵���=��;
			    break;
			  }
	      }
	if(������) return 0;
	return 1; 
}
9 .void ����(ʹ����,��ʹ����)
{
	if(��ʹ�������Ϊ�� && ʹ����Ϊ��)
	  {
	  	��ʹ����:Ѫ-1;
		if(��ʹ����:Ѫ<=0)
		  ����(ʹ����,��ʹ����)
		return ;
	  }
	if(ʹ��ĳ����(��ʹ����,ɱ))
	  ����(��ʹ����,ʹ����);
	else
	  {
	  	��ʹ����:Ѫ-1;
		if(��ʹ����:Ѫ<=0)
		  ����(ʹ����,��ʹ����) 
		return ; 
	  }
}
10 .bool �ж��Ƿ�ɹ���(��1����2)
{
	if(��1==���� && ��2��Ӫ!=��1��Ӫ)
	  return 1;
	if(��1==���� && ��2��Ӫ==����)
	  return 1;
	if(��1==���� && ��2��Ӫ!=��1��Ӫ)
	  return 1;
	return 0; 
}
11 .int �Ҿ���Ŀ��(ʹ����)
{
	int ��ʹ����=-1;
	if(ʹ����Ϊ����)
	  {
	  	��ʹ����=����; 
		ʹ��������=����;
	  }
	if(ʹ����Ϊ����)
	  {
	  	for(i=��ʱ�����������)
		  if(i������/�෴)
		    ��ʹ����=����,break;
	  }
	if(ʹ����Ϊ����)
	  {
	  	for(i=��ʱ�����������)
		  if(i������)
		    {
		      ��ʹ����=����,break;
			  ʹ��������=����; 
			}
	  }
	return ��ʹ����;
}
12 .bool �����Ƿ���Ч(ʹ����,��ʹ����)
{
	bool �Ƿ���и;
	if(��ʹ���������)
	  For(j=��ʱ�������ʹ����֮�����)
   	    If(j����Ӫ=��ʹ������Ӫ)
		  if(ʹ��ĳ����(j��,��и�ɻ�))
   	        {
		   	   j������=��ʹ��������;
		   	   if(��и(j��))
 			    �Ƿ���и=��, break;
		    }
	if(����и) return 0;
	return 1; 
} 
13. bool ʹ��ĳ����(ʹ����,ĳ����)
{
	int ��λ��=-1; 
	��λ��=ʹ��������.find(ĳ����);
	if(��λ��==-1)
	  return 0;
	����.earse(��λ��,1);
	return 1; 
}

*/

