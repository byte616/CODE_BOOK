// (|S|)

const int MAX_LEN = 1e5;
 
struct State{
    int len;
    int link;
    bool isFinal;
    long long count;
    map<int, int> next;
}machine[2*MAX_LEN+10];
 
struct SufficeAutoMachine{
    int first, last;
    int used;
    SufficeAutoMachine(const string &s){
        used = 0;
        first = last = used++;
        machine[first].len = 0;
        machine[first].link = -1;
        machine[first].isFinal = 0;
        machine[first].count = 0;
        for(char c:s){
            int add = used++;
            machine[add].len = machine[last].len + 1;
            machine[add].link = first;
            machine[add].isFinal = 0;
            machine[add].count = 0;
            int cur = last;
            while(cur != -1 && machine[cur].next.find(c) == machine[cur].next.end()){
                machine[cur].next[c] = add;
                cur = machine[cur].link;
            }
            if(cur != -1 && machine[cur].next[c] != add){
                int mid = machine[cur].next[c];
                if(machine[mid].len == machine[cur].len + 1){
                    machine[add].link = mid;
                }
                else{
                    int copy = used++;
                    // copy node mid to node copy
                    machine[copy].link = machine[mid].link;
                    for(auto e:machine[mid].next){
                        machine[copy].next[e.first] = e.second;
                    }
                    machine[copy].isFinal = 0;
                    machine[copy].count = 0;
 
                    machine[copy].len = machine[cur].len + 1;
                    machine[mid].link = machine[add].link = copy;
                    while(cur != -1 && (machine[cur].next.find(c))->second == mid){
                        machine[cur].next[c] = copy;
                        cur = machine[cur].link;
                    }
                }
            }
            last = add;
        }
        int cur = last;
        while(cur != first){
            machine[cur].isFinal = 1;
            cur = machine[cur].link;
        }
        dfs(first);
    }
    // count: using dp to count the number of different ways from state i to final state
    void dfs(int node){
        if(machine[node].count != 0){
            return;
        }
        if(machine[node].isFinal){
            machine[node].count += 1;
        }
        for(auto e:machine[node].next){
            dfs(e.second);
            machine[node].count += machine[e.second].count;
        }
    }
    long long check(const string &p){
        int cur = first;
        for(char c:p){
            if(machine[cur].next.find(c) == machine[cur].next.end()) return 0;
            cur = machine[cur].next[c];
        }
        return machine[cur].count;
    }
    void display(){
        for(int i=first;i<used;i++){
            cout<<"node "<<i<<":\n";
            for(auto e:machine[i].next){
                cout<<"\t"<<char(e.first)<<" "<<e.second<<'\n';
            }
            cout<<"\t link: "<<machine[i].link<<'\n';
            cout<<"\t count: "<<machine[i].count<<'\n';
        }
    }
};
