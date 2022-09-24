# 1. Faster()

```cpp
ios_base::sync_with_stdio(false); cin.tie(NULL);
```

# 2. Số ước của n

- Giả sử n =
$ a^i.b^j.c^z.... $
thì số ước của n là
$ (i+1)(j+1)(z+1)... $
# 3. Tổng các ước của n
- Giả sử n =
$ a^i . b^j . c^z....$
thì tổng các ước của n là
$ \frac{a^{i+1}-1}{a-1}.\frac{b^{j+1}-1}{b-1}.\frac{c^{z+1}-1}{c-1}... $
# 4. Dãy số Catalan

- Công thức: 
$ \frac{1}{n+1}.C_{2n}^n = \frac{(2n)!}{n!(n+1)!} (n \ge 0) $

- Ứng dụng:
    + Có bao nhiêu cách khác nhau để đặt n dấu mở ngoặc đóng và n dấu ngoặc đóng đúng đắn.
    + Có bao nhiêu cây nhị phân khác nhau có (n+1) lá.
    + Cho một đa giác lồi (n+2) đỉnh, ta chia đa giác thành các tam giác bằng cách vẽ các đường chéo không cắt nhau trong đa giác. Hỏi có bao nhiêu cách chia như vậy.

# 5. Phi hàm Euler

- Giả sử n =
$ a^i . b^j . c^z....$
- Gọi
$ \phi(n) $
là số lượng các số nguyên dương nhỏ hơn n nguyên tố cùng nhau với n. Ta có:
$ \phi(n) = n.(1-\frac{1}{a}).(1-\frac{1}{b}).(1-\frac{1}{c})...$

# 6. Thuật toán Euclid mở rộng

- Ta luôn có 
$ GCD(a,b) = a.x + b.y $

- Tìm x, y:

```cpp
int a,b,d,x,y;

// d là gcd

void extendedEuclid(int a,int b) {
    if (!b){
        d=a;
        x=1;
        y=0;
    }
    else{
        extendedEuclid(b,a%b);
        int tmp=x;
        x=y;
        y=tmp-(a/b)*y;
    }
}
```


# 7. Nghịch đảo Modulo

- Số x là số nghịch đảo modulo m của a khi 
$ a.m \equiv 1 (mod m) (x = a^{-1})$
- Nếu
$ GCD(a,m) = 1$
thì
    - $ a^{-1} = x $
    trong Euclid mở rộng của a và m.
    - $ a^{-1} = a^{\phi(m)-1} mod m$
    - Nếu m là số nguyên tố thì
    - $ a^{-1} = a^{m-2} mod m$


# 8. Nhân Modulo và Luỹ thừa Modulo

```cpp
ll multi(ll a,ll b, ll c){
    if (!b) return 0;
    ll d=multi(a,b/2,c);
    d=(d*2)%c;
    if (b&1) return (d+a)%c;
    return d;
}

ll pow(ll a,ll b, ll c){
    if (!b) return 1;
    ll d=pow(a,b/2,c);
    d=multi(d,d,c);
    if (b&1) return (d*a)%c;
    return d;
}
```

# 9. So sánh 2 số nguyên dương lớn

```cpp
int cmp(string s1,string s2){
    while(s1.size()<s2.size()) s1='0'+s1;
    while(s1.size()>s2.size()) s2='0'+s2;
    if (s1<s2) return -1;
    if (s1==s2) return 0;
    return 1;
}
```

# 10. Cộng 2 số nguyên dương lớn

```cpp
string add(string s1,string s2){
    while(s1.size()<s2.size()) s1='0'+s1;
    while(s1.size()>s2.size()) s2='0'+s2;
    string s="";
    int a,b=0;
    ford(i,s1.size()-1,0){
        a=s1[i]+s2[i]-'0'*2+b;
        s=char(a%10+'0')+s;
        b=a/10;
    }
    if (b) s="1"+s;
    while(s.size()>1&&s[0]=='0') s.erase(0,1);
    return s;
}
```

# 11. Trừ 2 số nguyên dương lớn

