//知识点:Trie树/字典树, 贪心 
/*
题意: 
上下各n个数,
求一种排列p,
使上面的数i异或pi成为新的数i,
求方案另字典序最小,输出该结果

- 分析题意 :  
    
  - 字典序最小 :   
    则 c 数列的各位置 c[i] ,  
    都应该是能达到的最小的值      
    就可以考虑贪心  
    
  - 异或 , 数据范围 :  
    为什么数据范围要写成 2^30 这个样子?  
    再考虑异或运算...  
    想到进行二进制拆分   
   	
    将 a[i],b[i] 拆分后 ,   贪心就可以方便地进行  
    枚举两 01 串上 每一位上的数  
    尽量使 各位 相异 或后为 0  
    即可选择出最合适的 b[i]
    
    
  - 用什么来维护 拆分后的二进制数 ?   
    可以将二进制数  
    当成字符串来处理    
    想到建立一棵字典树  
    由于只有 0,1 两字符,所以是一棵二叉树  
    根据 字典树 的性质 ,   
    可以很方便地完成上述操作 .  
    
  
-  算法实现:

  先建立一棵基于各 b[i] 的二进制数 的字典树  
  并记录 各节点代表的 元素出现的个数 cnt  
  
  每次查询操作 , 将 a[i] 作参数进行传递  
  从字典树根部 , 开始向下查找 ,   
  查找每一层 (即每一二进制位) 的元素 ,   
  都尽量使 a[i],b[i] 此二进制位相异或为 0  
  若最优元素在此位置个数为 0 ,选择另一元素  
  使此位置选择的元素数量 -1  
  并进入下一层 , 继续进行查找 .

  根据字典树的性质 ,   
  每次查询操作 必然可以找到,  
  一个满足局部最优的 , 最适合 a[i] 的 b[i]  
  查询 n 次后 , 即可找到最优的答案
  
-  注意的点:  
  
  为方便运算 ,   
  要保证 字典树 中 ,   
  二进制数按照正向存储  
  
  也就是说,
  如果使用位运算符进行二进制拆分  
  要先拆出高位 , 再拆出低位  
  详见代码
*/
#include<cstdio>
#include<ctype.h>
#include<algorithm>
#define int long long
//==================================================
const int MARX = 3e5+10;
struct node
{
	int cnt,son[2];//存每个节点代表元素出现次数 , 两儿子 
}trie[20*MARX];
int n,num=1;
int a[MARX],b[MARX];//原始数列 
//==================================================
inline int read()
{
	int fl=1,w=0;char ch=getchar();
	while(!isdigit(ch) && ch!='-') ch=getchar();
	if(ch=='-') fl=-1;
	while(isdigit(ch)){w=w*10+ch-'0',ch=getchar();}
	return fl*w;
}
inline void insert(int key)//建树 
{
	int now=1;//从根节点开始,向下查找 
	trie[1].cnt++;
	for(int i=30;i>=0;i--)//将二进制数正向加入字典树 
	{
		int next=(key>>i)&1; //当前位数 
		if(!trie[now].son[next]) trie[now].son[next]= ++num;//添加新节点 
		now=trie[now].son[next];
		trie[now].cnt++;//增加出现次数 
	}
}
inline int query(int key)//回答询问 
{
	int now=1,ans=0;//从根部查找 
	for(int i=30;i>=0;i--) 
	{
		int next=(key>>i)&1;//最优情况 
		if(!trie[trie[now].son[next]].cnt) next=(!next);//不能满足最优情况 
		ans=(ans<<1)+next;//更新找到的 b[i] 
		now=trie[now].son[next];
		trie[now].cnt--;//减少出现次数 
	}
	return ans^key;
}
//==================================================
signed main()
{
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++) b[i]=read(),insert(b[i]); 
	for(int i=1;i<=n;i++) printf("%lld ",query(a[i]));
}
