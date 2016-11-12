# Linux Command
리눅스 명령어

## mkdir
---
make directory의 약자로서 새로운 디렉토리를 만들때 사용한다. mkdir은 umask값의 이해가 필요하다는 것을 유념한다.
umask값은 /etc/bashrc에 정의되어있다.
* umask : 파일이나 디렉토리를 생성할 때 권한을 지정해준다.
* 새로운 파일이나 허가권 지정 명령어로 일반 파일인 경우 666, 디렉토리인 경우 777에서 umask값을 뺀 값을 기본 허가권으로 조정
* 666 - 022 = 644, 777 - 022 = 755
```bash
$ umask
    설정된 값 보기
    합리적인 표준값 (002, 007, 020, 070, 022)
$ umask 027
    로그아웃할 경우 022로 변경 /etc/profile값을 수정하면 유지가능
```

#### 디렉토리를 생성
```bash
$ mkdir linux
```

#### 현재 존재하지 않은 디렉토리의 하위 디렉토리까지 생성
```bash
$ mkdir -p Animals/dog
```

#### 특정 퍼미션을 가진 새로운 디렉토리를 생성
```bash
$ mkdir -m 644 linux
```

## touch
---
파일 생성

#### 일반 파일을 생성할 때
```bash
$ touch dog
```

## sec
---
ed명령어와 grep명령어 기능의 일부를 합친 것이 sed(stream editor)명령어이다.
sed명령어도 grep명령어와 같은 필터이지만 이 명령어는 파일을 수정할 수 있게 하는 반면 ed처럼 대화식처리는 불가능하다.
sed명령어는 1개 라인씩 입력 라인을 읽어들여 표준출력으로 출력한다.
sed는 각 라인을 읽을 때마다 ed에서 사용하던 형식의 대치작업을 실행한다.
일치하는 문자열이 있으면 그 문자열을 대치한 후 출력하고 일치하는 문자열이 없으면 그 라인은 수정되지 않고 그대로 출력된다.
이 sed명령어가 ed보다 좋은 점은 라인들을 하나씩 읽고, 수정하고, 출력하기 때문에 기억장치 안의 버퍼를 사용하지 않는다는 것이다.
버퍼를 사용하지 않으면 파일의 크기에 제한 없이 작업을 할 수 있다.
ed와 같이 버퍼를 사용하는 경우는 버퍼의 크기보다 큰 파일은 처리할 수 없으며 대개 버퍼의 크기는 1MB정도이다.
따라서 sed는 아주 큰 파일을 처리할 때 주로 사용된다.
sed 명령어를 호출하는 형식은 grep명령어와 같지만 완전한 형식의 대치 연산자를 사용한다는 점만이 다르다.

#### 치환(substitute)
```bash
cat inputfilename | sed 's/searchterm/replaceterm/'
echo "sheena leads, sheila needs" | sed 's/sh/le/g'
    sed는 기본적으로 처음 찾은 단어만 치환한다. 모든 단어를 치환하려면 g 스위치를 사용해야 한다.
sed 's/addrass/address/' list.txt
    addrass를 address로 바꾼다. 단, 원본파일을 바꾸지 않고 표준출력만 한다.
    단, 원본파일을 바꾸지 않고 표준출력만 한다.

sed 's//var/ftp/pub//opt/ftp/com/' test.txt
    Separator 변경법. Separator가 검색하려는 단어에 포함된 경우 유용하다.
    예를 들어 /var/ftp/pub을 검색하여 /opt/ftp/com으로 치환하려고 할 때 아래처럼 해도 제대로 작동하지 않는다.
sed 's_/var/ftp/pup_/opt/ftp/com_' test.txt
    이럴 땐 separator를 /에서 '#'나 '$'같은 다른 문자로 바꿔야 한다. 위는 _를 사용하는 예제다.

sed 's/surendra/Mr. &/' test.txt
    예제4: 아래는 surendra를 Mr. surendra로 바꾸는 예제다.
```

#### 삭제(delete)
```bash
sed '/TD/d' 1.html
    TD 문자가 포함된 줄을 삭제하여 출력한다.
sed '/Src/!d' 1.html
    Src 문자가 있는 줄만 지우지 않는다.
sed '1,2d' 1.html
    처음 1줄, 2줄을 지운다.
```

#### 저장
```bash
$ cat {SOURCE_FILE_NAME} | sed 's/{ORIGINAL}/{CHANGE}/g' > {NEW_FILE_NAME}
    치환 결과를 다른 파일에 저장해야 할 때
$ sed -i 's/{ORIGINAL}/{CHANGE}/g' {FILE_NAME}
    치환 결과를 원본에 저장할때
```

#### sed undefined label
```bash
$ sed -i '.bak' 's/mkyong/google/g' testing.txt
$ ls -ls
8 -rw-r--r--  1 mkyong  staff  19 Aug  2 14:22 testing.txt
8 -rw-r--r--  1 mkyong  staff  19 Aug  2 14:21 testing.txt.bak
$ cat testing.txt
this is google.com
$ cat testing.txt.bak
this is mkyong.com
```
[undefined label error on Mac OS X](https://www.mkyong.com/mac/sed-command-hits-undefined-label-error-on-mac-os-x/)

## scp
---
secure copy
```bash
$ scp <옵션> <원본 경로 및 파일> <복사 받을 곳 경로 및 파일>

1) 원격 파일을 로컬로 복사해오기(ssh 포트 22번 아닐경우)
$ scp -p 22 urisystem@123.123.12.1:/home/test.txt /home/myhome/
    123.123.12.1 서버의 22번 포트로 SSH 접속하여 사용자로 로그인 한 후 test.txt 파일을 /home/oracle /아래에 복사

2) 원격 폴더 전체를 로컬로 복사 (-r 옵션)
$ scp -r -p 22 urisystem@123.123.12.1:/home/ ./

3) 로컬 파일을 원격서버로 올리기(ssh 포트 22번 아닐경우)
$ scp -p 22 ./text.txt urisystem@123.123.12.1:home/
    text.txt파일을 /home/oracle로
```
자주사용하는 옵션
* -P : 포트번호 지정
* -p : preserve의 약자로 원본 파일 시간의 수정시간, 사용시간, 권한을 유지한다.
* -r : recursive의 약자로 하위 폴더/파일 모두 복사한다.