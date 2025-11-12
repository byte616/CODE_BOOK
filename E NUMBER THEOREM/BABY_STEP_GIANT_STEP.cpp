// solve a^x = b % M
// O(sqrt(M))  
ll Baby_Giant_Step(ll a, ll b, ll M) {
    ll k = 1, add = 0, g;
    while ((g = gcd(a, M)) > 1) {
        if (b == k) return add;
        if (b % g) return -1;
        b /= g, M /= g, add++;
        k = (k * a / g ) % M;
    }
    ll RT = sqrt(M)+1, aRT = fp(a, RT, M);
    unordered_map<ll, ll> mp;
    for (ll i = 0, cur = b; i <= RT; i++) {
        mp[cur] = i;
        cur = (cur * a)%M;
    }
    for (ll i = 1, cur = k; i <= M / RT + 1; i++) {
        cur = (cur * aRT) % M;
        if (mp.find(cur) != mp.end()) return RT * i - mp[cur] + add;
    }
    return -1;
}