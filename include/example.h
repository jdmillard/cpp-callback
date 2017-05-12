# include <iostream>
//# include <functional>
# include <math.h>


class Wrapper
{
public:
  Wrapper();
  void SetVar(int x);
  void PrintVar();
  void Callback(int x);
private:
  int private_x;
};


class Core
{
public:
  void addHandler(int in_val);
  // void addHandler(std::function<void(int)> callback)
  // {
  //   cout << "Handler added..." << endl;
  //   // Let's pretend an event just occured
  //   callback(1);
  // }
};