# include <example.h>


Large::Large()
{
  std::cout << "instantiated" << std::endl;
  private_x = 14;
}

void Large::SetVar(int x)
{
  private_x = x;
}

void Large::PrintVar()
{
  std::cout << private_x << std::endl;
}


void EventHandler::addHandler(int in_val)
{
    std::cout << in_val << std::endl;
}
