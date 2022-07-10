#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000
main(){
	int n,s;
	cout<<"Nhap so dinh: "; cin>>n;
	int a[n+1][n+1], d[n+1], truoc[n+1];
	cout<<"\nNhap ma tran ke:\n";
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin>>a[i][j];
			if(a[i][j]==0) a[i][j]=MAX;
		}
	}
	cout<<"\nNhap dinh bat dau: "; cin>>s;
	for(int i=1; i<=n; i++){
		d[i]=a[s][i];
		truoc[i]=s;
	}
	d[s]=0;
	for(int k=1; k<=n-2; k++){
		for(int i=1; i<=n; i++){
			if(i!=s){
				for(int j=1; j<=n; j++){
					if(a[j][i]!=MAX && d[j]!=MAX && (d[i]>d[j]+a[j][i])){
						d[i]=d[j]+a[j][i];
						truoc[i]=j;
					}
				}
			}
		}
	}
	for(int i=1; i<=n; i++){
		if(d[i]==MAX) cout<<"\nK/c "<<s<<" -> "<<i<<" = MAX\n";
		else{
			cout<<"\nK/c "<<s<<" -> "<<i<<" = "<<d[i];
			cout<<"\nDuong di: "<<i<<" <- ";
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
5
0 1 0 0 3
0 0 3 3 8
0 0 0 1 -5
0 0 2 0 0
0 0 0 4 0
1

K/c 1 -> 1 = 0
Duong di: 1 <- 1

K/c 1 -> 2 = 1
Duong di: 2 <- 1

K/c 1 -> 3 = 4
Duong di: 3 <- 2 <- 1

K/c 1 -> 4 = 3
Duong di: 4 <- 5 <- 3 <- 2 <- 1

K/c 1 -> 5 = -1
Duong di: 5 <- 3 <- 2 <- 1

*/







































