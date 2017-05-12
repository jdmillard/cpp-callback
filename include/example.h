# include <iostream>
# include <math.h>

// delcare the Wrapper class for use in typedef and saved owner pointers
class Wrapper;

// syntax for defining function pointer type:
//typedef void (*functionPtr)(int);
// functionPtr(14); // using the function pointer

// define the method pointer
typedef void (Wrapper::*methodPtr)(int);

class Core
{
public:


  // saved callback method pointer
  methodPtr saved_callback_method;

  // saved pointer to the master Wrapper class
  Wrapper* saved_owner;

  void addHandler(Wrapper* owner, methodPtr passed_in_function_pointer)
  {
    saved_owner = owner;
    saved_callback_method = passed_in_function_pointer;

    // pretend the event just occured
    (saved_owner->*saved_callback_method)(13);

    std::cout << "handler added inside core" << std::endl;
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