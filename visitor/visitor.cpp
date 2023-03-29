#include "visitor.h"
#include "component.h"
#include<iostream>
#include<string>


// aint it possible to use polymorphism here  for elememt ?
// get Icomponent ?
// modify to shared 
void ConcreteVisitor1::VisitConcreteComponentA(const ConcreteComponentA *element) const 
{
    std::cout<<element->ExclusiveMethodOfConcreteComponentA() << " + ConcreteVisitor1\n";
}

void ConcreteVisitor1::VisitConcreteComponentB(const ConcreteComponentB *element) const  
{
    std::cout<<element->SpecialMethodOfConcreteComponentB()<< " + ConcreteVisitor1\n";
}

void ConcreteVisitor2::VisitConcreteComponentA(const ConcreteComponentA *element) const
{
     std::cout << element->ExclusiveMethodOfConcreteComponentA() << " + ConcreteVisitor2\n";
} 

void ConcreteVisitor2::VisitConcreteComponentB(const ConcreteComponentB *element) const
{
     std::cout << element->SpecialMethodOfConcreteComponentB() << " + ConcreteVisitor2\n";
} 