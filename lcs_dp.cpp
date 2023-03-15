#include<bits/stdc++.h>
using namespace std;
#define ll long long
int lcs_dp(string s, string s1, int n, int m)
{
    int dp[n+1][m+1];
    memset(dp, -1, sizeof(dp));
    if(n==0||m==0)
    {
        return 0;
    }
    if(dp[n][m]!=-1)
    {
        return dp[n][m];
    }
    if(s[n-1]==s1[m-1])
    {
        return dp[n][m] = 1+lcs_dp(s,s1,n-1,m-1);
    }
    else{
        return dp[n][m] = max(lcs_dp(s,s1,n,m-1),lcs_dp(s,s1,n-1,m));
    }
}
int main()
{
    string s,s1;
    cin>>s>>s1;
    int n = s.size();
    int m = s1.size();
    cout<<lcs_dp(s,s1,n,m)<<endl;
    return 0;
}


