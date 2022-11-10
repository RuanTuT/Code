#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include<queue>
#include<set>
#include<unordered_set>
#include <numeric>
#include <sstream>
#include<unordered_map>
#include<stack>
using namespace std;

  
 
    bool dfs(string& expression,int left,int right,unordered_map<int,int>& hash)
    {
        int t=0,f=0;
         for(int i=left+2;i<right;i++)
         {
             if(expression[i]=='t')
             t++;
             else if(expression[i]=='f')
             f++;
             else if(expression[i]=='&'||expression[i]=='|'||expression[i]=='!')
             {
                bool res=dfs(expression,i,hash[i+1],hash);
                if(res)
                t++;
                else
                f++;
                i=hash[i+1];
             }
             else
             continue;
         }
         if(expression[0]=='!')
         return t==1?false:true;
         else if(expression[0]=='&')
         return f==0?true:false;
         else 
         return t==0?false:true;
    }
    int main()
    {
      unordered_map<int,int>hash;//记录左括号对应的右括号的位置
      stack<int> stk;
      string expression="|(&(t,f,t),!(t))";
        if(expression.size()==1)
        return expression=="t"?true:false;
      
     for(int i=0;i<expression.size();i++)
     {
         if(expression[i]=='(')
         stk.push(i);
         else if(expression[i]==')')
         {
             hash[stk.top()]=i;
             stk.pop();
         }
     }
    bool res= dfs(expression,0,expression.size()-1,hash);
     cout<<res<<endl;
    }