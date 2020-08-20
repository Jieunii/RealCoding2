# Personal Project10 : Dynamic Test(2020.08.20)

## 1. Unit Test(단위 테스트)

### 1.1 Unit Test란?
* 프로그램의 기본 단위인 모듈을 테스트하여 모듈 테스트라고도 한다.
* 구현 단계에서 각 모듈의 개발을 완료한 후 개발자가 명세서의 내용대로 정확히 구현되었는지를 테스트한다.
* 개별 모듈이 제대로 구현되어 정해진 기능을 정확히 수행하는지를 테스트한다.
* White-Box Test와 Black-Box Test를 모두 사용할 수 있지만 모듈 내부의 구조를 구체적으로 들여다볼 수 있는 White-Box Test 같은 구조적 테스트를 주로 시행한다.

### 1.2 Unit Testing 절차  
![단위테스트절차](/uploads/13b7eb9ab42058a893b86a205511d547/단위테스트절차.PNG)

## 2. 동적 테스팅

### 2.1 동적 테스트란?
* 소프트웨어 실행을 통하여 소프트웨어에 존재하는 결함을 검출하는 방법
* 특정 데이터를 제 3의 소프트웨어에 입력하여 수행 후 실제 수행 결과와 기대 결과의 일치 여부를 검증하는 테스트 방법
* 동적 테스트를 수행하기 위해서는 다음의 두가지 조건을 확인해야 한다.
  * 소프트웨어가 실행 가능한 환경 구축
  * 소프트웨어를 실행하기 위한 입력, 수행 결과를 관찰하기 위한 방법

### 2.2 동적 테스트의 구분
* 시험 단위에 따라 구분
  * 단위 동적 테스트
  * 통합 동적 테스트
  * 시스템 동적 테스트

### 2.3 동적 테스팅의 장단점
1. 장점
   * 오류 탐색 정확도 높다.
2. 단점
   * 코드 전체 수행이 어렵다.

## 3. CodeScroll Controller Tester

### 3.1 커버리지 
1. 테스트 케이스 뷰에서 원하는 테스트 케이스를 더블 클릭하면 해당 소스코드의 어느 부분이 커버되었는지 색상 정보로 표시해준다.
   |색상|의미|
   |---|---|
   |초록색|코드가 실행되고 모든 분기가 커버되었을 경우|
   |노란색|분기 중 일부만 커버된 경우|
   |빨간색|실행되지 않는 코드|
2. 세로 컬럼
   왼쪽 세로 컬럼에는 커버된 분기문의 T/F를 확인할 수 있다.  
   ![TF](/uploads/4cc4ca02f4f236c8614a2bcc5a7bf532/TF.PNG)
   
### 3.2 Unit Test 생성 및 수행
1. ArrayTest
   * case1  
    ![arraycase1](/uploads/fb5120cd34aacb6cd2727a6554b032f6/arraycase1.PNG)
   * case2  
    ![arraycase2](/uploads/a2e4afdbe05e2809af997d9d29547c4f/arraycase2.PNG)
   * case3  
    ![arraycase3](/uploads/7a2ee0663c6751c0a4b9680cab7dc1dd/arraycase3.PNG)
   * 구문, 분기 커버리지 100% 달성  
    ![array100](/uploads/3bff0ba85b8050faeb46ace8998d7bb3/array100.PNG)
2. inputVarTest
   * case1  
    ![inputcase1](/uploads/afe854a74e47cf7ef9f4429fa496f0e3/inputcase1.PNG)
   * case2  
    ![inputcase2](/uploads/75e098175eb7a98772c21eac36c38cb7/inputcase2.PNG)
   * case3  
    ![inputcase3](/uploads/40a6400ce581b35097d57a13a27d5a7b/inputcase3.PNG)
   * 구문, 분기 커버리지 100% 달성  
    ![input100_](/uploads/90477415e6c814333424463b6af4e8d7/input100_.PNG)
3. staticVarTest
   * case1  
   ![staticcase1](/uploads/f241a85c1ae18f13f3ca2c519d84e107/staticcase1.PNG)
   * case2  
   ![staticcase2](/uploads/829ddef3b6dbc865451e67ade205a36b/staticcase2.PNG)
   * case3  
   ![staticcase3](/uploads/3b82be3eac3a06d743a75d90dbedb656/staticcase3.PNG)
   * case4  
   ![static4](/uploads/4854add4f679a7d2b98d56e5078e6873/static4.PNG)
   * 구문, 분기 커버리지 100% 달성  
   ![static100](/uploads/9ff61b2938769e56188732337fb29d53/static100.PNG)

   