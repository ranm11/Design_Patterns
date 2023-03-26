#include<iostream>
#include<vector>
//using namespace std;
class Isubject;

/*
   we use an interface as an alternative for static attach function
*/
class IObserver
{
   public:
   //observer();
   virtual void  attach(Isubject*  s) = 0;
   virtual void NotifyAll()=0;
   private:
   //
};

class ObserverA :public IObserver
{
   public:
   ObserverA(){}
   void attach(Isubject *  s) override;
   void NotifyAll() override;
   private:
   std::vector<Isubject* > vec; 
};
