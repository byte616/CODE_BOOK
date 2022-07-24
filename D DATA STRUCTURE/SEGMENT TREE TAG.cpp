// segment tree build O(nlogn)
// segment update O(logn)
// segment query O(logn)


const int Edge_situation = 0;
int a[200005];
 
struct Node{
    int L, R;
    long long val, tag;
    bool setting;//the mode is setting(T) or add(F)
    Node(){};
}tree[800020];
 
void build(int idx, int L, int R){
    tree[idx].L = L, tree[idx].R = R;
    //remember to initialize the tag
    tree[idx].setting = false, tree[idx].tag = 0;
    if(L == R){
        tree[idx].val = a[L];
        return;
    }
    int mid = (L+R)/2;
    build(idx*2, L, mid);
    build(idx*2+1, mid+1, R);
    tree[idx].val = tree[idx*2].val + tree[idx*2+1].val;
}
 
void push(int idx){//push the tag into next level
    if(!tree[idx].setting && !tree[idx].tag)return;//nothing change
    if(tree[idx].setting){
        tree[idx].val = (tree[idx].R - tree[idx].L + 1) * tree[idx].tag;
        if(tree[idx].L != tree[idx].R){//L == R --> the leaf node
            tree[idx*2].tag = tree[idx].tag;
            tree[idx*2+1].tag = tree[idx].tag;
            tree[idx*2].setting = true, tree[idx*2+1].setting = true;
        }
    }else{
        tree[idx].val += (tree[idx].R - tree[idx].L + 1) * tree[idx].tag;
        if(tree[idx].L != tree[idx].R){
            tree[idx*2].tag += tree[idx].tag;
            tree[idx*2+1].tag += tree[idx].tag;
        }
    }
    tree[idx].tag = 0, tree[idx].setting = false;
}
 
void update(int idx, int L, int R, bool setting, int modify){
    if(tree[idx].L > R || tree[idx].R < L){return;}
    if(tree[idx].L >= L && tree[idx].R <= R){
        if(setting){
            tree[idx].setting = true;
            tree[idx].tag = modify;
        }else{
            tree[idx].tag += modify;
        }
        return;
    }
    push(idx);//push tree[idx] before process the it
    update(idx*2, L, R, setting, modify);
    update(idx*2+1, L, R, setting, modify);
    push(idx*2), push(idx*2+1);//compute the child answer
    tree[idx].val = tree[idx*2].val + tree[idx*2+1].val;
}
 
long long query(int idx, int L, int R){
    if(tree[idx].L > R || tree[idx].R < L){
        return Edge_situation;
    }
    push(idx);//push tree[idx] before process the it
    if(tree[idx].L >= L && tree[idx].R <= R){
        return tree[idx].val;
    }
    return query(idx*2, L, R) + query(idx*2+1, L, R);
}
 
void traverse(int idx){//debug
    cout<<idx<<":\t"<<tree[idx].L<<" "<<tree[idx].R<<"\t"<<tree[idx].val<<"\t"<<tree[idx].tag<<endl;
    if(tree[idx].L == tree[idx].R){
        return;
    }
    traverse(idx*2), traverse(idx*2+1);
}
