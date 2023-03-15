#include<bits/stdc++.h>
using namespace std;
#define ll long long
int knapsack(int wt[], int val[], int w, int n)
{
    int dp[n+1][w+1];
    memset(dp, -1, sizeof(dp));
    if(w==0 || n==0)
    {
        return 0;
    }
    if(dp[n][w]!=-1)
    {
        return dp[n][w];
    }
    if(wt[n-1]>w)
    {
        return dp[n][w] = knapsack(wt,val,w,n-1);
    }
    else{
        int taken = val[n-1] + knapsack(wt,val,w-wt[n-1],n-1);
        int not_taken = knapsack(wt,val,w,n-1);
        return dp[n][w] = max(taken,not_taken);
    }
}
int main()
{
    int n;
    cin>>n;
    int wt[n],val[n];
    for(int i=0;i<n;i++)
    {
        cin>>wt[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>val[i];
    }
    int w;
    cin>>w;
    cout<<knapsack(wt,val,w,n)<<endl;
    return 0;
}