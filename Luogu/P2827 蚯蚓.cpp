//知识点:思路题,模拟,单调队列(?) 
/*
关于处理 对 未被处理的元素 加上一个数 的操作,
  暴力加值显然不可取
  那么可以反向思考,
  考虑 懒标记 法 , 
    修改时 , 暂不对原数进行修改 
	而是用懒标记 记录应该累加的值
	显然,每次加值操作,
	懒标记都应 += Q ;
	 
    而 对于每次被处理 的,不应被加值的元素, 
      先将其还原回 原状态,
	  然后进行切割处理, 
	  更新懒标记后,
	  在将新得到的两段 , 
	  减去当前新的懒标记
	  
	  这样新的两段,
	  就比没有被操作的数少了 1*Q ,
   
暴力思路:
  直接使用 大根堆 进行模拟.
  类似 P1090合并果子 的思路
  每次都取出 堆顶元素
  将其变化成两个元素后,
  再将其插入堆中
  
  总复杂度 O((n+m)log(n+m))
  如此优秀的复杂度,
  却被毒瘤的出题人卡掉了 
  但是可以获得70~85分不等的好成绩(大雾) 
  
正解思路:
  可以发现:
  假设每次取出堆顶的元素 a1,
  将其变换后得到 floor(a1*u/v) 与 floor(a1 - a1*u/v)
  
  那么在其之后取出的元素 ai,
  有: ai<=a1 , 
  也有: floor(ai*u/v)<=floor(a1*u/v) , 
  		floor(ai - ai*u/v)<=floor(a1 - a1*u/v) 
  自身便满足单调性
  
  那么对于原数列,
  先进行一遍降序排序,
  
  之后开三个队列,
  分别存储 
  	没有被切割的,
  	被切割成floor(ai*u/v)的,
	被切割成floor(ai - ai*u/v)的. 
   
  对于这三个队列,
  由上可知, 
  如果每次都将新元素插入队尾, 
  那么分别满足 单调递减 的性质 

  每次进行选择时,
  将三个队列的队首进行比较,
  其中最长的一个,
  便是应该被处理的元素,
  
  然后进行切割处理,
  再将处理后的部分,
  对应加入上述指定队列中,
  
  由于n<=1e5,m<=7e6,
  nlogn < m, 
  所以总复杂度O是(m),
  很神奇地做到了线性 
*/
#include<cstdio>
#include<queue>
#include<algorithm>
#include<functional>
#define int long long
const int MARX = 1e5+10;
const int INF = 1<<31-1;
//============================================
int N,M,Q,U,V,T;//输入的初始变量. 
int l;//懒标记 
int a[MARX];
std:: queue <int> q[4];//分别存储 没有被切割的,  被切割成floor(ai*u/v)的	被切割成floor(ai - ai*u/v)的. 
//============================================
inline bool cmp(int first,int second) {return first>second;}
int find()//找到三个队列队首最大的元素 
{
	int top,maxx=-INF;
	//被处理元素减去懒标记,可能为负,需将最大值的初值设为负无穷. 
	for(int i=1;i<=3;i++)
	  if(!q[i].empty())
	    if(q[i].front()>maxx) 
	      top=i,maxx=q[i].front();//进行更新 
	return top;
}
void prepare()//输入 && 预处理 
{
	scanf("%lld%lld%lld%lld%lld%lld",&N,&M,&Q,&U,&V,&T);
	for(int i=1;i<=N;i++) scanf("%lld",&a[i]);
	std::sort(a+1,a+N+1,cmp);//进行排序 
	for(int i=1;i<=N;i++) q[1].push(a[i]);//加入第一队列 
}
//============================================
signed main()
{
	prepare();
	for(int i=1;i<=M;i++)
	{
	  int top=find() , maxx=q[top].front();//找到被处理元素
	  q[top].pop() , maxx+=l , l+=Q;//还原被处理元素,并更新懒标记  
	  int x = (int)((long long)maxx*U/V) , y=maxx-x;//进行切割操作 
	  q[2].push(x-l),q[3].push(y-l);//减去懒标记,再次入队 
	  if(i%T==0) printf("%d ",maxx); 
	}
	printf("\n");
	
	for(int i=1;i<=N+M;i++)
	{
	  int top=find() , maxx=q[top].front();//找到最大的元素 
	  q[top].pop();
	  if(i%T==0) printf("%d ",maxx+l);
	}
}
