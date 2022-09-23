
#include <iostream>
#include <string>

struct Point
{
    unsigned long long  x, y;
    Point(unsigned long long x, unsigned long long y): x(x), y(y){}
    Point minx(Point const &rha) const{
        return Point(rha.x < x ? rha.x : x, y);
    }
    Point miny(Point const &rha) const{
        return Point(x, rha.y < y ? rha.y : y);
    }
    Point maxx(Point const &rha) const{
        return Point(rha.x > x ? rha.x : x, y);
    }
    Point maxy(Point const &rha) const{
        return Point(x, rha.y > y ? rha.y : y);
    }
    void print() const{
        std::cout<< '(' << x << ',' << y << ')';
    }
    void operator= (Point& rha){
        this-> x = rha.x;
        this-> y = rha.y;
    }
};

class Rectangle{
    private:
        Point TopRight;
    public:
    Rectangle(): TopRight(0, 0){}
    Rectangle(Point const& target): TopRight(target){}
    Rectangle(int x, int y): TopRight(x, y){}
    Rectangle operator+ (Rectangle const& rha) const {
        return Rectangle(TopRight.maxx(rha.TopRight).maxy(rha.TopRight));
    }
    Rectangle operator* (Rectangle& rha) const {
        return Rectangle(TopRight.minx(rha.TopRight).miny(rha.TopRight));
    }
    void operator= (Rectangle rha) {
        this-> TopRight = rha.TopRight;
        return;
    }
    void print() const{
        TopRight.print();
    }
    friend std::ostream& operator<<(std::ostream& out, const Rectangle& R ) {
        out << R.TopRight.x<<R.TopRight.y;
        return out;
    }
};

Rectangle read(){
    std::string a, is, js;
    int i, j;
    getline(std::cin, a, '(');
    getline(std::cin, is, ',');
    getline(std::cin, js, ')');
    i = stoi(is);
    j = stoi(js);
    std::cout<<"i've read "<<i<<", "<<j<<'\n';
    return Rectangle(i, j);
}

Rectangle solve(Rectangle last){
    std::string a;
    Rectangle last, next;
    last = read();
    while(std::cin>>a){
        if( a=="*"){
            std::cout<<"i've read *\n";
            next = read();
            last = last*next;
        }
        else if( a=="+"){
            std::cout<<"i've read +\n";
            next = solve();
            last = last+next;
            return last;
        }
        else if( a == "\n"){
            return last;
        }
    }
    return last;
}

int main(){
    Rectangle last = read();
    std::cout<<solve(last);
}