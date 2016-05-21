#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include<unordered_set>
using namespace std;

class cmp{
 public:
    bool operator()(pair<int,int> a, pair<int,int> b){
        return a.second>b.second;
    }
}mycmp;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    //freopen("input.txt","r+",stdin);
    int t;
    cin>>t;
    for(int i = 0;i<t;i++){
        int n,m,s,e,r,start;
        cin>>n>>m;
        vector<vector<pair<int,int> > > graph(n+1);
        while(m--){
          cin>>s>>e>>r;
          graph[s].push_back({e,r});
          graph[e].push_back({s,r});
        }
        cin>>start;
        vector<int> res(n+1,-1);
        map<int,unordered_set<int>> cur;
        cur[0].insert(start);
        res[start] = 0;
        while(cur.size()){
            int dist = cur.begin()->first;
            int node = *cur[dist].begin();
            cur[dist].erase(node);
            if(cur[dist].size()==0) cur.erase(dist);
            for(auto p:graph[node]){
              int newdis = dist + p.second;
              if(res[p.first] == -1 || res[p.first]>newdis){
                 if(res[p.first]>newdis){
                     cur[res[p.first]].erase(p.first);
                     if(cur[res[p.first]].size()==0) cur.erase(res[p.first]);
                 }
                 res[p.first] = newdis;
                 cur[newdis].insert(p.first);
              }
            }
       }
       for(int j=1;j<=n;j++){
           if(res[j]==0) continue;
           cout<<res[j]<<(j==n?"\n":" ");
       }
    }
    return 0;
}
