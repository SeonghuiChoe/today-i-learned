# InAppBrowser cache

anuglar project를 build 하고 http-server로 서버에 올리고 패드에서 ionic project를 이용해 inappbroswer로 open했다. 출력은 잘되지만 만약 변경사항이 있어서 변경한뒤 build하고 적용하면 변경되기 전의 내용이 계속 출력된다. dist파일을 지우고 다시 build해봐도 전의 내용이 계속 나온다.

## Problem
문제는 캐시문제였다. 브라우저단의 캐시 문제가 걸려서 새로운 내용을 가져오지 못한다.

## Solution
1. [메타태그 입력](http://jhleed.tistory.com/73) 해본다.

2. [200 OK(from memory cache) vs 304](https://stackoverflow.com/questions/1665082/what-is-the-difference-between-http-status-code-200-cache-vs-status-code-304) 클라이언트쪽에서 캐시가 되버렸다.

3. [쿼리스트링](https://stackoverflow.com/questions/7413234/how-to-prevent-caching-of-my-javascript-file/7413283#7413283)을 추천한다. 메타태그 입력 html만 적용되는듯 하다.

4. [웹팩](https://medium.com/@tomaskoutsky/hey-webpack-can-you-bust-my-cache-21350f951220) - 파일이름에 해시값을 넣어서 다른 파일로 인식하도록 하는 방법

5. 시간이 지나면 캐시가 비워지는듯 하다.

6. 개발단계에서는 ``ionic-app-scripts build``를 통해 새로 빌드를 해준다.