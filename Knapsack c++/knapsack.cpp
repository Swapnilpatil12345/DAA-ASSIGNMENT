#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int dp[3][6+1];
for(int i=0; i<3 ;i++){
    for(int j=0;j<7 ;j++){
        dp[i][j]=-1;
    }
}
int fillKnapsack(vector<int> wt, vector<int> val, int w, int ind){
    
    // base case
    if(ind==0){
        if(w>=wt[0]){
            return val[0];
        }
        else{
            return 0;
        }
    }
    if(dp[ind][w]!=-1)return dp[ind][w];
    int take = INT_MIN;
    int notTake = 0;
    // Not take
    notTake= 0 + fillKnapsack(wt,val,w,ind-1);

    // take
    if(w>=wt[ind]){
        take = val[ind] + fillKnapsack(wt,val,w-wt[ind],ind-1);
        dp[ind][w]=take;
    }
    return max(take, notTake);
}
int main(){
    vector<int> wt;
    vector<int> val;
    wt.push_back(3);
    wt.push_back(2);
    wt.push_back(5);
    val.push_back(30);
    val.push_back(40);
    val.push_back(60);
    int w = 6;
    int n = wt.size();
    
    cout<<fillKnapsack(wt,val,w,n-1);
    return 0;
}