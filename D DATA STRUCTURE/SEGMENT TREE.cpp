#define EDGE_SITUATION 0
struct Node{
    int left, right;
    long long val;
}tree[800005];

long long a[200005];

long long pull(long long x, long long y){
    return x + y;
}

void build(int idx, int L, int R){
    tree[idx].left = L;
    tree[idx].right = R;
    if(L == R){
        tree[idx].val = a[L];
        return;
    }
    int M = (L + R)/2;
    build(idx*2, L, M);
    build(idx*2+1, M+1, R);
    tree[idx].val = pull(tree[idx*2].val, tree[idx*2+1].val);
}

long long query(int idx, int ql, int qr){
    if(tree[idx].left > qr || tree[idx].right < ql){
        return EDGE_SITUATION;
    }
    if(tree[idx].left >= ql && tree[idx].right <= qr){
        return tree[idx].val;
    }
    return pull(query(idx*2, ql, qr), query(idx*2+1, ql, qr));
}

void update(int idx, int pos, long long modify){
    if(tree[idx].left == pos && pos == tree[idx].right){
        tree[idx].val = modify;
        return;
    }
    if(tree[idx].right < pos || tree[idx].left > pos){
        return;
    }
    update(idx*2, pos, modify);
    update(idx*2+1, pos, modify);
    tree[idx].val = pull(tree[idx*2].val, tree[idx*2+1].val);
}