# include <iostream>
# include <math.h>


class Core
{
public:

  void* owner_saved;

  template<typename T>
  void addHandler(T* owner)
  {
    std::cout << "handler added inside core" << std::endl;
    std::cout << owner << std::endl;
    //std::cout << in_val << std::endl;
    // pretend the event just occured
    owner_saved = owner;
    owner->Callback(5);
  }




  void Process();

};


class Wrapper
{
public:
  Wrapper();
  void SetVar(int x);
  void PrintVar();
  void Callback(int x);
  Core memberCore;
private:
  int private_x;
};