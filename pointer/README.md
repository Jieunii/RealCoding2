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

### const란
변수를 상수화하기 위해 사용하는데, 쓰이는 위치에 따라서 용도가 조금씩 달라진다.
1. const int *n
    * `데이터 상수화`
    * n이라는 포인터가 가리키는 대상을 상수화 하겠다.
    ```c
    const int *n;

    int b = 10;
    n = &b;

    *n = 30; //error(n이 지닌 값은 변경 안된다.)
    ```
    -> 실제로 메모리 공간 자체가 상수화 된 것이 아니고, n이라는 포인터를 이용해서 데이터 변경을 막겠다. 하지만 변수 b를 이용하여 변경은 가능하다.
2. int* const n
   * `포인터 상수화`
    ```c
    int a = 20;
    int b = 10;
    int* const n = &b;

    n = &a; //error
    ```
    -> n이라는 포인터가 b를 가리키고 있을 때, 변수 a를 또 가리키도록 하는 것을 허용하지 않겠다.
3. const int* const n;
   * `데이터, 포인터 둘다 상수화`

### Noun-Adjective Form
1. int const a  
   constant integer
2. int const * a  
   (variable) pointer to a constant integer
3. int* const a  
   constant pointer to a (variable) integer
4. int* const *a  
   pointer to a constant pointer to an integer
5. int const * *a  
   pointer to a pointer to a constant integer
6. int const* const* a  
   pointer to a constant pointer to a constant integer

### Pointer - void *
* 주소값 안의 값에 대해 어떻게 해석해야 하는지에 대해 정해지지 않은 포인터
* 어떤 포인터 타입이든 가질 수 있다.
* 하지만 actual data type과 its arithmetic step size는 알 수 없다.

### Function pointer
* function pointer는 함수를 가리키는 변수(함수의 주소를 저장하는 변수)
* 마치 배열을 가리키는 포인터가 배열의 시작부분을 가리키는 것과 같이, 함수 포인터도 코드를 가리킬 때 코드의 시작부분을 가리킨다.
* 함수 포인터를 통해 메모리를 **할당**하거나 **회수**하는 것이 불가능하다. 따라서 함수 포인터를 대상으로 malloc(), free() 함수를 사용할 수 없다.
* 함수 포인터의 모양
  ```C
  int (*FuncPtr) (int, int); //함수의 return형은 int이고, int형 파라미터 2개를 받는 함수다.

  int add(int first, int second);
  double multi(double first, double second);

  FuncPtr = add //o
  FuncPtr = &add //o
  FuncPtr = multi //x
  FuncPtr = add() //x
  ```
* typedef를 이용한 함수 포인터의 모양
  ```C
  typedef int (*FuncPtr)(int, int);

  FuncPtr test = NULL;
  test = add;
  ```
* 함수 포인트의 문법
  ```C
  void prac1(int num){
    printf("%d\n", num);
  }

  void prac2(int num){
    printf("%d\n", num);
  }

  int main(){
    //#1
    void (*prac1_ptr)(int); //함수 포인터 선언
    prac1_ptr = &prac1; //prac1()함수의 주소값을 함수 포인터에 할당
    (*prac1_ptr)(3); //함수 포인터를 사용하여 prac1()함수 호출

    //#2
    (*prac1_ptr)(3); //함수 포인터를 사용하여 prac1()함수 호출
    prac1_ptr(3);
    (*prac1)(3); 
    prac1(3);

    //#3 함수 포인터 배열
    void (*fp[2])(int, int);
    fp[0] = &prac1;
    fp[1] = &prac2;
    (*fp[0])(3);
    (*fp[1])(5);

    return 0;
  }
  ```
