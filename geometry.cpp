typedef complex<gtype> point;
#define x real()
#define y imag()
#define polar(r, t) polar((gtype) (r), (gtype) (t))
bool cmp_point(point const& p1, point const& p2) {
    return p1.x == p2.x ? (p1.y < p2.y) : (p1.x < p2.x);
}
#define deg(a) ( (a) * 180 /pi )
#define rad(a) ( (a) * pi /180 )



// VECTOR
//#define norm(a) dot(a,a) // fast for [long double]
//#define abs(a) sqrt(norm(a)) // fast for [int]
#define arg(a) ( atan2((a).y, (a).x) )
#define unit(v) ( (v) / abs(v) )
#define dot(a, b) ( (conj(a) * (b)).x )
#define crs(a, b) ( (conj(a) * (b)).y )
#define rot(v, t) ( (v) * polar(1, t) )
#define rot2(v, t, o) ( rot((v) - (o), (t)) + (o) )
#define refelct(v, m) ( conj((v) / (m)) * (m) )
#define perp(v) ( point((v).y, -(v).x) )
#define vecVecProj(u, v) ( dot(u, v) * (v) / norm(v) )

// LINE
#define pntLinProj(a, b, p) ( (a) + vecVecProj((p) - (a), (b) - (a)) )
#define pntLinDist(a, b, p) ( abs(crs((b)-(a), (p)-(a)) / abs((b)-(a))) )
#define linIntrN(a, b, p, q) ( crs((p)-(a),(b)-(a)) * (q) - crs((q)-(a),(b)-(a)) * (p) )
#define linIntrD(a, b, p, q) ( crs((p)-(a),(b)-(a)) - crs((q)-(a),(b)-(a)) )
#define linOnLin(a, b, p) ( abs(crs((b) - (a), (p) - (a))) <= epsLen )
#define linOnRay(a, b, p) ( linOnLin(a, b, p) && dot((b) - (a), (p) - (a)) >= -epsLen )
#define linOnSeg(a, b, p) ( linOnRay(b, a, p) && dot((b) - (a), (p) - (a)) >= -epsLen )
#define linInRect(a, b, p, e) ( inRange((a).x, (b).x, (p).x, e) && inRange((a).y, (b).y, (p).y, e) )

// TRIANGLE
#define triPerim(a, b, c) ( (a) + (b) + (c) )
#define triSurface(a, b, c) ( (gtype) 0.5 * crs((b) - (a), (c) - (a)) )
#define triSurfaceH(s, a, b, c) ( sqrt((s) * ((s) - (a)) * ((s) - (b)) * ((s) - (c))) )
#define cosLaw(a, b, c) ( ((a) * (a) + (b) * (b) - (c) * (c)) / (2 * (a) * (b)) )


// CIRCLE
#define cirArcLen(r, a) ((a) * abs(r))
#define cirSectorSurface(r, a) ((a) * norm(r) / 2)
#define cirChordLen(r, a) sqrt(2 * norm(r) * (1 - cos(a)))
int cirCircInter(point & c0, point & c1, gtype r0, gtype r1, vector<point> & out) {
    point cT, v;
    gtype rT, phi;
    // init
    if (r1 > r0)
        rT = r0, r0 = r1, r1 = rT, cT = c0, c0 = point(c1), c1 = point(cT);
    out.clear(), v = c1 - c0, phi = acos(cosLaw(r0, abs(v), r1));
    // same center
    if (equ(abs(v), 0, epsLen))
        equ(r0, r1, epsLen) ? (equ(r0, 0, epsLen) ? out.push_back(c0) : out.resize(3)) : out.clear();
    // none
    else if (abs(abs(v) - r0) > r1 + epsLen)
        out.clear();
    // one point
    else if (equ(abs(abs(v) - r0), r1, epsLen))
        out.push_back(unit(v) * r0 + c0);
    // two points
    else
        out.push_back(rot(unit(v) * r0, -phi) + c0), out.push_back(rot(unit(v) * r0, phi) + c0);
    return out.size();
}

// POLYGON (must be closed, start & end vertex overlap)
#define polAngle(n) (((n) - 2) * pi / (n))
long double polArea(vector<point> & p) {
    long double area = 0;
    for (size_t i = 0; i < p.size() - 1; ++i)
        area += crs(p[i], p[i + 1]);
    return abs(area * 0.5l);
}
bool polIsConvex(vector<point> & p) {
    int a[2] = { 0, 0 }, n = p.size() - 1;
    for (size_t i = 1; i < p.size(); ++i) {
        long double cross = crs(p[i % n] - p[i - 1], p[(i + 1) % n] - p[i - 1]);
        if (cross != 0)
            ++a[cross > 0];
    }
    return !(a[0] && a[1]);
}
