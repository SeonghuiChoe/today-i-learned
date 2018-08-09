# Close InAppBrowser

단순히 InAppBrowser를 close하는 방법은 간단하다.

InAppBrowser를 만든 App에서 종료하거나, 켜진 InAppBrowser가 자신을 닫게 해본다. 

## browser.close();
App에서 종료할때는 단순히 open한 객체를 담아서 그 browser를 close(); 하라고 나온다. 

## Window.close();
켜진 InAppBrowser에서 자신을 닫을 때는 window.close();를 쓴다. 하지만 여기서 종료가 되지 않는다. ``Scripts may not close windows that were not opened by script.`` 라는 메세지를 받을 수 있게 되는데 자신이 open하지 않은 창은 닫을 수 없다는 내용이다. 

### window.open and close
자기 자신에서 창을 하나 키고 close를 해보라고 하는 글들을 많이 찾았다.
- [하지만 이제는 되지 않는듯 하다.](http://blog.daum.net/_blog/BlogTypeView.do?blogid=0e3oM&articleno=187&categoryId=8&regdt=20170316144956)
- [chrome update](https://code.i-harness.com/ko/q/12d8859)

## About:blank
결국 뒤로가기 버튼을 누르면 종료가 되니 그렇게 종료하거나 App에서 종료하는걸로 결정했다. 그런데 문제는 종료된듯 하면서도 ``chrome://inspect/#devices``로 확인해보면 꼭 ``about:blank``가 생성되서 사라지지 않는 현상이 발생했다. 다시 앱을 키고 반복하면 ``about:blank``가 계속해서 쌓이다가 어느순간 사라진다.

### Solution
open target을 바꿔봐도 해결이 안되다가 테스트를 계속해보니 생성되던 about:blank는 자동으로 생성되고 시간이 지나면 자동으로 사라지면서 앱은 정상작동하는것을 확인했다. ``about:blank``는 우리가 제거하는 영역이 아닌것 같다.
