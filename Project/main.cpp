#include <iostream> 
#include <string>
#include <map>
#include <SFML/Graphics.hpp>

/*static std::map<char, int> toint{
  {'A', 0},
  {'B', 1},
  {'C', 2},
  {'D', 3},
  {'E', 4},
  {'F', 5},
  {'G', 6},
  {'H', 7}
};*/
/*
class Piece{
  private:
    unsigned short x = 0;
    unsigned short y =0;
  public:
    unsigned short get_pts(){return 0;}
    bool can_move(unsigned short h, unsigned short v){return false;}
    bool can_eat(unsigned short h, unsigned short v) {return can_move(h, v);}
};

class King final : public Piece{
  public:
    unsigned short get_pts()  {return 0;}
    bool can_move(unsigned short h, unsigned short v) {
      if(h==0 and v==0) return false;
      if(abs(h)<=1 and abs(v)<=1) return true;
      return false;
    }
};

class Queen final : public Piece{
  public:
    unsigned short get_pts() {return 9;}
    bool can_move(unsigned short h, unsigned short v) {
      if(h==0 and v==0) return false;
      if(h==0) return true;
      if(v==0) return true;
      if(abs(h)==abs(v)) return true;
      return false;
    }
};

class Knight final : public Piece {
  public:
    unsigned short get_pts()  {return 3;}
    bool can_move(unsigned short h, unsigned short v) {
      if((abs(h)==2) and (abs(v)==1)) return true;
      if((abs(h)==1) and (abs(v)==2)) return true;
      return false;
    }
};

class Bishop final : public Piece{
  public:
    unsigned short get_pts()  {return 3;}
    bool can_move(unsigned short h, unsigned short v) {
        if((h==0) and (v==0)) return false;
        if(abs(h)==abs(v)) return true;
        return false;
      }
};

class Rook final : public Piece{
  public:
    unsigned short get_pts()  {return 5;}
    bool can_move(unsigned short h, unsigned short v) {
        if((h==0) and (v==0)) return false;
        if(h==0) return true;
        if(v==0) return true;
        return false;
    }
};

class Pawn final : public Piece{
  public:
    unsigned short get_pts()  {return 1;}
    bool can_move(unsigned short h, unsigned short v) {
      if((h==1) and (v==0)) return true;
      return false;
    }
    bool can_eat(unsigned short h, unsigned short v) {
      if((h==1) and (abs(v)==1)) return true;
      return false;
    }
};
*/

/*
class Board{
  private:
    Cell data[8][8];
  public:
    void reset(){
      data[0][0] = (Rook(), 0, 0);
    }
    Board(){
      reset();
    }
    void update(string A, string B){

    }
};*/

using namespace sf;

int main()
{
    // create the window
    std::cout<<"started";
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    std::cout<<"opened window";
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        std::cout<<"polled event";
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);
        std::cout<<"cleared window";
        // draw everything here...
        // window.draw(...);

        // end the current frame
        window.display();
        std::cout<<"displayed window";
    }

    return 0;
}
