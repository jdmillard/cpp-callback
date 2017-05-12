# include <example.h>


Wrapper::Wrapper()
{
  std::cout << "instantiated wrapper class" << std::endl;
  private_x = 14;
  memberCore.addHandler(this);
  memberCore.Process();
}

void Wrapper::SetVar(int x)
{
  private_x = x;
}

void Wrapper::PrintVar()
{
  std::cout << private_x << std::endl;
}

void Wrapper::Callback(int x)
{
  // do something special
  private_x = pow(x,2);
  std::cout << std::endl << "perform service call" << std::endl;
  PrintVar();
  std::cout << std::endl;
}
// think of Callback as any other standard function
// but this is the higher level
// when something happens in the "Core" class operations,
// it will be signaled to run





void Core::Process()
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
    // if (xyz==5)
    // {
    //   owner_saved->Callback(10)
    // }
  }
  std::cout << "ending core processing" << std::endl;

}


// void Core::addHandler(T* owner)
// {
//
//   std::cout << "handler added inside core" << std::endl;
//   //std::cout << in_val << std::endl;
//   // pretend the event just occured
//   owner->Callback(555555);
// }

