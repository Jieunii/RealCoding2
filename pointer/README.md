# Personal Project6 : Pointer(2020.08.11)

## pointer

### Pointer Basic
* &val : Address of val
* *ptr : Value in address val

### Three basic memory model in C
1. Automatic
2. Static
3. Manual

||Static|Auto|Manual|
|---|---|---|---|
|Set to zero on startup|O|||
|Scope-limited|O|O||
|Can set values on init|O|O||
|Can set nonconstant values on init||O||
|sizeof measures array size|O|O||
|Persists across function calls|O||O|
|Can be global|O||O|
|Array size can be set at runtime||O|O|
|Can be resized|||O|

### Noun-Adjective Form
1. int const a
2. int const * a
3. int* const a
4. int* const *a
5. int const * *a
6. int const* const* a


