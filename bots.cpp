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

class ermolaeva_right_hand_bot:public pc
{
public:
    ermolaeva_right_hand_bot(field * p, string n):pc(p, n) {}
    virtual void ai()
    {
        direction face=d;
        direction hand=clockwise(d);

        while (can_go(face))
        {
            go(face);
        }
        while (!won())
        {

            for (int i=1; i>0; i=1)
            {
                if (!can_go(face))
                {
                    hand=clockwise(hand);
                    face=clockwise(face);
                }
                else break;
            }
        for (int i=1; i>0; i=1)
            {
                if (can_go(hand))
                {
                    hand=clockwise(hand);
                    face=clockwise(face);
                }
                else break;
            }

        for (int i=1; i>0; i=1)
            {
                if (can_go(face) and !can_go(hand))
                {go(face);}
                else break;
            }
        for (int i=1; i>0; i=1)
            {
                if (!can_go(hand) and !can_go(face))
                {
                    hand=counterclockwise(hand);
                    face=counterclockwise(face);
                }
                else break;
            }
        }
    }
private:
    direction clockwise(direction direction)
    {
        if (direction==x) return z;
        if (direction==z) return a;
        if (direction==a) return w;
        if (direction==w) return e;
        if (direction==e) return d;
        if (direction==d) return x;
    }
direction counterclockwise(direction direction)
    {
        if (direction==x) return d;
        if (direction==z) return x;
        if (direction==a) return z;
        if (direction==w) return a;
        if (direction==e) return w;
        if (direction==d) return e;
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
    bots.push_back(new ermolaeva_right_hand_bot(NULL, "?"));
}

