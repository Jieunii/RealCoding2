# Personal Project5 : RaspberryPi에 LED 연결(2020.08.10)

## 1. GPIO

### 1.1 GPIO란?
* General Purpose Input/Output
* 단일 마이크로 프로레서와 같이 입출력(Input/Output) 신호를 제어할 수 있는 포트
* 사용자가 직접 회로를 구성하고 프로그래밍하여 라즈베리파이의 GPIO를 다룰 수 있다.

### 1.2 GPIO 명령어
1. gpio readall
   * gpio map 확인  
      ![gpioreadall](/uploads/3debd5de9da10778b41fcc8ded3cd65e/gpioreadall.PNG)  
      * BCM 열의 번호가 회로도에 나와있는 GPIO 핀 번호를 나타냈다.
      * wPi 열의 핀 번호가 wiringPi 라이브러리를 사용할 때의 실제 번호이다. (우리는 wPi를 사용한다.)
   * 각 핀의 현재 입/출력방향의 상태와 핀에 입력된 전압(0 or 1)등을 표시해준다.
2. gpio -h
   * gpio 명령어 및 정보 확인
3. man gpio
   * gpio 명령어에 대한 소개
4. gpio -g mode [핀번호] [input or output]
   * LED는 출력이고, 스위치는 입력이다. 그러면 각각 입력인지 출력인지 방향을 정해줘야 한다.
   * ex) gpio -g mode 21 output => 21번 핀에 LED를 연결했다면, 출력으로 설정한다.
   * ex) gpio -g mode 26 input => 26번 핀에 스위치를 연결했다면, 입력으로 설정해야 한다.
5. gpio -g write [핀번호] [1 or 0]
   * LED를 출력할 수 있도록 설정했으니, 불빛이 들어오도록 설정해야 한다.
   * ex) gpio -g write 29 1 => 29번 핀에 연결한 LED의 불빛이 들어온다.
   * ex) gpio -g write 29 0 => 29번 핀에 연결한 LED의 불빛이 꺼진다.
6. gpio toggle 1
   * 하나의 설정값으로부터 다른 값으로 전환한다.

## 2. 회로 구성 
* 준비물 : 라즈베리 파이, T자형 코블러, Breadboard(빵판), 빵판용 점퍼 와이어(전선), LED, 고정 저항기(레지스터)  
![연결상태](/uploads/99a8130d152cc09e8ea8bb14e08ac592/연결상태.jpg)

### 2.1 ledTest.c
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

### 2.2 실행 결과
* gcc ledTest.c -lwiringPi  
  ![실행방법](/uploads/5b2f627378d14e2cabd312597155daa2/실행방법.PNG)  
  ![5번깜빡](/uploads/0343b31a2a20a4f52388483f47bf1ecc/5번깜빡.mp4)
  
## 3. 01.led_wpi_st.c & 03.led_mem1_st.c

### 3.1 실행방법
1. 01.led_wpi_st.c
   ```C
   gcc 01.led_wpi_st.c -lwiringPi
   ./a.out 1
   ```
2. 03.led_mem1_st.c
   ```C
   gcc 03.led_mem1_st.c -o 03
   sudo ./03
   ```