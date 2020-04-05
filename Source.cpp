#include <iostream>
#include "Repo.h"
#include "Medikament.h"
#include <vector>
#include <cassert>
using namespace std;
#include<vector>


int main() {
    Repo r;
    Medikament a1(1,0,1, "def"), a2(2,2,2, "dff"), a3(3,2,2, "dnmm");
    r.add_Medikament(a1);
    a1.print();
    r.add_Medikament(a2);
    r.add_Medikament(a3);
    r.delete_Medikament("def",0);
    assert(r.size_medicine() == 2);

    
    
   
    return 0;
   
}