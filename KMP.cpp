#include <bits/stdc++.h>
using namespace std;
string s;
#define ll long long
const int maxn = 2e6+7;
ll kmp[maxn],k;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string a,b;
    cin >> a >> b;
    s = " " + b + '$' + a;
    long n = s.size()-1;
    for(long i = 2; i <= n; ++i){
        while (k > 0 && s[k+1] != s[i]) k = kmp[k];
        kmp[i] = (k += (s[k+1] == s[i]));
    }
    for(long i = b.size()+2; i <= n; ++i)
        if (kmp[i] == b.size())
            cout << i-2*b.size() << " ";
    return 0;
}
//1 2 3 4 5 6 7 8
//a a $ a a a a a

