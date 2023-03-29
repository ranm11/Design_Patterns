#include<iostream>
#include"visitor.h"

#pragma once
 
class IComponent {
 public:
  virtual ~IComponent() {}
  virtual void Accept(std::shared_ptr<Visitor> visitor) const = 0;
};


class ConcreteComponentA : public IComponent {
  
 public:
  void Accept(std::shared_ptr<Visitor> visitor) const override {
    visitor->VisitConcreteComponentA(this);
  }
  std::string ExclusiveMethodOfConcreteComponentA() const {
    return "A";
  }
};

class ConcreteComponentB : public IComponent {
 public:
  void Accept(std::shared_ptr<Visitor> visitor) const override {
    visitor->VisitConcreteComponentB(this);
  }
  std::string SpecialMethodOfConcreteComponentB() const {
    return "B";
  }
};
