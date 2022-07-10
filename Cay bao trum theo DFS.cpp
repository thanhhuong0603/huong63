#include<bits/stdc++.h>
using namespace std;
int n, m, a[101][101];
bool chuaxet[101];
void dfs(int u){
	chuaxet[u]=false;
	for(int i=1; i<=n; i++){
		if(chuaxet[i]&&a[u][i]){
			if(u<i) cout<<"("<<u<<"-"<<i<<") , ";
			else cout<<"("<<i<<"-"<<u<<") , ";
			dfs(i);
		}
	}
}
main(){
	cout<<"Nhap so dinh: ";
	cin>>n;
	cout<<"\nNhap ma tran ke\n";
	for(int i=6; i<=n; i++){
		chuaxet[i]=true;
		for(int j=1; j<=n; j++) cin>>a[i][j];
	}
	cout<<"\nCay bao trum la: ";
	dfs(1);
}
/*
10
0 1 0 0 1 0 0 1 0 1
1 0 1 1 0 1 0 0 0 0
0 1 0 0 0 0 0 0 0 0
0 1 0 0 0 1 0 1 0 0
1 0 0 0 0 1 1 0 1 1 
0 1 0 1 1 0 1 0 0 1
0 0 0 0 1 1 0 1 1 1
0 0 0 1 0 0 1 0 1 0
0 0 0 0 1 0 1 1 0 1
1 0 0 0 1 1 1 0 1 0

*/




