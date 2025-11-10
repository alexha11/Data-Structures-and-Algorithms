#include <bits/stdc++.h>
#define MAXSUM 1000001 

using namespace std;

typedef long long ll; 
const ll INF = 1e18;
const int MAXN1 = 1e5 + 1;
const int MAXN2 = 1e5;

struct Point {
    ll x, y;
};

bool checkSegment(Point point1, Point point2, Point point3) {
    return (point1.x >= min(point2.x, point3.x) && point1.x <= max(point2.x, point3.x) &&
            point1.y >= min(point2.y, point3.y) && point1.y <= max(point2.y, point3.y));
}

ll checkCovariant(Point point1, Point point2, Point point3) {
    Point point12;
    point12.x = point2.x - point1.x;
    point12.y = point2.y - point1.y;
    
    Point point13;
    point13.x = point3.x - point1.x;
    point13.y = point3.y - point1.y;
    
    ll val = point12.x *  point13.y - point12.y * point13.x;
    
    return val;
}


bool checkIntersect(Point point1, Point point2, Point point3, Point point4) {
    ll c1 = checkCovariant(point1, point2, point3);
    ll c2 = checkCovariant(point1, point2, point4);
    ll c3 = checkCovariant(point3, point4, point1);
    ll c4 = checkCovariant(point3, point4, point2);
    
    if ((c1 > 0 && c2 < 0 || c1 < 0 && c2 > 0) &&
        (c3 > 0 && c4 < 0 || c3 < 0 && c4 > 0))
        return true;

    if (c1 == 0 && checkSegment(point3, point1, point2)) return true;
    if (c2 == 0 && checkSegment(point4, point1, point2)) return true;
    if (c3 == 0 && checkSegment(point1, point3, point4)) return true;
    if (c4 == 0 && checkSegment(point2, point3, point4)) return true;

    return false;
} 

void solve() {
    ll t; 
    cin >> t; 
   
    while (t--) {
        Point a[5];
        for (int i = 1; i <= 4; i++) cin >> a[i].x >> a[i].y;
        
        checkIntersect(a[1], a[2], a[3], a[4]) ? cout << "YES\n" : cout << "NO\n";
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
