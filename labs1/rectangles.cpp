
#include <iostream>
#include <string>
#include <sstream>

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
    Rectangle(Rectangle const& target): TopRight(target.TopRight){}
    Rectangle(int x, int y): TopRight(x, y){}

    Rectangle operator+ (const Rectangle& rha) const {
        return Rectangle(TopRight.maxx(rha.TopRight).maxy(rha.TopRight));
    }
    Rectangle operator* (const Rectangle& rha) const {
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
        out << '('<<R.TopRight.x<<", "<<R.TopRight.y<<')';
        return out;
    }
};

Rectangle read(std::istream& iss = std::cin){
    std::string a, is, js;
    int i, j;
    getline(iss, a, '(');
    getline(iss, is, ',');
    getline(iss, js, ')');
    i = stoi(is);
    j = stoi(js);
    return Rectangle(i, j);
}

Rectangle solve(std::istream& iss, Rectangle last=Rectangle(0, 0), bool do_read=true){
    char a;
    if(do_read) last = read(iss);
    iss>>a;
    if( a=='*'){
        return solve(iss, last*read(iss), do_read=false);
    }
    else if( a=='+'){
        return last+solve(iss, last);
    }
    else if( a == '\n'){
        return last;
    }
    return last;
}

int main(){
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    std::cout<<"Answer is "<<solve(iss)<<std::endl;
}