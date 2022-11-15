#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

class Prototype {
 protected:
  std::string prototype_name_;
  float prototype_field_;

 public:
  Prototype() {printf("Construct this:%p\n",this);}
  Prototype(std::string prototype_name)
      : prototype_name_(prototype_name) {
        printf("Construct this string :%p\n",this);
  }
  virtual ~Prototype() {printf("Destruct this:%p\n",this);}
  virtual Prototype *Clone() const = 0;
  virtual void Method(float prototype_field) {
    this->prototype_field_ = prototype_field;
    std::cout << "Call Method from " << prototype_name_ << " with field : " << prototype_field << std::endl;
  }
};

class ConcretePrototype1 : public Prototype {
 private:
  float concrete_prototype_field1_;

 public:
  ConcretePrototype1(std::string prototype_name, float concrete_prototype_field)
      : Prototype(prototype_name), concrete_prototype_field1_(concrete_prototype_field) {
        printf("Concrete Construct %p\n",this);
  }
  ConcretePrototype1(){}

  /**
   * Notice that Clone method return a Pointer to a new ConcretePrototype1
   * replica. so, the client (who call the clone method) has the responsability
   * to free that memory. I you have smart pointer knowledge you may prefer to
   * use unique_pointer here.
   */
  Prototype *Clone() const override {
    return new ConcretePrototype1(*this);
  }
};

int main(int argc, char* argv[]){

    Prototype * pr1 = new ConcretePrototype1("haohaizi",0.5f);
    Prototype * pr1_clone = pr1->Clone();
    printf("concret this;%p\n",pr1_clone);
    pr1_clone->Method(90);
    delete pr1_clone;

std::cout << std::hash<std::string>{}("123df") <<" " << sizeof(unsigned long long ) << " " << sizeof(uint32_t) << std::endl;
    return 0;
}
