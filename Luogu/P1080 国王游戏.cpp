//知识点:贪心
/*
1. 可以发现,
   如果已经排好了队列,
   任意交换其中相邻两个人的位置,  
   对之前的,之后的人的答案
   都没有影响

   那么可以只分析相邻两个人的情况

2.  对于相邻两个人:
	设前面的人的 a 的总积为 a0
	设第一个人的数为: a1,b1
	设第二个人的数为: a2,b2

	由于两个人的排列方式只有两种, 
	所以可以枚举各情况 , 并取最大值
	所以:第一个人的答案为: a0/b1 ,或 (a0*a2)/b1
	     第二个人的答案为: a0/b2 ,或 (a0*a1)/b2

	所以两人的 奖赏 的最大值为:
	max(  max(a0/b1 , (a0*a1)/b2)  ,  max(a0/b2 , (a0*a2)/b1)  )
	进行通分后,最大值为: 
	max(  max( a0*b2/(b1*b2) , a0*(a1*b1)/(b1*b2) )  , max(a0*b1/(b1*b2) , a0*(a2*b2)/(b1*b2))  )
	即:  a0 * max( max(b2,a1*b1) , max(b1,a2*b2) )/(b1*b2);
	
	假设 a1*b1 <= a2*b2 , 
	因为 b2< a2*b2 , b1<a1*b1 ,则有:
	max(b2,a1*b1) <= a2*b2 <= max(b1,a2*b2) 
	那么将 第一个人 排在前面更加 合理. 
	同理,可以发现, 如果把ai*bi较小的排在前面 , 那么答案更优 

	所以按照 aibi的乘积升序排序后 , 模拟并取答案即可
	
	另外,此题最恶心的地方是高精度 , 要手写高精乘与高精除. 
*/
#include <cstdio>
#include <iostream>
#include <vector>
#include <iomanip>
#include <cassert>
#include <algorithm>
#include <cstring>

