#include<bits/stdc++.h>
using namespace std;
int n;
int a[101][101];
bool chuaxet[101];
void dfs(int u){
	chuaxet[u]=false;
	for(int i=1; i<=n; i++){
		if(chuaxet[i]&&a[u][i]) dfs(i);
	}
}
main(){	
	cout<<"Nhap so dinh: "; cin>>n;
	cout<<"\nNhap ma tran ke:\n";
	for(int i=1; i<=n; i++){
		chuaxet[i]=true;
		for(int j=1; j<=n; j++) cin>>a[i][j];
	}
	int s=0;
	for(int i=1; i<=n; i++){
		if(chuaxet[i]){
			s++;
			dfs(i);
		}	
	}
	for(int j=1; j<=n; j++) chuaxet[j]=true;
	cout<<"\nDinh tru: ";
	for(int i=1; i<=n; i++){
		chuaxet[i]=false;
		int so=0;
		for(int j=1; j<=n; j++){
			if(chuaxet[j]){
				so++;
				dfs(j);
			}
		}
		if(so>s) cout<<i<<" ";
		for(int j=1; j<=n; j++) chuaxet[j]=true;
	}
}
/*
12
0 1 0 1 0 0 0 0 0 0 0 0
1 0 1 0 0 0 0 0 0 0 0 0
0 1 0 1 0 0 0 0 0 0 0 0
1 0 1 0 0 1 0 0 0 0 0 0
0 0 0 0 0 1 0 1 0 0 0 0
0 0 0 1 1 0 1 0 0 0 0 0
0 0 0 0 0 1 0 1 0 0 0 0
0 0 0 0 1 0 1 0 0 1 0 0
0 0 0 0 0 0 0 0 0 1 0 0
0 0 0 0 0 0 0 1 1 0 1 0
0 0 0 0 0 0 0 0 0 1 0 1
0 0 0 0 0 0 0 0 0 0 1 0
*/







