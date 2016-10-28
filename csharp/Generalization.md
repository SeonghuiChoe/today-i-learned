# Generalization(일반화)
간단히 서로 다른 개념에서 공통점을 찾는것이다. 이렇듯 어떤 개념을 포괄하는 공통된 개념을 찾아 서로 다른 개념들을 하나로 묶어 줄 수 있다.

## Generalization method
int, float, string 등의 다른 타입을 변수라는 개념으로 묶어줄 수 있다.

```csharp
void print(int A) { console.WriteLine(A) }
void Print(float B) { console.WriteLine(B) }
void Print(string C) { console.WriteLine(C) }

void print<T> (T value) { console.WriteLine(value) }
    T(형식 매개변수)
```

```csharp
namespace Cs_Lecture
{
    class Program
    {
        static void print<T>(T value)
        {
            console.WriteLine(value);
        }

        static void Main(string[] args)
        {
            int age = 3;
            float height = 35.1f;
            string name = "Mocha"

            print<int>(age);
            print<float>(height);
            print<string>(name);
        }
    }
}
```

## Generalization Class
타입마다 서로 다른 클래스를 만드는것은 상당히 비효율적이다.

```csharp
class List_int { public int[] arr; }
class List_float { public float[] arr; }
class List_string { public string[] arr; }

class List<T> { public T[] arr;) }
```

```csharp
namespace Cs_Lecture
{
    class List<T>
    {
        public T[] arr;

        public List() { arr = new T[1];}
    }
    class Program
    {
        static void Main(string[] args)
        {
            List<int> list1 = new List<int>();
            list1.arr[0] = 10;
            List<float> list2 = new List<float>();
            list2.arr[0] = 2.2f;
            list<string> list3 = new List<string>();
            list3.arr[0] = "Generalization Class";

            console.WriteLine(list1.arr[0]);
            console.WriteLine(list2.arr[0]);
            console.WriteLine(list3.arr[0]);
        }
    }
}
```

## T 변수 제약조건 만들기
특정 조건을 갖춘 타입으로만 치환이 가능하도록 제한을 하고 싶을때 사용.
'Where T' T가 어디에 있어야 한다(어디에 속해야한다)라는 의미로 해석될 수 있다.
where라는 키워드로 T타입 범위를 지정

```csharp
where 형식매개변수 : 제약조건
class List<T> where T : class {}
void Print<U> where U : struct {}
```

```csharp
where T : new()
    T는 매개변수가 없는 생성자를 가진 타입이어야 한다.
where T : 클래스이름
    T는 지정한 클래스이거나 이를 상속받는 클래스이어야 한다.
where T : 인터페이스 이름
    T는 인터페이스를 상속받는 클래스 이어야 한다.
where T : U
    T는 형식매개 변수 U의 타입이거나, 이를 상속받는 클래스 이어야 한다.
```

```csharp
namespace Cs_Lecture
{
    class Parent
    {
        public string name { set; get; }
        public Parent() { name = "부모 클래스"; }
    }
    class Children : Parent
    {
        public Children() { name = "자식 클래스"; }
    }
    class List<T> where T : Parent
    {
        public T[] array;
        public List() { array = new T[2]; }
    }
    class Program
    {
        static void Main(string[] args)
        {
            List<Parent> list = new List<Parent>();

            list.array[0] = new Parent();
            list.array[1] = new Children();

            Console.WriteLine(list.array[0].name);
            Console.WriteLine(list.array[1].name);
        }
    }
}
```
