#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define f1(i,n) for (int i=1; i<=n; i++)

int n, m;
vector<int> a[12309];
bool Invalid = false;
bool Visited[12309];
int Color[12309];

void visit(int u){
   Visited[u]=true;
   for (int i=0,v; v=a[u][i]; i++){
      if (!Visited[v]){
         Color[v]=3-Color[u];
         visit(v);
      }
      else {
         if (Color[v] == Color[u])
         Invalid = true;
      }
   }
}

main(){
   cin >> n >> m;
   f1(i,m) {
      int p, q;
      cin >> p >> q;
      a[p].push_back(q);
      a[q].push_back(p);
   }
   f1(i,n) a[i].push_back(0);

   f1(i,n){
      if (!Visited[i]){
         Color[i]=1;
         visit(i);
      }
   }

   if (Invalid) cout << "Invalid" << endl;
   else {
      f1(i,n) cout << Color[i] << " "; cout << endl;
   }
}
