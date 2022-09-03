//check tow line segment is intersection or not
//O(1)


#include <complex>
typedef long long C;
typedef complex<C> P;
#define x real()
#define y imag()

int point_location_test(P p1, P p2, P p3){
    // check the location of p3 is on the (LEFT/RIGHT/TOUCH) of the line
    if(p1 == p2){
        //no line found
    }
    P u = p2 - p1;
    P v = p3 - p1;
    long long cross_product = (conj(u) * v).y;
    if(cross_product == 0){
        //cout<<"TOUCH\n";
        return 0;
    }else if(cross_product > 0){
        //cout<<"LEFT\n";
        return 1;
    }else{
       // cout<<"RIGHT\n";
        return -1;
    }
}


bool on_segment(P a, P b, P c){
    // c is on the segment or not
    // a, b, c are located on  the same line
    if(a.x > b.x)   swap(a, b);
    if(a.x <= c.x && c.x <= b.x &&\
            min(a.y, b.y) <= c.y && c.y <= max(a.y, b.y)){
        return true;
    }
    return false;
}

bool line_segment_intersection(P a, P b, P c, P d){
    int o1 = point_location_test(a, b, c);
    int o2 = point_location_test(a, b, d);
    int o3 = point_location_test(c, d, a);
    int o4 = point_location_test(c, d, b);
    
    if(o1 != o2 && o3 != o4){return true;}
    if(o1 == 0 && on_segment(a, b, c)){return true;}
    if(o2 == 0 && on_segment(a, b, d)){return true;}
    if(o3 == 0 && on_segment(c, d, a)){return true;}
    if(o4 == 0 && on_segment(c, d, b)){return true;}
    return false;
}

