---
title: Template
date: 2018-03-31 20:17:43
tags: 
    - 模板
top: true
categories: C/C++
description: ICPC模板
---

<!-- # Template -->

## number theory(数论)

### 扩展欧几里得相关

``` C++
// ax + by = gcd(a, b)
LL exgcd(LL a, LL b, LL &x, LL &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    else{
        LL d = exgcd(b, a % b, y, x);
        y -= x * (a / b);
        return d;
    }
}

// ax + by = c
bool linear_equation(LL a, LL b, LL c, LL &x, LL &y){
    LL d = exgcd (a, b, x, y);
    if( c % d )
        return false;
    LL k = c / d;
    x *= k; y *= k;
    return true;
    // 其他解为 x + b / d * t; y - a / d * t; t为任意整数
}

// ax ≡ b (mod n)
bool modular_linear_equation(LL a, LL b, LL n, LL &x, LL &y){
    LL x0, i;
    LL d = exgcd(a, n, x, y);
    if( b % d ) return false;
    x0 = x * ( b / d ) % n;
    for(i = 1; i <= d; i ++)
        printf("%d\n", ( x0 + i * ( n / d ) ) % n );
    return true;
}

// inverse
int inverse(LL a, LL m, LL x, LL y){
    LL d = exgcd(a, m, x, y);
    return (x + m) % m;
}
```

### 勾股数组

取n $\lt$ m且满足(n & 1) ^ (m & 1)为1（这里的^为异或，此表达式说明二者奇偶不同），同时gcd(n, m) = 1（即二者互素），则可得到满足 $a^2 + b^2 = c^2$ 的勾股数组：

$ a = m^2 - n^2 $
$ b = 2 * n * m $
$ c = m^2 + n^2 $

按照顺序枚举满足上述条件（奇偶不同的互素n $\lt$ m二元组（n, m）），就可以得到所有的本源勾股数组，同时它们的整数倍也是勾股数组。这个方法可以取得所有的勾股数组。

### 欧拉线性筛

欧拉线性筛求判断素数和求最小质因子

```C++
// MinFactor[i] = x 表示为i最小质因子为 x
// p[i] = x 表示为第 i+1 个素数为x
// MinFactor 只求素数可换为 bool 类型判断 not_prime
void euler(){
    int t = 0;
    pos = 0;
    for(int i = 2; i < LIM; i ++){
        if ( !MinFactor[i] ) p[pos ++] = MinFactor[i] =  i;
        for(int j = 0; (t = i * p[j]) < LIM; j ++){
            MinFactor[t] = p[j];
            if( !(i % p[j]) ) break;
        }
    }
}
```

### 欧拉函数

phi(i) 意义： 小于 i 且与 i 互质的正整数的个数

1. 打表时间复杂度 O(n)

    ```C++
    void init_phi(){
        int t;
        phi[1] = 1;
        for(int i = 2; i < LIM; i ++){
            if( !phi[i] ){
                phi[i] = i - 1;
                p[cnt ++] = i;
            }
            for(int j = 0; (t = i * p[j]) < LIM; j ++){
                if( i % p[j] ) phi[t] = phi[i] * (p[j] - 1);
                else {
                    phi[t] = phi[i] * p[j];
                    break;
                }
            }
        }
    }
    ```

2. 单个时间复杂度为 O($\sqrt{n}$)

    ```C++
    LL phi(LL n) {  
        LL ret = 1;
        for (LL i = 2; i * i <= n; i++) {
            if (!(n % i)) {
                ret *= i - 1;
                n /= i;
                while (!(n % i))
                    ret *= i, n /= i;
            }
        }
        if (n ^ 1) ret *= (n - 1);
        return ret;
    }
    ```

## Numberical Methods(数值方法)

### 高精度平方根

牛顿逼近法

