/**
 * 2017-02-10
 * 정수의 짝수 홀수 판별 프로그램
 */
package main

import "fmt"

func isEvenOdd(n int) string {
    result := "odd"
    if n % 2 == 0 {
        result = "even"
    }
    return result 
}

func main() {
    num := 3
    num2 := 8

    fmt.Println(num, isEvenOdd(num))
    fmt.Println(num2, isEvenOdd(num2))
}

