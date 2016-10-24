# HashTable VS Dictionary
* csharp 에서는 key 와 value를 사용해서 자료를 저장하는 타입이 hashtable과 dictionary이다.
* 사용법은 거의 동일하지만 내부적으로 처리하는 기술이 다르다.

## **HashTable**
```csharp
HashTable hashtable = new Hashtable();

hashtable.Add("data1", new Cat() { name = "mocha", age = 3 });
hashtable.Add("data1", new Cat() { name = "ccino", age = 2 });

if (hashtable.ContainKey("data1").Equals(true)) {
    Cat cat = hashtable["data1"] as Cat; // (Un-Boxing)
    Console.WriteLine(cat.name);
}

foreach (string key in hashtable.Keys) {
    Cat cat = hashtable[key] as Cat;
    Console.WriteLine(cat.name);
}
```

1. Non-Generic
2. Key와 Value 모두 Object를 입력 받는다.
3. Boxing/Un-Boxing을 사용한다.

## **Dictionary**

```csharp
Dictionary<string, Cat> dictionary = new Dictionary<string, Cat>();

dictionary.Add("data1", new Cat() { name = "mocha", age = 3 });
dictionary.Add("data1", new Cat() { name = "ccino", age = 2 });

if (dictionary.ContainKey("data1").Equals(true)) {
    Console.WriteLine(dictionary["data1"].name);
}

foreach (Cat cat in dictionary.Values) {
    Console.WriteLine(cat.name);
}
```

1. Generic
2. Key와 Value 모두 Strong Type을 입력받는다. (선언시 타입을 입력해줘야 함)
3. Boxing/Un-Boxing을 사용하지 않는다.

## 결론
* 두가지 타입 타입은 내부적인 처리와 수용하는 타입의 형태가 다르므로 필요에 따라 선택한다.
* 고정적으로 하나의 타입만 입력받을 시 dictionary Value에 일정한 형식이 없고 여러 형태를 저장하려면 hashtable