#include<bits/stdc++.h>
using namespace std;
int n, m, a[101][101], CE[101], dem;
bool chuaxet[101];
void hamilton(int k){
	for(int i=1; i<=n; i++){
		if(a[CE[k-1]][i]){
			if(k==n+1 && i==CE[1]){
				++dem;
				cout<<"\nChu trinh/duong di Hamilton:\n";
				for(int i=1; i<=n; i++)
					cout<<CE[i]<<" -> ";
				cout<<CE[1];
			}
			else{
				if(chuaxet[i]){
					CE[k]=i;
					chuaxet[i]=false;
					hamilton(k+1);
					chuaxet[i]=true;
				}
			}	
		}
	}
}
main(){
	cout<<"Nhap so dinh: "; cin>>n;
	cout<<"Nhap ma tran ke:\n";
	for(int i=1; i<=n; i++){
		chuaxet[i]=true;
		for(int j=1; j<=n; j++) cin>>a[i][j];
	}
	cout<<"\Nhap dinh bat dau: ";	cin>>m;
	chuaxet[m]=false;
	CE[1]=m;
	dem=0;
	hamilton(m+1);
	cout<<"\n"<<dem;
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
0 1 0 1 0 0 1 0 0 1
1 1 0 0 0 0 0 1 0 1
1 1 1 0 0 0 0 1 1 0
1
*/
