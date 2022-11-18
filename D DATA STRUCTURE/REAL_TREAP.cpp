#include<iostream>
using namespace std;

struct Node{
    Node* l, *r;
    int key;
    int pri, tree_size;
    int swap_tag;
    long long sum;
    Node(int k):\
    l(0), r(0), key(k), pri(rand()), tree_size(1), swap_tag(0), sum(k){};
    void up(){
        tree_size = 1;
        sum = key;
	if(l){
		tree_size += l->tree_size;
		sum += l -> sum;
	}
        if(r){
		tree_size += r->tree_size;
		sum += r -> sum; 
	}
	
    }
};

void push(Node *root){
	if(!root)	return;
	if(root->swap_tag){
		swap(root->l, root->r);
		if(root -> l )
			(root -> l) -> swap_tag ^= 1;
		if(root -> r)
			(root -> r) -> swap_tag ^= 1;
	}
	root->swap_tag = 0;
}


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
        push(a);
	a->r = merge(a->r, b);
        a->up();
        return a;
    }else{
    	push(b);
        b->l = merge(a, b->l);
        b->up();
        return b;
    }
}

//split o into a and b(tree)
//the node which key < k goto a
//other goto b(key >= k)
void output(Node *root);
void split(Node *o, Node *&a, Node *&b, int k){
    //done?
    //who is root given to
    //which side is not done
    if(o == 0){
        a = 0, b = 0;
        return;
    }
    push(o);
    int osize = (o->l) ? (o->l)->tree_size : 0;
    if(osize < k){
		split(o->r, o->r, b, (o->l) ? (k - (o->l)->tree_size -1) : (k-1));
		a = o;
		a->up();
		return;
    }
    split(o->l, a, o->l, k);
    b = o;
    b->up();
    return;
}

void output(Node *root){
	return;
	if(!root)	return;
	push(root);
	output(root->l);
	cout<<(root->key);
	output(root->r);
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	srand(time(0));
	int n, m;
	cin>>n>>m;
	Node *root = NULL;
	for(int i=0, x;i<n;i++){
		cin>>x;
		root = merge(root, new Node(x));
	}
	output(root);
	cout<<'\n';
	int act, left, right;
	while(m--){
		cin>>act>>left>>right;
		Node *l, *mid, *r;
		split(root, mid, r, right);
		split(mid, l, mid, left-1);
		if(act == 1){
			mid->swap_tag ^= 1;
		}
		else{
			cout<<(mid->sum)<<endl;
		}
/*
		output(l);
		cout<<'\n';
		output(mid);
		cout<<'\n';
		output(r);
		cout<<'\n';
*/
		root = merge(l, mid);
		root = merge(root, r);
	}
	output(root);
	cout<<'\n';
	return 0;
}
