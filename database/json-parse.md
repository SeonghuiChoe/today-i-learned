# JSON Parse
JSON Text를 Object로 변환.

JSON Text : JSON의 형태이지만 자바스크립트에서 Object가 아닌 텍스트로만 인식. Object로 바꾸어야 사용 가능.

Ajax로 호출을 하고 결과값으로 받은 req.responseText로 JSON을 받았을 경우에는 그냥 Text이기 때문에 Object로 변환해 주어야 한다.

> { id:'test', sex:'18' }

Ajax에서 리턴받을 JSON의 형태가 위와 같이 되어 있을 경우 eval을 해주면 JSON 오브젝트로 변환할 수 있다.

```javascript
var obj = eval("("+returnValue.responseText+")");
alert(obj.id);  // test
```

 > [ { id:'test', sex:'18' },
  { id:'mocha', sex:'3' } ]

JSON이 위의 형태처럼 배열로 되어 있을 경우에는

```javascript
var obj = eval(returnValue.responseText);
// { id:"test", sex:"18" }
```

```eval()```은 빠르지만 단순히 스트링 실행하기 때문에 리턴값으로 자바스크립트 명령문이 온다면 그대로 실행시켜버리기 때문에 보안이슈가 발생.

이렇게 리턴받은 소스를 신뢰하기 어려울 때는 JSON.org에서 제공하는 JSON parser을 사용. JSON parser는 오직 JSON text만 받아들이고 다른 스크립트는 거부하고 ```eval()```만큼이나 빠르다.

```javascript
var obj = JSON.parse(returnValue.responseText);
// { id:"Outsider", sex:"male" }
```

* JSON.parse()의 목적대로 JSON 텍스트 외에는 거부해야하기 때문에 JSON문법을 정확히 지켜주지 않으면 SyntaxError 예외가 던져진다.
* 키와 값을 모두 쌍따옴표로 묶어주는 문법을 정확하게 지켜주어야 한다.(string)
* ```JSON.stringify()```는 ```JSON.parse()```와는 완전히 반대로 JSON 객체를 주면 JSON 텍스트로 만들어서 준다.
