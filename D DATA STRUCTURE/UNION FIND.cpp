//O(alpha(N))

int djset[100005];
int treesize[100005];

void build(int n){
    for(int i=0;i<=n;i++){
        djset[i] = i;
        treesize[i] = 1;
    }
}

int findBoss(int x){
    if(djset[x]== x){
        return x;
    }
    return djset[x]=findBoss(djset[x]);
}

void combine(int a,int b){
    a = findBoss(a);
    b = findBoss(b);
    if(a == b) return;
    int temp;
    if(treesize[a] < treesize[b]){
        temp = a;
        a = b;
        b = temp;
    }
    djset[b] = a;
    treesize[a] += treesize[b];
}

bool same(int a,int b){
	return findBoss(a)==findBoss(b);
}
