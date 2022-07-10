#include<bits/stdc++.h>
using namespace std;
int n,s,t;
int a[101][101], truoc[101];
bool chuaxet[101];
void dfs(int u){
	chuaxet[u]=false;
	for(int i=1; i<=n; i++){
		if(chuaxet[i]&&a[u][i]){
			truoc[i]=u;
			dfs(i);
		}
	}
}
main(){	
	cout<<"Nhap so dinh: "; cin>>n;
	cout<<"\nNhap ma tran ke:\n";
	for(int i=1; i<=n; i++){
		chuaxet[i]=true;
		truoc[i]=0;
		for(int j=1; j<=n; j++) cin>>a[i][j];
	}
	cout<<"\nNhap dinh bat dau va ket thuc: ";
	cin>>s>>t;
	dfs(s);
	if(truoc[t]==0) cout<<"\nKhong co duong di";
	else{
		cout<<"\nDuong di DFS: "<<t<<" <- ";
		int u=truoc[t];
		while(u!=s){
			cout<<u<<" <- ";
			u=truoc[u];
		}
		cout<<s;
	}
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
1 1 0 0 1 1 1 0 1 0
*/
