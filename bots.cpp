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

<<<<<<< Updated upstream
void fill_bots(vector<pc*> & bots)
{
    bots.push_back(new right_hand_tokarenko_bot(NULL, "!"));
  
=======
class skorodumov_right_hand_bot: public pc
{
public:
    skorodumov_right_hand_bot(field * p, string n):pc(p, n) {}
    direction start_dir()
    {
        /*vector<int> dirs(6,0);

        if(can_go(a))dirs[0]=1;
        if(can_go(w))dirs[1]=1;
        if(can_go(e))dirs[2]=1;
        if(can_go(d))dirs[3]=1;
        if(can_go(x))dirs[4]=1;
        if(can_go(z))dirs[5]=1;
        for(int i(0);i<6;i++){if(dirs[i]==1)set_dir=i;break;}*/
        for (auto i: {direction::a, direction::w, direction::e, direction::d, direction::x, direction::z})
            if (can_go(i)) return i;
    }
    direction hand_d(direction gogo)
    {direction a;
        if(gogo==direction::a)a=direction::w;
        if(gogo==direction::w)a=direction::e;
        if(gogo==direction::e)a=direction::d;
        if(gogo==direction::d)a=direction::x;
        if(gogo==direction::x)a=direction::z;
        if(gogo==direction::z)a=direction::a;
        return a;
    }
    direction left_d(direction gogo)
    {
        direction b;
        if(gogo==direction::a)b=direction::z;
        if(gogo==direction::w)b=direction::a;
        if(gogo==direction::e)b=direction::w;
        if(gogo==direction::d)b=direction::e;
        if(gogo==direction::x)b=direction::d;
        if(gogo==direction::z)b=direction::x;
        return b;
    }
    virtual void ai()
    {

        direction gogo = start_dir();
        direction left = left_d(gogo);
        direction hand = hand_d(gogo);
        while (can_go(gogo)) go(gogo);
        while(!won()){
            while(!can_go(gogo) and !can_go(hand)){gogo=left; hand=hand_d(gogo); left=left_d(gogo);}
            while(can_go(hand)){gogo=hand; hand=hand_d(gogo); left=left_d(gogo);}
            while(can_go(gogo) and !can_go(hand)) go(gogo);
        }

    }
};

class turovceva_bot: public pc
{
public:
    turovceva_bot(field * p, string n):pc(p, n){}
    direction choose_dir(int n,int m)
    {
        direction y=direction::d;
        while(2!=1)
        {   if(can_go(w)){y=direction::w; break;}
            if(can_go(e)){y=direction::e; break;}
            if(can_go(d)){y=direction::d; break;}
            if(can_go(x)){y=direction::x; break;}
            if(can_go(z)){y=direction::z; break;}
            if(can_go(a)){y=direction::a; break;}
        }
        return(y);
    }
    direction right(direction g)
    {
        if(g==a)return w;
        if(g==w)return e;
        if(g==e)return d;
        if(g==d)return x;
        if(g==x)return z;
        if(g==z)return a;
    }
    direction left(direction g)
    {
        if(g==a)return z;
        if(g==w)return a;
        if(g==e)return w;
        if(g==d)return e;
        if(g==x)return d;
        if(g==z)return x;
    }
    virtual void ai()
    {
        direction st=d;

       while(!won())
       {
            if(can_go(right(st)))st=right(st);
            else if(!can_go(st))st=left(st);
            go(st);
       }
    }
};



void fill_bots(vector<pc*> & bots)
{
    //bots.push_back(new skorodumov_right_hand_bot(NULL, "@"));
    //bots.push_back(new right_bot(NULL, ">"));
    //bots.push_back(new panic_bot(NULL, "?"));
   // bots.push_back(new right_hand_tokarenko_bot(NULL, "!"));
    bots.push_back(new turovceva_bot(NULL, "1"));
>>>>>>> Stashed changes
}
