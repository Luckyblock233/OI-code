/*THE QUICK BROWN FOX JUMPED OVER THE LAZY DOG.
THIS IS AN EXAMPLE TO TEST FOR YOUR
HISTOGRAM PROGRAM.
HELLO!
https://ps.ssl.qhimg.com/sdmt/130_132_100/t01b469ce7e89c026b3.webp

                            *
                            *
        *                   *
        *                   *     *   *
        *                   *     *   *
*       *     *             *     *   *
*       *     * *     * *   *     * * *
*       *   * * *     * *   * *   * * * *
*     * * * * * *     * * * * *   * * * *     * *
* * * * * * * * * * * * * * * * * * * * * * * * * *
A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
*/
#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
int a[26];
string b[4];
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int max=0;
	for(int i=0;i<=3;i++)
	  {
	  	getline(cin,b[i]);
	  	for(int j=0;j<b[i].length();j++)
	  	  {
	  	  	a[b[i][j]-'A']++;
	  	  	if(a[b[i][j]-'A']>max)
	  	  	  max=a[b[i][j]-'A'];
		  }
	  }
	int k=max;
	for(int i=1;i<=max;i++)
	  {
	  	if(a[0]==k)
	  	  {
			printf("*");
			a[0]--;
		  }
	  	else
	  	  printf(" ");
	  	for(int j=1;j<=25;j++)
	  	  {
	  	  	if(a[j]==k)
	  	  	  {
				printf(" *");
				a[j]--;
			  }
	  	  	else
	  	  	  {
	  	  	  	bool ju=1;
				for(int l=j+1;l<=25;l++)
				  if(a[l]==k)
				    ju=0;
				if(ju==0)
	  	  	      printf("  ");
	  	  	    else
	  	  	      break;
		      }
		  }
		k--;
		printf("\n");
	  }
	printf("A");
	for(int i=1;i<26;i++)
	  printf(" %c",i+'A');
	fclose(stdin);
	fclose(stdout);
}