const int Big_B = 10; const int Big_L = 1;
inline int intcmp_ (int a, int b) { if (a > b) return 1; return a < b ? -1 : 0; }
struct Int 
{
	#define rg register
    inline int max (int a, int b) { return a > b ? a : b; }
    inline int min (int a, int b) { return a < b ? a : b; }
    std :: vector <int> c; Int () {} typedef long long LL; 
    Int (int x) { for (; x > 0; c.push_back (x % Big_B), x /= Big_B); }
    Int (LL x) { for (; x > 0; c.push_back (x % Big_B), x /= Big_B); }
    inline void CrZ () { for (; !c.empty () && c.back () == 0; c.pop_back ()); }
    inline Int &operator += (const Int &rhs)
    {
        c.resize (max (c.size (), rhs.c.size ())); rg int i, t = 0, S;
        for (i = 0, S = rhs.c.size (); i < S; ++ i)
            c[i] += rhs.c[i] + t, t = c[i] >= Big_B, c[i] -= Big_B & (-t);
        for (i = rhs.c.size (), S = c.size (); t && i < S; ++ i)
            c[i] += t, t = c[i] >= Big_B, c[i] -= Big_B & (-t);
        if (t) c.push_back (t); return *this;
    }
    inline Int &operator -= (const Int &rhs)
    {
        c.resize (max (c.size (), rhs.c.size ())); rg int i, t = 0, S;
        for (i = 0, S = rhs.c.size (); i < S; ++ i)
            c[i] -= rhs.c[i] + t, t = c[i] < 0, c[i] += Big_B & (-t);
        for (i = rhs.c.size (), S = c.size (); t && i < S; ++ i)
            c[i] -= t, t = c[i] < 0, c[i] += Big_B & (-t);
        CrZ (); return *this;
    }
    inline Int &operator *= (const Int &rhs)
    {
        rg int na = c.size (), i, j, S, ai; 
        c.resize (na + rhs.c.size ()); LL t;
        for (i = na - 1; i >= 0; -- i)
        {
            ai = c[i], t = 0, c[i] = 0;
            for (j = 0, S = rhs.c.size (); j < S; ++ j)
            {
                t += c[i + j] + (LL) ai * rhs.c[j];
                c[i + j] = t % Big_B, t /= Big_B;
            }
            for (j = rhs.c.size (), S = c.size (); t != 0 && i + j < S; ++ j)
                t += c[i + j], c[i + j] = t % Big_B, t /= Big_B;
            assert (t == 0);
        }
        CrZ (); return *this;
    }
    inline Int &operator /= (const Int &rhs) { return *this = div (rhs); }
    inline Int &operator %= (const Int &rhs) { return div (rhs), *this; }
    inline Int &shlb (int l = 1)
    {
        if (c.empty ()) return *this; c.resize (c.size () + l);rg int i;
        for (i = c.size () - 1; i >= l; -- i) c[i] = c[i - l];
        for (i = 0; i < l; ++ i) c[i] = 0;
        return *this;
    }
    inline Int &shrb (int l = 1)
    {
        for (rg int i = 0; i < c.size () - l; ++ i) c[i] = c[i + l];
        c.resize (max (c.size () - l, 0)); return *this;
    }
    inline Int div (const Int &rhs)
    {
        assert (!rhs.c.empty ()); Int q, r; rg int i; if (rhs > *this) return 0;
        q.c.resize (c.size () - rhs.c.size () + 1); rg int _l, _r, mid;
        for (i = c.size () - 1; i > c.size () - rhs.c.size (); -- i) r.shlb (), r += c[i];
        for (i = c.size () - rhs.c.size (); i >= 0; -- i)
        {
            r.shlb (); r += c[i]; 
            if (r.Comp (rhs) < 0) q.c[i] = 0;
            else 
            {
                _l = 0, _r = Big_B;
                for (; _l != _r; )
                {
                    mid = _l + _r >> 1;
                    if ((rhs * mid).Comp (r) <= 0) _l = mid + 1; else _r = mid;
                }
                q.c[i] = _l - 1, r -= rhs * q.c[i];
            }
        }
        q.CrZ (), *this = r; return q;
    }
    inline int Comp (const Int &rhs) const 
    {
        if (c.size () != rhs.c.size ()) return intcmp_ (c.size (), rhs.c.size ());
        for (rg int i = c.size () - 1; i >= 0; -- i) 
            if (c[i] != rhs.c[i]) return intcmp_ (c[i], rhs.c[i]);
        return 0;
    }
    friend inline Int operator + (const Int &lhs, const Int &rhs)
    { Int res = lhs; return res += rhs; }
    inline friend Int operator - (const Int &lhs, const Int &rhs)
    { 
        if (lhs < rhs)
        {
            putchar ('-'); 
            Int res = rhs; return res -= lhs;
        }
        else { Int res = lhs; return res -= rhs; }
    }
    friend inline Int operator * (const Int &lhs, const Int &rhs)
    { Int res = lhs; return res *= rhs; }
    friend inline Int operator / (const Int &lhs, const Int &rhs)
    { Int res = lhs; return res.div (rhs); }
    friend inline Int operator % (const Int &lhs, const Int &rhs)
    { Int res = lhs; return res.div (rhs), res; }
    friend inline std :: ostream &operator << (std :: ostream &out, const Int &rhs)
    { 
        if (rhs.c.size () == 0) out << "0";
        else 
        {
            out << rhs.c.back ();
            for (rg int i = rhs.c.size () - 2; i >= 0; -- i)
                out << std :: setfill ('0') << std :: setw (Big_L) << rhs.c[i];
        }
        return out;
    } 
    friend inline std :: istream &operator >> (std :: istream &in, Int &rhs)
    {
        static char s[100000];
        in >> s + 1; int Len = strlen (s + 1);
        int v = 0; LL r = 0, p = 1;
        for (rg int i = Len; i >= 1; -- i)
        {
            ++ v; r = r + (s[i] - '0') * p, p *= 10;
            if (v == Big_L) rhs.c.push_back (r), r = 0, v = 0, p = 1;
        }
        if (v != 0) rhs.c.push_back (r); return in;
    }
    friend inline bool operator < (const Int &lhs, const Int &rhs)
    { return lhs.Comp (rhs) < 0; }
    friend inline bool operator <= (const Int &lhs, const Int &rhs)
    { return lhs.Comp (rhs) <= 0; }
    friend inline bool operator > (const Int &lhs, const Int &rhs)
    { return lhs.Comp (rhs) > 0; }
    friend inline bool operator >= (const Int &lhs, const Int &rhs)
    { return lhs.Comp (rhs) >= 0; }
    friend inline bool operator == (const Int &lhs, const Int &rhs)
    { return lhs.Comp (rhs) == 0; }
    friend inline bool operator != (const Int &lhs, const Int &rhs)
    { return lhs.Comp (rhs) != 0; }
#undef rg    
};
//=============================================================
#define int long long
#define max(a,b) a>b?a:b
const int MARX = 1e3+10;
struct person
{
    int a,b;
}s[MARX];
int n;
Int ans;
//=============================================================
inline bool cmp(person x,person y) {return x.a*x.b < y.a*y.b;}//自定义优先级,进行排序
Int mul(Int a,int b)
{
	Int ans=0;
	while(b)
	{
	  if(b & 1) ans+=a;
	  a+=a;
	  b>>=1;
	}
	return ans;
}
//=============================================================
signed main ()
{
	std::cin>>n; n=n+1;
    for(int i=1;i<=n;i++) std::cin>>s[i].a>>s[i].b;//输入各数据
    std::sort(s+2,s+n+1,cmp);//排序
    Int sum=s[1].a;
	for(int i=2; i<=n ; sum=mul(sum,s[i].a),i++) ans=max(ans,sum/s[i].b);//进行贪心 
	std::cout<<ans;
	return 0;
}
