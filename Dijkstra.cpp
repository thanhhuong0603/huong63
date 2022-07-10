#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000
main(){
	int n,s;
	cout<<"Nhap so dinh: "; cin>>n;
	int a[n+1][n+1], truoc[n+1], d[n+1];
	cout<<"\nNhap ma tran ke:\n";
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin>>a[i][j];
			if(a[i][j]==0) a[i][j]=MAX;
		}
	}
	bool chuaxet[n+1];
	cout<<"\nNhap dinh bat dau: "; cin>>s;
	for(int i=1; i<=n; i++){
		d[i]=a[s][i];
		truoc[i]=s;
		chuaxet[i]=true;
	}
	d[s]=0;
	chuaxet[s]=false;
	for(int i=1; i<=n; i++){
		if(chuaxet[i]){
			int u=0, du=MAX;
			for(int j=1; j<=n; j++){
				if(chuaxet[j] && d[j]<du){
					u=j;
					du=d[j];
				}
			}
			if(u!=0){
				chuaxet[u]=false;
				for(int j=1; j<=n; j++){
					if(chuaxet[j] && d[j]>du+a[u][j]){
						d[j]=du+a[u][j];
						truoc[j]=u;
					}
				}
			}
			else{
				chuaxet[i]=false;
			}
			i=0;
		}
	}
	for(int i=1; i<=n; i++){
		if(d[i]==MAX) cout<<"\nK/c "<<s<<" -> "<<i<<" = MAX\n";
		else{
			cout<<"\nK/c "<<s<<" -> "<<i<<" = "<<d[i]<<"\n";
			cout<<"Duong di: "<<i<<" <- ";
			int u=truoc[i];
			while(u!=s){
				cout<<u<<" <- ";
				u=truoc[u];
			}
			cout<<s<<"\n";
		}
	}
}
/*
6
0 1 0 0 0 0
0 0 5 2 0 7
0 0 0 0 0 1
2 0 1 0 4 0
0 0 0 3 0 0
0 0 0 0 1 0
1

K/c 1 -> 1 = 0
Duong di: 1 <- 1

K/c 1 -> 2 = 1
Duong di: 2 <- 1

K/c 1 -> 3 = 4
Duong di: 3 <- 4 <- 2 <- 1

K/c 1 -> 4 = 3
Duong di: 4 <- 2 <- 1

K/c 1 -> 5 = 6
Duong di: 5 <- 6 <- 3 <- 4 <- 2 <- 1

K/c 1 -> 6 = 5
Duong di: 6 <- 3 <- 4 <- 2 <- 1
*/
