//֪ʶ��: ����ѧ�Ƶ�, ����, ö��
/*
��������:
- ͨ�� �򵥷��� �� �۲����� , ���Է��� : 
  ��ȵ�����Ԫ�� ��Ϊ x_a,x_b,x_c,x_d ���ֵĴ�����ͬ

   ��n<=15000 , ���� ������Ͱֱ�� ��¼ ÿһ���� ֵ���ֵĴ���
   ���ʱ ֱ����� ĳ����Ԫ�ض�Ӧ��ֵ ��Ϊ x_a,x_b,x_c,x_d ���ֵĴ�������

- �� ��Ŀ���� �������� ����ת��:
    - x_a<x_b<x_c<x_d ��
      x_b-x_a=2(x_d-x_c) ��
      x_b-x_a<(x_c-x_b)/3 ��
	- ��  t = x_d-x_c
	   ���� ���� ���� , ����: x_b-x_a = 2* t ��
	  �� �� ���� ���� , ����: 2* t < (x_c-x_b)/3
	  ���� ת����: 6* t<x_c - x_b 
	  
   - ���� 6* t+k =x_c - x_b ��
	  ����Եõ�һ�������ϵĹ�ϵ

	- ͨ���۲���� , ���Եõ� ������ֵ�� ȡֵ��Χ
	   1<t , ��9* t<n
	   1<= x_a<n-9* t
	   9* t+1<x_d <= n
	-  ���Է���  ,  ���� ��֪ t �� x_a , 
	   ��ɵ� x_b = x_a+2t
		
	    ͬʱ���ɷ��� , ���� ��֪�� t �� x_a,    
	    ���� x >x_a+2t+6t ��λ�ö�������Ϊ �Ϸ��� x_c   
	    ��֪ x_c ��λ�ú� ���� ��� x_d = x_c+t  

  - ͬ�� , �� t �� x_d ��֪ , Ҳ���� ���������� ���´�
	

- ͨ������ ���� , ���ֿ���ͨ�� ö�� t,x_a�� x_d �������:   
	
	 - ö�� t ��ֵ , 1<t , ��9* t<n
		  - ö��x_a ��ֵ ,����� x_b ��ֵ 1<= x_a<n-9* t
			  - ö�ٺϷ��� x_c ,����� x_d
			     - ���ھͻ���� һ�� �Ϸ��� ����Ԫ�ص�ֵ
			     - �� x_a,x_b,x_c,x_d �������ֱ�Ϊ num[x_a],...,num[x_d]   
			       ���ݳ˷�ԭ�� ,  �� ������Ϻ� �����Ϸ����� ������Ϊ num[x_a]* num[x_b]* num[x_c]* num[x_d]
				- ��: ���� x_a , ����Ϊ A Ԫ�س��ֵĸ��� +=num[x_b]* num[x_c]* num[x_d]
						���� x_b , ����Ϊ B Ԫ�س��ֵĸ��� +=num[x_a]* num[x_c]* num[x_d]
						����ͬ��
			  - ��� ʹ�ó˷�ԭ�� , ���� ����
				  
		  - ö��x_d ��ֵ,����� x_c ��ֵ  9* t+1<x_d <= n
			  - ����ͬ��
---

- ����ʽ ���й۲�:

	���� x_d ����ʱ , x_a �ĺϷ���Χ ��߽粻�� , ֻ���ұ߽� ���ҵ���
	����� x_a ���ظ�ö�� , ���� ʱ�临�Ӷ� ����
	
	�Դ� �й��׵� ֻ�� x_a������  * x_b������
	���� ���Զ� (x_a������  * x_b������) ȡһǰ׺��   
	ÿ�� ֻ��Ҫ ö�� ������ �ұ߽� �ϵ� x_a������  * x_b������
	�� ����� ����ǰ׺�� ,  ����ǰ׺�� ���� ��       
  - ���� x_a:
	ͬ�� 
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
	for(int i=1; i<=m; i++) //�������� 
	{
	  x[i] = read();
	  num[x[i]] ++;
	}
	
	for(int t=1,sum=0; 9*t<n; t++,sum=0)//ö��t 
	{
	  for(int A = n-9*t-1; A; A--)//ö��A 
	  {
	  	int B = A+2*t , C = B+6*t+1 , D = C+t;//�������ֵ 
		sum += num[C]*num[D];
	  	ansa[A] += num[B]*sum;//���´� 
		ansb[B] += num[A]*sum;
	  }
	  sum = 0;
	  for(int D=9*t+2; D<=n; D++)//ö��D
	  {
	  	int A = D-9*t-1 , B = A+2*t , C = D-t;//�������ֵ 
	  	sum += num[A]*num[B];
	  	ansc[C] += sum*num[D];//���´� 
		ansd[D] += sum*num[C];
	  }
	}
	for(int i=1; i<=m; putchar('\n'),i++)
	  printf("%d %d %d %d",ansa[x[i]],ansb[x[i]],ansc[x[i]],ansd[x[i]]);
}
//O(n^3) 85��
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
//O(n^4) 40��
/*
#include<cstdio>
int n,m , x[40010],ans[40010][5];
signed main()
{
    scanf("%d%d",&n,&m);
    for(int i=1; i<=m; i++) scanf("%d",&x[i]);
    for(int a=1; a<=m; a++) //����ö��
      for(int b=1; b<=m; b++)
        for(int c=1; c<=m; c++)
          for(int d=1; d<=m; d++)
            if(x[a] < x[b] && x[b] < x[c] && x[c] < x[d])
              if(x[b] - x[a] == 2*x[d] - 2*x[c])
                if(3*x[b] - 3*x[a] < x[c]-x[b])//�����ж�, ���´�
                  ans[a][1]++, ans[b][2]++, ans[c][3]++, ans[d][4]++;
    
    for(int i=1; i<=m; putchar('\n'),i++)//���
      for(int j=1; j<=4; j++)
        printf("%d ",ans[i][j]);
}
*/ 
