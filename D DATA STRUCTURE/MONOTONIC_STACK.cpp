#include<iostream>
#include<stack>
using namespace std;
 
 
int a[200005];
 
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	stack<pair<int, int>> st;
	st.emplace(0, 0);
	for(int i=1;i<=n;i++){
		while(st.top().first >= a[i]){
			st.pop();
		}
		cout<<st.top().second<<" ";
		st.emplace(a[i], i);
	}
	cout<<'\n';
	return 0;
}
