# Personal Project5 : RaspberryPi에 LED 연결(2020.08.10)

## 실행 전 연결 상태  
![연결상태](/uploads/99a8130d152cc09e8ea8bb14e08ac592/연결상태.jpg)

## ledTest.c
1. wiringPi.h 헤더파일을 추가시킨다.
    ```C
    #include <wiringPi.h>
    ```
  
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
  
