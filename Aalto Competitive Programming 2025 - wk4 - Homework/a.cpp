// BÀI TẬP
// NỘP BÀI
// BẢNG CHẤM BÀI QMAXC
// CÁC LẦN BẠN NỘP
// QMAXC - Giá trị lớn nhất

// Dữ liệu vào: standard input
// Dữ liệu ra: standard output
// Giới hạn thời gian: 1.0 giây
// Giới hạn bộ nhớ: 128 megabyte
// Đăng bởi: admin

// Cho một dãy gồm n phần tử có giá trị ban đầu bằng 0.

// Cho m phép biến đổi, mỗi phép có dạng (u, v, k): tăng mỗi phần tử từ vị trí u đến vị trí v lên k đơn vị.

// Cho q câu hỏi, mỗi câu có dạng (u, v): cho biết phần tử có giá trị lớn nhất thuộc đoạn [u, v]

// Dữ liệu

// Dòng 1: n, m
// m dòng tiếp theo:
// 0 u v k: Tăng mỗi phần tử từ vị trí u đến vị trí v lên k đơn vị
// 1 u v: Cho biết phần tử có giá trị lớn nhất thuộc đoạn [u, v] 
// Kết quả

// Ghi ra trả lời cho lần lượt từng câu hỏi

// Ví dụ
// Input:

// 6 3
// 0 1 3 3
// 0 4 6 4
// 1 1 6

// Output:

// 4

// Giới hạn

// n, m, q <= 50000
// k > 0
// Giá trị của một phần tử luôn không vượt quá 231-1
#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 2e5 + 1;
long long n, q, t, a, b;
long long f[MAXN];

long long builtTree(long long x, long long l, long long r, long long u, long long v, long long k) {
    if (l > v) return 0;
	if (r < u) return 0;
	if (r < l) return 0;
	
	if((u <= l) && (r <= v)) {
	    f[x] += k;
	    b[x] += k;
	    return 0;
	}
	
	long long mid = (l + r) / 2;
	built_tree(2 * x , l, mid, u, v, k);
    built_tree(2 * x + 1, mid+1, r, u, v, k);
	    
	f[x] = max(f[x * 2],f[2 * x + 1])+ b[x];
}

long long request(long long x, long long l, long long r, long long u, long long v) {
    if(r < u || v < l) return -1e18;
    if(u <= l && r <= v) return f[x];
    long long mid = (l+r) /2;
    
    return max(request(2 * x, l, mid, u, v),request(2 * x + 1, mid+1, r, u, v)) + b[x];
}

void solve() {
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> f[i];
    for(int i = 1; i <= q; i++) {
        cin >> t >> a >> b;
        
        if (t == 1) {
            builtTree(1, 1, n, u, v, k);
        } else {
            cout << request(1, 1, n, u, v) << endl;
        }
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    solve();
 
    return 0;
}