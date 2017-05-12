# include <example.h>


int main(int argc, char **argv)
{

  Large object1;
  object1.PrintVar();
  object1.SetVar(3);
  object1.PrintVar();


  std::cout << "terminating" << std::endl;
} // end of main