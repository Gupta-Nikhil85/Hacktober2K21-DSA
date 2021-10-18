#include <bits/stdc++.h>
using namespace std;


void file_i_o()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

// int t[102][1002]; // Assuming n<=100 & w<=1000.
vector<vector<int>> t(102, vector<int> (1002,-1));

int knapsack(int weight, int w[], int val[], int n){
	if(weight ==0 || n==0){
		return 0;
	}
	if(t[n][weight]!=-1){
		return t[n][weight];
	}

	if(w[n-1]<= weight){
		return t[n][weight]= max((val[n-1] + knapsack(weight-w[n-1], w, val, n-1)), knapsack(weight, w, val, n-1));
	}
	// else if(w[n]>weight){
		return t[n][weight]= knapsack(weight, w, val, n-1);

}

int main(){
    file_i_o();
    int w[]= {1, 4, 14, 10};
    int val[]= {200, 150, 400, 200};
    cout<<knapsack(20, w, val, 4)<<endl;

	return 0;
}