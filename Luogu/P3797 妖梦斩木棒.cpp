//知识点: 线段树,模拟 
/*
By:Luckyblock
题目要求:   
给定 一 长度为 n 的字串 , 由 “(” 、“X” 、 “)”三种字符构成 ,   
初始状态 为  “(XX...XX)”   
需要支持下列两种操作:    
1.  修改 : 将第 i 个元素替换为 三种元素中 给定的的一种.   
2.  查询 : 查询区间 [l,r] 中 , 形如 “(X..X)” 或 “()” 字符串的个数   
	( 目标字串 首尾为 “()”  , 且 “()”中间 只能存在 “X” )   



分析题意:   

一开始走了许多弯路 = = ,    
得到了许多 看起来很有用 实际上 卵用没有的结论   
经过整理后 ,  用的只有下列结论 :   

1. 对于一个只由 “(” 与 “)”构成的字串 ,   
	向其中 任意位置 插入 任意数量 的 “X” ,     
	对任意区间内 目标字串的数量都没有影响   

	根据此结论 , 可以将 原字串 进行 转化 ,   
	忽略所有 的 “X”,  以便于之后的的 分析及调试	   

2.  假设现 有两相邻字串 A与 B    
	A, B 中 目标字串 的数量 分别为 sum_a 与 sum_b,    
	 求 两序列 合并后 目标字串的数量  sum_{a+b}    
	
    - 显然 , 合并后 sum_{a+b}至少为 sum_a + sum_b    
	  可不可能出现新的目标字串 , 使合并后 目标字串数量有所增加  ?    
	  答案是肯定的.     

	    如下列情况 (忽略了所有的 “X”) :   
	
      | ...( | )...| ...()..| 
      | A 	 | B   |   A+B  |
      此时有: sum_{a+b} = sum_a+sum_b+1  

    - 合并时 如何维护 此类 横跨两个区间的 目标字串??   
	  可以维护每一个区间的 最左侧的非 “X”字符与 最右侧的非“X”字符.   
	  
	  在合并时 , 若 左区间最右侧为“(”且 右区间最左侧为“)” 
	  则证明 出现上述情况  , 区间目标字串数+1   

3. 由结论 2扩展而来 :   
	如何维护 区间的 最左,最右侧的 非“X”符 ?   
	
	- 区间内只有一个元素时: 两 非“X”字符 即 该元素   
	- 当区间 有多个元素时, 可以将区间 看做 两不相交的 子区间合并而来 :   
		1. 当两子区间均不全为“X”时  ,     
			区间最左侧 非“X”字符 = 左子区间 最左侧非 “X”字符,     
			区间最右侧 非“X”字符 = 右子区间 最右侧非 “X”字符,     
			
		2. 当右子区间 全为“X”时:   
			区间最左侧 非“X”字符 = **左**子区间 最**左**侧非 $“X”$ 字符,     
			区间最右侧 非“X”字符 = **左**子区间 最**右**侧非 $“X”$ 字符,     
		3. 当左子区间 全为“X”时:  同 2 

	- 由上 , 只需要再维护 区间是否为空 ,        
	  该信息即可由 递归回传 来进行维护 .      

4. 题目要求的 区间查询:    
	本体 即 简单的区间求和     
	但是 存在 结论 2 中描述的: 横跨 两子区间的 目标字串     
	则需要对 线段树的区间求和操作 进行微小的改造:     
	
	设查询区间为 [L,R] , 可以发现:     
	
	满足下列 3 个条件时 , 存在 横跨 两子区间的 目标字串     
	- 当 [L,R]横跨 某区间 的 左右子区间    
	- 左子区间 最右侧  非 “X” 字符为  “(”, 位置为 pos1    
	  右子区间 最左侧  非 “X”字符为 “)”, 位置为 pos2    
	- L<= pos1 且 pos2 <= R   
	
	为实现上述操作 , 还需要维护 最左 , 最右侧的 非 “X” 字符 的位置       
	
	

算法实现:

根据 上述结论 , 现在需要一种数据结构 ,    
支持 维护区间信息 , 递归回传 , 单点修改   

- 建立 一棵 维护下列 区间信息的线段树:
	- 最左侧第一个 非“X”字符 是否为 “)”
	  最右侧第一个 非“X”字符 是否为 “(”
    - 是否全部为 “X”  
    - 目标字串数量
- 单点修改 操作 :
   先深入至 目标 叶节点 , 更新叶节点的信息
   之后 根据 结论 2,3 , 递归更新区间信息 
- 区间查询 操作 : 根据结论4, 求区间和即可
*/
#include<cstdio>
#include<cstdlib>
#include<ctype.h>
#define ls (now<<1)
#define rs ((now<<1)+1)
const int MARX = 2e5+10;
//=============================================================
struct node
{
    int L,R;//维护的区间,
    bool allX,side[3];//是否全为X , side[0]:最左侧是否有) , side[1]:最右侧是否有( ,
    int sum,pos[3]; //区间内完整木棒数, 及区间内 最左侧),最右侧( 位置 
}tree[MARX<<4];
int n,m, map[110],map1[3];//map存映射关系, 0<->( , 1<->) , 2<->X 
char now_list[MARX];//当前的 字串 
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
void Build(int now,int l,int r)//常规建树
{
    tree[now].L=l,tree[now].R=r;
    if(l == r) return ;
    int mid = (l+r)>>1;
    Build(ls,l,mid);
    Build(rs,mid+1,r);
}
void pushup(int now)//更新 第now个节点 的各信息 
{
    //维护 区间最左侧 是否有) 
    if(tree[ls].side[0]) tree[now].side[0]=1, tree[now].pos[0] = tree[ls].pos[0]; 
    else if(!tree[ls].allX && tree[rs].side[0]) tree[now].side[0]=1 , tree[now].pos[0]= tree[rs].pos[0];
    else tree[now].side[0] = 0;
    //维护 区间最右侧 是否有( 
    if(tree[rs].side[1]) tree[now].side[1]=1 , tree[now].pos[1] = tree[rs].pos[1];
    else if(!tree[rs].allX && tree[ls].side[1]) tree[now].side[1]=1 , tree[now].pos[1]= tree[ls].pos[1];
    else tree[now].side[1] = 0;
    //更新区间 合法字串数, 区间是否全为'X' 
    tree[now].sum = tree[ls].sum+tree[rs].sum + (tree[ls].side[1] && tree[rs].side[0]);;
    tree[now].allX = (tree[ls].allX || tree[rs].allX);
}
void Change(int now,int pos,int value) //单点修改, 将第pos个位置修改为 value 
{
    if(tree[now].L==pos && tree[now].R==pos)//当前区间 即指定位置 
    {
      now_list[pos] = map1[value];//更新各信息 
      tree[now].allX = (value!=2);//是否全为X 
      tree[now].side[0] = tree[now].side[1] = 0;//更新 最左,最右侧元素 
      tree[now].side[value] = 1, tree[now].pos[value]=pos;
      return ;
    }
    int mid = (tree[now].L+tree[now].R)>>1;
    if(pos <= mid) Change(ls,pos,value);
    if(pos > mid) Change(rs,pos,value);
    pushup(now);//更新当前位置 
}
int Inquiry(int now,int L,int R)//查询区间 L,R 的目标字串数 
{
    if(L <= tree[now].L && tree[now].R <= R) return tree[now].sum;
    int sum=0,flag=0;//flag 判断区间 是否同时被左右子区间更新过   
    int mid = (tree[now].L+tree[now].R)>>1;
    if(L<=mid) sum += Inquiry(ls,L,R), flag++;
    if(R>mid) sum += Inquiry(rs,L,R), flag++;
    //存在 合法字串 横跨左右子区间  
    if(flag == 2) sum += (tree[ls].side[1] && L<=tree[ls].pos[1] && tree[rs].side[0] && R>=tree[rs].pos[0]);
    return sum; 
}
void prepare()//预处理 
{
    n=read() , m=read();
    Build(1,1,n);
    Change(1,1,1) , Change(1,n,0);

    now_list[1]='(' , now_list[n]=')';//原始字串 
    for(int i=2; i<n; i++) now_list[i]='X';

    map['(']=1, map[')']=0, map['X']=2;//建立映射关系 
    map1[1]='(',map1[0]=')',map1[2]='X';
}
//=============================================================
signed main()
{
    prepare();
    for(int i=1; i<=m; i++)
    {
      int type=read(),value1,value2;
      char value3;
      if(type == 1) //修改操作 
      {
        value1=read(); value3 = getchar();//读入防卡 
        getchar();
        if(now_list[value1] == value3) continue;
        Change(1,value1,map[(int)(value3)]);
      }
      else //查询操作 
      {
        value1=read(), value2=read();
        printf("%d\n",Inquiry(1,value1,value2));
      }
    }
}
