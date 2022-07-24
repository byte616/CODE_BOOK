struct Node{
    Node* l, *r;
    int key, pri, tree_size;
    Node(int k):\
    l(0), r(0), key(k), pri(rand()), tree_size(1){};
    void up(){
        tree_size = 1;
        if(l){tree_size += l->tree_size;}
        if(r){tree_size += r->tree_size;}
    }
};


//merge a and b return a Node* of root
//a's maximum <= b's minimum
Node *merge(Node *a, Node *b){
    //done?
    //who is root
    //which side is not done.
    if(a == 0 || b == 0){
        return a?a:b;
    }
    if(a->pri < b->pri){//min heap
        a->r = merge(a->r, b);
        a->up();
        return a;
    }else{
        b->l = merge(a, b->l);
        b->up();
        return b;
    }
}

//split o into a and b(tree)
//the node which key < k goto a
//other goto b(key >= k)
void split(Node *o, Node *&a, Node *&b, int k){
    //done?
    //who is root given to
    //which side is not done
    if(o == 0){
        a = 0, b = 0;
    }else if(o->key < k){
        a = o;
        split(o->r, a->r, b, k);
        a->up();
    }else{
        b = o;
        split(o->l, a, b->l, k);
        b->up();
    }
}


void insert(Node *&root, int k){
    Node *a, *b;
    split(root, a, b, k);
    Node *tmp = new Node(k);
    root = merge(a, merge(tmp, b));
}

bool erase(Node *&root, int k){
    if(root == 0){return false;}
    if(root->key == k){
        Node *t = root;
        root = merge(root->l, root->r);
        delete t;
        return true;
    }
    Node *&t = (k > root->key)? root->r : root->l;
    if(erase(t, k)){root->up();return 1;}
    return 0;
}

int find_kth_element(Node *root, int k){
    if(root == NULL){return -1;}
    const Node *left = root->l;
    if((left && left ->tree_size == k-1) || (!left && k == 1)){
        return root -> key;
    }else if(left && left ->tree_size > k-1){
        return find_kth_element(root->l, k);
    }else{
        return find_kth_element(root->r, left ? k - left->tree_size -1 : k-1);
    }
}