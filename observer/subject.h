#include <iostream>
//using namespace std;

class IObserver;

class Isubject
{
   public:
   //subject();
   virtual void notify() = 0;
};

class subjectA : public  Isubject
{
   public:
   subjectA(std::shared_ptr<IObserver>);
   void notify() override;
   private:
   std::shared_ptr<IObserver> observer;
};

class subjectB : public Isubject
{
   public:
   subjectB(std::shared_ptr<IObserver>);
   void notify() override;
   private:
   std::shared_ptr<IObserver> observer;

};