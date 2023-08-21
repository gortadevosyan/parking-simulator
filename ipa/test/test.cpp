#include <iostream>
#include "utils/Utils.h"
using namespace std;

void testRandomFloat();

int main(){
    testRandomFloat();
    return 0;
}

void testRandomFloat(){
    Utils::initRandom();
    for (int i = 0; i < 10; ++i) {
        cout<<Utils::getRandomFloat(-0.1,0.1)<<endl;
    }
}
