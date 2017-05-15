# include <iostream>
# include <math.h>

// delcare WrapperClass early
// this is needed for use in typedef and saved owner pointers
class WrapperClass;

// syntax for defining function pointer type:
// typedef void (*functionPtr)(int);
// functionPtr would be the type. using it requires passing int with no return
// functionPtr(14); // using the function pointer

// define the method pointer
typedef void (WrapperClass::*methodPtr)(int);

class MemberClass
{
public:

  // saved callback method pointer for use elsewhere
  // saved WrapperClass instantiation pointer
  methodPtr     saved_method_;
  WrapperClass* saved_owner_;

  void process_stuff();
  void add_handler(WrapperClass* owner, methodPtr method)
  {
    // update the saved pointers
    saved_owner_  = owner;
    saved_method_ = method;

    // display success
    std::cout << "handler added inside core" << std::endl;

    // pretend the event just occured
    (saved_owner_->*saved_method_)(15);
  }
};


class WrapperClass
{
public:
  WrapperClass();
  void set_var(int x);
  void print_var();
  void callback(int x);
  MemberClass core_;
private:
  int private_x;
};