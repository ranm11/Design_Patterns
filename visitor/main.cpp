#include<iostream>
#include "visitor.h"
#include "component.h"
#include<array>

using namespace std;

void ClientCode(std::array<const shared_ptr<IComponent>, 2> components, shared_ptr<Visitor> visitor) {
  // ...
  for (const shared_ptr<IComponent> comp : components) {
    comp->Accept(visitor);
  }
  // ...
}

int main() {
  std::array<const shared_ptr<IComponent>, 2> components = {make_shared<ConcreteComponentA>(), make_shared<ConcreteComponentB>()};
  std::cout << "The client code works with all visitors via the base Visitor interface:\n";
  shared_ptr<ConcreteVisitor1> visitor1 = make_shared<ConcreteVisitor1>();
  ClientCode(components, visitor1);
  std::cout << "\n";
  std::cout << "It allows the same client code to work with different types of visitors:\n";
  shared_ptr<ConcreteVisitor2> visitor2 = make_shared<ConcreteVisitor2>();
  ClientCode(components, visitor2);

  return 0;
}