```java
public static BigDecimal sqrt(BigDecimal b, BigDecimal eps) {
    BigDecimal crt = new BigDecimal(b.toString());
    BigDecimal two = BigDecimal.valueOf(2);
    int scale = eps.scale() + 2;
    Boolean isNegtive = false;
    if (crt.compareTo(BigDecimal.valueOf(0)) < 0) {
        b = b.negate();
        crt = crt.negate();
        isNegtive = true;
    }
    while (true) {
        BigDecimal nxt = crt.subtract(crt.multiply(crt).subtract(b).divide(two.multiply(crt),
            scale, BigDecimal.ROUND_DOWN));
        // test
        // System.out.println(nxt);
        if (nxt.subtract(crt).abs().compareTo(eps) <= 0) {
            crt = nxt;
            break;
        }
        crt = nxt;
    }
    if (isNegtive) {
        b = b.negate();
        crt = crt.negate();
    }
    return crt;
}
public static BigDecimal sqrt(BigDecimal b) {
    BigDecimal eps = new BigDecimal("0.00000000000000000000000001");
    return sqrt(b, eps);
}
public static BigDecimal sqrt(BigInteger b, BigDecimal eps) {
    BigDecimal tmp = new BigDecimal(b.toString());
    return sqrt(tmp, eps);
}
public static BigDecimal sqrt(BigInteger b) {
    BigDecimal tmp = new BigDecimal(b.toString());
    return sqrt(tmp);
}
```

### 快速求幂取模法

```C++
//计算(a*b)%c
long long mul(long long a,long long b,long long mod) {
    long long res = 0;
    while(b > 0){
        if( (b&1) != 0)  // 二进制最低位是1 --> 加上 a的 2^i 倍, 快速幂是乘上a的2^i ）
            res  = ( res + a) % mod;
        a = (a << 1) % mod;    // a = a * 2    a随着b中二进制位数而扩大 每次 扩大两倍。
        b >>= 1;               // b -> b/2     右移  去掉最后一位 因为当前最后一位我们用完了，
    }
    return res;
}

//幂取模函数
long long pow1(long long a,long long n,long long mod){
    long long res = 1;
    while(n > 0){
        if(n&1)
            res = (res * a)%mod;
        a = (a * a)%mod;
        n >>= 1;
    }
    return res;
}


// 计算 ret = (a^n)%mod
long long pow2(long long a,long long n,long long mod) {
    long long res = 1;
    while(n > 0) {
        if(n & 1)
            res = mul(res,a,mod);
        a = mul(a,a,mod);
        n >>= 1;
    }
    return res;
}
```

### 矩阵乘法和快速幂

```C++
struct matrix{
    LL m[10][10];
    matrix(){ memset(m,0,sizeof(m)); }
};
matrix operator * (const matrix & a,const matrix & b){
    matrix c;
    for (int i=1; i<=9; i++)
        for (int j=1; j<=9; j++){
            c.m[i][j]=0;
            for (int k=1; k<=9; k++)
                c.m[i][j]=(c.m[i][j]+a.m[i][k]*b.m[k][j])%mod;//一般题目都要求要modulo一个数
        }
    return c;
}
matrix quick(matrix base,int pow){
    matrix a;
    for (int i=1; i<=9; i++) a.m[i][i]=1;
    while (pow)    {
        if (pow&1) a=a*base;
        base=base*base;
        pow>>=1;
    }
    return a;
}
```

## 组合数学

### Contar康托展开

由一个排列计算它是全排列中的第几个排列的方法。

```C++
int fac[15];
void factor(){
    fac[0] = fac[1] = 1;
    for(int i = 2; i < 13; ++ i)
        fac[i] = fac[i - 1] * i;
}
//逆康托
string uncantor(int x, int k) {
    string res;
    int i, j, l, t;
    bool h[100];
    for (i = 1; i <= k; i++) {
        t = x / fac[k - i];
        x -= t * fac[k - i];
        for (j = 1, l = 0; l <= t; j++)
            if ( !h[j] ) l++;
        j --;
        h[j] = true;
        res += j + '0';
    }
    return res;
}
//康托
int cantor(int* a, int len){
    int ans = 0;
    for(int i = 0; i < len; ++ i){
        int t = 0;
        for(int j = i + 1; j < len; ++j)
            if(a[j] < a[i]) t ++;
        ans += fac[len - i - 1] * t;
    }
    return ans + 1;
}
```

