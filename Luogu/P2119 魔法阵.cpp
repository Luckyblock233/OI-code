//知识点: 简单数学推导, 暴力, 枚举
/*
分析题意:
- 通过 简单分析 和 观察样例 , 可以发现 : 
  相等的数列元素 作为 x_a,x_b,x_c,x_d 出现的次数相同

   而n<=15000 , 所以 可以用桶直接 记录 每一种数 值出现的次数
   输出时 直接输出 某数列元素对应数值 作为 x_a,x_b,x_c,x_d 出现的次数即可

- 对 题目给出 限制条件 进行转化:
    - x_a<x_b<x_c<x_d ①
      x_b-x_a=2(x_d-x_c) ②
      x_b-x_a<(x_c-x_b)/3 ③
	- 设  t = x_d-x_c
	   将其 代入 ②中 , 则有: x_b-x_a = 2* t ④
	  将 ④ 代入 ③中 , 则有: 2* t < (x_c-x_b)/3
	  将其 转化后: 6* t<x_c - x_b 
	  
   - 再设 6* t+k =x_c - x_b ⑤
	  则可以得到一个数轴上的关系

	- 通过观察分析 , 可以得到 各个数值的 取值范围
	   1<t , 且9* t<n
	   1<= x_a<n-9* t
	   9* t+1<x_d <= n
	-  可以发现  ,  假设 已知 t 和 x_a , 
	   则可得 x_b = x_a+2t
		
	    同时还可发现 , 对于 已知的 t 和 x_a,    
	    所有 x >x_a+2t+6t 的位置都可以作为 合法的 x_c   
	    已知 x_c 的位置后 可以 求得 x_d = x_c+t  

  - 同理 , 若 t 和 x_d 已知 , 也可以 由上述过程 更新答案
	

- 通过上述 结论 , 发现可以通过 枚举 t,x_a和 x_d 解决问题:   
	
	 - 枚举 t 的值 , 1<t , 且9* t<n
		  - 枚举x_a 的值 ,并求得 x_b 的值 1<= x_a<n-9* t
			  - 枚举合法的 x_c ,并求得 x_d
			     - 现在就获得了 一组 合法的 序列元素的值
			     - 若 x_a,x_b,x_c,x_d 的数量分别为 num[x_a],...,num[x_d]   
			       根据乘法原理 ,  将 它们组合后 产生合法序列 的数量为 num[x_a]* num[x_b]* num[x_c]* num[x_d]
				- 则: 对于 x_a , 其作为 A 元素出现的个数 +=num[x_b]* num[x_c]* num[x_d]
						对于 x_b , 其作为 B 元素出现的个数 +=num[x_a]* num[x_c]* num[x_d]
						其他同理
			  - 则可 使用乘法原理 , 计算 贡献
				  
		  - 枚举x_d 的值,并求得 x_c 的值  9* t+1<x_d <= n
			  - 过程同上
---

- 对上式 进行观察:

	发现 x_d 递增时 , x_a 的合法范围 左边界不变 , 只有右边界 向右递增
	有许多 x_a 被重复枚举 , 导致 时间复杂度 上升
	
	对答案 有贡献的 只有 x_a的数量  * x_b的数量
	所以 可以对 (x_a的数量  * x_b的数量) 取一前缀和   
	每次 只需要 枚举 新增的 右边界 上的 x_a的数量  * x_b的数量
	用 新情况 更新前缀和 ,  再用前缀和 更新 答案       
  - 对于 x_a:
	同上 
*/
#include<cstdio>
#include<ctype.h>
const int MARX = 1e4+5e4+10;
//=============================================================
int n,m , x[MARX<<2],num[MARX];;
int ansa[MARX],ansb[MARX],ansc[MARX],ansd[MARX];
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
//=============================================================
signed main()
{
	n=read(),m=read();
	for(int i=1; i<=m; i++) //计算数量 
	{
	  x[i] = read();
	  num[x[i]] ++;
	}
	
	for(int t=1,sum=0; 9*t<n; t++,sum=0)//枚举t 
	{
	  for(int A = n-9*t-1; A; A--)//枚举A 
	  {
	  	int B = A+2*t , C = B+6*t+1 , D = C+t;//获得其他值 
		sum += num[C]*num[D];
	  	ansa[A] += num[B]*sum;//更新答案 
		ansb[B] += num[A]*sum;
	  }
	  sum = 0;
	  for(int D=9*t+2; D<=n; D++)//枚举D
	  {
	  	int A = D-9*t-1 , B = A+2*t , C = D-t;//获得其他值 
	  	sum += num[A]*num[B];
	  	ansc[C] += sum*num[D];//更新答案 
		ansd[D] += sum*num[C];
	  }
	}
	for(int i=1; i<=m; putchar('\n'),i++)
	  printf("%d %d %d %d",ansa[x[i]],ansb[x[i]],ansc[x[i]],ansd[x[i]]);
}
//O(n^3) 85分
/*
#include<cstdio>
int n,m , x[40010];
int ansa[15010],ansb[15010],ansc[15010],ansd[15010];
int num[15010];
signed main()
{
  scanf("%d%d",&n,&m);
  for(int i=1; i<=m; i++) 
  {
    scanf("%d",&x[i]);
    num[x[i]] ++;
  }

  for(int t=1; 9*t<n; t++)
  {
    for(int A = 1; A<=n-9*t-1; A++)
      for(int D = A+9*t+1; D<=n; D++)
      {
        int B = A+2*t;
        int C = D-t;
        ansa[A] += num[B]*num[C]*num[D];
        ansb[B] += num[A]*num[C]*num[D];
      }
    for(int D=9*t+2; D<=n; D++)
      for(int A = 1; A<= D-9*t-1; A++)
      {
        int B = A+2*t;
        int C = D-t;
        ansc[C] += num[A]*num[B]*num[D];
        ansd[D] += num[A]*num[B]*num[C];
      }
  }

  for(int i=1; i<=m; putchar('\n'),i++)
    printf("%d %d %d %d",ansa[x[i]],ansb[x[i]],ansc[x[i]],ansd[x[i]]);
}
*/ 
//O(n^4) 40分
/*
#include<cstdio>
int n,m , x[40010],ans[40010][5];
signed main()
{
    scanf("%d%d",&n,&m);
    for(int i=1; i<=m; i++) scanf("%d",&x[i]);
    for(int a=1; a<=m; a++) //暴力枚举
      for(int b=1; b<=m; b++)
        for(int c=1; c<=m; c++)
          for(int d=1; d<=m; d++)
            if(x[a] < x[b] && x[b] < x[c] && x[c] < x[d])
              if(x[b] - x[a] == 2*x[d] - 2*x[c])
                if(3*x[b] - 3*x[a] < x[c]-x[b])//暴力判断, 更新答案
                  ans[a][1]++, ans[b][2]++, ans[c][3]++, ans[d][4]++;
    
    for(int i=1; i<=m; putchar('\n'),i++)//输出
      for(int j=1; j<=4; j++)
        printf("%d ",ans[i][j]);
}
*/ 
