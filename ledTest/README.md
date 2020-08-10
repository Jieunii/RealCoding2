# Personal Project5 : RaspberryPi에 LED 연결(2020.08.10)

## GPIO

### GPIO란?
* General Purpose Input/Output
* 단일 마이크로 프로레서와 같이 입출력(Input/Output) 신호를 제어할 수 있는 포트
* 사용자가 직접 회로를 구성하고 프로그래밍하여 라즈베리파이의 GPIO를 다룰 수 있다.

### GPIO 명령어
1. gpio readall
   * gpio map 확인
   * 각 핀의 현재 입/출력방향의 상태와 핀에 입력된 전압(0 or 1)등을 표시해준다.
2. gpio -h
   * gpio 명령어 및 정보 확인
3. man gpio
   * gpio 명령어에 대한 소개
4. gpio -g mode [핀번호] [input or output]
   * 
   * ex) gpio -g mode 21 output => 21번 핀에 LED를 연결했다면, 출력으로 설정한다.
5. gpio -g write [핀번호] [1 or 0]
   * ex) gpio -g write 29 1 => 29번 핀에 연결한 LED의 불빛이 들어온다.

## 회로 구성 
* 준비물 : 라즈베리 파이, T자형 코블러, Breadboard(빵판), 빵판용 점퍼 와이어(전선), LED, 고정 저항기(레지스터)  
![연결상태](/uploads/99a8130d152cc09e8ea8bb14e08ac592/연결상태.jpg)

## ledTest.c
1. wiringPi.h 헤더파일을 추가시킨다.
    ```C
    #include <wiringPi.h>
    ```
    * wiringPi : 라즈베리 파이의 BCM2835 프로세서에 접근하는 라이브러리
2. 핀 모드를 29번으로 설정한다.(BCM으로 21번이 wiringPi에서 29번이므로)
    ```C
    pinMode(29, OUTPUT);
    ```
3. for문을 이용하여 동작을 5번 실행한다.
   ```C
   for(i=0;i<5;i++)
   {

   }
   ```
4. led를 키고 0.5초 지연시킨다.
   ```C
   digitalWrite(29, 1);
   delay(500);
   ```
5. led를 끄고 0.5초 지연시킨다.
   ```C
   digitalWrite(29, 0);
   delay(500);
   ```

## 실행 결과
* gcc ledTest.c -lwiringPi  
  ![실행방법](/uploads/5b2f627378d14e2cabd312597155daa2/실행방법.PNG)  
  ![5번깜빡](/uploads/0343b31a2a20a4f52388483f47bf1ecc/5번깜빡.mp4)
  
