#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,m;
    cin>>n>>m;
    int graph[n+1][n+1];
    fill_n(&graph[0][0],(n+1)*(n+1),-1);
    while(m--){
     int s,e,r;
     cin>>s>>e>>r;
     graph[s][e] = r;
    }
   for(int k=1;k<=n;k++)
      for(int i = 1;i<=n;i++)
        for(int j = 1;j<=n;j++){
            if(i==j) graph[i][j] =0;
            else if(k == i|| k==j ||graph[i][k]==-1 || graph[k][j] == -1) continue;
            else if(graph[i][j]==-1||graph[i][j]>graph[i][k]+graph[k][j]) graph[i][j] = graph[i][k]+graph[k][j];
    }
    int q;
    cin>>q;
    while(q--){
      int s,e;
      cin>>s>>e;
      cout<<graph[s][e]<<endl;
    }
    return 0;
}
