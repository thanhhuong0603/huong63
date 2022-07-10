#include<bits/stdc++.h>
using namespace std;
main(){
	int n;
	cout<<"Nhap so dinh: ";
	cin>>n;
	int a[n+1][n+1];
	bool chuaxet[n+1];
	cout<<"\nNhap ma tran ke:\n";
	for(int i=1; i<=n; i++){
		chuaxet[i]=true;
		for(int j=1; j<=n; j++) cin>>a[i][j];
	}
	cout<<"\nCay bao trum la: ";
	queue <int> hd;
	hd.push(1);
	chuaxet[1]=false;
	while(!hd.empty()){
		int u=hd.front(); hd.pop();
		for(int i=1; i<=n; i++){
			if(chuaxet[i]&&a[u][i]){
				if(u<i) cout<<"("<<u<<"-"<<i<<")  ";
				else cout<<"("<<i<<"-"<<u<<")  ";
				chuaxet[i]=false;
				hd.push(i);
			}
		}
	}
}
/*
10
0 1 0 0 0 0 0 0 1 1
1 0 1 1 0 0 0 1 1 1
0 1 0 1 1 0 0 0 0 1
0 1 1 0 1 1 1 1 0 0
0 0 1 1 0 1 0 0 0 0
0 0 0 1 1 0 1 0 0 0
0 0 0 1 0 1 0 1 0 0
0 0 0 1 0 0 1 0 1 0 
1 1 0 0 0 0 0 1 0 1
1 1 1 0 0 0 0 0 1 0
*/



