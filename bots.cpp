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

class right_hand_tokarenko_bot:public pc
{
public:
    right_bot(field * p, string n):pc(p, n) {}
    virtual void ai()
    {
        direction face=d;
        direction hand=x;
        while (can_go(face) and !can_go(hand)) go(face);
        hand=clockwise(hand);
        face=

    }
private:
direction clockwise_direction(direction direction q)
    {
        if (q==d) return x;
        if (q==x) return z;
        if (q==z) return a;
        if (q==a) return w;
        if (q==w) return e;
        if (q==e) return d;
    }
direction unclockwise_direction(direction direction q)
    {
        if (q==d) return e;
        if (q==x) return d;
        if (q==z) return x;
        if (q==a) return z;
        if (q==w) return a;
        if (q==e) return w;
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
    bots.push_back(new right_bot(NULL, ">"));
    bots.push_back(new panic_bot(NULL, "?"));
}
