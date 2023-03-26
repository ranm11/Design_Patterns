#include<iostream>
#include "subject.h"
#include "observer.h"


void main()
{
    std::shared_ptr<ObserverA> obs_a = std::make_shared<ObserverA>();
    std::shared_ptr<subjectA>  subject_a = std::make_shared<subjectA>(obs_a);
    std::shared_ptr<subjectB>  subject_b = std::make_shared<subjectB>(obs_a);
    obs_a->NotifyAll();

}