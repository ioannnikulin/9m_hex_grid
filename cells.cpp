#include "base.h"
using namespace std;
float pc::dist_to_exit() const
{
    return parent->dist_to_exit(this);
}

bool pc::won() const
{
    return (dist_to_exit() < 2);
}
void pc::go(direction dir) {parent->go(this, dir);}
bool pc::can_go(direction dir) const {return parent->can_go(this, dir);}