```cpp
string sub(string s1,string s2){
    while(s1.size()<s2.size()) s1='0'+s1;
    while(s1.size()>s2.size()) s2='0'+s2;
    string s="";
    int a,b=0;
    ford(i,s1.size()-1,0){
        a=s1[i]-s2[i]-b;
        if (a<0){
            a+=10;
            b=1;
        }
        else b=0;
        s=char(a+'0')+s;
    }
    while(s.size()>1&&s[0]=='0') s.erase(0,1);
    return s;
}
```

# 12. Nhân 2 số nguyên dương lớn

```cpp
string multi(string s1,string s2){
    int n1=s1.size();
    int n2=s2.size();
    vector<int> a(n1+n2,0);
    foru(i,0,n1-1)
        foru(j,0,n2-1) a[i+j]+=(s1[i]-'0')*(s2[j]-'0');
    string s="";
    int b=0;
    ford(i,n1+n2-2,0){
        a[i]+=b;
        s=char(a[i]%10+'0')+s;
        b=a[i]/10;
    }
    if (b>0) s=char(b+'0')+s;
    while(s[0]=='0'&&s.size()>1) s.erase(0,1);
    return s;
}
```

# 13. Chia phần nguyên 2 số nguyên dương lớn

```cpp
string div(string s1,string s2){
    string a[10];
    a[0]="0";
    foru(i,1,10) a[i]=add(a[i-1],s2);
    string tmp="",s="";
    int b;
    foru(i,0,s1.size()-1){
        tmp+=s1[i];
        b=1;
        while(cmp(tmp,a[b])>-1) b++;
        b--;
        s+=char(b+'0');
        tmp=sub(tmp,a[b]);
    }
    while(s[0]=='0'&&s.size()>1) s.erase(0,1);
    return s;
}
```

# 14. Chia phần dư 2 số nguyên dương lớn

```cpp
string mod(string s1,string s2){
    string a[10];
    a[0]="0";
    foru(i,1,10) a[i]=add(a[i-1],s2);
    string s="";
    int b;
    foru(i,0,s1.size()-1){
        s+=s1[i];
        b=1;
        while(cmp(s,a[b])>-1) b++;
        b--;
        s=sub(s,a[b]);
    }
    while(s[0]=='0'&&s.size()>1) s.erase(0,1);
    return s;
}
```

# 15. Tìm số fibo thứ n bằng ma trận

```cpp
#include<bits/stdc++.h>
using namespace std;
 
#define foru(i,a,b) for(int i=a;i<=b;++i)
#define ford(i,b,a) for(int i=b;i>=a;--i)
#define ii pair<int,int>
#define ll long long
#define fi first
#define se second
#define fill(a,b) memset(a,b,sizeof(a))
 
const int du=1e9+7;
struct mtx{
    ll a[2][2]={0,1,
                1,1};
};
int t,n;
 
mtx operator * (mtx x,mtx y){
    mtx ans;
    foru(i,0,1)
        foru(j,0,1){
            ans.a[i][j]=0;
            foru(z,0,1) ans.a[i][j]=(ans.a[i][j]+x.a[i][z]*y.a[z][j]%du)%du;
        }
    return ans;
}
 
mtx pow(mtx x,int k){
    if (k==1) return x;
    mtx b=pow(x,k/2);
    b=b*b;
    if (k&1) return b*x;
    return b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    mtx x;
    x=pow(x,n);
    cout << x.a[0][1] << "\n";
}
```

# 16. Sàng số nguyên tố trên đoạn [l;r]

```cpp
vector<bool> isPrime(r-l+1,true);

void sieve(){
    for(ll i=2;i*i<=r;++i)
        for(ll j=max(i*i,(L+i-1)/i*i);j<=r;j+=i) isPrime[j-l]=false;
    if (1>=l) isPrime[1-l]=false;
}

for (ll i=l;i<=r;++i) {
    if (isPrime[i-l]){
        // i là số nguyên tố
    }
}
```

# 17. Hash

```cpp
#include<bits/stdc++.h>
using namespace std;

#define foru(i,a,b) for(int i=a;i<=b;++i)
#define ford(i,b,a) for(int i=b;i>=a;--i)
#define ii pair<int,int>
#define ll long long
#define fi first
#define se second
#define fill(a,b) memset(a,b,sizeof(a))

const int N=1e5+5;
const ll du=1e9+7;
const ll base=31;
int n;
ll a[N],pw[N];
string s;

ll get(int i,int j){
    return (a[j]-a[i-1]*pw[j-i+1]+du*du)%du;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    n=s.size();
    s=" "+s;
    pw[0]=1;
    foru(i,1,n){
        pw[i]=(pw[i-1]*base)%du;
        a[i]=(a[i-1]*base+s[i]-'0'+1)%du;
    }
}
```

