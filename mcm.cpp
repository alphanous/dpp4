#include<bits/stdc++.h>
using namespace std;
#define ll long long
int mcm(int a[],int x, int y)
{
    if(x>=y)
    {
        return 0;
    }
    
    int min_cost = INT_MAX;
    for(int k=x;k<=y-1;k++){
        int temp = mcm(a,x,k) + mcm(a,k+1,y) + (a[x-1]*a[k]*a[y]);
        min_cost =min(temp,min_cost);
    }
    return min_cost;
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int x = 1;
    int y = n-1;
    cout<<mcm(a,x,y)<<endl;
    return 0;
}