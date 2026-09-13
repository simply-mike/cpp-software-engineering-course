#include <print>

#pragma GCC diagnostic ignored "-Wkeyword-macro"

#ifndef SOLUTION
#define SOLUTION 3
#endif

#if SOLUTION == 1
struct SomeConstructorStruct {
  SomeConstructorStruct() { std::print("Hello from global object constructor\n"); }
};

static SomeConstructorStruct someInstance;

#elif SOLUTION == 2
struct SomeDestructorStruct {
  ~SomeDestructorStruct() { std::print("Hello after return 0 from destructor\n"); }
};

static SomeDestructorStruct someInstance;

#elif SOLUTION == 3
#define return                                                                                     \
  std::print("Hello from macro return replacement\n");                                             \
  return

#elif SOLUTION == 4
namespace {
struct Base {
  Base() { std::print("Hello from anonymous namespace base class\n"); }
};

struct Derived : Base {
} instance;
} // namespace

#else
#error unsupported
#endif

int main() {
  return 0;
}
