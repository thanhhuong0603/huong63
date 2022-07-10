#include<bits/stdc++.h>
using namespace std;
struct canh{
	int d, c, h;
};
int n, a[101][101], ne;
bool chuaxet[101];
canh dothi[101], tree[101];
int atree[101][101];
void dfs(int u){
	chuaxet[u]=false;
	for(int i=1; i<=n; i++){
		if((atree[u][i]==1) && chuaxet[i])
			dfs(i);
	}
}
main(){
	cout<<"Nhap so dinh: "; cin>>n;
	cout<<"\nNhap ma tran ke:\n";
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin>>a[i][j];
			if(a[i][j]!=0 && (i<j)){
				ne++; 
				dothi[ne].d=i; dothi[ne].c=j; dothi[ne].h=a[i][j];
			}
		}
	}
	for(int i=1; i<=n; i++) chuaxet[i]=true;
	for(int i=1; i<=ne-1; i++){
		for(int j=ne; j>i; j--){
			if(dothi[j].h<dothi[j-1].h) swap(dothi[j],dothi[j-1]);
		}
	}
	int DH=0, net=0;
	for(int i=1; i<=ne; i++){
		for(int j=1; j<=n; j++) chuaxet[j]=true;
		dfs(dothi[i].d);
		if(chuaxet[dothi[i].c]==true){
			net++;
			int dau=dothi[i].d;
			int cuoi=dothi[i].c;
			tree[net].d=dau;
			tree[net].c=cuoi;
			atree[dau][cuoi]=atree[cuoi][dau]=1;
			DH+=dothi[i].h;
		}
	}
	cout<<"\nCay khung be nhat theo KRUSAL:\n";
	for(int i=1; i<=net; i++) cout<<tree[i].d<<"-"<<tree[i].c<<"\n";
	cout<<"\nTong quang duong dH = "<<DH;
}
/*
13
0 2 1 3 0 0 0 0 0 0 0 0 0
2 0 2 0 0 5 5 0 0 0 0 0 0
1 2 0 4 0 5 0 0 0 0 0 0 0
3 0 4 0 5 5 0 0 0 0 0 0 0
0 0 0 5 0 6 0 0 0 6 0 0 0
0 5 5 5 6 0 6 6 6 6 0 0 0 
0 5 0 0 0 6 0 6 0 0 0 0 0 
0 0 0 0 0 6 6 0 7 0 0 7 7
0 0 0 0 0 6 0 7 0 7 7 0 0
0 0 0 0 6 6 0 0 7 0 7 7 0
0 0 0 0 0 0 0 0 7 7 0 8 0
0 0 0 0 0 0 0 7 0 7 8 0 8
0 0 0 0 0 0 0 7 0 0 0 8 0

Cay khung be nhat theo KRUSAL:
1-3
1-2
1-4
2-6
2-7
4-5
5-10
6-8
6-9
8-12
8-13
9-11
Tong quang duong dH = 60
*/









