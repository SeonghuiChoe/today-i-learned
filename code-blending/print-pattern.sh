#!/bin/bash
# 2017-02-20
# 문자열과 반복 횟수를 입력받아서 패턴으로 출력
# ex) 수박 3 => 수박수
#     수박 4 => 수박수박

function printPattern() {
    divide=$(($2/${#1}))
    mod=$(($2%${#1}))
    for ((i = 0; i < divide; i++)); do
        result="$result$1"
    done
    result="$result${1:0:$mod}"
}

printPattern $1 $2
echo $result
