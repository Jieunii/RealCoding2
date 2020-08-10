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

    * main.c 파일을 컴파일하여 오브젝트 파일을 만들고 func.o 파일과 링킹하여 main이라는 실행 프로그램을 만든다.
  
5. gcc -D
   
   * 매크로를 외부에서 define할 때 사용한다.
   * ex) gcc -D PRINT_ID => 소스 내에서 #define PRINT_ID를 추가한 것과 동일하다.
  
6. gcc -U

   * -D와 반대로 소스 파일 내에 #undef [매크로] 옵션을 추가한 것과 동일하다.

### three_files 컴파일
1. gcc -D PRINT_ID로 컴파일 할 때
   
   * gcc -D PRINT_ID main.c func.c
   * PRINT_ID가 정의되어 있으므로 학번 출력

2. gcc -D PRINT_ID로 컴파일 하지 않을 때

   * gcc main.c func.c
   * PRINT_ID가 정의되어 있지 않으므로 이름 출력

3. 조건부 컴파일
   
   * #ifdef []: 만약 []가 정의되어 있다면 처리하고 그렇지 않으면 건너뛴다.
   * #else, #elif
   * #endif : 조건부 컴파일의 종료를 나타낸다.

## Personal Project3 : 컴파일러와 인터프리터의 차이 & gcc 컴파일 옵션(2020.08.06)

### 컴파일러 vs 인터프리터
1. 컴파일러
   
   * 고급언어로 쓰여진 프로그램이 컴퓨터에서 수행되기 위해서 컴퓨터가 직접 이해할 수 있는 언어로 바꾸어 주는 프로그램
   * 번역과 실행 과정을 거쳐야하므로 번역 과정이 번거롭고 번역 시간이 오래 걸린다. 하지만 한 번 번역한 후에는 다시 번역하지 않으므로 속도가 빠르다.
  
2. 인터프리터

    * 프로그램을 한 단계씩 기계어로 해석하여 실행하는 **언어처리 프로그램**
    * 줄 단위로 번역, 실행되기 때문에 시분할 시스템에 유용하며 원시 프로그램의 변화에 대한 반응이 빠르다.
    * 대화형 언어에 적합하지만 실행 시간이 길어 속도가 늦다


||컴파일러|인터프리터|
|---|---|---|
|번역 단위|전체|한줄씩|
|실행 속도|빠름|느림|
|번역 속도|느림|빠름|
|실행 파일|생성함|생성하지 않음|

