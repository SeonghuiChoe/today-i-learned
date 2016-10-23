# C# Random Class
생성자는 오버로딩 되어있어 생성시 시드값을 정하거나 정하지 않을 수 있다.  
정할 경우 계속 같은 패턴의 난수가 발생한다.  
default일 경우에는 시스템의 시간을 이용하여 시드값을 정하기 때문에 매번 다른 패턴의 난수 발생.

## 제공하는 메소드
1. r.Next() : 범위가 없는 랜덤한 값을 리턴한다. ex r.Next() % 10
2. r.Next(int maxValue) : 난수의 범위의 상한을 지정.
3. r.Next(int minValue, int maxValue) : 난수의 범위의 하한과 상한을 지정.
4. r.Bytes() : byte 배열의 난수 발생
5. r.Double() : double 타입의 난 수 발생

난수의 하한은 난수에 포함되지만 상한은 포함되지 않는다.  
1부터 10의 값을 얻고 싶을때는 Next(1, 11)을 호출 해야한다.  
난수가 발생하는 빠른시간 순서 : Next(void) > Next(int maxValue) > Next(int minValue, int maxValue)