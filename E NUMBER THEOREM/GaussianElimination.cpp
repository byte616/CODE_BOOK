const long long MOD = 1000000007;

void divdRow(vector<long long> &v, long long div){
    for(int i=0;i<v.size();i++){
        v[i] *= inv(div);
        v[i] %= MOD;
    }
}

void subRow(vector<long long> &a, vector<long long> &b, long long mul){
    if(mul == 0) return;
    for(int i=0;i<a.size();i++){
        b[i] -= (a[i] * mul) % MOD;
        b[i] = (b[i] + MOD) % MOD;
    }
}

bool GaussianElimination(vector<vector<long long>> &v, vector<long long> &ans){
    // x_1, .., x_m will be put in ans
    // v: equation (will be changed)
    // return false if no solution
    // return true if one or multi solution
    int n = v.size();
    int m = v[0].size()-1; // v[0].back is constant
    ans.assign(m, 0);

    // Gaussian
    int actRow, pi;
    for(actRow=0, pi=0;actRow<n && pi<m;pi++){
        if(v[actRow][pi] == 0){
            for(int j=actRow+1;j<n;j++){
                if(v[j][pi] != 0){
                    swap(v[actRow], v[j]);
                    break;
                }
            }
        }
        if(v[actRow][pi] == 0){ 
            // x_{pi} is don't care
            for(int j=0;j<actRow;j++){
                v[j][pi] = 0;
            }
            continue;
        }
        
        long long div = v[actRow][pi];
        divdRow(v[actRow], div);

        for(int j=actRow+1;j<n;j++){
            long long mul = v[j][pi];
            subRow(v[actRow], v[j], mul);
        }

        actRow++;
    }

    // x_pi~x_m don't care
    for(int k=0;k<n;k++){
        for(int j=pi;j<m;j++){
            v[k][j] = 0;
        }
    }
    
    // check for no solution
    for(int i=actRow;i<n;i++){
        bool all_zero = true;
        for(int j=0;j<m;j++){
            if(v[i][j] != 0){
                all_zero = false;
                break;
            }
        }
        if(all_zero && v[i].back() != 0){
            return false;
        }
    }

    // Jordan
    for(int i=actRow-1, pi=m-1;i>=0&&pi>=0;pi--){
        if(v[i][pi] == 0) {
            continue;
        }
        for(int j=0;j<i;j++){
            subRow(v[i], v[j], v[j][pi]);
        }
        ans[pi] = v[i].back();
        i--;
    }
    return true;
}
