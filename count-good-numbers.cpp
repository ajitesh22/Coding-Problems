//https://leetcode.com/problems/count-good-numbers/
#define mod 1000000007
#define ll long long int
class Solution {
public:
    
    ll binpow(ll a, ll b) {
        ll res = 1;
        while (b > 0) {
            if (b & 1)
                res = (res * a)%mod;
            a = (a * a)%mod;
            b >>= 1;
        }
        return res%mod;
    }
    
    int countGoodNumbers(long long n) {
        ll a = n/2 , b = n/2;
        if(n%2!=0)
            a++;
        
        ll ans = (binpow(5,a)%mod * binpow(4,b)%mod)%mod;
        return ans;
    }
};
