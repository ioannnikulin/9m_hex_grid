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
class karpov_star_bot:public pc
{
public:
    karpov_star_bot(field * p, string n):pc(p, n) {}

    virtual void ai()
    {
            vector<vector<float> > map1(11,vector<float>(11,fog));
            vector<pair<int,int> > vozm;

    int x(5),y(5);
        while(!won()){
            direction ld=w;
            float dist=dist_to_exit();
            map1[y][x]=dist;
        for (auto i: {direction::w, direction::e, direction::d, direction::x, direction::z, direction::a})
        {
            bool cg = can_go(i);
            int deltay=dy(i,y),deltax(i,x,y);
            if(cg and map1[deltay][deltax]==fog){
                go(i);
                map1[deltay][deltax]=dist_to_exit();
                if(map1[vozm[vozm.end()][0]]vozm[vozm.end()][1]]}>map1[deltay][deltax]){

                vozm.push_back({deltay,deltax});
                }

            if(dist_to_exit()<dist){
                    ld=i;
                    dist=dist_to_exit();
                }
                go(raz(i));
            }
            if(!can_go(i)){
            map1[deltay][deltax]=wall;
            }
            show(map1,x,y);
        }
        x=dx(ld,x,y);
        y=dy(ld,y);
        go(ld);

        }
    }
private:
    static const int wall=888;
    static const int fog=999;
void show(vector<vector<float>> a, int x, int y){
for(int i=0;i<a.size();i++){
    for(int j=0;j<a[0].size();j++){
        char s=' ';
        if (i==y and j==x) s = '*';
        else if(a[i][j]==fog){s='F';}
        else if(a[i][j]==wall){s='W';}
        if(i%2==1){cout<<s<<' ';}
        else{cout<<' '<<s;}
    }
    cout<<endl;
}
cout << std::flush;
}
int dx(direction p,int x1,int y){
        if (p==d) return x1+1;
        if (p==a) return x1-1;
        if(y%2==0){
        if (p==x or p==e) return x1+1;
        if (p==z or p==w) return x1;
        }
        if(y%2==1){
        if (p==x or p==e) return x1;
        if (p==z or p==w) return x1-1;
        }
}
int dy(direction p,int y){
if(p==direction::w or p==direction::e) return y-1;
if(p==direction::a or p==direction::d) return y;
if(p==direction::z or p==direction::x) return y+1;
}
direction cw(direction p)
    {
        if (p==d) return x;
        if (p==x) return z;
        if (p==z) return a;
        if (p==a) return w;
        if (p==w) return e;
        if (p==e) return d;
    }
direction raz(direction p)
    {
        if (p==d) return a;
        if (p==x) return w;
        if (p==z) return e;
        if (p==a) return d;
        if (p==w) return x;
        if (p==e) return z;
    }
vector<pair<int,int> > namesto(vector<pair<int,int> > v,vector<vector<float> > m,int x,int y){
                if(map1[vozm[vozm.end()][0]]vozm[vozm.end()][1]]}>map1[deltay][deltax]){

                vozm.push_back({deltay,deltax});
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
    bots.push_back(new karpov_star_bot(NULL, "K"));
}

