#include<bits/stdc++.h>
using namespace std;
int x1,y11,x2,y2,ans=0;
int y[105][3];
int n;
double dis(int x1,int y12,int x2,int y2)
{
  return sqrt((x1-x2)*(x1-x2)+(y12-y2)*(y12-y2));
}
int main()
{
    cin>>n;
    for(int i=0;i<3;i++)
      for(int j=0;j<n;j++)
        cin>>y[j][i];
    cin>>x1>>y11>>x2>>y2;
    for(int i=0;i<n;i++)
      if(dis(x1,y11,y[i][0],y[i][1])<y[i][2]!=dis(x2,y2,y[i][0],y[i][1])<y[i][2])
	    ans++;
    cout<<ans;
}
