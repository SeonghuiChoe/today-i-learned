# Promise
자바스크립트로 어플리케이션을 개발하다 보면 비동기 프로그래밍을 하지 않을 수 없다.

여러 이벤트를 순서대로 제어하고 싶을때

```javascript
$('.button').click(function (){
    setTimeout(function (){
        $.get('center-child-list.php', function (result){
            //..... 
        });
      }, 1000);
    });
});
```
위와 같은 코드를 콜백 피라미드 악몽 <sub>callback pyramid of doom</sub> 이라고 한다.
이러한 비동기 프로그래밍에 대하여 Common JS Promises/A 스펙이 제안되었다.(jquery는 1.5이후)

```javascript
var promise = $.ajax();
promise.done(function (){});
promise.fail(function (){});
promise.always(function (){});
```

## $q
Common JS Promises/A 스펙에 대한 구현 API를 AngularJS는 $q 서비스를 이용해 제공.

## promise 객체
promise는 문자 그대로 약속을 표현하는 자바스크립트 객체다.

```javascript
var promiseWithStudent = Student.doHomework(homework);

promiseWithStudent.then(
    //then 메소드의 첫번째 인자로 전달되는 콜백함수는 약속이 지켜지면 실행된다.
    function (data) {
        if (Teacher.makeScore(data) === 100) {
            Teacher.giveCandy(100, Student);
        } else {
            Teacher.giveCandy(50, Student);
        }
    },
    //then 메소드의 두번째 인자로 전달되는 콜백함수는 약속을 어기면(취소/거절) 실행된다.
    function (error) {
        Teacher.punishStudent(10, Student);
    }
);
```
AngularJS는 $http, $timeoute, $resource, $route등 여러 서비스에서 promise 객체를 반환.

## Promise all ($q.all)

```javascript
factory('asyncService', function($http, $q) {
  return {
    loadDataFromTwoReq: function () {
      var deferred = $q.defer(),
          httpPromise1 = $http.get('/api/req1'),
          httpPromise2 = $http.get('/api/req2');

      //두 약속을 $q.all 메서드를 이용해 새로운 약속을 만든다.
      $q.all(httpPromise1, httpPromise2)
        .then(
          function (results) {
            //두 약속이 모두 지켜지면 asyncService서비스가 반한하는 약속을 지키고 두 약속이 전달하는 결과를 묶은 배열로 전달한다.
            deferred.resolve(results)
          },
          function (errors) {
            deferred.reject(errors);
          },
          function (updates) {
            deferred.update(updates);
        });
      return deferred.promise;
    }
  };
});
```

## Deferred
약속을 만들고 이 약속의 상태를 변경.
AngularJS에서는 $q.defer()를 이용해 deferred객체를 생성할 수 있다. (deferred객체의 생성은 곧 promise의 생성이기도 하다.)
resolve, reject, notify를 통해 약속을 지키거나 거절/취소와 같은 진행 상태를 알려준다.

```javascript
angular.module('demo-app', [])
    .factory('userService', function ($http, $log, $q) {
        return {
            getUser: function (userId) {
                //deferred 객체를 생성한다.
                var deferred = $q.defer();
                $http.get('/api/users/' + userID)
                    .success(function (data) {
                        //요청이 성공하면 약속을 지키고 별도 데이터를 전달한다.
                        deferred.resolve({
                        name: data.name,
                        address: data.address});
                    }).error(function (msg, code) {
                        //요청이 실패하면 약속을 취소하고 메시지를 전달한다.
                        deferred.reject(msg);
                        $log.error(msg, code);
                    });
                //해당 deferred 객체의 약속을 반환한다.
                return deferred.promise;
            }
        }
});
```
