# Current working directory is not a Cordova-based project

``Ionic platform add android`` 혹은 ``cordova platform add android``를 하는데 <br>``Current working directory is not a Cordova-based project``라는 문장을 볼 수 있다.

### Solution

간단한 해결방법은 root directory 안에  www [폴더를 만들면 해결된다.](https://github.com/ionic-team/ionic-cli/issues/935)

 > For posterity: usually the solution is to make sure there's a www/ directory inside the root directory.
mkdir www in your project folder and it works well.

빌드할때 났던 에러였는데 www 폴더를 만들어주니 에러는 안나지만 근본적인 해결방법이 아니다. ``www/index.html``을 찾는데 없기 때문에 또다시 오류를 만나게된다.

```bash
npx ionic-app-scripts build
```
원하는 www 폴더를 만들어주기위해 빌드를 하면 정상적으로 작동한다.
