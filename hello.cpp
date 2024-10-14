#include<iostream>
#include<vector>
using namespace std;
int main()
 {
	//int x;
     for(int i=0;i<5;i++)
	 {
		
	    int  x=1;
		
		cout<<x<<endl;
	 }
	 cout<<x<<endl;

// 	int T;
// 	cin>>T;
// 	while(T--)
// 	{
// 		int n,m;
// 		cin>>n>>m;
// 		vector<int> parent(n+1,0);
// 		vector<int> depth(n+1,0);
// 		for(int i=1;i<=n;i++)
// 		{
// 			int x,y;
// 			cin>>x>>y;
// 			if(x!=-1)
// 			{
// 				depth[x]=depth[i]+1;
// 				parent[x]=i;
// 			}
// 			if(y!=-1)
// 			{
// 				depth[y]=depth[i]+1;
// 				parent[y]=i;
// 			}
// 		}
// 		while(m--)
// 		{
// 			int x,y;
// 			int len=0;
// 			cin>>x>>y;
// 		    int ma=depth[x]>=depth[y]?x:y;
// 			int mi=depth[x]>=depth[y]?y:x;
// 			while(depth[ma]>depth[mi])
// 			{
// 				ma=parent[ma];
// 				len++;
// 			}
// 			while(ma!=mi)
// 			{
// 				ma=parent[ma];
// 				mi=parent[mi];
// 				len+=2;
// 			}
// 			cout<<len<<endl;
// 		}
// 	}
}