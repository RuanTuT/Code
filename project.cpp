#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include<unordered_set>
#include<queue>
using namespace std;
 const int mod=1000000007;
    int dfs(vector<vector<int>>&graph,int u,int v)
    {
        if(u==v)
        return 1;
        int n=graph.size();
        vector<int>visited(n,0);
        visited[u]=1;
        int count=0;
        for(const auto& node:graph[u])
        {
           if(!visited[node])
           {
               count+=dfs(graph,node,v);
            if (count>= mod) {
              count-= mod;
                }
           }
            
                
        }
        visited[u]=0;
        return count;
    }
    int  main() 
    {      int n=12;
        vector<vector<int>>roads=[[1,0,2348],[2,1,2852],[2,0,5200],[3,1,12480],[2,3,9628],[4,3,7367],[4,0,22195],[5,4,5668],[1,5,25515],[0,5,27863],[6,5,836],[6,0,28699],[2,6,23499],[6,3,13871],[1,6,26351],[5,7,6229],[2,7,28892],[1,7,31744],[3,7,19264],[6,7,5393],[2,8,31998],[8,7,3106],[3,8,22370],[8,4,15003],[8,6,8499],[8,5,9335],[8,9,5258],[9,2,37256],[3,9,27628],[7,9,8364],[1,9,40108],[9,5,14593],[2,10,45922],[5,10,23259],[9,10,8666],[10,0,51122],[10,3,36294],[10,4,28927],[11,4,25190],[11,9,4929],[11,8,10187],[11,6,18686],[2,11,42185],[11,3,32557],[1,11,45037]];
          vector<vector<long long>>dist(n,vector<long long>(n,LLONG_MAX/2));
          for(const auto& road:roads)
          {
              dist[road[0]][road[1]]=road[2];
              dist[road[1]][road[0]]=road[2];
          }
          vector<int>visited(n,0);
          visited[0]=0;
          dist[0][0]=0;
          for(int i=0;i<n-1;i++)//round
          {
              //find min_dist
              int Min=INT_MAX;
                  int index=-1;
              for(int j=1;j<n;j++)
              {
                  
                  if(!visited[j]&&(index==-1||dist[0][index]>dist[0][j]))
                  {
                      index=j;
                  } 
              }
             /*  if(index==-1)//cannot find
              break; */
              visited[index]=1;
              //upgrade dist
              for(int j=1;j<n-1;j++)
              {
                  if(!visited[j])
                  dist[0][j]= min(dist[0][j],dist[0][index]+dist[index][j]);
              }
          }
          //build graph
          vector<vector<int>>graph(n);
          for(const auto& road:roads)
          {
              auto u=road[0];
              auto v=road[1];
              auto w=road[2];
              if(dist[0][u]-dist[0][v]==w)
              {
                   graph[v].emplace_back(u);

              }
              else if(dist[0][v]-dist[0][u]==w)
              graph[u].emplace_back(v);
          }
          cout<<dfs(graph,0,n-1)<<endl;
    }
