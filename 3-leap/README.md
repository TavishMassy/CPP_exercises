## C++ Compilation Note: Fixing "Not a member of" Error

### The Problem
When building a C++ project (like the Exercism `leap` exercise), we might encounter an error looking like this during compilation:
```
error: 'is_leap_year' is not a member of 'leap'
TEST_CASE("not_divisible_by_4") { REQUIRE(!leap::is_leap_year(2015)); }
```
Even if we have perfectly written the logic in our .cpp file, the test file fails to recognize the function.

### The Solution
To fix this, we must explicitly declare the function inside the header file (.h) so that other files know it exists before they try to use it.

1. The Header File (leap.h)
This is where we declare the function.
```
#if !defined(LEAP_H)
#define LEAP_H

namespace leap {
    // Declaration: Tells the compiler this function exists
    bool is_leap_year(int year);
}

#endif // LEAP_H
```
2. The Source File (leap.cpp)
This is where we define the function (our actual logic).
```
#include "leap.h"

namespace leap {
    // Definition: Tells the compiler what the function actually does
    bool is_leap_year(int year) {
        if (year % 4 != 0) {
            return false;
        } else if (year % 100 != 0) {
            return true;
        } else if (year % 400 != 0) {
            return false;
        } else {
            return true;
        }
    }
}  // namespace leap
```
### Why It Works: Understanding C++ Compilation
C++ processes files in a very specific way. Here is exactly what happens under the hood that makes this header/source structure necessary:

#### 1. Declaration vs. Definition
C++ strictly separates what a function is from how it works.

- Declaration (in .h): Acts as a promise to the compiler. It says, "There is a function named is_leap_year in the leap namespace, it takes an int, and it returns a bool."

- Definition (in .cpp): Fulfills the promise. It contains the actual if/else logic.

#### 2. The ```#include``` Mechanism
When we run the build command, the compiler looks at leap_test.cpp. The test file has a line at the top like ```#include "leap.h"```.
Before compiling the test, C++ effectively copy-pastes the contents of leap.h into the test file. Because of our update, the test file now sees the declaration of is_leap_year.

#### 3. The Compiler and The Linker
- Compiling Phase: The compiler checks leap_test.cpp, sees we are calling ```leap::is_leap_year(2015)```, and checks the header. Since the header says this function exists and takes an integer, the compiler is happy and creates an object file (leap_test.cpp.obj).

- Linking Phase: A tool called the Linker looks at all the compiled object files and connects the function call in leap_test.cpp.obj to the actual logic residing in leap.cpp.obj.

Without the header file declaration, the compiler reads leap_test.cpp, hits the function call, and panics because it has no idea what is_leap_year is—resulting in the 'is_leap_year' is not a member of 'leap' error.