### Catalan Number 卡特兰数

$C_n = \frac{4n - 2}{n + 1} C_{n-1}$

相关问题

1. Cn可以表示长度为2n的Dyck Words的种类数，Dyck Words由n个A字符与n个B字符组成，且满足在任意位置上，前缀中A的数量不小于B的数量，如果A用(代替，把B用)代替，就是一个典型的括号表达式，因此也可以用来表示合法的表达式个数。
2. Cn可以表示有n个结点的不同构的二叉树的种类数。
3. Cn可以表示有2n + 1个结点的不同构的满二叉树的种类数。
4. Cn可以表示在n*n的格点中从左下角延格线走到右上角且始终不超过对角线的方案数。
5. Cn可以表示通过连接顶点将n + 2个顶点的凸多边形划分成三角形的方案数。
6. Cn表示有n个元素的出栈顺序的种类数。
7. Cn可以用在买票找零钱问题上，对于2n的观众，收银台初始没有钱，无法找零，接下来有n个人拿a元买票，n个人拿2a元买票（需要找零钱数为a），能够保证每一个需要找零的观众来的时候都能够得到找零的合法方案数。
8. Cn可以表示在二维直角坐标系中，从(0, 0)走到(2n, 0)点，每个相邻整数点的纵坐标差值的绝对值为1，且点始终不会落到x轴下方的方案数。

## 高精度

### 大数操作BigInteger

```JAVA
import java.math.BigInteger;
import java.util.Scanner;
public class BI {
    public static void main(String[] args) {
        Scanner in = new Scanner (System.in);
        BigInteger a, b;
        a = in.nextBigInteger();
        b = in.nextBigInteger();
        System.out.println(a.add(b));
        System.out.println(a.subtract(b));
        System.out.println(a.multiply(b));
        System.out.println(a.divide(b));
        BigInteger mod = BigInteger.valueOf(3);
        System.out.println(b.mod(mod));
    }
}
```

### 小数操作BigDecimal

```JAVA
import java.math.BigDecimal;
import java.util.*;
public class BD {
    public static void main(String[] args) {
        BigDecimal a = new BigDecimal(10);
        BigDecimal b = new BigDecimal(10.5);
        BigDecimal c = new BigDecimal(123456789101222L);
        BigDecimal d = new BigDecimal("-123456.31");
        System.out.println(a);
        System.out.println(b);
        System.out.println(c);
        System.out.println(d);
        System.out.println(a.add(b).add(c).add(d));
        System.out.println(a.subtract(b).subtract(a));
        System.out.println(a.multiply(b).multiply(c));
        System.out.println(c.divide(a).divide(new BigDecimal(20)));
        System.out.println(d.divide(a));
        System.out.println(d.doubleValue());
        System.out.println(a.compareTo(b));// -1
        System.out.println(a.equals(b));// flase
    }
}
```

### 生成排列

next_permutation() 生成下一个排列
prev_permutation() 生成上一个排列

```C++
do{
    cout << str << endl;
// }while (next_permutation(str.begin(), str.end()));
}while (prev_permutation(str.begin(), str.end()));
```

## Graph 图论

### topu 拓扑排序

```C++
int in[maxn];//存入度数
vector <int > edge[maxn]; //存边

int topu_sort(){
    queue<int>q;
    for (int i = 1; i <= n; i++)
        if (!in[i]) q.push(i); //取出入度为0的点放
    while (!q.empty()){
        int u = q.front(); q.pop();
        for (int i = 0; i < edge[u].size(); i++){ //删边与统计操作
            int v = edge[u][i];
            in[v] --;  //删边
            if ( ! in[v] ) q.push(v);
        }
        printf ("%d ", u);
    }
    for (int i = 1; i <= n; i++) //若存在全部遍历完仍存在入度不为0的点说明存在环
        if (in[i]) return -1;
}
```

### Shortest Path 最短路

#### Dijstra

