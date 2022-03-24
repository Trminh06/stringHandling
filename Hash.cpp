#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9+3;
const int Base = 31;
const int maxn = 1e6+1;
string a,b;
ll hashA = 0,hashB[maxn],Pow[maxn],n,m;
ll getHash(long i,long j){
    return (hashB[j]-hashB[i-1]*Pow[j-i+1]+MOD*MOD) % MOD;
}
void prepare(){
    Pow[0] = 1;
    n = a.size();
    m = b.size();
    a = " " + a;
    b = " " + b;
    for(int i = 1; i <= n; ++i)
        hashA = (hashA*Base + a[i]-'a'+1) % MOD;
    for(int i = 1; i <= m; ++i)
        hashB[i] = (hashB[i-1]*Base + b[i]-'a'+1) % MOD;
    for(int i = 1; i <= m; ++i)
        Pow[i] = (Pow[i-1]*Base) % MOD;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> b >> a;
    prepare();
    cout << hashA << "\n";
    for(long i = 1; i <= m; ++i)
        cout << hashB[i] << "\n";
    /*
    cout << "\n";
    cout << hashA << "\n";
    */
    vector <long> ans;
    long cnt = 0;
    for(int i = 1; i <= m-n+1; ++i){
        cout << getHash(i,i+n-1) << "\n";
        if (hashA == getHash(i,i+n-1)){
            //++cnt;
            //ans.push_back(i);
            //cout << i << " ";
        }
    }
    /*
    cout << cnt << "\n";
    for(auto i:ans)
        cout << i << " ";
    */
    return 0;
}
