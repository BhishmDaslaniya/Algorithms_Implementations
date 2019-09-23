#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll LCS(string a, string b){
    ll l1=a.size();
	ll l2=b.size();
	ll dp[l1+1][l2+1];
	for(ll i=0;i<=l1;i++){
		for(ll j=0;j<=l2;j++){
			if(!i || !j)
				dp[i][j]=0;
			else if(a[i-1] == b[j-1]){
				dp[i][j] = dp[i-1][j-1] + 1;
			}else{	
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	return dp[l1][l2];
}

int main(){
    cout<<"Enter two strings for finding longest common subsequence :"<<endl;
    string str1,str2;
    cout<<"String 1 :";
    cin>>str1;
    cout<<"String 2 :";
    cin>>str2;
    cout<<"Longest Common Subsequence is of length : "<<LCS(str1,str2)<<endl;
}