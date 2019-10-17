//知识点:模拟 
/*
By:Luckyblock
容易发现一个简单的性质:
1.当暗文ci <= 密钥ki 时:   明文mi = ci - ki;
2.当暗文ci >  密钥ki 时:   明文mi = ci + 26 - ki
有了上述性质 , 就可以在明文暗文之间 简单地相互转换

注意处理密钥与暗文之间的大小写关系: 
要使密钥的大小写 与 暗文的大小写相同; 
*/
#include<cstdio>
#include<cstring>
const int MARX = 1010;
//=============================================================
int lthk,lthc;//分存 密钥,暗文长度 
char k[MARX]="@",c[MARX]="@";//密钥 , 暗文 
//=============================================================
signed main()
{
	scanf("%s",k+1); scanf("%s",c+1);
	lthk=strlen(k)-1,lthc=strlen(c)-1;
	
	for(int i=1,j=1; i<=lthc; i++,j=(j==lthk?1:j+1))//枚举明文与密钥 
	{
	  char key = k[j] - 32*(k[j]>='a') + 32*(c[i]>='a');//密钥大小写转换 
	  printf("%c", c[i] + 26*(c[i]<key)-key + (c[i]>='a'?'a':'A'));//输出明文 
	}
}
