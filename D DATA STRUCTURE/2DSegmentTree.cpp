#include<iostream>
#include<vector>
using namespace std;
#define maxSize 1024
#define edge_situation 0
 
int a[maxSize][maxSize];
 
struct Node{
	int L, R;
	long long val;
	Node(){};
};
 
struct SegTree{
	int L, R;
	long long val;
	vector<Node> tree;
	void build(int id, int row, int L, int R);
	SegTree(){};
	SegTree(int n):tree(4*n+5){};
	long long query(int id, int L, int R);
	int update(int id, int pos, long long val);
};
 
void SegTree::build(int id, int row, int L, int R){
	tree[id].L = L;
	tree[id].R = R;
	if(L == R){
		tree[id].val = a[row][L];
		return;
	}
	int MID = (L + R) / 2;
	build(id*2, row, L, MID);
	build(id*2+1, row, MID+1, R);
	tree[id].val = tree[id*2].val + tree[id*2+1].val;
}
 
long long SegTree::query(int id, int L, int R){
	if(tree[id].L > R || tree[id].R < L){
		return 0;
	}
	if(L <= tree[id].L && tree[id].R <= R){
		return tree[id].val;
	}
	return query(id*2, L, R) + query(id*2+1, L, R);
}
 
int SegTree::update(int id, int pos, long long val){
    //cout<<"SegTree: "<<id<<", "<<pos<<", "<<val<<", ("<<tree[id].L<<", "<<tree[id].R<<")\n";
	if(tree[id].L > pos || tree[id].R < pos){
		return -1;
	}
	if(tree[id].L == pos && tree[id].R == pos){
		tree[id].val = val;
		return id;
	}
	int idl = update(id*2, pos, val);
	int idr = update(id*2+1, pos, val);
	tree[id].val = tree[id*2].val + tree[id*2+1].val;
    return (idl != -1)? idl:idr;
}
 
 
struct SegSegTree{
	int n, m;
	vector<SegTree> outTree;
	SegSegTree(int n, int m):n(n), m(m), outTree(4*m+5){};
	void build(int id, int rowL, int rowR);
	SegSegTree(int n):outTree(n+5){};
	long long query(int id, int rowL, int rowR, int L, int R);
	int update(int id, int posX, int posY);
    void pull(int id);
};
 
void SegSegTree::build(int id, int rowL, int rowR){
	outTree[id].L = rowL;
	outTree[id].R = rowR;
	outTree[id].tree.resize(4*n+8);
	if(rowL == rowR){
		outTree[id].build(1, rowL, 1, n);
		return;
	}
	int MID = (rowL + rowR) / 2;
	build(id*2, rowL, MID);
	build(id*2+1, MID+1, rowR);
	for(int i=0;i<outTree[id].tree.size();i++){
		outTree[id].tree[i].L = outTree[id*2].tree[i].L;
		outTree[id].tree[i].R = outTree[id*2].tree[i].R;
	}
    pull(id);
}
 
void SegSegTree::pull(int id){
	for(int i=0;i<outTree[id].tree.size();i++){
        outTree[id].tree[i].val = outTree[id*2].tree[i].val;
		outTree[id].tree[i].val += outTree[id*2+1].tree[i].val;
	}
}
 
long long SegSegTree::query(int idx, int x1, int y1, int x2, int y2){
    if(outTree[idx].L > x2 || outTree[idx].R < x1){
        return edge_situation;
    }
    if(outTree[idx].L >= x1 && outTree[idx].R <= x2){
        return outTree[idx].query(1, y1, y2);
    }
    return query(idx*2, x1, y1, x2, y2) + query(idx*2+1, x1, y1, x2, y2);
}
 
 
int SegSegTree::update(int idx, int posX, int posY){
    if(outTree[idx].L > posX || outTree[idx].R < posX){
        return -1;
    }
    //cout<<"SegSegTree: "<<idx<<", "<<posX<<", "<<posY<<", "<<outTree[idx].L<<", "<<outTree[idx].R<<'\n';
    if(outTree[idx].L == outTree[idx].R){
        a[posX][posY] = 1 - a[posX][posY];
        return outTree[idx].update(1, posY, a[posX][posY]);
    }
    int idl = update(idx*2, posX, posY);
    int idr = update(idx*2+1, posX, posY);
    int idy = ((idl == -1)? idr:idl);
    long long lv = outTree[idx*2].tree[idy].val;
    long long rv = outTree[idx*2+1].tree[idy].val;
    outTree[idx].update(1, posY, lv + rv);
    return idy;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin>>n>>q;
    char c;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>c;
            a[i][j] = (c == '*');
        }
    }
 
    SegSegTree segs(n, n);
    segs.build(1, 1, n);
    int act, x, y, lx, ly, rx, ry;
    while(q--){
        cin>>act;
        if(act == 1){
            cin>>x>>y;
            segs.update(1, x, y);
        }
        else{
            cin>>lx>>ly>>rx>>ry;
            cout<<segs.query(1, lx, ly, rx, ry)<<'\n';
        }
    }
 
	return 0;
}
