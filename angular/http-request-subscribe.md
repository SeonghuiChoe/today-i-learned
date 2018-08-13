# Http request and subscribe
Promise에서 Observable로 변경하면서 나타난 이슈

## Http - @angular/http
처음에는 http를 사용해서 ajax요청을 해서 toPromise()를 이용해 promise객체로 만들어서 ajax service를 사용하는 쪽에서 then을 사용하는 방식을 사용했다. 버전업을 하면서 ``HttpClient``를 사용해야한다. 

## HttpClient - @angular/common/http
request를 사용했는데 반환이 Observable이기 때문에 사용하는 쪽에서 subscribe를 해서 다음 행동을 하면된다.

### Solution - Subscribe
프로젝트중에 사용자가 알람을 설정하거나 제거하는 기능만 안되길래 살펴보니 get은 상관없지만 다른 메소들은 다음일이 없더라도 subscribe를 해야한다. 
