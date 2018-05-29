# Inappbrowser

## whitelist
Ionic 앱 안에 Web을 열고 싶다. 그럼 **Inappbrowser**
```bash
ionic cordova plugin add cordova-plugin-inappbrowser
```

이렇게 간단히 쓸수 있다.
```typescript
import { InAppBrowser } from '@ionic-native/in-app-browser';

constructor(private iab: InAppBrowser) {}
const browser = this.iab.create('url', 'target', 'options');
```
결과는 모든 target(_blank, _self, _system)이 전부 앱을 뒤로한채 새로운 웹페이지가 나온다. 나는 앱안에 웹을 원한다!

이 문제의 해결책은!
```html
<allow-navigation href="*" />
<!-- 플러그인 -->
<plugin name="cordova-plugin-whitelist" spec="1.3.3" />
```
이녀석만 넣어주면 해결.
이동하려는 URL을 whitelist에 등록하면 된다. 그래서 모든 URL을 허용해준것

## loadstop
splashScreen이 시작되고 꺼지더니 흰화면이 계속되다가 켜지는 웹.
splashScreen이 웹이 켜지기 전까지 계속 실행되려면 loadstop event를 사용한다.

```typescript
browser.on('loadstop').subscribe(event => {
    this.splashScreen.hide();
    browser.show();
});
```
로드가 끝나면 splashScreen를 감추고 웹을 보여줘!

결과는..
```
browser.on(...).subscribe is not a function
```
계속해서 이 error를 보다가 찾아낸 [해결책](https://forum.ionicframework.com/t/inappbrowser-loadstart-loadstop-etc-not-working-help/38685/5)은

> The events do not fire when _self target is used. The events fire when _blank target is used

target을 _self로 계속 테스트 해서 안되고 있었던것. _blank로 변경하자.

