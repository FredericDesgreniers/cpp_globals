# cpp_globals
Type / Runtime -safe c++ global temp variables. Why make local variables when they could be global?

# Features
* Type safe global temp variables!
* Run time safe temp variable indexing!
* L-value ***and*** r-value support!
* Easily share global state, helps prevent nasty encapsulation bugs!
* Header only library!
* Avoid memory allocations, use temp memory that lives for the full program lifetime!

# Usage

```cpp
    int x = 10;

    temp() = x; // l-value support!
    temp<1>() = 20; // r-value support!
    temp<2>() = 3213; // Multiple temps per type using compile time indexing!
    temp() = std::string("a temp value!"); // Works with any type! Each type has it's own temp memory!

    std::cout << *temp<1, int>() << std::endl; // OUTPUT: 20
    std::cout << *temp<0, std::string>() << std::endl; //OUTPUT: a temp value!
    std::cout << *temp<0, int>() << std::endl; //OUTPUT: 10
    std::cout << *temp<2, int>() << std::endl; //OUTPUT: 3213
```
