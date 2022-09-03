//找點在 polygon 的哪個地方
//O(n)


const long long MAX = 1000000009;

int point_in_polygon(vector<P> polygon, P a){
    //input should be a closed the polygon: polygon[0] == polygon.back()
    //polygon is ordered
    //check boundary
    for(int i=1, o;i<int(polygon.size());i++){
        o = point_location_test(polygon[i-1], polygon[i], a);
        if(o == 0 && on_segment(polygon[i-1], polygon[i], a)){
            cout<<"BOUNDARY\n";
            return 0;
        }
    }

    //找一條絕對不會跟頂點撞的射線
    P b = {MAX, a.y + MAX - a.x + 1};
    int cnt = 0;
    for(int i=1;i<int(polygon.size());i++){
        if(line_segment_intersection(polygon[i-1], polygon[i], a, b)){
            cnt++;
        }
    }
    if(cnt % 2 == 0){
        cout<<"OUTSIDE\n";
        return 1;
    }
    cout<<"INSIDE\n";
    return -1;
}

int main(){
    vector<P> polygon;
    int n, m;
    cin>>n>>m;
    for(int i=0, ix, iy;i<n;i++){
        cin>>ix>>iy;
        polygon.emplace_back(ix, iy);
    }
    polygon.emplace_back(polygon[0]);
    P point;
    int ix, iy;
    while(m--){
        cin>>ix>>iy;
        point.real(ix);
        point.imag(iy);
        point_in_polygon2(polygon, point);
    }
    return 0;
}
