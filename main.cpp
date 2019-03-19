#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;

    ifstream f("data.in");
    ofstream g("data.out");

#include "Polinom.h"
#include "Pereche.h"

int main()
{
    Pereche per1;

    f>>per1;

    cout<<per1.verificaRadacina(per1);

    return 0;
}