# 18. Mảng cộng dồn 2 chiều

```cpp
#include<bits/stdc++.h>
using namespace std;

#define foru(i,a,b) for(int i=a;i<=b;++i)
#define ford(i,b,a) for(int i=b;i>=a;--i)
#define ii pair<int,int>
#define ll long long
#define fi first
#define se second
#define fill(a,b) memset(a,b,sizeof(a))

const int N=1005;
int n,m,a[N][N],b[N][N];

int get(int x1,int y1,int x2,int y2){
    return b[x2][y2]-b[x1-1][y2]-b[x2][y1-1]+b[x1-1][y1-1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    foru(i,1,n)
        foru(j,1,m){
            cin >> a[i][j];
            b[i][j]=a[i][j]+b[i][j-1]+b[i-1][j]-b[i-1][j-1];
        }
}
```

# 19. Deque min max trên đoạn tịnh tiến

```cpp
#include<bits/stdc++.h>
using namespace std;

#define foru(i,a,b) for(int i=a;i<=b;++i)
#define ford(i,b,a) for(int i=b;i>=a;--i)
#define ii pair<int,int>
#define ll long long
#define fi first
#define se second
#define fill(a,b) memset(a,b,sizeof(a))

const int N=1e7+5;
int n,k,a[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    foru(i,1,n) cin >> a[i];
    deque<int> dq;
    foru(i,1,n){
        while(!dq.empty()&&a[dq.back()]<=a[i]) dq.pop_back();
        // max <=
        // min >=
        dq.push_back(i);
        if (dq.front()+k<=i) dq.pop_front();
        if (i>=k) cout << a[dq.front()] << " ";
    }
}
```

# 20. Bán dừa (Stack left right)

```cpp
#include<bits/stdc++.h>
using namespace std;
 
#define foru(i,a,b) for(int i=a;i<=b;++i)
#define ford(i,b,a) for(int i=b;i>=a;--i)
#define ii pair<int,int>
#define ll long long
#define fi first
#define se second
#define fill(a,b) memset(a,b,sizeof(a))
 
const int N=1e6+5;
int n,a[N],l[N],r[N],ans;
stack<int> b;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    foru(i,1,n) cin >> a[i];
    foru(i,1,n){
        while(!b.empty()&&a[i]<=a[b.top()]) b.pop();
        if (b.empty()) l[i]=1;
        else l[i]=b.top()+1;
        b.push(i);
    }
    b=stack<int>{};
    ford(i,n,1){
        while(!b.empty()&&a[i]<=a[b.top()]) b.pop();
        if (b.empty()) r[i]=n;
        else r[i]=b.top()-1;
        b.push(i);
    }
    ans=0;
    foru(i,1,n)
        if (r[i]-l[i]+1>=a[i]) ans=max(ans,a[i]);
    cout << ans;
}
```

# 20. Dijkstras

```cpp
const ll M = 1e9+7;
 
vector<pair<int,int>> a[10005];
 
int d[10005];
int st,en;
bool kt = false;
 
 
void dijkstra(int x){
    d[x] = 0;
    priority_queue<pii,vector<pii>,greater<pii>> Q;
    Q.push({d[x],x});
    while (Q.size()){
        pii x = Q.top(); Q.pop();
        int u = x.se;
        int val = x.fi;
        if (u == en) kt= true;
        if (val > d[u]) continue;
        for (pii it : a[u]){
            int v = it.fi;
            int w = it.se;
            if (d[v] > max(w,d[u])) {
                d[v] = max(w,d[u]);
                Q.push({d[v],v});
            }
        }
    }
}
 
void solve(){
    int V,E;
    cin >> V >> E;
    cin >> st >> en;
    for (int i=0;i<E;i++){
        int x,y,z;
        cin >> x >> y >> z;
        a[x].push_back({y,z});
        a[y].push_back({x,z});
    }
    for (int i=0;i<10005;i++) d[i] = 1e9;
    dijkstra(st);
    if (!kt) cout << -1;
    else cout << d[en];
}
```
