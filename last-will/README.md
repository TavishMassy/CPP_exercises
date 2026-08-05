# C++ Namespaces: The Mysterious Vault Exercise

## Overview
In this exercise, I acted as an estate executor for a prestigious law firm. My goal was to open a mysterious vault by assembling secret codes and account numbers from three different families. To prevent naming collisions between the families' data and to organize the code properly, I heavily utilized **C++ Namespaces**.

## Concepts Learned
* **Namespaces:** A tool used for code organization to prevent naming collisions (e.g., when two different functions or variables share the same name).
* **Scope-Resolution Operator (`::`):** Used to access functions or variables inside a specific namespace (e.g., `my_ns::foo()`).
* **Nested Namespaces:** Namespaces can be placed inside one another to further structure large code bases (e.g., `my_ns::my_inner_ns::baz()`).

## What I Did (Tasks Completed)

### 1. Created the Executor Workspace
To keep my own executor functions separate from the families' data, I defined a dedicated namespace called `estate_executor`. All subsequent logic was written inside the body of this namespace.

### 2. Assembled the Secret Account Number
I wrote a function called `assemble_account_number` that takes a `secret_modifier` (an integer) as an argument. 
To generate the final account number, I accessed the `bank_number_part` variable from each of the three families' namespaces and summed them together alongside the secret modifier.

### 3. Assembled the Secret Code
Finally, I wrote a parameter-less function called `assemble_code`. Based on the testament instructions, I accessed specific "blue" and "red" fragments from the families' namespaces. I summed all the blue fragments together, summed all the red fragments together, and then multiplied the two sums to return the final secret code.

---

## Example Implementation
Here is a representation of the code structure I built to solve this:

```cpp
namespace estate_executor {

    // Task 2: Find the secret account number
    int assemble_account_number(int secret_modifier) {
        return family1::bank_number_part + 
               family2::bank_number_part + 
               family3::bank_number_part + 
               secret_modifier;
    }

    // Task 3: Enter the secret code
    int assemble_code() {
        int blue_sum = family1::blue_fragment + 
                       family2::blue_fragment + 
                       family3::blue_fragment;
                       
        int red_sum = family1::red_fragment + 
                      family2::red_fragment + 
                      family3::red_fragment;
                      
        return blue_sum * red_sum;
    }
}