```C++
typedef pair<int, int> P;
int pre[2501];   // 路径记录
void Dijkstra( int s ){
    priority_queue< P, vector<P>, greater<P> > q;
    fill (d + 1, d + n + 1, INF);
    d[s] = 0;
    q.push(P(0, s));
    while (q.size()){
        P p = q.top(); q.pop();
        int h = p.second;
        if( d[h] < p.first ) continue;
        for(int i = 0; i < v[h].size(); i ++){
            edge e = v[h][i];
            if( d[e.to] > d[h] + e.cost ){
                d[e.to] = d[h] + e.cost;
                q.push(P(d[e.to], e.to));
                pre[e.to] = h;  // 记录前驱
            }
        }
    }
}
```

#### SPFA

从起点到任意一个点最短距离经过的点最多只有 n 个，用 cnt[ i ] 表示从起点（假设就是 1）到 i 的最短距离包含点的个数，初始化 cnt[ 1 ] = 1，那么当我们能够用点 u 松弛点 v 时，当我们能够用点 u 松弛点 v 时，松弛时同时更新 cnt[ v ] = cnt[ u ] + 1，若发现此时 cnt[ v ] > n，那么就存在负环

```C++
bool SPFA( int s ){
    queue<int > q;
    fill(d + 1, d + n + 1, INF);
    d[s] = 0;
    q.push(s);
    vis[s] = 1;
    while ( q.size() ){
        int t = q.front(); q.pop();
        vis[t] = 1;
        for(auto i = v[t].begin(); i != v[t].end(); i ++ ){
            if( i -> cost + d[t] < d[i -> to] ){
                d[i -> to] = i -> cost + d[t];
                // cnt[ i -> to ] = 1 + cnt[t];
                // if(cnt[i -> to] > n ) return false;
                if( !vis[i -> to] )
                    q.push(i -> to);
            }
        }
    }
    return true;
}
```

### MST 最小生成树

#### Kruskal

```C++
void init(){
    for(int i = 1; i <= n; i ++)
        p[i] = i;
}
int find( int x ){
    return x == p[x] ? x : p[x] = find(p[x]);
}
ll Kruskal(){
    ll res = 0;
    sort(E, E + m, cmp);
    init();
    int cnt = 0;
        for (int i = 0; i < m; i ++ ){
        edge e = E[i];
        int x = find(e.from);
        int y = find(e.to);
        if( x != y ){
            p[x] = p[y];
            cnt ++;
            res += (ll) e.cost;
        }
        if( cnt == n - 1 ) break;
    }
    return res;
}
```

#### Prim

```C++
ll Prim(){
    fill (cost + 1, cost + n + 1, INF);
    cost[1] = 0;
    priority_queue <P, vector<P>, greater<P> > q;
    q.push(P(0, 1));
    ll res = 0;
    while ( q.size() && cnt < n ){
        P p = q.top(); q.pop();
        int v = p.second;
        if( !vis[v] ){
            cnt ++;
            vis[v] = 1;
            res += p.first;
            for(int i = 0; i < E[v].size(); i ++){
                edge e = E[v][i];
                if( cost[e.to] > e.cost ){
                    cost[e.to] = e.cost;
                    q.push(P(cost[e.to], e.to));
                }
            }
        }
    }
    return res;
}
```

#### 最大流

```C++
typedef struct node{
    int to, cap, rev;
}edge;

bool vis[101];
vector <edge > G[101];
int dfs(int v, int t, int f){
    if(v == t) return f;
    vis[v] = 1;
    for(int i = 0; i < G[v].size(); i ++){
        edge e = G[v][i];
        if( !vis[e.to] && e.cap > 0 ){
            int d = dfs(e.to, t, min(f, e.cap));
            if( d > 0 ){
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
}

int max_flow(int s, int t){
    int flow = 0;
    while(true){
        memset(vis, 0, sizeof(vis));
        int f = dfs(s, t, INF);
        if( !f ) return flow;
        flow += f;
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    int from, to, s = 0, t = n + m + 1;
    for(int i = 1; i <= m; i ++{
        G[s].push_back({i, 1, G[i].size()});
        G[i].push_back({s, 0, G[s].size() - 1});
    }
    for(int j = m + 1; j <= n + m; j ++){
        G[j].push_back({t, 1, G[t].size()});
        G[t].push_back({j, 0, G[j].size() - 1});
    }
    while ( scanf("%d%d", &from, &to), from != -1){
        G[to].push_back({from, 1, G[from].size()});
        G[from].push_back({to, 0, G[to].size() - 1});
    }
    cout << max_flow(s, t) << endl;
    return 0;
}
```

