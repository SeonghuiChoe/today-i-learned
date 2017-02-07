# eval()
문자로써 표현된 javascript 코드를 실행하는 메소드.

> eval(*string*)

파라미터 string
* javascript표현식, 문장(statement), 연속적인 문장들을 나타내는 문자열이다.
* 표현식은 존재하는 객체들의 프로퍼티들과 변수를 포함할 수 있다.

전역 객체의 함수 프로퍼티
만약 문자열이 표현식을 나타낸다면, eval()은 표현식을 실행한다. 만약에 인자가 하나 이상의 javascript 문을 나타낸다면 문장들을 실행한다. 연산식을 계산하기 위해 호출하지 말것.

당신이 문자열로 연산식을 구성한다면, 나중에 그 식을 계산하기 위해 eval()을 사용할 수 있다.

```javascript
eval(new String("2 + 2")); // "2 + 2" 인 문자열 객체를 반환
eval("2 + 2");             // 4을 반환

당신은 toString() 을 사용하는 일반적인 방식으로 이 제약을 피할 수 있다.

var expression = new String("2 + 2");
eval(expression.toString());
```

eval 외에 참조를 통해 eval 함수를 호출하여 간접적으로 사용한다면(indirect call) ECMAScript 5부터는 지역 스코프 대신 전역 스코프에서 동작.
함수 선언은 전역 함수를 생성한다는 의미 이며, 수항할 코드는 그것이 호출 될 스코프 내의 지역 변수에 접근하지 않는다는 것을 의미.

```javascript
function test() {
  var x = 2, y = 4;
  console.log(eval("x + y"));  // 직접 호출은 지역 스코프를 사용하며, 결과는 6이다
  var geval = eval;
  console.log(geval("x + y")); // 간접 호출은 전역 스코프를 사용하며, `x` 가 정의되지 않았기 때문에 ReferenceError 를 던진다.
}
```

## 불필요하게 eval 을 사용하지 마라
eval() 은 caller 의 특권으로 통과한 코드를 수행하는 위험한 함수이다.
당신이 악의적인 영향을 받을 수 있는 문자열을 eval() 로 실행한다면, 당신의 웹페이지 / 확장프로그램의 허가를 가지는 사용자의 기계에서 악의적인 코드를 수행하게 될 것이다.
더 중요한건, 제 3의 코드가 eval() 이 적용된 스코프를 볼 수 있으며, 이것이 비슷한 Function 은 민감하지 않다는 면에서 공격 가능성을 야기할 수 있다.

또한 eval() 은 요즘 JS 엔진에 의해 최적화된 많은 다른 구조들에 비해, JS interpreter 를 적용해야 하기 때문에, 일반적으로 대안들보다 느리다.

eval() 의 일반적인 사용법을 위한 안전한 (그리고 빠른!) 대안이 있다.

멤버 프로퍼티들의 접근

당신은 프로퍼티들 내에서 프로퍼티 명을 변환하기 위해 eval() 을 사용해선 안된다.
코드가 실행될 때까지 접근될 객체의 프로퍼티가 알려져 있지 않은 다음의 예제를 고려해라. 이것은 eval 과 함께 사용될 수 있다:

```javascript
var obj = { a: 20, b: 30 };

function getPropName() {  // "a" 또는 "b" 를 반환
    var random = Math.floor(Math.random() * 2);
    return Object.keys(obj)[random];
}

var propname = getPropName();
eval( "var result = obj." + propname );

그러나, eval() 은 여기에 불필요하다. 사실, 여기서 그것을 사용하는 것은 말릴 일이다.
대신, 훨씬 빠르고 안전한 property accessors 를 사용해라:

var result = obj[ propname ];  //  obj[ "a" ] 는 obj.a 와 동일함
```
