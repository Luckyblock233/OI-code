//人生第一黑 
//底部为大纲,已经写的非常详细了 
//请恕我不写注释= = 
#include<iostream>
#include<cstdlib>
#include<queue>
#include<string>
using namespace std;
//=============变量=============================
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
//============子函数列表===========================
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
//==============主函数================================
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
//==============子函数================================ 
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
猪国杀
目录：

主函数
备注
变量列表
子函数列表













主函数：
int main()
{
	输入()
	while(1)
  	  {
  		bool  判断是否用过杀=0;
		bool 使用了牌=0;
		摸牌(当前猪)x2;
		while(1)
		  {
		  	int i=0(牌指针)
		    For(i=所有牌,初值为0)
  		      {
  		  	    string 当前牌;
			    当前牌+=手牌[i];
			    If(桃 && 血量<4)
　　		      手牌.earse(i,1),使用了牌,血量+1;
                if(诸葛连弩)
                  手牌.earse(i,1),使用了牌,装备; 
			    if(南蛮入侵||万箭齐发)
  			      手牌.earse(i,1),使用了牌,当前牌(使用猪);
			    if(决斗)
      		      {
					int 决斗对象=决斗能否生效(当前猪);
					if(决斗对象==-1)
					  continue; 
      		      	手牌.earse(i,1),使用了牌;
				    if(决斗是否生效(使用猪,被使用猪))
			          决斗(当前猪,决斗对象); 
		          }
			    if(能攻击(当前猪,下一猪) && 杀)
  			  	  if(没有使用杀||诸葛连弩) 
      			    手牌.earse(i,1),使用了牌,杀(当前猪,下一猪),使用了杀;
      	       if(使用了牌)
			     break;
			  }
		    if(!使用了牌) break;
			if(当前猪:血<=0) break;
			i=0; 
		  }
     	当前猪=下一猪; 
      }
}





备注:
1.	队列存手牌,牌堆(手牌用数组模拟,牌堆用stl)
2.	链表存猪的顺序(链表指向下一猪)
3.  0主公，1忠臣，2反贼 


变量列表:
1.	结构体存某一猪
{
	int型 血量;
	int型 身份;(0主公，1忠臣，2反贼 ) 
	int型 倾向(0表示没有跳 1确定倾向主公,2确定倾向反贼,3倾向类反贼)
	string型 手牌;
	bool型 是否装备诸葛连弩;
}
2 int型二维数组,链表存上一猪,下一猪;
3 bool型变量，判断主公是否死亡，初始为1;
4 int型变量，记录存活的反贼个数; 



