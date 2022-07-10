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
	cout<<"\nNhap dinh bat dau: ";
	cin>>m;
	cout<<"\nBFS: "<<m<<" ";
	queue <int> hd;
	hd.push(m);
	chuaxet[m]=false;
	while(!hd.empty()){
		int s=hd.front();
		hd.pop();
		for(int i=1; i<=n; i++){
			if(chuaxet[i]&&a[s][i]){
				cout<<i<<" ";
				chuaxet[i]=false;
				hd.push(i);
			}
		}
	}	
}



