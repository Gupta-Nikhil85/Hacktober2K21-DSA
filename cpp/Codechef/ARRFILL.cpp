/*  Problem: https://www.codechef.com/AUG21C/problems/ARRFILL
    Solution By: Ratan Raj Ojha
    Github: https://github.com/ratanojha10
    C++17
    */
#include <bits/stdc++.h>  
using namespace std;  

unsigned long long int n;

int main() 
{   
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	long long int t;
	cin>>t;
	while(t--){
		unsigned long long int m,sum=0;
		cin>>n>>m;
		unsigned long long int zeros, l=1;
		vector<pair<long long int,long long int>> v_pairs(m);
		for(int i=0;i<m;i++){
			int x,y;
			cin>>x>>y;
			v_pairs[i]={x,y};
		}
		sort(v_pairs.rbegin(), v_pairs.rend());
		l=v_pairs[0].second;
		for(int i=0;i<m;i++){
			int temp_x=v_pairs[i].first, temp_y=v_pairs[i].second;
			l=lcm(temp_y,l);
			if(i==0){
				zeros=n/l;
				sum+=temp_x*(n-(zeros));
			}
			else{
				zeros-=n/l;
				sum+=temp_x*(zeros);
				zeros=n/l;		
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
