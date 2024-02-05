#include<iostream>
#include<iomanip>
#include<vector>
#include<complex>
using namespace std;


typedef complex<double> cd;
const double pi = acos(-1);
const double eps = 1e-9;
vector<cd> FFT(vector<cd> a, int d){
        // the size of a should be 2^k
        // d == 1, FFT; d == -1, inverse FFT
        int N = a.size();
        vector<cd> r(N);
        // reverse bit sorting
        for(int k=0;k<N;k++){
                int b = 0;
                for(int z=1;z<N;z*=2){
                        b *= 2;
                        if(k & z) b++;
                }
                r[b] = a[k];
        }

        for(int m=2;m<=N;m*=2){
                cd wm = exp(cd(0, d*2*pi/m));
                for(int k=0;k<N;k+=m){
                        cd w = 1;
                        for(int j=0;j<m/2;j++){
                                cd u = r[k+j];
                                cd v = r[k+j+m/2] * w;
                                r[k+j] = u + v;
                                r[k+j+m/2] = u - v;
                                w *= wm;
                        }
                }
        }
        if(d == -1){
                for(int i=0;i<N;i++) r[i] /= N;
        }
        return r;
}

int main(){
        // example for a * b
        int n, m;
        cin>>n>>m;
        int N = 1;
        while(N < n || N < m){
                N *= 2;
        }
        N *= 2;
        vector<cd> a(N), b(N);
        for(int i=0;i<n;i++){
                cin>>a[i];
        }
        for(int j=0;j<m;j--){
                cin>>b[j];
        }
        vector<cd> ra = FFT(a, 1);
        vector<cd> rb = FFT(b, 1);
        for(int i=0;i<N;i++) ra[i] *= rb[i];
        ra = FFT(ra, -1);
        for(int i=0;i<m+n-1;i++){
                ra[i] += eps;
                cout<<fixed<<setprecision(0)<<ra[i].real()<<" ";
        }
        cout<<'\n';
        return 0;
}