### gcc 컴파일 옵션 연습
1. gcc -E
   * 전처리까지만 실행한 결과를 화면에 출력한다.  
    ![gcc-E(1)](https://user-images.githubusercontent.com/54850435/89533294-2b9c9a00-d82e-11ea-9d6e-f170b127536c.PNG)
   * 01.option-E.i 생성  
    ![gcc-E(2)](https://user-images.githubusercontent.com/54850435/89533368-4969ff00-d82e-11ea-879d-9c3c28f3c29c.PNG)


2. gcc -S : 컴파일 단계만 실행
   * 전처리된 파일을 어셈블리 파일로 컴파일까지만 수행한다.
   * 02.option-S.s 생성  
    ![gcc-s](https://user-images.githubusercontent.com/54850435/89533405-5555c100-d82e-11ea-8765-65f17c5b112b.PNG)


3. gcc -c : 컴파일과 어셈블
   * 어셈블까지만 수행하고 링크는 수행하지 않는다.
   * 03.option-c.o 생성  
    ![gcc-c](https://user-images.githubusercontent.com/54850435/89533512-80401500-d82e-11ea-98e9-82294f9667ae.PNG)

4. gcc -g
   * gdb에게 제공하는 정보를 바이너리에 삽입한다.
   * 디버깅 정보가 담긴 실행파일을 생성한다.
   * a.out 생성  
    ![gcc-g](https://user-images.githubusercontent.com/54850435/89533542-89c97d00-d82e-11ea-9b30-82e8e85a10b3.PNG)

5. gcc -Wall
   * 모든 모호한 코딩에 대해서 경고를 보내는 옵션이다.  
    ![gcc-Wall](https://user-images.githubusercontent.com/54850435/89533566-9352e500-d82e-11ea-9fd2-5cb7a3a53a5d.PNG)

6. gcc -o : 출력 파일 지정
   * 실행파일을 만든다.
   * 이름이 00인 실행파일 만들기  
    ![gcc-o(1)](https://user-images.githubusercontent.com/54850435/89533595-9e0d7a00-d82e-11ea-9a66-c41af3c71e6a.PNG)
   * 이름이 01.exe인 실행파일 만들기  
    ![gcc-o(2)](https://user-images.githubusercontent.com/54850435/89533613-a665b500-d82e-11ea-87ed-542d346a70a6.PNG)

7. gcc -D : 매크로 지정
   * 매크로를 외부에서 define할 때 사용한다.  
    ![gcc-D](https://user-images.githubusercontent.com/54850435/89533642-b1204a00-d82e-11ea-850b-d5b982c8850a.PNG)

## Personal Project4 : Makefile 만들기(2020.08.07)

### make란?
* **maintain, update, and regenerate group of progrmas**
* 명령을 생성하는 유틸리티, 프로그램 그룹을 유지하는데 필요한 유틸리티
* **많은 프로그램 모듈들로 구성된 프로그램을 효율적으로 유지하고 일관성 있게 관리하도록 도와주는 도구**
* 소스 수정 시 유관 파일들을 재컴파일 & 링크하는 반복적인 작업을 간단하게 처리함

### make의 동작
* **make는 여러 파일들 간의 의존성을 저장하고 수정된 파일에 연관된 소스 파일들만을 재컴파일 하도록 해줌**
* make 유틸리티는 이전에 make명령을 실행했던 시점 이후에 이뤄진 프로젝트 작업들에 대해서만 갱신 작업을 수행함
* 개별 항목은 순서에 따라 실행되지만 전체 내용은 순서를 따르지 않음

### make 필요성
* **프로그램 개발 및 유지보수의 편리성을 지원**
* 명령어의 배치 처리 기능, 자주 쓰는 명령어를 자동화할 수 있음
* 자동적으로 특정 프로그램 수행을 원할 때

### Makefile 작성
1. 빌드 규칙(Rule) 블록
    ```Text
    <Target> : <Dependencies>
        <Recipe>
    ```
    * Target : 빌드 대상 이름. 최종적으로 생성해내는 파일명
    * Dependencies or prerequisities : 빌드 대상이 의존하는 Target이나 파일 목록. 이곳에 나열된 대상들을 먼저 만들고 빌드 대상 생성
    * Recipe : 빌드 대상을 생성하는 명령. 각 줄 시작에 반드시 `Tab`문자로 된 Indent가 있어야 한다.
  
2. 내장 매크로(Pre-defined Macro) - Variables Used by Implicit Rules
   * CC : 컴파일러
   * CFLAGS : 컴파일 옵션
   * OBJS : 중간 산물 Object 파일 목록
   * TARGET : 빌드 대상(실행 파일) 이름
   * LDFLAGS : 링커 옵션
   * LDLIBS : 링크 라이브러리

3. 내장 매크로(Internal Macro) - Automatic variables
   * $@ : 현재의 목표 (Target) 파일명
   * $? : 현재의 목표파일(Target)보다 더 최근에 갱신된 의존 파일 명단
   * $* : 현재의 목표파일(Target)보다 더 최근에 갱신된 현재 의존 파일 명단(확장자를 제외한)
   * $< : 의존 파일(전제 조건) 중 첫번째 파일명
   * $^ : 현재 모든 의존 파일들의 명단
  

### Makefile 작성 실습 과정
1. Makefile 형식  
   ![make1](/uploads/0a40029e667928fe4d54a7b588d974fe/make1.PNG)
2. Dummy Target(Label) & Dependency Check  
   ![make2](/uploads/9d701192aea00d8fe458105fb6120295/make2.PNG)
3. 매크로(Macro, Variable)의 이용  
   ![make3](/uploads/02da1b99ea3eed380e1b7715ea8c2a75/make3.PNG)
4. 내장 매크로(Internal Macro)의 이용  
   ![make4](/uploads/bdd7a9dba3dcb3937dbcc8386fc00d1d/make4.PNG)
5. 내장 매크로(Pre-definced Macro)의 이용  
   ![make5](/uploads/1f1285d02099c4a8435c900737c7d4a0/make5.PNG)
6. 확장자규칙(Suffix Rules)의 이용 & 확장자(Suffix)의 치환 이용  
   ![make6](/uploads/46ba746c8c95efe7909a05cb642570f6/make6.PNG)
7. 디폴트 확장자규칙(Default Suffix Rules)의 이용  
   ![make7](/uploads/4e3b187a18d5f578b28af2f1cec71280/make7.PNG)
8. make clean 후 make
   * make clean 했을 때 설정한 파일들이 지워지고 make를 했을 때 설정 파일들을 컴파일한다.  
   ![makeclean_make](/uploads/7433da7c8dbcfdc40f57f1e05f95b77a/makeclean_make.PNG)