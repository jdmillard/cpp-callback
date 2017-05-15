# include "example.h"


WrapperClass::WrapperClass()
{
  std::cout << "instantiated WrapperClass class" << std::endl;
  private_x = 14;

  // create the method pointer to the callback method
  methodPtr function_pointer_to_pass_in = &WrapperClass::callback;
  core_.add_handler(this, function_pointer_to_pass_in);
  core_.process_stuff();
}

void WrapperClass::set_var(int x)
{
  private_x = x;
}

void WrapperClass::print_var()
{
  std::cout << private_x << std::endl;
}

void WrapperClass::callback(int x)
{
  // do something special
  private_x = pow(x,2);
  std::cout << std::endl << "perform service call" << std::endl;
  print_var();
  std::cout << std::endl;
}
// think of callback as any other standard function
// but this is the higher level
// when something happens in the "MemberClass" class operations,
// it will be signaled to run





void MemberClass::process_stuff()
{
  // lots of processing
  std::cout << "beginning core processing" << std::endl;
  int xyz = 0;
  while (xyz < 10)
  {
    // xyz is a certain value, an "event" occurs
    // and the callback function is called
    std::cout << xyz << std::endl;
    xyz++;
    if (xyz==5)
      (saved_owner_->*saved_method_)(13);

  }
  std::cout << "ending core processing" << std::endl;

}