#include <iostream>
#include <vector>
#include <cmath>
#include "base.hpp"
#include <conio.h>

using namespace std;

int main()
{
    vector<field> labyrinths;
    fill_labyrinths(labyrinths);

    vector<pc*> bots;
    fill_bots(bots);

    for (auto bot: bots)
    {
        int passed(0);
        int failed(0);
        for (auto lab: labyrinths)
        {
            lab.place_player(bot);
            #if MODE == SHOW

            system("cls");
            lab.show();
            #endif
            int res = 0;
            try
            {
                bot->ai();
                res=lab.get_steps();
                if (lab.dist_to_exit(bot)>=2) throw std::runtime_error("didn't finish in the right spot");
                #if MODE == SHOW
                cout << "done!" << endl;
                #endif
            }
            catch (const std::exception & e)
            {
                #if MODE == SHOW
                cout << e.what() << endl;
                #endif
                failed++;
            }
            passed+=res;
            #if MODE == SHOW
            getch();
            system("cls");
            #endif
        }
        cout << "passed " << labyrinths.size() - failed << " labyrinths with total of " << passed << " steps" << endl;
        #if MODE == SHOW
        getch();
        #endif
    }
    return 0;
}
