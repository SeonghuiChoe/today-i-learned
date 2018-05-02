# Popup

## Parent function call

Global scope를 침범 하지 않기 위해 Global에 function을 정희 하지 않고 open한 popup에 function을 정의하고 호출하면 좀 더 안전하고 꺼림칙하지 않은 코드를 작성한다.

```javascript
// prarent
var popup = $window.open();
popup.somefunction = function () {}
// child
$winow.somefunction();
```
