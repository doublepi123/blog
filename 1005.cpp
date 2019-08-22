#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+10;
int t[MAXN];
int main(){
    ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while(T--){
        long long n,k;
        long long ans = 0;
        cin >> n >> k;
        for(int i = 0 ; i < n ; i++){
            cin >> t[i];
        }
        ans += k;
        sort(t,t+n);
        for(int i = n-1 ; i > 0 ; i--){
            if(t[i] > k)
                ans += t[i];
            else ans += k;
        }
        ans += t[0];
        cout << ans << endl;
    }
}