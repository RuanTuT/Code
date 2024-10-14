#include<iostream>
#define MAX 350001//最小遍历到35w，就能找到第1w多个发财数
using namespace std;
int isCom[MAX]= {0}; //合数标记,为1代表是合数
vector<int>prime;//记录素数集合
vector<int> nums(10000,0);//不是nums=(10000,0)
int count=0;//发财数个数
/*分解质因数，找发财数*/
int cal(int n)
{
	if(n<=count)
		return nums[n-1];
    int i=2;
	if(n>count&&count!=0)
	   i=nums[count-1]+1;
    for(; i<MAX; i++)
    {
        if(isCom[i]==1)//合数
        {
            int pcount=0;//素因子个数
            int j=0;
            int tmp=i;
            int bound=sqrt(i);//sqrt函数相当耗时，放在while里会超时
            while(j<prime.size()&&prime[j]<bound)
            {
                if(tmp%prime[j]==0)
                {
                    tmp/=prime[j];
                    pcount++;//i增加一个素因子
                    if(pcount==8)
                    {
						nums[count]=i;
                        if(++count==n)
                            return i;
                    }
                }
                else
                    j++;
            }
            //最后剩下的是素数且是发财数
            if(tmp!=1&&++pcount==8)
            {
				nums[count]=i;
                if(++count==n)
                    return i;
            }
        }
    }
    return -1;
}
/*欧拉线性筛法*/
void find_prime()
{
    for(int i=2; i<MAX; i++)
    {
        //是素数，加入素数集合
        if(isCom[i]==0)
            prime.push_back(i);
        //把"i*最小素数"标记为合数
        for(int j=0; i*prime[j]<MAX&&j<prime.size(); j++)
        {
            isCom[i*prime[j]]=1;
            //找到最小素因子退出
            if(i%prime[j]==0)
                break;
        }
    }
}
int main()
{

    find_prime();
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        //找第n个发财数
        cout<<cal(n)<<endl;
    }
}








// #include <iostream>
// #include <map>
// using namespace std;
// int find(char x,char y,map<char,char>& M)
// {
//     int ans=0;
//     while(x!='#')
//     {
//         if(x==y)
//         return ans;
//         else
//         {
//              x=M[x];
//              ans++;
//         }    
//     }
//     return 0;
// }
// int main() {
//     int n,m;
//     while(cin>>n>>m)
//     {
//         map<char,char> M;
//         while(n--)
//         {
//             string str;
//             cin>>str;
//             M[str[1]]=str[0];
//             M[str[2]]=str[0];
//         }
//         while(m--)
//         {
//             string s;
//             cin>>s;
//             char x=s[0];
//             char y=s[1];
//             int height1=find(x,y,M);
//             int height2=find(y,x,M);
//             if(!height1&&!height2)//不应该先判断两个
//              cout<<'-'<<endl;
//             if(height1)
//             {
//                 if(height1==1)
//                 cout<<"parent"<<endl;
//                 else if(height1>=2)
//                   for(int i=0;i<height1-2;i++)
//                    cout<<"great-";
//                   cout<<"grandparent"<<endl;
//             }
//              if(height2)
//             {
//                 if(height2==1)
//                 cout<<"child"<<endl;
//                 else if(height2>=2)
//                   for(int i=0;i<height2-2;i++)
//                    cout<<"great-";
//                   cout<<"grandchild"<<endl;
//             }
//         }
//     }
// }


// #include <iostream>
// #include <vector>
// using namespace std;
// const int N=100;
// struct plur{
//     int a;
//     int b;
//     plur(int x,int y):a(x),b(y){}
// };
// void Pop(vector<plur> &Plurs)
// {
//     int max=0;
//     int tmp=0;
//     for(auto i=0;i<Plurs.size();i++)
//     {
//         if(Plurs[i].a*Plurs[i].a+Plurs[i].b*Plurs[i].b>max||Plurs[i].a*Plurs[i].a+Plurs[i].b*Plurs[i].b==max&&Plurs[i].b<Plurs[tmp].b)
//           {
//             tmp=i;
//             max=Plurs[i].a*Plurs[i].a+Plurs[i].b*Plurs[i].b;
//           }
//     }
//     cout<<Plurs[tmp].a<<'+'<<'i'<<Plurs[tmp].b<<endl;
//     Plurs.erase(Plurs.begin()+tmp);
//     cout<<"SIZE = "<<Plurs.size()<<endl;
// }
// int main() {
//     int n;
//     char command[N];
//     vector<plur> Plurs;
//     while(scanf("%d",&n)!=EOF)
//     {
//         //getchar();
//         while(n--)
//         {
//           scanf("%[^\n]",command);
//           getchar();
//           if(command[0]=='P')
//           {
//             if(Plurs.empty())
//               cout<<"empty"<<endl;
//             else
//              {
//                Pop(Plurs);
//              }
//           }
//           else {
//           scanf("%[^\n]",command);
//           int x=command[7]-'0';//这里错误,因为数字可能是多位的
//           int y=command[10]-'0';//错误,理由同上
//           plur p=plur(x,y);
//           Plurs.emplace_back(p);
//           cout<<"SIZE = "<<Plurs.size()<<endl;
//           }
//         }
//     }
// }



