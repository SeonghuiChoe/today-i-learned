object SumDigits {
    def sumDigit(digits: Int) : Int = {
        var sum = 0
        var dgs = digits
        while (dgs != 0) {
            sum = sum + (dgs % 10)
            dgs = dgs / 10
        }
        
        return sum
    }
    def main(args: Array[String]) {
        var num = sumDigit(args(0).toInt)
        println(args(0) + " => " +  num)
    }   
}
