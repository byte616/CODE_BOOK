// check the location of p3 is on the (LEFT/RIGHT/TOUCH) of the line
//O(1)


const int ON_LINE = 0;
const int LEFT = 1;
const int RIGHT = 2;
 
int point_location_test(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3){
    // check the location of p3 is on the (LEFT/RIGHT/TOUCH) of the line
    if(p1 == p2){
        //no line found
    }
    pair<long long, long long> u = {p2.x - p1.x, p2.y - p1.y};
    pair<long long, long long> v = {p3.x - p1.x, p3.y - p1.y};
    long long cross_product = u.x * v.y - u.y * v.x;
    if(cross_product == 0){
        cout<<"TOUCH\n";
        return ON_LINE;
    }else if(cross_product > 0){
        cout<<"LEFT\n";
        return LEFT;
    }else{
        cout<<"RIGHT\n";
        return RIGHT;
    }
}
