#include <bits/stdc++.h>

using namespace std;
#define testCases int TestCases; cin >> TestCases; while (TestCases--)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define endl '\n'
#define space ' '
#define Mod (int)(1e9 + 7)
#define not_ ~
#define NO cout << "NO\n"
#define YES cout << "YES\n"
#define new_line cout << "\n"
#define printAns(ans) cout << ans << '\n'
#define cin_cout ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define FILE freopen("input.txt", "r", stdin) , freopen("output.txt", "w", stdout)
typedef long long ll;
#define sizeArray (int)(2e5 + 2)
//const double pi = 3.1415926536;
#define getMid(l, r) ((l) + ((r - l) >> 1));


/// Floor ⌊x⌋ : gives as output the greatest integer less than or equal to x

// 2.4 -> 2
// 2.9 -> 2
// -2.7 -> -3

/// Ceiling ⌈x⌉ : maps x to the least integer greater than or equal to x
// 2.4 -> 3
// 2.9 -> 3
// -2.7 -> -2

// a * b = LCM(a, b) * GCD (a, b)
// LCM(a, b) = (a * b) / GCD(a, b)
// Time Complexity: O(log(min(a,b))
// Auxiliary Space: O(1)
ll GCD(ll a, ll b) {
    while (a > 0 and b > 0) {
        if (a > b) {
            a = a % b;
        } else {
            b = b % a;
        }
    }
    return a == 0 ? b : a;
}

ll LCM(ll a, ll b) {
    return (a * b) / GCD(a, b);
}

int convertBinaryStringToInteger(const string &s) {
    return stoi(s, nullptr, 2);
}

ll mod(ll x) {
    return (x % Mod);
}

int sum(ll x, ll y) {
    return mod(mod(x) + mod(y));
}

int sub(ll x, ll y) {
    return mod(mod(x) - mod(y) + Mod);
}

int multi(ll x, ll y) {
    return mod(mod(x) * mod(y));
}

// Time Complexity: O(n*log(log(n)))
// Auxiliary Space: O(n)
bool sievePrime[(int) 1e6 + 10];
vector<int> primes;

void sieve(int n) {
    for (bool &i : sievePrime) {
        i = true;
    }
    sievePrime[0] = sievePrime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (sievePrime[i]) {
            primes.emplace_back(i);
            for (int j = i * i; j <= n; j += i) {
                sievePrime[j] = false;
            }
        }
    }
}

// Time Complexity:
// x is odd:  O(sqrt(x))
// x is even: O(1)
bool isPrime(int x) {
    if (x == 2) {
        return true;
    }
    if (x < 2 || x % 2 == 0) {
        return false;
    }
    for (int i = 3; i * i <= x; i += 2) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

// Time Complexity: O(log n)
// Auxiliary Space: O(1)
//  x^n
ll power(int x, int n) {
    ll result = 1;
    while (n) {
        if (n & 1) {
            result = result * x;
        }
        x = x * x;
        n >>= 1;
    }
    return result;
}

//  x^n
ll powerWithMod(ll x, ll n) {
    ll result = 1;
    while (n) {
        if (n & 1) {
            result = result * x;
            result = mod(result);
        }
        x = multi(x, x);
        n >>= 1;
    }
    return result;
}

ll modInverse(ll a) {
    return powerWithMod(a, Mod - 2);
}

string intToBinary(ll num) {
    string binary;
    if (num == 0) {
        binary = "0";
    } else {
        while (num > 0) {
            binary += to_string(num % 2);
            num >>= 1;
        }
    }
    reverse(all(binary));
    return binary;
}

template<class Template>
void printArray(Template *array, int length) {
    cout << endl;
    for (int i = 0; i < length; ++i) {
        cout << i << space;
    }
    cout << endl;
    for (int i = 0; i < length; ++i) {
        cout << array[i] << space;
    }
    cout << endl;
}

// ll combinatorics(ll n, ll r) {
//     return multi(multi(fact[n], modInverse(fact[r])), modInverse(fact[n - r]));
// }

bool isPalindrome(const string &s) {
    int l = 0, r = s.length() - 1;
    while (l <= r and s[l] == s[r]) {
        l++;
        r--;
    }
    return l >= r;
}

int dx4[4] = {1, -1, 0, 0};
int dy4[4] = {0, 0, 1, -1};
int dx8[8] = {1, -1, 1, -1, 1, -1, 0, 0};
int dy8[8] = {1, -1, -1, 1, 0, 0, 1, -1};

class Solution {
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
};

/*

# Intuition 🧠 👋 ✅ 🔥
<!-- Describe your first thoughts on how to solve this problem. -->

# Approach 🛤️
<!-- Describe your approach to solving the problem. -->

# Complexity ⏱️
- Time complexity: $$O(n)$$
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity: $$O(n)$$
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
- [My Submission]()
- [Github](https://github.com/Ahmad-Nour-Haidar)
# Code 👨🏻‍💻
```cpp
 * */