# noStrictGenericChecks

ionic build시 rxjs에서 이런 에러가 출력되면서 빌드가 안된다.

```bash
Running app-scripts build:
[03:42:34]  build dev started ...
[03:42:34]  clean started ...
[03:42:34]  clean finished in 8 ms
[03:42:34]  copy started ...
[03:42:35]  deeplinks started ...
[03:42:35]  deeplinks finished in 492 ms
[03:42:35]  transpile started ...
[03:42:44]  typescript: node_modules/rxjs/Subject.d.ts, line: 16
            Class 'Subject<T>' incorrectly extends base class 'Observable<T>'. Types of property 'lift' are
            incompatible. Type '<R>(operator: Operator<T, R>) => Observable<T>' is not assignable to type '<R>(operator:
            Operator<T, R>) => Observable<R>'. Type 'Observable<T>' is not assignable to type 'Observable<R>'. Type 'T'
            is not assignable to type 'R'.

      L16:  export declare class Subject<T> extends Observable<T> implements ISubscription {
      L17:      observers: Observer<T>[];

Error: Failed to transpile program
    at new BuildError (/usr/local/app/node_modules/@ionic/app-scripts/dist/util/errors.js:16:28)
    at /usr/local/app/node_modules/@ionic/app-scripts/dist/transpile.js:159:20
    at new Promise (<anonymous>)
    at transpileWorker (/usr/local/app/node_modules/@ionic/app-scripts/dist/transpile.js:107:12)
    at Object.transpile (/usr/local/app/node_modules/@ionic/app-scripts/dist/transpile.js:64:12)
    at /usr/local/app/node_modules/@ionic/app-scripts/dist/build.js:109:82
    at <anonymous>
[03:42:45]  copy finished in 10.86 s
```

noStrictGenericChecks를 tsconfig에 추가해주면 해결된다.

### tsconfig.json
```json
{
    "compilerOptions": {
        "noStrictGenericChecks": true,
        ...
    },
    ...
}
```
