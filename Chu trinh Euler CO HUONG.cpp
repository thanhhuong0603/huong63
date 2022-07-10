#include<bits/stdc++.h>
using namespace std;
main(){
	int n,m;
	cout<<"Nhap so dinh: "; cin>>n;
	int a[n+1][n+1], CE[2*n+1], ne=0;
	cout<<"\nNhap ma tran ke:\n";
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++) cin>>a[i][j];
	cout<<"\nNhap dinh bat dau: "; cin>>m;
	stack <int> nx;
	nx.push(m);
	while(!nx.empty()){
		int s=nx.top();
		int dem=0;
		for(int i=1; i<=n; i++){
			if(a[s][i]){
				dem=1;
				nx.push(i);
				a[s][i]=0;
				break;
			}
		}
		if(dem==0){
			CE[ne++]=s;
			nx.pop();
		}
	}
	cout<<"\nChu trinh/duong di Euler:\n";
	for(int i=ne-1; i>=0; i--){
		if(i==0) cout<<CE[i];
		else cout<<CE[i]<<" -> ";
	}
}
/*
10
0 1 1 0 0 0 0 0 0 0
0 0 1 1 1 0 0 0 0 0
0 0 0 0 0 0 0 0 1 1
0 0 0 0 0 1 1 0 0 0
0 0 0 0 0 1 0 0 0 0
0 0 0 0 0 0 1 1 0 0
0 0 0 1 0 0 0 1 0 0 
1 1 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 1
1 1 0 0 0 0 0 0 0 0
1
Chu trinh Euler
1 -> 2 -> 3 -> 9 -> 10 -> 1 -> 3 -> 10 -> 2 -> 4 
-> 6 -> 7 -> 4 -> 7 -> 8 -> 2 -> 5 -> 6 -> 8 -> 1
*/
/*
10
0 1 0 0 1 0 0 1 0 1
1 0 1 1 0 1 0 0 0 0
0 1 0 1 0 0 0 0 0 0
0 1 1 0 0 1 0 0 0 0
1 0 0 0 0 1 1 1 1 1
0 1 0 0 1 0 1 0 0 0
0 0 0 0 1 0 0 1 1 1
1 0 0 0 1 0 1 0 0 0
0 0 0 0 1 0 1 0 0 0
1 0 0 0 1 0 1 0 0 0
1
1 -> 2 -> 1 -> 5 -> 1 -> 8 -> 1 -> 10 -> 5 -> 6 -> 2 -> 3 -> 2 -> 4 
-> 3 -> 4 -> 6 -> 2 -> 6 -> 7 -> 5 -> 7 -> 5 -> 8 -> 5 -> 9 -> 5 -> 10 
-> 7 -> 8 -> 7 -> 9 -> 7 -> 10 -> 1
*/
