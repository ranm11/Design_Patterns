#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>
 

class A
{
   private:
   std::condition_variable & cv_A;
   std::condition_variable & cv_B;
   std::mutex & mtx_A;
   int & value_to_inc;
   public:
   A(int & val,std::condition_variable & cva,std::condition_variable & cvb, std::mutex & mtx);
   void run();
};

class B
{
   private:
   std::condition_variable & cv_B;
   std::condition_variable & cv_A;
   std::mutex & mtx_B;
   int & value_to_inc;
   public:
   B(int & val , std::condition_variable & cva,std::condition_variable & cvb, std::mutex & mtx);
   void run();
};

A::A(int & val , std::condition_variable & cva,std::condition_variable & cvb,std::mutex & mtx):value_to_inc(val),cv_B(cvb),cv_A(cva),mtx_A(mtx){}
B::B(int & val,std::condition_variable & cvb, std::condition_variable & cva,std::mutex & mtx):value_to_inc(val),cv_A(cva),cv_B(cvb),mtx_B(mtx){}

void A::run()
{
   while(true)
   {
     std::unique_lock<std::mutex> lck(mtx_A); 
     std::cout<<"thread A "<<value_to_inc++<<std::endl;
     std::this_thread::sleep_for(std::chrono::milliseconds(100));
     cv_B.notify_one();
     cv_A.wait(lck); 

   }
}

void B::run()
{
   while(true)
   {
      std::unique_lock<std::mutex> lck(mtx_B); 
      cv_B.wait(lck);
      std::cout<<"thread B "<<value_to_inc++<<std::endl;
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
      cv_A.notify_one();
   }
}

int main(int argc, char *argv[])
{
   std::condition_variable cv_A;
   std::condition_variable cv_B;
   std::mutex mtx_A;
   std::mutex mtx_B;
   int value_to_increment(0);
   std::shared_ptr<A> a = std::make_shared<A>(value_to_increment,cv_A,cv_B,mtx_A);
   std::shared_ptr<B> b = std::make_shared<B>(value_to_increment,cv_B,cv_A,mtx_B);
   std::thread th_A(&A::run,a.get());
   std::thread th_B(&B::run,b.get());
   th_A.join();
   th_B.join();
   //std::thread

   return 0;
}

//mutex & condition _variable - can be delivered as static or via arguments
