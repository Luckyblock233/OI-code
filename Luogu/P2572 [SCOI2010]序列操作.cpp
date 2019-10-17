//
/*
By:Luckyblock
*/
#include<cstdio>
#include<ctype.h>
#include<algorithm>
#define ls (now << 1)
#define rs (now <<1 | 1)
#define ll long long
const int MARX = 1e5+10;
//=============================================================
struct node
{
	int l,r,lth,sum,tag;
	int l1,r1; //左右侧连续的1数量 
	int l0,r0;
}t[MARX<<2];
int n,m,begin[MARX];
//=============================================================
inline int read()
{
    int s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
void pushup(int now)
{
	if(t[ls].tag == 1 && t[rs].tag == 1) t[now].tag = 1;
	else if(t[ls].tag == 0 && t[rs].tag == 0) t[now].tag = 0;
	else t[now].tag = -1;
	
	t[now].sum = t[ls].sum + t[rs].sum;
	t[now].l1 = t[ls].l1 + t[rs].l1*(t[ls].l1 == t[ls].lth);
	t[now].r1 = t[rs].r1 + t[ls].r1*(t[rs].r1 == t[rs].lth);
	
	t[now].l0 = t[ls].l0 + t[rs].l0*(t[ls].l0 == t[ls].lth);
	t[now].r0 = t[rs].r0 + t[ls].r0*(t[rs].r0 == t[rs].lth);
}
void pushdown(int now)
{
	t[ls].tag = t[rs].tag = t[now].tag;
	
	if(t[now].tag <2)
	{
	  t[ls].sum = t[ls].tag * t[ls].lth;
	  t[rs].sum = t[rs].tag * t[rs].lth;
	
	  if(t[ls].tag) t[ls].l1 = t[ls].r1 = t[ls].lth, t[ls].l0 = t[ls].r0 = 0;
	  else t[ls].l1 = t[ls].r1 = 0, t[ls].l0 = t[ls].r0 = t[ls].lth;
	  if(t[rs].tag) t[rs].l1 = t[rs].r1 = t[rs].lth, t[rs].l0 = t[rs].r0 = 0;
	  else t[rs].l1 = t[rs].r1 = 0, t[rs].l0 = t[rs].r0 = t[rs].lth; 
	}
	else
	{
	  t[ls].tag = t[rs].tag = 2;
	  t[ls].sum = (t[ls].lth - t[ls].sum);
	  t[rs].sum = (t[rs].lth - t[rs].sum);
	  std::swap(t[ls].l1,t[ls].l0), std::swap(t[ls].r1,t[ls].r0);
	  std::swap(t[rs].l1,t[rs].l0), std::swap(t[rs].r1,t[rs].r0);
	}
	t[now].tag = -1;
}
void build(int now,int l,int r)
{
	t[now].l = l, t[now].r = r, t[now].lth = r - l + 1;
	if(l == r) 
	{
	  t[now].sum = t[now].tag = begin[l]; 
	  if(t[now].sum) t[now].l1 = t[now].r1 = 1;
	  else t[now].l0 = t[now].r0 = 1;
	  return ;
	}
	int mid = (l + r) >> 1;
	build(ls, l, mid), build(rs, mid+1, r);
	pushup(now);
}
void change(int now,int L,int R,int opt)
{
	if(L <= t[now].l && t[now].r <= R)
	  if(opt <= 1)
	  {
	  	t[now].tag = opt;
		t[now].l1 = t[now].r1 = t[now].sum = t[now].lth * opt;
		t[now].l0 = t[now].r0 = t[now].lth * (!opt);
	    return ;
	  }
	  else 
	  {
	  	t[now].tag = 2;
	  	t[now].sum = (t[now].lth - t[now].sum);
	  	std::swap(t[now].l1,t[now].l0);
	  	std::swap(t[now].r1,t[now].r0);
	    return ;
	  }
	if(t[now].tag != -1) pushdown(now);
	int mid = (t[now].l + t[now].r) >> 1;
	if(L <= mid) change(ls,L,R,opt);
	if(R > mid) change(rs,L,R,opt);
	pushup(now);
}
int query3(int now,int L,int R)
{
	if(L <= t[now].l && t[now].r <= R)
	{
	  if(t[now].tag == 2)
	  {
	  	t[now].sum = (t[now].lth - t[now].sum);
	  	std::swap(t[now].l1,t[now].l0);
	  	std::swap(t[now].r1,t[now].r0);
	  }
	  return t[now].sum;
	}
	if(t[now].tag != -1) pushdown(now);
	int mid = (t[now].l + t[now].r) >> 1 , ret = 0;
	if(L <= mid) ret += query3(ls,L,R);
	if(R > mid) ret += query3(rs,L,R);
	return ret;
}
void query4(int now,int L,int R,int &l,int &r)
{
	if(L <= t[now].l && t[now].r <= R && t[now].tag == 1)
	{
	  l = t[now].l, r = t[now].r;
	  return ;
	}
	
	if(t[now].l == t[now].r) return ;
	if(t[now].tag != -1) pushdown(now);
	int mid = (t[now].l + t[now].r) >> 1 , flag = 0;
	int LL = 0, LR = 0, RL = 0, RR = 0 ,  midl = 0, midr = 0;
	if(L <= mid) query4(ls,L,R,LL,LR), flag ++;
	if(R > mid) query4(rs,L,R,RL,RR), flag ++;
	
	if(flag == 2) midl = mid - t[ls].r1 + 1, midr= mid + t[rs].l1;
	if(LR - LL + 1 > RR - LR + 1) l = LL, r = LR;
	else l = RL, r = RR;
	if(midr - midl + 1 > r - l + 1) l = midl, r = midr;
}
//=============================================================
signed main()
{
	n = read(), m = read();

	for(int i = 1; i <= n; i ++) begin[i] = read();
	build(1,1,n);
	
	for(int i = 1; i <= m; i ++)
	{
	  int opt = read(), a = read()+1, b = read()+1;
	  if(opt <= 2) {change(1,a,b,opt);}
	  if(opt == 3)  printf("%d\n",query3(1,a,b));
	  if(opt == 4) 
	  {
	  	int l = 0, r = 0;
	  	query4(1,a,b,l,r);
	  	printf("%d\n",(r-l+1));
	  }
	}
}
