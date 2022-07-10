#include<bits/stdc++.h>
using namespace std;
main(){
	int n,s,t;
	cout<<"Nhap so dinh: "; cin>>n;
	int a[n+1][n+1], truoc[n+1];
	bool chuaxet[n+1];
	cout<<"\nNhap ma tran ke:\n";
	for(int i=1; i<=n; i++){
		chuaxet[i]=true;
		truoc[i]=0;
		for(int j=1; j<=n; j++) cin>>a[i][j];
	}
	cout<<"\nNhap dinh bat dau va ket thuc: ";
	cin>>s>>t;
	queue <int> hd;
	hd.push(s);
	chuaxet[s]=false;
	while(!hd.empty()){
		int u=hd.front(); hd.pop();
		for(int i=1; i<=n; i++){
			if(chuaxet[i]&&a[u][i]){
				chuaxet[i]=false;
				truoc[i]=u;
				hd.push(i);
			}
		}
	}
	if(truoc[t]==0) cout<<"\nKhong co duong di";
	else{
		cout<<"\nDuong di theo BFS: "<<t<<" <- ";
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



