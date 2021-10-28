// CODECHEF LUNCHTIME 2021 

//PROBLEM lINK :https://www.codechef.com/LTIME101B/problems/N1VALUES

#include<bits/stdc++.h>
using namespace std;
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 long long int t;
 cin>>t;
 while(t--){
	 long long int n;
	 cin>>n;
	 for(long long int i=0;i<=n;i++){
		 if(i==0){
			 cout<<1<<" ";
		 }
		 else{
			 long long int ans = pow(2,i-1);
			 cout<<ans<<" ";
		 }
	 }
	 cout<<endl;
 }
return 0;
}