#include <iostream>
#include<string>// ！！！！ stoi
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		for(int i=31;i>=0;i--)
		{
			if(str[i]=='1')//不是数字1，而是字符‘1’  ！！！！
			{
				str[i]='0';
			}
			else
			{
				str[i]='1';
				break;
			}
		}
		cout<<str<<endl;
		for(int i=30;i>=0;i--)
		{
			if(str[i]=='1')
			{
				str[i]='0';
			}
			else
			{
				str[i]='1';
				break;
			}
		}
		cout<<str<<endl;
	}
}








// #include<iostream>
// #include<vector>
// #define INF 0x3fffffff//不是#define INF=0x3fffffff  要注意！！！！！！
// //const int INF=0x3fffffff;
// using namespace std;
// vector<vector<int>> G;
// int T,n,m,k;
// int floyd(){
// 	for(int k=1;k<=n;k++)//是1-n，不是从0-n-1   ！！！！！！！
// 	{
// 		for(int i=1;i<=n;i++)
// 		{
// 			for(int j=1;j<=n;j++)
// 			{
// 				if(G[i][k]!=INF&&G[k][j]!=INF&&G[i][k]+G[k][j]<G[i][j])
// 					G[i][j]=G[i][k]+G[k][j];
// 			}
// 		}
// 	}
// 	return G[1][n];
// }
// typedef struct edge{
// 	int a;
// 	int b;
// 	int cost;
// 	edge(int from,int to ,int val):a(from),b(to),cost(val){}
// }edge;			
// int main()
// {
// 	cin>>T;
// 	while(T--)
// 	{
// 		vector<edge> edges;//放在这里，每次循环清空！！！！！！
// 		G=vector<vector<int>>(100,vector<int>(100,INF));//每次循环记得清空数据
// 		int x,y,z;
// 		cin>>n>>m>>k;
// 		vector<int> close(m,0);
// 		while(m--)
// 		{
// 			cin>>x>>y>>z;
// 			edge e(x,y,z);
// 			edges.emplace_back(e);
// 			if(G[x][y]>z)
// 				G[x][y]=G[y][x]=z;
// 				//G[x][y]=z;领接矩阵一定要注意：一条边对应矩阵两个值
// 		}
// 		cout<<floyd()<<endl;
// 		G=vector<vector<int>>(100,vector<int>(100,INF));
// 		while(k--)
// 		{
// 			int t;
// 			cin>>t;
// 			//edges.erase(edges.begin()+close-1);
// 			close[t-1]=1;
// 		}
// 		for(int i=0;i<edges.size();i++)
// 		{
// 			if(close[i]==0&&edges[i].cost<G[edges[i].a][edges[i].b])
// 				//G[edges[i].a][edges[i].b]=edges[i].cost;
// 				G[edges[i].a][edges[i].b]=G[edges[i].b][edges[i].a]=edges[i].cost;
// 		}
// 		cout<<floyd()<<endl;
// 	}
// }



// typedef struct treenode{
//     char val;
//     struct treenode *left;
//     struct treenode *right;    
//     treenode(char c):val(c),left(NULL),right(NULL){}
// } TreeNode;
// TreeNode *create(string s,int &m)//先序遍历,则先序建树
// {
//     if(m>=s.length()||s[m++]=='#')
//     return nullptr;
//     TreeNode *node =new TreeNode(s[m-1]);
//     node->left=create(s,m);
//     node->right=create(s,m);
//     return node;
// }
// void inorder(TreeNode *root)
// {
//    if(!root)
//    return ;
//    if(root->left)
//    inorder(root->left);
//    cout<<root->val<<" ";
//    if(root->right)
//    inorder(root->right);
// }


// int isCom[MAX]= {0}; //合数标记,为1代表是合数
// vector<int>prime;//记录素数集合
// vector<int>nums;//不是nums=(10000,0)
// /*分解质【 因数，找发财数*/
// int cal(int n,int &count)
// {   
// 	if(n<=count)
// 		return nums[n-1];
// 	int i=count>0?nums[count-1]+1:2;
//     for(; i<MAX; i++)
//     {
//         if(isCom[i]==1)//合数
//         {
//             int pcount=0;//素因子个数
//             int j=0;
//             int tmp=i;
//             int bound=sqrt(i);//sqrt函数相当耗时，放在while里会超时
//             while(j<prime.size()&&prime[j]<=bound)
//             {
//                 if(tmp%prime[j]==0)
//                 {
//                     tmp/=prime[j];
//                     pcount++;//i增加一个素因子
//                     if(pcount==8)
//                     {
// 						nums.emplace_back(i);
//                         if(++count==n)
//                             return i;
// 						break;//找到发财数，退出循环
//                     }
//                 }
//                 else
//                     j++;
//             }
//             //最后剩下的是素数且是发财数
//             if(tmp!=1&&++pcount==8)//while循环结束，但是pcount没有为8时的情况
//             {
// 				nums.emplace_back(i);
//                 if(++count==n)
//                     return i;//return 发财数
//             }
//         }
//     }
//     return -1;
// }
// /*欧拉线性筛法*/
// void find_prime()
// {
//    for(int i=2;i<MAX;i++)
//    {
//       if(isCom[i]==0)
//       prime.emplace_back(i);
//       for(int j=0;j<prime.size()&&i*prime[j]<=MAX;j++)
//       {
//         isCom[i*prime[j]]==1;
//         if(i%prime[j]==0)
//         break;
//       }
//    }    
// }
// int main()
// {
//     find_prime();
//     int t;
// 	int count=0;
//     cin>>t;
//     while(t--)
//     {
//         int n;
//         cin>>n;
//         //找第n个发财数
//         cout<<cal(n,count)<<endl;
//     }
// }

// #include <iostream>
// using namespace std;
// typedef struct treenode{
// 	struct treenode *left;
// 	struct treenode *right;
// 	char val;
// }Node,* TreeNode;
// TreeNode create(string str1,int x,int y,string str2,int m,int n)
// {
// 	TreeNode node =new Node;
// 			node->left=NULL;
// 			node->right=NULL;
// 	 node->val=str1[x];
// 	for(int i=m;i<=n;i++)
// 	{
// 		if(str2[i]==str1[x])
// 		{
// 			//node->val=str1[x];
// 			if(x+1<=x+i-m&&m<=i-1)
// 			node->left=create(str1,x+1,x+i-m,str2,m,i-1);
// 			if(x+i-m+1<=y&&i+1<=n)
// 			node->right=create(str1,x+i-m+1,y,str2,i+1,n);
// 		}
// 	}
// 	return node;	
// }
// void postorder(TreeNode root)
// {
// 	if(!root)
// 		return ;
// 	if(root->left)
// 		postorder(root->left);
// 	if(root->right)
// 		postorder(root->right);
// 	cout<<root->val;	
// }
// int main()
// {
// 	string str1,str2;
// 	TreeNode root=new Node;
//     root->left=NULL;
// 	root->right=NULL;
//     cin>>str1>>str2;
// 	root=create(str1,0,str1.length()-1,str2,0,str2.length()-1);
// 	postorder(root);
// 	cout<<endl;
// }
	
