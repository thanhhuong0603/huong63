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
	cout<<"\ncanh cau: ";
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){			
			if(a[i][j] && i<j){
				int so=0;
				a[i][j]=0; a[j][i]=0;
				for(int z=1; z<=n; z++){
					if(chuaxet[z]){
						so++;
						dfs(z);
					}
				}
				if(so>s) cout<<"("<<i<<"-"<<j<<")   "; 
				a[i][j]=1; a[j][i]=1;
				for(int z=1; z<=n; z++) chuaxet[z]=true;
			}
		}
	}
}


//#include<bits/stdc++.h>
//using namespace std;
//int n;
//int a[101][101];
//bool chuaxet[101];
//void dfs(int u){
//	chuaxet[u]=false;
//	for(int i=1; i<=n; i++){
//		if(chuaxet[i]&&a[u][i]) dfs(i);
//	}
//}
//main(){	
//	cout<<"Nhap so dinh: "; cin>>n;
//	cout<<"\nNhap ma tran ke:\n";
//	for(int i=1; i<=n; i++){
//		chuaxet[i]=true;
//		for(int j=1; j<=n; j++) cin>>a[i][j];
//	}
//	int s=0;
//	for(int i=1; i<=n; i++){
//		if(chuaxet[i]){
//			s++;
//			dfs(i);
//		}	
//	}
//	cout<<"\n"<<s<<"\n";
//	for(int j=1; j<=n; j++) chuaxet[j]=true;
//	cout<<"\ncanh cau: ";
//	for(int i=1; i<=n; i++){
//		for(int j=1; j<=n; j++){			
//			if(a[i][j] && i<j){
//				int so=0;
//				a[i][j]=0; a[j][i]=0;
//				for(int z=1; z<=n; z++){
//					if(chuaxet[z]){
//						so++;
//						dfs(z);
//					}
//				}
//				if(so>s) cout<<"("<<i<<"-"<<j<<")   "; 
//				a[i][j]=1; a[j][i]=1;
//				for(int z=1; z<=n; z++) chuaxet[z]=true;
//			}
//		}
//	}
//}
///*
//12
//0 1 1 1 0 0 0 0 0 0 0 0
//1 0 1 1 0 0 0 0 0 0 0 0
//1 1 0 1 0 0 0 0 0 0 0 0
//1 1 1 0 1 0 0 0 0 0 0 0
//0 0 0 1 0 1 1 1 0 0 0 0
//0 0 0 0 1 0 1 1 0 0 0 0
//0 0 0 0 1 1 0 1 0 0 0 0
//0 0 0 0 1 1 1 0 0 1 0 0
//0 0 0 0 0 0 0 0 0 1 1 1
//0 0 0 0 0 0 0 1 1 0 1 0
//0 0 0 0 0 0 0 0 1 1 0 1
//0 0 0 0 0 0 0 0 1 0 1 0
//*/


