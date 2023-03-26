#include "subject.h"
#include"observer.h"

void ObserverA::attach(Isubject * Isub)
{
   vec.push_back(Isub);
}

void ObserverA::NotifyAll()
{
   for (auto & sub:vec)
   {
      sub->notify();
   }
}