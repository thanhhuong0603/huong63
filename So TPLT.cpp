#include<bits/stdc++.h>
using namespace std;
int n;
int a[101][101];
bool chuaxet[101];
void dfs(int u){
	cout<<u<<" ";
	chuaxet[u]=false;
	for(int i=1; i<=n; i++){
		if(chuaxet[i]&&a[u][i]) dfs(i);
	}
}
main(){
	int so=0;
	cout<<"Nhap so dinh: "; cin>>n;
	cout<<"\nNhap ma tran ke:\n";
	for(int i=1; i<=n; i++){
		chuaxet[i]=true;
		for(int j=1; j<=n; j++) cin>>a[i][j];
	}
	for(int i=1; i<=n; i++){
		if(chuaxet[i]){
			so++;
			cout<<"thanh phan lien thong so "<<so<<": ";
			dfs(i);
			cout<<"\n";
		}
	}
	cout<<"\nso tplt: "<<so;
}
/*
10
0 0 0 1 0 0 0 0 1 1
0 0 0 1 1 0 0 0 0 0
0 0 0 0 0 1 1 0 0 0
1 1 0 0 1 0 0 0 0 0
0 1 0 1 0 0 0 0 0 0
0 0 1 0 0 0 1 0 0 0
0 0 1 0 0 1 0 0 0 0
0 0 0 0 0 0 0 0 1 1
1 0 0 0 0 0 0 1 0 1
1 0 0 0 0 0 0 1 1 0
*/

