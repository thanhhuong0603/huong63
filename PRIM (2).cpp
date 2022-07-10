#include <iostream>
#define MAX 100
using namespace std;
struct edg{
    int     dau, cuoi, h;
};
class dothi{
    int         n, a[MAX][MAX], ne, atree[MAX][MAX];
    edg         graph[MAX], tree[MAX];
    public:
    int         s;
    bool        chuaxet[MAX];
    void        readdata();
    void        init();
    void        dfstree(int u);
    void        bubblesort();
    void        prim(int s);
};
void    dothi::readdata(){
	cout<<"Nhap so dinh: ";
    cin>>n;
    cout<<"\nNhap dinh bat dau: "; cin>>s;
    ne=0;
    cout<<"\nNhap ma tran ke:\n";
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++){
            cin>>a[i][j];
            if((a[i][j]>0)&&(i<j)){
                ne++;
                graph[ne].dau=i;
                graph[ne].cuoi=j;
                graph[ne].h=a[i][j];
            }
        }
}
void    dothi::init(){
    for(int i=1; i<=n; i++)
        chuaxet[i]=true;
}
void    dothi::dfstree(int u){  
    chuaxet[u]=false;
    for(int i=1; i<=n; i++)
        if((atree[u][i]==1)&&(chuaxet[i]==true))
            dfstree(i);
}
void    dothi::bubblesort(){
    for(int i=1; i<ne; i++)
        for(int j=ne; j>=i+1; j--)
            if(graph[j].h<graph[j-1].h)
                swap(graph[j], graph[j-1]);
}
void    dothi::prim(int s){
    int dH=0;
    int net=0;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            atree[i][j]=0;
    bubblesort();
    while(net!=n-1){
        for(int i=1; i<=ne; i++){
            init();
            dfstree(s);
            int dau=graph[i].dau, cuoi=graph[i].cuoi;
            if(chuaxet[dau]!=chuaxet[cuoi]){
                net++;
                tree[net].dau=dau;
                tree[net].cuoi=cuoi;
                dH+=graph[i].h;
                atree[dau][cuoi]=atree[cuoi][dau]=1;
                break;
            }
        }
    }
    cout<<"\nCay khung be nhat theo PRIM:\n";
    for(int i=1; i<=net; i++)
        cout<<tree[i].dau<<"   "<<tree[i].cuoi<<endl;
    cout<<"\nTong quang duong dH = "<<dH<<"\n";
}
int main(){
    dothi       g;
    g.readdata();
    g.prim(g.s);
}


