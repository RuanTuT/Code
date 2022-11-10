#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include<unordered_map>
#include<queue>
using namespace std;
void swap(pair<int,string>&x ,pair<int,string>&y)
    {
        pair<int,string>tmp;
        tmp=x;
        x=y;
        //y=x;
        y=tmp;
    }
    void quicksort(vector<pair<int,string>>&values,vector<string>&ans,int k,int start,int end)
    {
        

        if(start==end)
        {
            ans.emplace_back(values[start].second);
            return;
        }
        int x=rand()%(end-start+1)+start;
        int pivot=values[x].first;
        string str=values[x].second;
        swap(values[x],values[start]);
        int l=start,r=end+1,it=start+1;
        while(it<r)
        {
            if(values[it].first<pivot)
            {
                swap(values[it++],values[++l]);
            }
            else if(values[it].first>pivot)
            {
                swap(values[it],values[--r]);
            }
            else 
            {
                if(values[it].second>str)
                swap(values[it++],values[++l]);
                else if(values[it].second<str)
                swap(values[it],values[--r]);

            }
        }
        swap(values[start],values[l]);
        
        if(end-l<=k)
        {
            sort(values.begin()+l-start+1,values.begin()+end-start+1,[](const auto& x,const auto& y){//少了一个start
                if(x.first!=y.first)return x.first>y.first;
                 return x.second<y.second;
            });
            for(int i=l+1;i<=end;i++)
                {
                    ans.emplace_back(values[i].second);
                }
                if(end-l<k)
                quicksort(values,ans,k-end+l,start,l);
        }
        else
        {
            //if(r!=end+1)
           quicksort(values,ans,k,l+1,end);
          /*  else
           {
               for(int i=0;i<k;i++)
               ans.emplace_back(values[x].second);
           } */
        }
        

    }
   int main()
   {
    vector<string>words={"i","love","leetcode","i","love","coding"};
    int k=2;
     unordered_map<string,int>occurrences;
       for(const auto& word:words)
       occurrences[word]++;
       vector<pair<int,string>>values;
       for(const auto& [word,count]:occurrences)
       {
           values.emplace_back(count,word);
       }
      // srand(time(0));
      nth_element(values.begin(),values.begin()+k,values.end(),[](const auto& x,const auto& y){
        if(x.first==y.first)return x.second<y.second;
        return x.first>y.first;
      });
     sort(values.begin(),values.begin()+k,[](const auto& x,const auto& y){
        if(x.first==y.first)return x.second<y.second;
        return x.first>y.first;
      });
       vector<string>ans;
       //quicksort(values,ans,k,0,values.size()-1);
       for(int i=0;i<k;i++)
   {
    ans.emplace_back(values[i].second);
   }
       for(const auto& node:ans)
       cout<<node<<endl;
       cout<<endl;
    
   }