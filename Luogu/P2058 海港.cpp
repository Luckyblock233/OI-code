//知识点: 模拟,单调队列 
/*
题目要求 :   
给定 n 个 数列 ,      
第 i 个数列 会在第 ti 秒出现 , 数列元素数为 ki , 其第 j 个元素为 x(i,j)   
对于每一个 ti , 求 时间段 [ti - 86400,ti] 内出现的数列中   
不同的元素 的个数   
n<=100,000, sum(ki) <=300,000

分析题意:
1.如果想要 记录下 每个数列中的每个元素      
  为保证不越界 , 需要 声明一个 100,000 X 300,000 的静态数组   
  若为int型 , 占用空间 为 100,000 X 300,000 X 4  ÷ (1024^2) =114440.91796875 MB     

  显然 , 如果不使用 动态数组 , 那么必须 边读入 边进行处理 ,       
  否则有占用空间 爆炸 , 直接爆零的危险. 
2.对于 题目中 按照时间顺序 给出的数列  
  满足 队列的 先进先出 性质    
  同时 能对答案做出贡献的 数列 都位于时间段 [ti - 86400,ti] 中  

  此题变成一个 很显然的 单调队列 类问题  .     
  单调队列 中将 数列作为 单调队列元素 , 
  各数列 出现时间单调 递增
  
3.如何计算 某时刻 数列中不同的元素 的个数 ?     
  可以 维护 所求时间段内 各数列元素 的数量  ,       
  当 添加/删除 单调队列中的元素时 , 更新 各数列元素 的数量   

  当 某 数列元素数量 0-->1 时 , 
  说明 数列中 不同元素数量 +1
  当 某 数列元素数量 1 -->0 时 , 
  说明 数列中 不同元素数量 -1
 
4.对于 单调队列 类问题 ,    
  需要 支持 从队尾添加元素  , 从 队首删除元素   
  则 需要记录 队首被删除 元素	

  但是空间会爆炸怎么办 ? ? ?	
  有一种 非常巧妙的 处理方法:
5. sum(ki)说明 所有数列元素数 <= 300,000   
  通过 一个结构体 , 记录 某数列元素 出现时间 和 值	
  则 可以 直接把 数列元素 作为单调队列的元素
  
6.由于 数据给出时 , 已经按照 时间递增顺序 给出  
  所以 所有数列元素 出现时间 满足时间递增的 单调性  
  可以直接 使用 普通队列 来模拟单调队列
7.边输入 边进行处理:    
	1. 每当输入 一个新数列 ,      
	对于 每一个数列元素 , 都建立一个 结构体 , 储存 其值与 出现时间       
	更新 所求时间段内 各数列元素 的数量  , 与 数列中不同的元素 的个数     
	然后 将 此数列 放入队列尾部    

	2. 新数列 输入完毕后 , 	  
	开始处理 队首 出现时间 较早 , 已经不在要求区间内的 数列元素	  	  
	直接 将它们弹出队列 , 直到弹到 一个 位于要求区间内的 数列元素	  
	同时更新 所求时间段内 各数列元素 的数量  , 
	与 数列中不同的元素 的个数 

 	3. 输出 数列中不同的元素 的个数 即可
*/
#include<iostream>
#include<queue>
const int MARX = 100010;
using namespace std;

struct person//单调队列元素 
{
	int nation,time;
};
int n,ans , nation_num[MARX*3];
queue <person> q; 
int main()
{
	cin >> n;
	for(int i=1; i<=n; i++)
	{
	  int t,k;
	  cin >> t >> k;
	  
	  for(int i=1; i<=k; i++)//加入新元素 
	  {
		person now;
		cin >> now.nation;
		now.time = t;
		
		if(!nation_num[now.nation]) ans++;//更新答案 
		nation_num[now.nation] ++;
		
		q.push(now);//入队 
	  }
	  
	  if(!q.empty())//删除 不合法元素 
	    while(t - q.front().time >= 24*60*60)//超出范围 
	    {
	  	  nation_num[q.front().nation] --;//更新答案 
		  if(!nation_num[q.front().nation]) ans--;
	  	  q.pop();
	  	  if(q.empty()) break;
	    }
	  
	  cout << ans <<endl;
	}
}
//无耻vector 暴力过 
/*
#include<iostream>
#include<queue>
#include<vector>
const int MARX = 100010;
using namespace std;

int n,t[MARX],k[MARX],nation[MARX];
vector <int> x[MARX*3];

int main()
{
	cin >> n;
	for(int i=1; i<=n; i++)
	{
	  cin >> t[i] >> k[i];
	  for(int j=1; j<=k[i]; j++)
	  {
		int tmp;
		cin >> tmp;
		x[i].push_back(tmp);
	  }
	}
	
	
	int last_boat = 1 , nation_num = 0;
	for(int i=1; i<=n; i++)
	{
	  while(t[i] - t[last_boat] >= 24*60*60)
	  {
	  	for(int j=0; j<k[last_boat]; j++)
	  	{
	  	  nation[x[last_boat][j]] --;
          if(nation[x[last_boat][j]] == 0)
            nation_num --;
		}
		last_boat ++;
	  }
	  
	  for(int j = 0;j < k[i];++ j)
        {
          nation[x[i][j]] ++;
          if(nation[x[i][j]] == 1)
            nation_num ++;
        }
        cout << nation_num << endl;
	}
	return 0;
}
*/
