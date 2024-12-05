#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n = 4;
int VISITED_ALL = (1<<n)-1;
int dist[10][10] = {
            {0,20,42,25},
            {20,0,30,34},
            {42,30,0,10},
            {25,34,10,0}};

int tsp(int mask, int pos){
    if(mask == VISITED_ALL){
        return dist[pos][0];  // back to start - hamiltonian cycle
    }

    int ans = INT_MAX;
    for(int city=0 ; city<n ; city++){
        if(( mask & (1<<city) ) == 0){
            int nAns = dist[pos][city] + tsp(mask|(1<<city),city);
            ans = min(ans,nAns);
        }
    }

    return ans;
}
int main(){
    int mask=1;
    int pos=0; // => starting A Node or 0th node
    cout<<tsp(mask,pos);
    return 0;
}