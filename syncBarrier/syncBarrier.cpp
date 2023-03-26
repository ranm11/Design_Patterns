#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>
#include<vector>

class A
{
   private:
   std::condition_variable & cv_A;
   std::mutex & mtx_A;
   int & value_to_inc;
   static int thread_counter;
   public:
   static int NOF_threads;
   A(int & val,std::condition_variable & cv, std::mutex & mtx);
   void run(int threadID);
};
int A::NOF_threads = 9;
int A::thread_counter = 0;

A::A(int & val , std::condition_variable & cv,std::mutex & mtx):value_to_inc(val),cv_A(cv),mtx_A(mtx){}

//every iteration  - every thread execute run once and wait  - last one  notify all for next iteration

void A::run(int threadId)
{
   std::unique_lock<std::mutex> lck(mtx_A);
   
   thread_counter++;
   std::cout<<"thread Number "<<threadId<<" counter is "<<thread_counter<<std::endl;
   if(NOF_threads==thread_counter + 1)
   {
      std::cout<<"reached final thread"<<std::endl;
      //lck.unlock(); // last thread didnt execut wait - thus its mutex still locked. 
      cv_A.notify_all();
   }else{
      cv_A.wait(lck);
       std::cout<<"released thread "<<threadId<<std::endl;
   }
   
}

int main(int argc, char *argv[])
{
   std::condition_variable cv;
   std::mutex mtx;
   int value_to_increment(0);
   constexpr int NOF_Threads = 9;
   std::vector<std::shared_ptr<A> > vec_a;
   std::thread th_[NOF_Threads];
   for (int i=0; i < NOF_Threads; i++)
   {
      std::shared_ptr<A> a = std::make_shared<A>(value_to_increment,cv,mtx);
      vec_a.push_back(a);
      th_[i]=std::thread(&A::run,a.get(),i );
   }
   for (int i=0; i < NOF_Threads; i++)
   {
      th_[i].join();
   }

   return 0;
}

//mutex & condition _variable - can be delivered as static or via arguments
//std::thread th_A(&A::func,a.get(),arg);
//or
// th[i] = std::thread(&A::func,a.get(),arg)
// sync primitives:
// mutex
// conditin var
// notify one ( pthread cond signal)
// notify all (pthread cond broadcast)
// cv.wait() ( pthread_cond_wait()) - release mutex and wait for condition signal 