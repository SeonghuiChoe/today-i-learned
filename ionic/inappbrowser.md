# Inappbrowser

## whitelist
첫번째, Ionic 앱 안에 Web을 열고 싶다. 그럼 Inappbrowser를 쓰라고 한다.
```bash
ionic cordova plugin add cordova-plugin-inappbrowser
```

이렇게 간단히 코딩은 한다.
```typescript
import { InAppBrowser } from '@ionic-native/in-app-browser';

constructor(private iab: InAppBrowser) {}
const browser = this.iab.create('url', 'target', 'options');
```
결과는 모든 target(_blank, _self, _system)이 전부 앱을 뒤로한채 새로운 웹페이지가 나온다. 나는 앱안에 웹을 원한다!

몇일 동안 고민했는데 결국 찾았다.
```html
<allow-navigation href="*" />
<!-- 플러그인 -->
<plugin name="cordova-plugin-whitelist" spec="1.3.3" />
```
이녀석만 넣어주면 해결.
이동하려는 URL을 whitelist에 등록하면 된다. 그래서 모든 URL을 허용해준것
