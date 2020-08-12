# Personal Project1 : printf(2020.08.03)

## stdio.h

### 표준 스트림
* 표준 스트림은 Standard Stream의 약자로 컴퓨터 프로그램에서 **표준적으로** 입력으로 받고 출력으로 보내는 데이터와 매체를 총칭하는 용어
* 표준 입력은 프로그램에 입력되는 데이터의 표준적인 출처로 stdin라고 표현
* 표준 출력은 프로그램에서 출력되는 데이터의 표준적인 방향으로 크게 stdout과 stderr로 구분

### stdin, stdout, stderr
1. stdin(standart input)-0
   * 리눅스에서 표준 입력은 file descriptor가 0으로 설정
   * C, C++
        ```C
        //C
        FILE* stdin
        ```
        ```C++
        //C++
        std::cin
        ```
2. stdout(standard output)-1
   * 정상적인 출력이 반환되는 방향
   * 리눅스에서 표준 출력은 file descriptor가 1로 설정
   * C, C++
        ```C
        //C
        FILE* stdout
        ```
        ```C++
        //C++
        std::cout
        ```
3. stderr(standard error)-2
   * 프로그램의 비정상 종료시에 반환되는 방향
   * 리눅스에서 표준 출력은 file descriptor가 2로 설정
   * C, C++
        ```C
        //C
        FILE* stderr
        ```
        ```C++
        //C++
        std::cerr
        ```

||||

## Redirection
* 표준 입력이나 표준 출력을 키보드나 화면으로 하는 것이 아니라 파일로 입력받거나 파일로 출력하도록 변경하는 것
* `> file`
  * 표준 출력을 파일로 redirection
  * 파일이 없으면 새로 만들고, 파일이 있으면 덮어쓴다.
* `>> file`
  * 표준 출력을 파일로 redirection
  * 파일이 없으면 새로 만들고, 파일이 있으면 파일의 끝에 덧붙인다.
* `2>&1`
  * 표준 에러를 표준 출력으로 redirection
  * 표준 에러도 표준 출력의 자격으로 보내진다.
* `< file`
  * 파일로부터 표준 입력을 받도록 redirection
* ex)
  * ./a.out < input_data > output_data  
    입력값은 input_data에서 받고 output_data에 출력된다.
