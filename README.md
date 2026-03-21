# Bridging

## Challenges

### 1. Refactoring the code

- After creating the basic structure of my backened logic in C++ and my classes, I found out that I need to "re-structure" my
  code to make it bridge-ready
- Currently, my classes use `std::string` and internal validation. To make them work with a Node.js server, I need to add a **Wrapper**
- I figured out that I don't need to change my class logic, but I need to create a "Public Entrance" (the extern "C" part) that the web server can call

#### Why `extern "C"`?

- C++ "mangles" function names to support features like overloading
- A web server looking for `addExpense` won't find it if the compiler renamed it to something like`_Z10addExpensePKci`
- `extern "C"` tells the compiler: "keep the name simple so the outside world can find it"

#### Why `const char*`?

- Web browsers and servers speak in simple character arrays
- They don't know what a C++ `std::string` object is
- We accept a `const char*` at the door, then immediately turn it into a `std::string` once we're safely inside the C++ logic

## Strategy

- To allow these 2 languages to talk to each other, I created a bridging file calld `bridge.cpp`
- This is a **wrapper** file
  - It includes my existing files (#include "classes.h")
  - It sits "on top" of my existing code
  - It translates the Web Browser's language (`char*`) into my C++ language (`std::string`)

#### How it works:

- The existing files (classes.cpp, validation.cpp) are the _engine_ under the hood
  - They do the heavy lifting
- The `bridge.cpp` file is the dashboard
  - It _doesn't replace the engine_
  - It just gives the driver (the Web Browser) a _way to talk_ to the engine
