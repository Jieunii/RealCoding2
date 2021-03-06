# Personal Project9 : Static Testing(2020.08.18)

## 1. Software Testing

### 1.1 SW Testing이란?
* 소프트웨어 개발 과정에서 발생할 수 있는 오류들을 가정하고, 그러한 오류들을 발견해 내는 활동
* IEEE애서의 SW 테스트 정의 : 수동이나 자동으로 시스템을 시험 작동시키고 평가하는 작업으로 명시된 요구를 잘 만족하는지, 즉 예상된 결과와 실제 결과와의 차이를 인식하기 위한 목적을 가진다.
* 동작 실행 여부에 따라 Static Testing과 Dynamic Testing으로 나눠질 수 있고, 내부 구조 파악 여부에 따라 Black-Box Testing과 White-Box Testing으로 나눠질 수 있다.  
![swtesting](/uploads/2956a060a7d3d602ae99f668642f6bca/swtesting.PNG)

## 2. 정적 테스팅

### 2.1 정적 테스트란?
* 소프트웨어를 **실행시키지 않고 결함을 검출**하는 방법
* 소프트웨어 오류에 대한 특정한 판단 기준을 두고 검사를 실시한다. 이때, 소프트웨어 **검사 결과**와 **특정한 판단 기준**을 **비교**하여 오류를 찾는다.

### 2.2 정적 테스팅 구분
* 수행 기법에 따라 'Syntax'와 'Semantic' 테스트로 구분
* Syntax는 소스코드의 문법 결함을 발견
  * 소프트웨어 소스코드에 존재하는 `문법적인 오류`를 미리 정해놓은 패턴의 기준으로 검사하여 발견하는 정적 테스트 방법
* Semantic은 의미적인 결함을 발견

### 2.3 정적 테스팅 장단점
1. 장점
    * 빠른 시간에 소프트웨어 결함 검출
    * 수행 노력이 작다.
2. 단점
    * 잘못된 패턴 판단으로 False 알림 가능
    * 기능 동작 테스트 불가

## 3. Code Inspector

### 3.1 개발 코드 MISRA-C 2012 코딩규칙 검사
1. 수정 전 위배사항  
![91](/uploads/f69adacfe0260f1f68d326c53a9ff51d/91.PNG)

2. 수정 후 위배사항  
![45](/uploads/1db559f2f19e96624f096de05ad9db86/45.PNG)

### 3.2 개발 코드 MISRA-C 2012 코딩규칙 리포트
1. [violations](https://git.ajou.ac.kr/Jieuni/battle_c/-/blob/master/Project9%20-%20Software%20Testing/violations.pdf)
