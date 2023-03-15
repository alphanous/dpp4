#include<bits/stdc++.h>
using namespace std;
#define ll long long
int lcs(string s, string s1, int n, int m)
{
    if(n==0||m==0)
    {
        return 0;
    }
    if(s[n-1]==s1[m-1])
    {
        return 1+lcs(s,s1,n-1,m-1);
    }
    else{
        return max(lcs(s,s1,n,m-1),lcs(s,s1,n-1,m));
    }
}
int main()
{
    // substring must be continuous and subsequnece can be non-continuous
    string s,s1;
    cin>>s>>s1;
    int n = s.size();
    int m = s1.size();
    cout<<lcs(s,s1,n,m)<<endl;
    return 0;
}


