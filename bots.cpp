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

class sidorova_right_hand_bot:public pc
{
public:
    sidorova_right_hand_bot(field * p, string n):pc(p, n) {}
    virtual void ai()
    {
        direction face=d;
        direction hand=x;
    while (can_go(face))
        {
            go(face);
        }
    while (!won())
        {

    while (can_go(face) and !can_go(hand))
    {
        go(face);
    }
    while (can_go(hand))
    {
        face = clockwise(face);
        hand = clockwise(hand);
    }
    while(!can_go(face) and !can_go(hand))
    {
        face = backwards_clockwise(face);
        hand = backwards_clockwise(hand);
    }

    }
    }


private:

    direction clockwise(direction o)
    {
    if (o==a) return w;
    if (o==w) return e;
    if (o==e) return d;
    if (o==d) return x;
    if (o==x) return z;
    if (o==z) return a;
    }
    direction backwards_clockwise(direction o)
    {
    if (o==a) return z;
    if (o==w) return a;
    if (o==e) return w;
    if (o==d) return e;
    if (o==x) return d;
    if (o==z) return x;
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

class right_hand_tokarenko_bot:public pc
{
public:
    right_hand_tokarenko_bot(field * p, string n):pc(p, n) {}
    virtual void ai()
{
        direction face=d;
        direction hand=x;
        while (can_go(face)) go(face);
while (!won())
{
        while (!can_go(face))
        {
           hand=clockwise(hand);
           face=clockwise(face);
        }
        while (can_go(face) and !can_go(hand)) go(face);
        while (can_go(hand))
        {
           hand=clockwise(hand);
           face=clockwise(face);
        }
        while (!can_go(hand) and !can_go(face))
        {
           hand=counter_clockwise(hand);
           face=counter_clockwise(face);
        }
}
}
private:
direction clockwise(direction q)
    {
        if (q==d) return x;
        if (q==x) return z;
        if (q==z) return a;
        if (q==a) return w;
        if (q==w) return e;
        if (q==e) return d;
    }
direction counter_clockwise(direction q)
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

    bots.push_back(new sidorova_right_hand_bot(NULL, "<3"));
//bots.push_back(new ermolaeva_right_hand_bot(NULL, "?"));

    //bots.push_back(new right_bot(NULL, ">"));
    //bots.push_back(new panic_bot(NULL, "?"));
	//bots.push_back(new right_hand_tokarenko_bot(NULL, "!"));

}

