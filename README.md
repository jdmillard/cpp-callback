## C++ Callback Example

A basic implementation of a C++ callback function.

### Some Specifics

This example considers the case where a C++ class has a member class that performs various operations. The main class is called `WrapperClass` and the other is called `MemberClass`. The operations of `MemberClass` encounter events that require a callback to a method in `WrapperClass`.

In C++ 11 it is possible to use `std::function` and `std::bind` as seen in [this example](https://stackoverflow.com/questions/14189440/c-class-member-callback-simple-examples/14189561#14189561). However, this repo contains a general solution for all C++ versions. Therefore, the desired callback method needs to be passed to `MemberClass` in the form of a method pointer.

A working example with comments is provided.

### Run Commands
```bash
cd build/
cmake ..
make
./cpp-callback
```

### Resource Links
* [Calling Method Through Method Pointers](https://stackoverflow.com/questions/16276373/how-to-call-member-function-through-member-function-pointer)
* [Method Pointer Syntax](https://stackoverflow.com/questions/36969471/c-how-to-make-function-pointer-to-class-method)
* [Function Pointers in C](https://stackoverflow.com/questions/840501/how-do-function-pointers-in-c-work)