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


shared_ptr<Iprototype> prototypeA::clone()
{
    cout<<"cloning A"<<endl;
    return  make_shared<prototypeA>(*this);
}

shared_ptr<Iprototype> prototypeB::clone()
{
    cout<<"cloning B"<<endl;
    return  make_shared<prototypeB>(*this);
}