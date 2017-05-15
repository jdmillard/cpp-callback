# include <iostream>
# include <math.h>


// syntax for defining function pointer type:
// typedef void (*functionPtr)(int);
// functionPtr would be the type. using it requires passing int with no return
// functionPtr(14); // using the function pointer


// forward declare WrapperClass for use in typedef and saved owner pointers
class WrapperClass;

// define the method pointer (similar syntax to function pointer above)
typedef void (WrapperClass::*methodPtr)(int);


// declare MemberClass first so core_ can be instantiated using a complete type
class MemberClass
{
public:
  void process_stuff();
  void add_handler(WrapperClass* owner, methodPtr method);
  methodPtr     saved_method_;  // saved callback method pointer
  WrapperClass* saved_owner_;   // saved WrapperClass instantiation pointer
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
  int x_val_;
};