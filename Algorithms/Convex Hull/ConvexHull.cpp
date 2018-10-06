#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct point { 
    double x, y;                       
    point(double u, double v) { 
        x = u; y = v; 
    }
 };  

point pivot(0,0);

double dist2(point A, point B) {
    return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y);
}
void swapPoints(int a, int b, vector<point> &P) {
    point temp = P[a]; 
    P[a] = P[b]; 
    P[b] = temp;
}

bool counterclock(point p, point q, point r) {
  return ( (q.x - p.x) * (r.y - p.y) - (q.y - p.y) * (r.x - p.x) ) > 0; 
}

bool collinear(point p, point q, point r) {
  return fabs( (q.x - p.x) * (r.y - p.y) - (q.y - p.y) * (r.x - p.x) ) < 1e-9; 
}

bool angleCompare(point A, point B) { // Compare points according to pivot
    if (collinear(pivot, A, B)) return dist2(pivot, A) < dist2(pivot, B);
    return (atan2(A.y - pivot.y, A.x - pivot.x) - atan2(B.y - pivot.y, B.x - pivot.x)) < 0; 
}

int findPivot(vector<point> P) { // Pivot should be the lowest/righest point
    int res = 0;
    for (int i = 1; i < P.size(); i++)
        if (P[i].y < P[res].y || (P[i].y == P[res].y && P[i].x > P[res].x)) res = i;
    return res;
}

vector<point> convexHull(vector<point> P) {
    if (P.size() <= 3) return P; 
    
    swapPoints(0, findPivot(P), P); // The first point of the set must be the Pivot
    pivot = P[0];
    sort( ++P.begin(), P.end(), angleCompare); // O(n logn)
    
    vector<point> ch;
    ch.push_back(P[P.size() -1]); // Previus
    ch.push_back(P[0]); // Current
    ch.push_back(P[1]); // Next

    for(int i = 2; i < P.size();) { // Only update i, when ccw - O(n)
        if(counterclock( ch[ch.size() - 2], ch[ch.size() - 1], P[i] )) ch.push_back(P[i++]);
        else ch.pop_back();
    }
    return ch;
}

int main() {
    vector<point> P; 
    P.push_back(point(0,3));
    P.push_back(point(1,1));
    P.push_back(point(2,2));
    P.push_back(point(4,4));
    P.push_back(point(0,0));
    P.push_back(point(1,2));
    P.push_back(point(3,1));
    P.push_back(point(3,3));

    vector<point> ch = convexHull(P);
    for(int i = 0; i < ch.size(); i++)
        cout << "(" << ch[i].x << "," << ch[i].y << ")" << endl;
    return 0;
}
    