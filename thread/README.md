# Personal Project7 : Thread(2020.08.12)

## Thread

### Thread란?
* 프로그램(프로세스) 실행의 단위이며 하나의 프로세스는 **여러개의 쓰레드(multithread)**로 구성할 수 있다.
* Thread들은 프로세스에 할당된 메모리, 자원 등을 공유한다.
* 실행 상태가 변할 때 **context switching**을 수행한다.

### Process vs Thread
1. Process
   * 운영체제로부터 자원을 할당받는 작업의 단위
   * 실행 중인 프로그램
2. Thread
   * 프로세스가 할당받은 자원을 이용하는 실행의 단위
   * 프로세스의 실행 단위

### PThread
* 병렬적으로 작동하는 소프트웨어의 작성을 위해 제공되는 표준 API
* pthread.h를 include함으로써 호출 가능하다.
    * pthread_create : 호출되는 프로세스에서 새로운 thread를 시작한다. 함수가 성공하면 0을 리턴한다.
        ```C
        int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void*), void *arg)
        ```
        * thread : 성공적으로 함수가 호출되면 thread ID가 저장된다. 이 인자로 넘어온 값을 통해서 pthread_join과 같은 함수를 사용할 수 있다.
        * attr : thread의 특성을 정의한다. 기본적으로 NULL을 지정한다. 만약 thread의 속성을 지정하려한다면 pthread_attr_init등의 함수로 초기화해야한다.
        * start_routine : 어떤 로직을 할 지 함수 포인터를 매개변수로 받는다.
        * arg : start_routine에 전달될 인자를 의미한다.
    * pthread_exit : 현재 실행중인 thread를 종료시킨다. 프로세스는 종료하지 않고 스레드만 종료시킨다.
        ```C
        void pthread_exit(void *rval ptr);
        ```


## 과제

### 병렬 성적 처리
1. 학생들의 성적을 입력받아 배열에 넣는다.
2. 성적을 입력해서 저장한 후 배열을 한 번 출력한다.
3. 2개의 thread를 만든다.
4. 첫번째 thread에서는 성적의 평균과 합을 구한다.
5. 두번째 thread에서는 성적순으로 sorting하여 출력한다.

### 실행방법
```C
make
./threadTest < sample.txt
```

### 실행결과
```text
성적 sample
 50
 30
 90
100
  4
 65
 75
 95
 85
 47
 96
 19
 52
 68
 73
 81
  1
 32
 25
 88
 61
 80
 67
 95
 99
 10
  9
 78
 89
 73
Main start!
합 : 1837, 평균 : 61.233334
Main end!
 1등 : 100
 2등 : 99
 3등 : 96
 4등 : 95
 5등 : 95
 6등 : 90
 7등 : 89
 8등 : 88
 9등 : 85
10등 : 81
11등 : 80
12등 : 78
13등 : 75
14등 : 73
15등 : 73
16등 : 68
17등 : 67
18등 : 65
19등 : 61
20등 : 52
21등 : 50
22등 : 47
23등 : 32
24등 : 30
25등 : 25
26등 : 19
27등 : 10
28등 : 9
29등 : 4
30등 : 1
```
sthread2가 sthread1보다 연산량이 많아 늦게 끝나는 것을 볼 수 있다.