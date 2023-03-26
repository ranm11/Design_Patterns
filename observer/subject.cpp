#include "subject.h"
#include<iostream>
#include"observer.h"

subjectA::subjectA(std::shared_ptr<IObserver> Iobs)
{
   observer = Iobs;
   observer->attach(this);
};

void subjectA::notify()
{
   std::cout<<"call subjectA notify"<<std::endl;
};

subjectB::subjectB(std::shared_ptr<IObserver> Iobs)
{
   observer = Iobs;
   observer->attach(this);
};

void subjectB::notify()
{
   std::cout<<"call subjectB notify"<<std::endl;
};