#include <bits/stdc++.h>
using namespace std;

int main() {
	int N,K,D;
	cin>>N>>K>>D;
	
	vector<int> a(N);
	for(int i=0;i<N;i++)cin>>a[i];
	
	vector dp(N+1,vector(K+1,vector<long long>(D,-1)));
	dp[0][0][0] = 0;
	
	for(int i=0;i<N;i++){
		for(int j=0;j<K+1;j++){
			for(int k=0;k<D;k++){
				if(dp[i][j][k]==-1)continue;
				
				//a_i を選ばない場合の遷移
				dp[i+1][j][k] = max(dp[i+1][j][k],dp[i][j][k]);
				
				//a_i を選ぶ場合の遷移
				if(j!=K){
					dp[i+1][j+1][(k+a[i])%D] = max(dp[i+1][j+1][(k+a[i])%D],dp[i][j][k] + a[i]);
				}
			}
		}
	}
	
	cout<<dp[N][K][0]<<endl;
	
	return 0;
}
