//知识点:区间DP,高精度 
/*
By:Luckyblock
感谢zlycerqan的强大高精 
 
可以发现,两行之间没有影响, 每一行相对独立
 
由于只能从 区间的首或尾 取数
则 一个区间状态[l,r], 可以由[l-1,r] 或者 [l,r+1]转移而来
并且 取走 k个数之后, 剩下的m-k个数 一定是相邻的 

则: 设f[i][l][r] 为第i行, 还剩下 [l,r]未被取走 能达到的最大价值和
由上, f[i][l][r] 可由状态f[i][l-1][r] 与 f[i][l][r+1]转移而来

状态转移方程式: f[i][l][r] = max(f[i][l-1][r] + map[i][l-1]*mul[m-j],f[i][l][r+1] + map[i][r+1]*mul[m-j]); (mul[k] 为2^k)
最后 枚举每一个长度为1的 区间,
取 最大的价值和 + 取最后一个数的价值, 作为此行的价值和 
*/
#include <cstdio>
#include <iostream>
#include <vector>
#include <iomanip>
#include <cassert>
#include <algorithm>
#include <cstring>
typedef long long LL; 
using namespace std;
const int MARX = 85;
const int Big_B = 10; const int Big_L = 1;
inline int intcmp_ (int a, int b) { if (a > b) return 1; return a < b ? -1 : 0; }
struct Int 
{
#define rg register
    inline int max (int a, int b) { return a > b ? a : b; }
    inline int min (int a, int b) { return a < b ? a : b; }
    std :: vector <int> c; Int () {} 
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
LL n,m , map[MARX][MARX];
Int mul[MARX]={1};
Int ans,f[MARX][MARX][MARX];//d[i][l][r] : 第i行,剩下 l~r 的最大价值 
//=============================================================
inline LL read()
{
    LL s=1, w=0; char ch=getchar();
    for(; !isdigit(ch);ch=getchar()) if(ch=='-') s =-1;
    for(; isdigit(ch);ch=getchar()) w = w*10+ch-'0';
    return s*w;
}
//=============================================================
signed main()
{
	n = read(), m = read();
	for(int i=1; i<=n; i++)
	  for(int j=1; j<=m; j++)
	    map[i][j] = read();
	
	for(int i=1; i<MARX; i++) mul[i] = mul[i-1]*2;//预处理 2^i 
	for(int i=1; i<=n; i++)
	{
	  f[i][1][m] = 0;//初始状态 
	  for(int j = m-1; j>=1; j--)//枚举区间 并进行转移 
	    for(int l=1,r=l+j-1; r<=m; l++,r++)
	      f[i][l][r] = max(f[i][l-1][r] + map[i][l-1]*mul[m-j],f[i][l][r+1] + map[i][r+1]*mul[m-j]);
	  Int sum = 0;
	  for(int j=1; j<=m; j++) sum = max(sum,f[i][j][j] + map[i][j]*mul[m]);//枚举最后一个被 选的位置 
	  ans += sum;
	}
	cout << ans;
}
