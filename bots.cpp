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
class karpov_right_hand_bot:public pc
{
public:
    karpov_right_hand_bot(field * p, string n):pc(p, n) {}
    virtual void ai()
    {
    direction nap(d);
    while(!won()){
    if(can_go(cw(nap))){nap=cw(nap);}
    else if(!can_go(nap) and !can_go(cw(nap))){nap=ccw(nap);}
    go(nap);
    }
    }
private:
direction cw(direction p)
    {
        if (p==d){return x;}
        if (p==x){return z;}
        if (p==z){return a;}
        if (p==a){return w;}
        if (p==w){return e;}
        if (p==e){return d;}
    }
direction ccw(direction p)
    {
        if (p==d){return e;}
        if (p==x){return d;}
        if (p==z){return x;}
        if (p==a){return z;}
        if (p==w){return a;}
        if (p==e){return w;}
    }
    };
void fill_bots(vector<pc*> & bots)
{
    //bots.push_back(new right_bot(NULL, ">"));
    //bots.push_back(new panic_bot(NULL, "?"));
    bots.push_back(new karpov_right_hand_bot(NULL, "K"));
}
