const long long Boundary_condition = 0;
 
long long compute(long long a, long long b){
    return a + b;
}
 
struct Node{
    int L, R;
    long long val;
    Node *lc, *rc;
    int used_cnt;
    Node(int L, int R, long long val, Node *lc, Node *rc):
        L(L), R(R), val(val), lc(lc), rc(rc), used_cnt(1){
    };
    Node(Node &r, long long _val):
        L(r.L), R(r.R), val(_val), lc(r.lc), rc(r.rc), used_cnt(1){
            r.used_cnt -= 1;
            if(r.lc)  (r.lc)->used_cnt += 1;
            if(r.rc)  (r.rc)->used_cnt += 1;
    };
    void pull(){
        if(lc == nullptr || rc == nullptr){
            return;
        }
        val = compute(lc->val, rc->val);
    }
    void display(){
        cout<<"L, R, val, used_cnt = "<<L<<" "<<R<<" "<<val<<" "<<used_cnt<<' ';
        cout<<lc<<" "<<rc<<'\n';
    }
};
 
struct SegmentTree{
    private:
        Node *build(int L, int R, vector<int> &a){
            if(L == R){
                return new Node(L, R, a[L], nullptr, nullptr);
            }
            int Mid = (L + R) / 2;
            Node *lc = build(L, Mid, a);
            Node *rc = build(Mid+1, R, a);
            Node *tree = new Node(L, R, 0, lc, rc);
            tree->pull();
            return tree;
        }
        long long _query(Node *tree, int L, int R){
            if(tree == nullptr) return Boundary_condition;
            if(tree->L > R || tree->R < L)    return Boundary_condition;
            if(tree->L >= L && tree->R <= R){
                return tree->val;
            }
            return compute(_query(tree->lc, L, R), _query(tree->rc, L, R));
        }
        Node *_update(Node *tree, int pos, int modify){
            if(tree == nullptr) return tree;
            if(tree->L > pos || tree->R < pos){
                return tree;
            }
            if(tree->L >= pos && tree->R <= pos){
                if(tree->used_cnt != 1){
                    return new Node(*tree, modify);
                }
                tree->val = modify;
                return tree;
            }
            if(tree->used_cnt != 1){
                tree = new Node(*tree, 0);
            }
            Node *lc = _update(tree->lc, pos, modify);
            Node *rc = _update(tree->rc, pos, modify);
            tree->lc = lc;
            tree->rc = rc;
            tree->pull();
            return tree;
        }
        void _display(Node *tree){
            if(tree == nullptr) return;
            cout<<tree<<" ";
            tree->display();
            _display(tree->lc);
            _display(tree->rc);
        }
    public:
        Node *root;
        SegmentTree(vector<int> &a){
            root = build(0, a.size()-1, a);
        };
        SegmentTree(Node *r):root(r){};
        long long query(int l, int r){
            return _query(root, l, r);
        }
        void update(int pos, int modify){
            root = _update(root, pos, modify);
        }
        void display(){
            _display(root);
        }
};
 
SegmentTree *copy(const SegmentTree &r){
    r.root->used_cnt += 1;
    Node *root = new Node(*(r.root), (r.root)->val);
    SegmentTree *tree = new SegmentTree(root);
    return tree;
}
