#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include<unordered_set>
using namespace std;


int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    //freopen("input.txt","r+",stdin);
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> graph(n+1);
    while(m--){
     int s,e,r;
     cin>>s>>e>>r;
     graph[s].push_back({e,r});
     graph[e].push_back({s,r});
    }
    int start;
    cin>>start;
    map<int,unordered_set<int>> cur;
    unordered_set<int> chosen;
    cur[0].insert(start);
    int dis[n+1];
    fill_n(dis,n+1,-1);
    int res=0;
    dis[start] = 0;
    while(cur.size()){
      int dist = cur.begin()->first;
      int node = *cur[dist].begin();
      chosen.insert(node);
      res+=dist;
      cur[dist].erase(node);
      if(cur[dist].size()==0) cur.erase(dist);
      for(auto p:graph[node]){
          int e = p.first,r= p.second;
          if(chosen.count(e)) continue;
          if(dis[e] == -1 || dis[e]>r){
              if(dis[e]>r) {
                  cur[dis[e]].erase(e);
                  if(cur[dis[e]].size()==0) cur.erase(dis[e]);
              }
              dis[e] = r;
              cur[r].insert(e);
          }
      }
    }
    cout<<res<<endl;
    return 0;
}
