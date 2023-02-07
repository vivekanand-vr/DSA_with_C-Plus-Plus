#include<bits/stdc++.h>
#define X long long int TTXC=1; cin>>TTXC;
#define F first
#define S second
#define PB push_back
#define MP make_pair
using namespace std;

typedef long long ll;
typedef long double ld;
using namespace std;

void print(int x)
 {


 }

void VV07()
{
    
   int N, P;
    cin >> N >> P;

    vector<int> dp(N + 1, 0), dp2(N + 1, 0);
    dp[1] = dp2[1] = mod_inverse(2);

    int inv2 = mod_inverse(2);
    for (int i = 2; i <= N; i++){
        int y = binpow(P, i - 1);
        y = mod_inverse(y);
        int val = dp[i - 1] + mul(binpow(y, 2), inv2) + mul(y, dp2[i - 1]);
        val %= mod1;
        dp[i] = val;
        dp2[i] = (dp2[i - 1] + mul(y, inv2)) % mod1;
    }
    for (int i = 1; i <= N; i++)
        cout << dp[i] << ' ';
    cout << endl;

}


int main() {
	ios_base::sync_with_stdio(0); 
    cin.tie(0);                   
    cout.tie(0);
	X
	while(TTXC>0)
	{
	VV07();    
	TTXC--;    
	}
	
	return 0;
}