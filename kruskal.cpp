#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_set>

using namespace std;

int find(int x,vector<int> &pre){
    if(x!=pre[x])
      pre[x] = find(pre[x],pre);
    return pre[x];
}
void connect(int x,int y, vector<int> &pre){
    int xp = find(x,pre);
    int yp = find(y,pre);
    pre[yp] = xp;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    //freopen("input.txt","r+",stdin);
    int n,m;
    cin>>n>>m;
    multimap<int,pair<int,int>> edges;
    vector<int> pre(n+1);
    iota(pre.begin(),pre.end(),0);
    while(m--){
      int s,e,r;
      cin>>s>>e>>r;
      edges.insert({r,{s,e}});
    }
    int res = 0;
    for(auto it = edges.begin();it!=edges.end();it++){
        int s = it->second.first;
        int e = it->second.second;
        int r = it->first;
        if(find(s,pre)!=find(e,pre)){
            connect(s,e,pre);
            res+=r;
        }
    }
    cout<<res<<endl;
    return 0;
}
