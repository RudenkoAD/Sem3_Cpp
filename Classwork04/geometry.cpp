#include<iostream>
#include<vector>
#include<cmath>

struct Point {
  double x = 0;
  double y = 0;
  Point():x(0), y(0){}
  Point(double x, double y):x(x), y(y){}
};

struct MPoint: public Point {
  double m = 1;
  MPoint():Point(), m(0){}
  MPoint(double x, double y, double m):Point(x, y), m(m){}
};

// Abstract class
class Shape {
  private:

    double darea(Point a, Point b) const{
      return (b.x-a.x)*(b.y+a.y)/2;
    }

    double dperim(Point a, Point b) const{
      return std::pow(std::pow((a.x - b.x), 2) + std::pow((a.y - b.y), 2), 1/2);
    }

    double init_mass(std::vector<MPoint> src){
      double m=0;
      for(int i=0; i<storage.size(); i++){
        m+=storage[i].m;
      }
      return m;
    }

  protected:
    std::vector<MPoint> storage;
    double mass;

  public:
    Shape():storage(), mass(0){}
    Shape(std::vector<MPoint> src):storage(src){
      mass = init_mass(src);
    }

    double get_mass() const{
      return mass;
    }

    double area() const{
      double store = 0;
      for(int i=1; i<storage.size(); i++){
        store+=darea(storage[i-1], storage[i]);
      }
      return store;
    }

    double perimeter() const{
      double store = 0;
      for(int i=1; i<storage.size(); i++){
        store+=dperim(storage[i-1], storage[i]);
      }
      return store;
    }

    Point center() const{
      double x, y;
      for(int i=0; i<storage.size(); i++){
        x+=storage[i].x*storage[i].m;
        y+=storage[i].y*storage[i].m;
      }
      x/=mass;
      y/=mass;
      return Point(x, y);
    }
};

class Triangle: public Shape {
  Triangle():Shape(){}
  Triangle(MPoint a, MPoint b, MPoint c): Shape(std::vector<MPoint>({a, b, c})){}
};


class Square: public Shape {
  Square():Shape(){}
  Square(MPoint a, MPoint b, MPoint c, MPoint d): Shape(std::vector<MPoint>({a, b, c, d})){}
};

class Line: public Shape {
  Line():Shape(){}
  Line(MPoint a, MPoint b): Shape(std::vector<MPoint>({a, b})){}
};


int main(){

}