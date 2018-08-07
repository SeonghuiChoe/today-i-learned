# Angular http request 401 catch

Ajax를 요청해서 401 error를 처리하고 싶을때에 catchError를 사용하면된다.

## 기존 코드
```javascript
this.http.request(req).pipe(
  last(),
  map((m: HttpResponse<anY>) => {
    return m.body;
  }),
);
```

## 변경 코드
단순히 map안에 m.status를 확인해서 401을 잡아내려고 했는데 map에 가기도 전에 throw를 날리기 때문에 불가능 했다.
[Angular 문서](https://angular.io/guide/http)를 보고 catchError를 사용하기로 한다.
```javascript
this.http.request(req).pipe(
  catchError((err: any): any => {
    if (err.status === 401) {
      // 원하는 코드
    }
    return throwError(err);
  }),
  ... // 동일한 코드
)
```

이렇게 하니 잘 동작하지만 thorw를 던졌기 때문에 console에 error는 남는다.