// #include <iostream>
// include<string>
// #include<cstdlib>
// #include<cstring>//strlen
// using namespace std;
// const int N=100;
// //只需记录‘0’到‘9’出现的次数即可,不用判断连续,因为题目中给出了连续的条件
// int main() {
//     char a[N], b[6];
//     while (scanf("%s%s", &a, &b) != EOF) {
//         int count[10] = {0};
//         int len_a = strlen(a);
//         int len_b = strlen(b);
//         bool flag = false;
//         for (int i = 0; i < len_a; i++) {
//             count[a[i] - '0']++;
//         }
//         int index = b[0] - '0' + 1; //必须加一,牌a的数字应该比牌b的大
//         if (len_b < 5) {
//             for (int i = index; i < 10; i++) { //index控制所抽的牌比b的大
//                 if (count[i] >=
//                         len_b) { //大于等于很重要,而不光是等于,大于也可以取子集
//                     flag = true;
//                     break;
//                 }
//             }
//         }
//         else {
//             for (int i = index; i < 6; i++) {
//                 if (count[i] > 0 && count[i + 1] > 0 &&
//                         count[i + 2] > 0 && count[i + 3] > 0 && count[i + 4] > 0) {
//                     flag = true;
//                     break;
//                 }
//             }
//         }
//         if (flag)
//             printf("YES");
//         else
//             printf("NO");
//     }
// }

// struct Matrix{
//     int row;
//     int col;
//     int matrix[MAXN][MAXN];
//     Matrix(int x,int y):row(x),col(y){}
// };
// Matrix Mul(Matrix x , Matrix y){      //矩阵乘法
//     Matrix ans = Matrix(x.row,y.col);
//     for(int i = 0; i < ans.row; ++i){
//         for(int j = 0; j < ans.col; ++j){
//             ans.matrix[i][j] = 0;
//             for(int k = 0; k < x.col; ++k){
//                 ans.matrix[i][j] += x.matrix[i][k] * y.matrix[k][j];
//             }
//         }
//     }
//     return ans;
// }
// int main()
// {
//     vector<vector<int>> c(3,vector<int>(3,7));
//     cout<<c.at(1).at(2);
// }

// vector<vector<int>> multiply(vector<vector<int>>a ,vector<vector<int>>b,int n)
// {
//       //int n=sizeof(a)/sizeof(a[0]);
//       vector<vector<int>> c(n,vector<int>(n,0));
//       for(int i=0;i<n;i++)
//          for(int j=0;j<n;j++)
//             for(int k=0;k<n;k++)
//               c[i][j]+=a[i][k]*b[k][j];
//     return c;
// }
// vector<vector<int>> pow(vector<vector<int>>a ,int k,int n)//使用快速幂
// {
//     vector<vector<int>>ans(n,vector<int>(n,0));
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<n;j++)
//         {
//             if(i==j)
//             ans[i][j]=1;
//             else
//              ans[i][j]=0;
//         }
//     }
//     while(k)//快速幂算法
//     {
//         if(k&1)
//         ans=multiply(ans,a,n);
//         a=multiply(a,a,n);
//         k>>=1;
//     }
//     return ans;  
// }
// vector<vector<int>> pow(vector<vector<int>>a ,int k,int n)//暴力幂,未使用快速幂
// {
//      vector<vector<int>> b=a;   
//      while(k>1)
//      {
//         b=multiply(a,b,n);
//         k--;
//      }
//      return b;
// }
// int main() {
//     int n,k;   
//     while(cin>>n>>k)
//     {
//        vector<vector<int>> m(n,vector<int>(n,0));
//        for(int i=0;i<n;i++)
//           for(int j=0;j<n;j++)
//             cin>>m[i][j];
//         m=pow(m,k,n);
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<n;j++)
//             {
//                 cout<<m[i][j];
//                 if(j<n-1)
//                 cout<<" ";
//             }
//             cout<<endl;
//         }
//     }
// }

// void dtob(unsigned int num)
// {
//     int data[50],len=0;
//     while(num)
//     {
//         data[len++]=num%2;
//         num/=2;
//     }
//     for(int i=len-1;i>=0;i--)//len-1,不要忘了减去1 !!!!
//     {
//         cout<<data[i];
//     }
//     cout<<endl;
// }
// int main()
// {  
//     unsigned int  num;
//     while(cin>>num)
//     {
//      dtob(num);
//     }
// }

// int main() {//二进制数问题
//     unsigned int num;
//     while (cin >> num) {
//         const int bits = 8 * sizeof(unsigned int); //8*4byte
//         bitset<bits> bs(num);
//         bool flag = false;
//         string result;
//         for (int i = bits - 1; i >= 0; i--) {//从bs最后一位往前遍历太费时间了!!!
//             if (bs[i])
//                 flag = true;
//             if (flag)
//                 result += bs[i] ? "1" : "0";
//         }
//         cout << result << endl;
//     }
// }
