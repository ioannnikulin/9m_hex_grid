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

class evtukhov_a_star: public pc{
public:
    evtukhov_a_star(field * p, string n):pc(p, n), row(25), col(25){}
    virtual void ai(){
        while(!won()){
            int wall(999);
            int fog(9999);
            vector<vector<int>> field_model(50, vector<int> (50, fog));
            float cur_dist = dist_to_exit();
            field_model[row][col] = cur_dist;
            direction choice = w;
            pair<int,int> choice_coord ({-1,-1});
            choice_coord.first = row + delta(w).first;
            choice_coord.second = col + delta(w).second;
            for (auto i: {direction::w, direction::e, direction::d, direction::x, direction::z, direction::a}){
            pair <int, int> deltas = delta(i);
            if(!can_go(i)) field_model[row+deltas.first][col+deltas.second] =  wall;
            else{
                go(i);
                field_model[row+deltas.first][col+deltas.second] = dist_to_exit();
                if(field_model[row+deltas.first][col+deltas.second] < field_model[choice_coord.first][choice_coord.second]){
                    choice = i;
                    choice_coord.first = row + delta(i).first;
                    choice_coord.second = col + delta(i).second;
                }
                go(counter_trend(i));
            }
        }
        go(choice);
        }
    }
private:
    int row;
    int col;
    pair <int, int> delta(direction dir){
        if(dir == w) return {-1,-row%2};
        if(dir == e) return {-1,1-row%2};
        if(dir == d) return {0,1};
        if(dir == x) return {1,row%2};
        if(dir == z) return {1,row%2-1};
        if(dir == a) return {0,-1};
    }
    direction counter_trend(direction dir){
        if (dir == w) return x;
        if (dir == e) return z;
        if (dir == d) return a;
        if (dir == x) return w;
        if (dir == z) return e;
        if (dir == a) return d;
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

    //bots.push_back(new jenya705::jenya705_bot_starter(NULL));
    //bots.push_back(new right_bot(NULL, ">"));
    //bots.push_back(new panic_bot(NULL, "?"));
    //bots.push_back(new dubovenko_righthand_bot(NULL, "^"));
    //bots.push_back(new skorodumov_right_hand_bot(NULL, "@"));
    //bots.push_back(new sidorova_right_hand_bot(NULL, "<3"));
    //bots.push_back(new ermolaeva_right_hand_bot(NULL, "?"));
    // bots.push_back(new right_hand_tokarenko_bot(NULL, "!"));
   // bots.push_back(new turovceva_bot(NULL, "1"));
   bots.push_back(new evtukhov_a_star(NULL, "$"));
}

