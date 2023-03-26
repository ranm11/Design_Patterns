#include<iostream>
#include"prototype.h"

using namespace std;

void main()
{
    shared_ptr<Iprototype> prot_a = make_shared<prototypeA>();
    auto cloned_a1 = prot_a->clone();
    auto cloned_a2 = cloned_a1->clone();
    
    shared_ptr<Iprototype> prot_b = make_shared<prototypeB>();
    auto cloned_b1 = prot_b->clone();
    auto cloned_b2 = cloned_b1->clone();
    
}