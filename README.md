# battle_c

## Jieun Yoon - Team 6

실전코딩2 실습

## Personal Project1 : printf(2020.08.03)

### stdio.h
* stderr, stdout, stdin에 대해서 배움

### Redirection
* 표준 입력이나 표준 출력을 키보드나 화면으로 하는 것이 아니라 파일로 입력받거나 파일로 출력하도록 변경하는 것
* 표준 출력 변경

    * cat > 파일명
    * \>
    * 1>
  
* 표준 입력 변경

    * \< 
    * 0>
  
* 표준 에러 변경
  
    * 2>


## Personal Project2 : three_files(2020.08.05)

### C Compile and Execution
1. Compile, Preprocessor Directive
2. Compile User Source Code, Generate Assembly
3. Link Assembler, Generate Excutable Code
4. Loader, Loads the executable code into memory

### gcc를 통해 컴파일 하는 방법
1. gcc [소스파일 이름]
   
   * gcc를 사용하여 컴파일에 성공하면 a.out이라는 파일이 생긴다. 

2. ./a.out
   
    * 생성된 a.out 파일을 이용하여 실행한다.
    * 컴파일 과정에서 실행파일의 이름을 정해주지 않으면 기본적으로 a.out이라는 이름으로 생긴다.

### gcc compile option
1. gcc -c

    * 소스 파일을 컴파일만 하고 링크는 수행하지 않는다.
    * *.o 파일을 생성한다.
    * ex) gcc -c main.c func.c => main.o func.o 파일 생성
  
2. gcc -o [소스파일 이름] [컴파일할 파일]

    * 바이너리 형식의 출력 파일 이름을 지정한다.(지정하지 않으면 a.out)

3. gcc -E
   
   * 컴파일의 첫 단계인 전처리까지만 실행한 결과를 출력한다.
   * ex) gcc -E func.c => 매우 방대한 내용이 소스파일 위에 붙는다.
  
4. gcc main.c func.o -o main

    * main.c 파일을 컴파일하여 오브젝트 파일을 만들고 func.o 파일과 링킹하여 main이라는 실행 프로그램을 만든다

### three_files 컴파일
1. gcc -DPRINT_ID로 컴파일 할 때
   
   * gcc -DPRINT_ID main.c func.c
   * PRINT_ID가 정의되어 있으므로 학번 출력

2. gcc -DPRINT_ID로 컴파일 하지 않을 때

   * gcc main.c func.c
   * PRINT_ID가 정의되어 있지 않으므로 이름 출력