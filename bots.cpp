#include "base.hpp"
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
class dubovenko_righthand_bot:public pc
{
private: direction clockwise(direction dir)
{
    if(dir==d)
        return x;
    if(dir==x)
        return z;
    if(dir==z)
        return a;
    if(dir==a)
        return w;
    if(dir==w)
        return e;
    if(dir==e)
        return d;
}
private: direction counterclockwise(direction dir)
{
    if(dir==d)
        return e;
    if(dir==e)
        return w;
    if(dir==w)
        return a;
    if(dir==a)
        return z;
    if(dir==z)
        return x;
    if(dir==x)
        return d;
}
public:
    dubovenko_righthand_bot(field * p, string n):pc(p, n) {}
    virtual void ai()
    {
        direction face=d;
        direction hand=clockwise(face);
        while (can_go(face))
        {
           go(face);
        }
        while (!won())
        {
            /*if(!can_go(face))
            {
                face=clockwise(face);
                hand=clockwise(hand);
            }*/
            while ((can_go(face))and(!can_go(hand)))
            {
                go(face);
            }
            if(can_go(hand))
            {
                face=clockwise(face);
                hand=clockwise(hand);
            }

            if((!can_go(hand))and(!can_go(face)))
            {
                face=counterclockwise(face);
                hand=counterclockwise(hand);
            }
        }
    }
};

void fill_bots(vector<pc*> & bots)
{
    //bots.push_back(new jenya705::jenya705_bot_starter(NULL));
    //bots.push_back(new right_bot(NULL, ">"));
    //bots.push_back(new panic_bot(NULL, "?"));
    bots.push_back(new dubovenko_righthand_bot(NULL, "^"));
}
