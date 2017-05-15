# include "example.h"


WrapperClass::WrapperClass()
{
  std::cout << "instantiated WrapperClass" << std::endl;

  // x_val_ is a simple private member which is set by the callback
  // arbitrarily initialize its value at 14
  x_val_ = 14;

  // the core_ object is an instantiation of MemberClass
  // create the method pointer to be used by core_
  methodPtr callback_method = &WrapperClass::callback;
  core_.add_handler(this, callback_method);

  // break the "don't do work constructor" rule and do some processing
  core_.process_stuff();
}

void WrapperClass::set_var(int x)
{
  x_val_ = x;
}

void WrapperClass::print_var()
{
  std::cout << x_val_ << std::endl;
}

void WrapperClass::callback(int x)
{
  // callback can be thought of as any other standard function, with the only
  // difference being that a pointer exists elsewhere, which will be used when
  // particular events occur.

  std::cout << std::endl << "callback has been called" << std::endl;

  // update the special value and display
  set_var(pow(x,2));
  print_var();
  std::cout << std::endl;
}


void MemberClass::add_handler(WrapperClass* owner, methodPtr method)
{
  // update the saved pointers
  saved_owner_  = owner;
  saved_method_ = method;

  // display status
  std::cout << "handler added inside core" << std::endl;

  // pretend the event just occurred, provide an arbitrary input of 15
  //(saved_owner_->*saved_method_)(15);
}

void MemberClass::process_stuff()
{
  // pretend to do some sort of computation
  std::cout << "beginning core processing inside MemberClass" << std::endl;

  // when xyz is 5, it is considered a special event for which the callback
  // needs to be executed
  int xyz = 0;
  while (xyz < 10)
  {
    std::cout << xyz << std::endl;
    if (xyz==5)
    {
      // the event has occurred, callback with arbitrary input of 12
      std::cout << "special event has occurred!" << std::endl;
      (saved_owner_->*saved_method_)(12);
    }
    xyz++;
  }
  std::cout << "ending core processing inside MemberClass" << std::endl;
}