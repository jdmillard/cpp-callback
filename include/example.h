# include <iostream>


class Large
{
public:
    Large();
    void SetVar(int x);
    void PrintVar();
private:
    int private_x;
};


class EventHandler
{
public:
    void addHandler(int in_val);

};