### 欧拉路和欧拉回路

有向图

```C++
inline void dfs(int x, int lst) {
    register int &i=lnk[x];
    for(;i;i=e[i].nxt){
        if(vis[i]) continue;
        vis[i]=1,dfs(e[i].to,i);
    }
    if(lst) res[++res_]=lst;
}
```

无向图

```C++
inline void dfs(int x,int lst) {
    register int &i=lnk[x];
    for(;i;i=e[i].nxt){
        if(vis[i+1>>1]) continue;
        vis[i+1>>1]=1,dfs(e[i].to,i&1?(i+1>>1):-(i+1>>1));
    }
    if(lst) res[++res_]=lst;
}
```

## Dynamic Programming 动态规划

### LIS 最长上升子序列

```C++
void solve(){
    memset(dp, 0, sizeof(dp));
    int res = 0;
    for(int i = 0; i < n; i ++){
        dp[i] = 1;
        for(int j = 0; j < i; j ++)
            if( a[j] < a[i] )
                dp[i] = max (dp[i], dp[j] + 1);
        res = max (res, dp[i]);
    }
    printf("%d", res);
}
```

### 数划分

```C++
1.问题描述：
    给定一个正整数N和K

    1. 将n划分成若干正整数之和的划分数。
    2. 将n划分成k个正整数之和的划分数。
    3. 将n划分成最大数不超过k的划分数。
    4. 将n划分成若干奇正整数之和的划分数。
    5. 将n划分成若干不同整数之和的划分数。

2.问题分类：总的来说这些都是背包问题；

第一个问：就是一个完全背包，物品有 1 --- N 种，第 i 种物品的重量为 i ，价值为 i

        dp[0] = 1;
        for (i = 1;i <= N;i++)
            for (j = i;j <= N;j++)
                dp[j] += dp[j-i];

其中 dp[j] 是用前 i 个数能构成 j 的种类数，则结果就为 dp[N]

看完这个问题了，那么 第3个问就知道了 ， 即用前 K 种物品所得结果，
只需把第一层循环的 i <= N 改为 i <= K 即可；

        dp[0] = 1;
        for (i = 1;i <= K;i++)
            for (j = i;j <= N;j++)
                dp[j] += dp[j-i];   结果同样为 dp[N] ;

那么第四个问呢，想想是奇数，那么 i = 2，4，6，…… 等等值就不能取了，
因为这些物品不合要求，这很简单啊  i++ 改为 i += 2 不就行了；

        dp[0] = 1;
        for (i = 1;i <= N;i+=2)
            for (j = i;j <= N;j++)
                dp[j] += dp[j-i];   结果同样为 dp[N] ;

再看看第五个问，若干个不同的就是一种物品最多只能用一次
这是经典的 01背包 啊，与第一个问的不同就是第二层循环的顺序而已；

        dp[0] = 1;
        for (i = 1;i <= N;i++)
            for (j = n;j >= i ;j--)
                dp[j] += dp[j-i];

最后我们来思考第二个问：

   要求只要 K 个，这怎么办呢？？？想想特殊情况…… 如果 K = 1 呢，只能是 N 咯
   若果 N = 0 呢， 结果只能是 0 中可能啊，那同样N < K 的话，不可能分啊 结果为 0
   那么我们再考虑，分的结果中有没有 1 ，如果有那么就把剩下的 N - 1 分成 K - 1 份
   如果没有，那么我们先拿出 K 份给每一堆一个1，再把剩下的 N - K 分成 K 份就行了

        int work(int n,int k){
            if (k == 1) return 1;
            if (n == 0) return 0;
            if (n < k) return 0;
            return work(n-k,k) + work(n-1,k-1);
        }
```

