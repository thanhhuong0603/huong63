#include<bits/stdc++.h>
using namespace std;
main(){
	int n,m;
	cout<<"Nhap so dinh: ";
	cin>>n;
	int a[n+1][n+1];
	bool chuaxet[n+1];
	cout<<"\nNhap ma tran ke:\n";
	for(int i=1; i<=n; i++){
		chuaxet[i]=true;
		for(int j=1; j<=n; j++) cin>>a[i][j];
	}
	cout<<"\nNhap dinh bat dau: "; cin>>m;
	cout<<"\nDFS: "<<m<<" ";
	stack <int> nx;
	nx.push(m);
	chuaxet[m]=false;
	while(!nx.empty()){
		int s=nx.top(); nx.pop();
		for(int i=1; i<=n; i++){
			if(chuaxet[i]&&a[s][i]){
				cout<<i<<" ";
				chuaxet[i]=false;
				nx.push(s);
				nx.push(i);
				break;
			}
		}
	}
}
/*
13
0 1 1 1 0 0 0 0 0 0 0 0 0
1 0 1 1 0 1 0 0 0 0 0 0 0
1 1 0 1 1 0 0 0 0 0 0 0 0
1 1 1 0 0 0 1 0 0 0 0 0 0
0 0 1 0 0 1 1 1 0 0 0 1 0
0 1 0 0 1 0 1 0 0 0 0 1 0
0 0 0 1 1 1 0 1 0 0 0 0 0
0 0 0 0 1 0 1 0 0 0 0 1 0
0 0 0 0 0 0 0 0 0 1 1 0 1
0 0 0 0 0 0 0 0 1 0 1 1 1
0 0 0 0 0 0 0 0 1 1 0 0 1
0 0 0 0 1 1 0 1 0 1 0 0 0
0 0 0 0 0 0 0 0 1 1 1 0 0

*/






