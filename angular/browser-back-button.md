# Angular browser back button

Angular를 이용해서 project를 만들었는데 디바이스에서 back button를 눌렀때 어떤 동작을 하고 싶다면
```javascript
import { PlatformLocation } from '@angular/common';

constructor(private location: PlatformLocation) {
  location.onPopState(() => {
    console.log('pressed back!!');
  }
}
```

[이렇게 하면 back button이 눌렸을때 'pressed back!!'이 출력되는걸 볼 수 있다.](https://stackoverflow.com/questions/40381814/how-do-i-detect-user-navigating-back-in-angular2)

하지만 보고 있는 화면에서만 출력될 줄 알았는데 다른 페이지에서 돌아오기 위해 누른 backbutton도 감지 하고 있는것 같다.  

