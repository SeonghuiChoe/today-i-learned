# Promise
자바스크립트로 어플리케이션을 개발하다 보면 비동기 프로그래밍을 하지 않을 수 없다.

여러 이벤트를 순서대로 제어하고 싶을때

```javascript
$('.button').click(function(){
    setTimeout(function(){
      $.get('center-child-list.php',function(result){
        //..... });
      }, 1000);
    });
});
```
위와 같은 코드를 콜백 피라미드 악몽 <sub>callback pyramid of doom</sub> 이라고 한다.
이러한 비동기 프로그래밍에 대하여 Common JS Promises/A 스펙이 제안되었다.(jquery는 1.5이후)

```javascript
var promise = $.ajax();
promise.done(function(){});
promise.fail(function(){});
promise.always(function(){});
```

## $q
Common JS Promises/A 스펙에 대한 구현 API를 AngularJS는 $q 서비스를 이용해 제공.

## promise 객체
promise는 문자 그대로 약속을 표현하는 자바스크립트 객체다.

```javascript
var promiseWithStudent = Student.doHomework(homework);

promiseWithStudent.then(
    //then 메소드의 첫번째 인자로 전달되는 콜백함수는 약속이 지켜지면 실행된다.
    function(data) {
        if (Teacher.makeScore(data) === 100) {
            Teacher.giveCandy(100,Student);
        } else {
            Teacher.giveCandy(50,Student);
        }
    },
    //then 메소드의 두번째 인자로 전달되는 콜백함수는 약속을 어기면(취소/거절) 실행된다.
    function(error) {
        Teacher.punishStudent(10,Student);
    }
);
```
AngularJS는 $http, $timeoute, $resource, $route등 여러 서비스에서 promise 객체를 반환.

## Deferred