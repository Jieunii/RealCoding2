# Personal Project8 : Thread(2020.08.14)

## 1. Multi-tasking

### 1.1 Multi-tasking이란
* 여러 개의 task가 동시에 실행되는 것
* 운영체제의 스케줄링에 의해 번갈아 가면서 수행한다.
* 빠른 속도로 조금씩 번갈아 가면서 task들을 처리하여 user가 느끼기에는 동시에 처리되는 것처럼 보인다.
* Multi-tasking의 스케줄링 방식
  1. Multi-programming
  2. Time-sharing
  3. Real-time

## 2. Multi-thread

### 2.1 Multi-thread란
* 한 프로그램 내에서 둘 이상의 스레드를 동시에 실행하는 것
* 장점
  * 프로세스 내의 메모리를 공유함
  * 프로세스 간의 전환 속도보다 스레드 간의 전환 속도가 빠름
* 단점
  * 공유 데이터에 대한 경쟁조건이 발생

### 2.2 스레드 제어 system call API
* int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start)(void *), void *arg)
* void pthread_exit(void *retval)
* pthread_t pthread_self(void)
* int pthread_equal(pthread_t t1, pthread_t t2)

### 2.3 스레드 동기화 제어 system call API
* pthread_mutex_init
  * mutex를 동적으로 초기화
  * 성공하면 0 return, 에러가 발생하면 에러번호(양수) return
  ```C
  int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr)
  ```
* pthread_mutex_destory
  * mutex를 제거함
  * mutex는 풀려있고 다른 스레드가 잠그려고 하지 않은 상태에서 제거해야한다.
  * 성공하면 0 return, 에러가 발생하면 에러번호(양수) return
 ```C
 int pthread_mutex_destory(pthread_mutex_t *mutex)
 ```
* pthread_mutex_lock
  * mutex를 잠금
  * mutex가 현재 풀려있으면, mutex를 잠그고 즉시 return
  * mutex가 다른 스레드에 의해 잠겨있으면, 해당 뮤텍스가 풀릴 때까지 block되었다가 mutex가 풀리면 다시 잠그고 return
  ```C
  int pthread_mutex_lock(pthread_mutex_t *mutex)
  ```
* pthread_mutex_unlock
  * 잠근 mutex를 품
  * 현재 잠겨 있지 않은 mutex를 풀거나 다른 스레드가 잠근 mutex를 푸는 것은 오류이다.
  ```C
  int pthread_mutex_unlock(pthread_mutex_t *mutex)
  ```


## 3. 과제

### 3.1 3개의 LED를 제어하는 응용 메인 코드 작성하기
* 실행 조건
  * 빨간색 LED는 1초 간격으로 on/off
  * 초록색 LED는 2초 간격으로 on/off
  * 노란색 LED는 3초 간격으로 on/off
* 실행 방법
  * cmake
    ```C
    cmake . -Bbuild
    cmake --build build //cd build로 가지 않고 그 자리에서 build하는 방법 (= make -C build)
    ```
    ![cmake](/uploads/0e996304c81c8e24d440e56cbabfb4a9/cmake.PNG)  
    ![build](/uploads/8e2b6ae8b543e31856e585cd655f5d26/build.PNG)
    * clean하는 법
        ```C
        //make
        make -C build clean

        //cmake
        cmake --build build/ --target clean
        ```
* 실행 예시 및 예상
  * ./led_main  
    빨간색 LED만 1초 간격으로 10 on/off 반복
  * ./led_main 1 5  
    빨간색 LED만 1초 간격으로 10 on/off 반복 + 초록색 LED는 2초 간격으로 5회 on/off
  * ./led_main 2 7  
    빨간색 LED만 1초 간격으로 10 on/off 반복 + 노란색 LED는 3초 간격으로 7회 on/off
  * ./led_main 3 6  
    빨간색 LED만 1초 간격으로 10 on/off 반복 + 초록 LED는 2초 간격으로, 노란색 LED는 3초 간격으로 각각 6회 on/off
* 실행 결과
  * ./build/led_main 2 7
    ```text
    RED ON!
    YELLOW ON!
    RED OFF!
    RED ON!
    YELLOW OFF!
    RED OFF!
    RED ON!
    RED OFF!
    YELLOW ON!
    RED ON!
    RED OFF!
    RED ON!
    YELLOW OFF!
    RED OFF!
    RED ON!
    RED OFF!
    YELLOW ON!
    RED ON!
    RED OFF!
    RED ON!
    YELLOW OFF!
    RED OFF!
    RED ON!
    RED OFF!
    YELLOW ON!
    RED ON!
    RED OFF!
    YELLOW OFF!
    YELLOW ON!
    YELLOW OFF!
    YELLOW ON!
    YELLOW OFF!
    YELLOW ON!
    YELLOW OFF!
    ```  
    ![led_main_2_7](/uploads/5371bf3edccf76290717e89e8e522fa5/led_main_2_7.mp4)
    
  * ./build/led_main 3 6
    ```text
    YELLOW ON!
    RED ON!
    GREEN ON!
    RED OFF!
    GREEN OFF!
    RED ON!
    YELLOW OFF!
    RED OFF!
    GREEN ON!
    RED ON!
    RED OFF!
    YELLOW ON!
    GREEN OFF!
    RED ON!
    RED OFF!
    GREEN ON!
    RED ON!
    YELLOW OFF!
    RED OFF!
    GREEN OFF!
    RED ON!
    RED OFF!
    YELLOW ON!
    GREEN ON!
    RED ON!
    RED OFF!
    GREEN OFF!
    RED ON!
    YELLOW OFF!
    RED OFF!
    GREEN ON!
    RED ON!
    RED OFF!
    YELLOW ON!
    GREEN OFF!
    RED ON!
    RED OFF!
    GREEN ON!
    YELLOW OFF!
    GREEN OFF!
    YELLOW ON!
    YELLOW OFF!
    YELLOW ON!
    YELLOW OFF!
    ```  
    ![led_main_3_6](/uploads/d25a8046fa31e4ead1cf9c4b0090221c/led_main_3_6.mp4)