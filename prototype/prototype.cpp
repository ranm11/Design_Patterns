#include"prototype.h"

using namespace std;

prototypeA::prototypeA(prototypeA & pr_a)
{
    cout<<"call  A copy cot"<<endl;
}

prototypeB::prototypeB( prototypeB & pr_b)
{
    cout<<"call  B copy cot"<<endl;
}


prototypeA::clone()
{
    cout<<"cloning A"<<endl;
    return  new this;
}

prototypeB::clone()
{
    cout<<"cloning B"<<endl;
    return  new this;
}