子函数列表：
1.	Void 输入
{
	For(i=人数)
      {
	    身份,摸牌(i)x4;
		记录身份;
		if(阵营为主公)
		  倾向=主公; 
		血量=4;
		If(反贼) 反贼存活数+1;
	  }
    for(i=牌堆牌数)
   	  输入,压入牌堆队列;
}
2.	Void 摸牌(猪编号)
{
	string 摸得牌;
	摸得牌=牌堆.front();
	if(不是最后一张牌) 
	  {
		牌堆牌数--; 
		牌堆.pop();
	  }
    此猪手牌+摸得牌;
	return ;
}
３.void 杀(使用猪编号,被使用猪编号)
{
	if(被使用猪倾向为反贼) 使用猪倾向=主公;
	if(被使用猪倾向主公) 使用猪倾向=反贼;
    If(!使用某张牌(被使用猪,闪)) 
  	  被使用猪:血量-1; 
	if(被使用猪:血量<=0)
  	  濒死(使用猪,被使用猪);
}
４. void 濒死(使用猪,被使用猪)
{ 
	while(被使用猪:血量<=0) 
      {
      	if(使用某张牌(被使用猪,桃))  被使用猪:血量+1;
	    else break; 
	  }
	if(被使用猪:血量<=0)
      {
		if(被使用猪为反贼) 
		  {
            反贼数-1;
			游戏结束(); 
			摸牌(使用猪)x3; 
		  }
        if(被使用猪为忠臣 &&　使用猪为主公)
　　　　　主公手牌="",装备牌弃除;
		if(被使用猪为主公)
          {
		    主公死亡;
		    游戏结束();
		  }
		被指用猪的上一猪,链表指向被使用猪的下一猪; 
	  }
}
5.void 游戏结束()
{
	if(主猪死亡 || 反贼数==0)
  	  {
  	  	输出;
		exit(0);
	  }
	return ;
}
6.void 南蛮入侵(使用猪)
{
	for(i=存活所有猪)
  	  {
      	bool 是否被无懈; 
     	if(i猪跳身份)
		  for(j=以使用猪为起点逆时针遍历猪)
   			if(j猪阵营=i猪倾向)
			  if(使用某张牌(j猪,无懈可击))
　　 			{
				  j猪倾向=i猪倾向;
				  if(无懈(j猪))
 					是否被无懈=真, break;
				}
		if(被无懈)continue;
		if(!使用某张牌(i猪,杀))
		  {
			血-1; 
			if(i猪为主公&&使用猪无倾向) 使用猪倾向类反贼; 
		  }
       	If(i猪血<=0) 濒死(使用猪,i猪);
	  }
}
7.万箭齐发(使用猪)
{
	for(i=存活所有猪)
  	  {
      	bool 是否被无懈; 
     	if(i猪跳身份)
		  for(j=以使用猪为起点逆时针遍历猪)
   			if(j猪阵营=i猪倾向)
			  if(使用某张牌(j猪,无懈可击))
　　 			{
				  j猪倾向=i猪倾向;
				  if(无懈(j猪))
 					是否被无懈=真, break;
				}
		if(被无懈)continue;
		if(!使用某张牌(i猪,闪))
		  {
			血-1; 
			if(i猪为主公&&使用猪无倾向) 使用猪倾向类反贼; 
		  }
       	if(i猪血<=0) 濒死(使用猪,i猪);
	  }
}
8 .bool 无懈可击(使用猪)
{
	bool 是否被抵消; 
	for(i=逆时针遍历从使用猪之后的猪)
	  if(i猪与使用猪相反阵营)
	    if(使用某张牌(i猪,无懈可击))
	      {
	        i猪倾向=(!使用猪倾向)
		    if(无懈可击(i猪)) 
		      {
			    是否被抵消=真;
			    break;
			  }
	      }
	if(被抵消) return 0;
	return 1; 
}
9 .void 决斗(使用猪,被使用猪)
{
	if(被使用猪身份为忠 && 使用猪为主)
	  {
	  	被使用猪:血-1;
		if(被使用猪:血<=0)
		  濒死(使用猪,被使用猪)
		return ;
	  }
	if(使用某张牌(被使用猪,杀))
	  决斗(被使用猪,使用猪);
	else
	  {
	  	被使用猪:血-1;
		if(被使用猪:血<=0)
		  濒死(使用猪,被使用猪) 
		return ; 
	  }
}
10 .bool 判断是否可攻击(猪1，猪2)
{
	if(猪1==主猪 && 猪2阵营!=猪1阵营)
	  return 1;
	if(猪1==忠猪 && 猪2阵营==反猪)
	  return 1;
	if(猪1==反猪 && 猪2阵营!=猪1阵营)
	  return 1;
	return 0; 
}
11 .int 找决斗目标(使用猪)
{
	int 被使用猪=-1;
	if(使用猪为反猪)
	  {
	  	被使用猪=主猪; 
		使用猪倾向=反猪;
	  }
	if(使用猪为主猪)
	  {
	  	for(i=逆时针遍历所有猪)
		  if(i猪跳反/类反)
		    被使用猪=该猪,break;
	  }
	if(使用猪为忠猪)
	  {
	  	for(i=逆时针遍历所有猪)
		  if(i猪跳反)
		    {
		      被使用猪=该猪,break;
			  使用猪倾向=主猪; 
			}
	  }
	return 被使用猪;
}
12 .bool 决斗是否生效(使用猪,被使用猪)
{
	bool 是否被无懈;
	if(被使用猪跳身份)
	  For(j=逆时针遍历从使用猪之后的猪)
   	    If(j猪阵营=被使用猪阵营)
		  if(使用某张牌(j猪,无懈可击))
   	        {
		   	   j猪倾向=被使用猪倾向;
		   	   if(无懈(j猪))
 			    是否被无懈=真, break;
		    }
	if(被无懈) return 0;
	return 1; 
} 
13. bool 使用某张牌(使用猪,某张牌)
{
	int 牌位置=-1; 
	牌位置=使用猪手牌.find(某张牌);
	if(牌位置==-1)
	  return 0;
	手牌.earse(牌位置,1);
	return 1; 
}

*/

