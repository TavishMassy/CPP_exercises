## Logical Operators
C++ supports three boolean operators: ! (NOT), && (AND), and || (OR). You can also use the alternative versions not, and, and or.
```
true || false // => true
true && false // => false
!true // => false
not false // => true
```
## Precedence
The three boolean operators each have different operator precedence. As a consequence, they are evaluated in this order: ! first, && second, and finally ||. If you want to force a different ordering, you can enclose a boolean expression in parentheses (ie. ()), as the parentheses have even higher operator precedence.
```
!true && false   // => false
!(true and false) // => true
```
## Advanced
#### Conversion
If you use true or false in a place where a number is expected, they will be converted to 1 and 0 respectively. If you use a number in a Boolean operation, everything except 0 is treated as true - even negative values.
```
!true && 0.0   // => false
true + true + false // => 2
```