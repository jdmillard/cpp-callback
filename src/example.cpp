# include <example.h>


Wrapper::Wrapper()
{
  std::cout << "instantiated" << std::endl;
  private_x = 14;
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
}
// think of Callback as any other standard function
// but this is the higher level
// when something happens in the "Core" class operations,
// it will be signaled to run


void Core::addHandler(int in_val)
{
    std::cout << in_val << std::endl;
}
