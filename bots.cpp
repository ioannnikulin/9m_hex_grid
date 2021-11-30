#include "base.hpp"
#include "jenya705.hpp"

class right_bot:public pc
{
public:
    right_bot(field * p, string n):pc(p, n) {}
    virtual void ai()
    {
        while (can_go(d)){
            go(d);
        }
    }
};
class evtukhov_right_hand_bot:public pc{
private:
    direction clockwise(direction s){
        return (direction) ((s + 1) % 6);
    }
    direction counterclockwise (direction s){
        return (direction) ((s - 1) % 6);
    }
    direction face=d;
    direction hand = clockwise(face);
    bool perfect_place(){
        if(can_go(face) && !can_go(hand))
            return true;
        else
            return false;
    }
public:
    evtukhov_right_hand_bot(field * p, string n):pc(p, n) {}
    virtual void ai(){
        while(can_go(face))
            go(face);
        while(!won()){
           if (!can_go(face) and can_go(hand)){
            go(hand);
           }
           if(can_go(hand)){
            face = clockwise(face);
            hand = clockwise(hand);
           }
           if(perfect_place())
            go(face);
           if(!can_go(hand) and !can_go(face)){
            face = counterclockwise(face);
            hand = counterclockwise(hand);
          }
        }
    }
};

class panic_bot:public pc
{
public:
    panic_bot(field * p, string n):pc(p, n) {}
    virtual void ai()
    {
        while (!won())
        for (auto i: {direction::w, direction::e, direction::d, direction::x, direction::z, direction::a})
        {
            go(i);
        }
    }
};

void fill_bots(vector<pc*> & bots)
{
    //bots.push_back(new jenya705::jenya705_bot_starter(NULL));
    //bots.push_back(new right_bot(NULL, ">"));
    //bots.push_back(new panic_bot(NULL, "?"));
    bots.push_back(new evtukhov_right_hand_bot(NULL, "e"));
}
