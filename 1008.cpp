#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+10;
int t[MAXN];
queue <int> q;
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
        int now = t[n-1];
        sort(t,t+n);
        int p = n-2;
        while(true){
            if(p < 0 && now == 0&&q.empty()) break;
            while(now > k){
                now -= k;
                q.push(t[p--]);
                ans += k;
            }
            if(p >= 0){
                if(q.empty()){
                    now = 0;
                    q.push(t[p--]);
                    ans += k;
                }
                else{
                    ans += now;
                    now = 0;
                }
            }
            else{
                ans += now;
                now = 0;
            }
            if(now == 0 && !q.empty()){
                now = q.front();
                q.pop();
            }
        }

        cout << ans << endl;
    }
}
