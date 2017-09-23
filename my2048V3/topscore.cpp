#include "topscore.h"
#include <fstream>

TopScore::TopScore()
{
    std::ifstream fintop;
    fintop.open("top.txt");
    fintop >> this->topscore;
    fintop.close();
}

void TopScore::add(int sc) {
    if (sc > topscore) {
        topscore = sc;
    }
    std::ofstream fouttop;
    fouttop.open("top.txt");
    fouttop << this->topscore;
    fouttop.close();
}
