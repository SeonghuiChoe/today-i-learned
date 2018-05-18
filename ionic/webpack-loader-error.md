# Webpack loader error
When we build ionic project 'npm run ionic:build -- --prod'.

```bash
[08:28:22]  Error: Entry module not found: Error: Can't resolve '@angular-devkit/build-optimizer/webpack-loader' in
            '/usr/local/app' resolve '@angular-devkit/build-optimizer/webpack-loader' in '/usr/local/app' Parsed request
            is a module using description file: /usr/local/app/package.json (relative path: .) after using description
            file: /usr/local/app/package.json (relative path: .) resolve as module /usr/local/node_modules doesn't exist
            or is not a directory /usr/node_modules doesn't exist or is not a directory /node_modules doesn't exist or
            is not a directory looking for modules in /usr/local/app/node_modules using description file:
            /usr/local/app/package.json (relative path: ./node_modules) after using description file:
            /usr/local/app/package.json (relative path: ./node_modules) using description file:
            /usr/local/app/package.json (relative path: ./node_modules/@angular-devkit/build-optimizer/webpack-loader)
            no extension /usr/local/app/node_modules/@angular-devkit/build-optimizer/webpack-loader doesn't exist .js
            /usr/local/app/node_modules/@angular-devkit/build-optimizer/webpack-loader.js doesn't exist .json
            /usr/local/app/node_modules/@angular-devkit/build-optimizer/webpack-loader.json doesn't exist as directory
            /usr/local/app/node_modules/@angular-devkit/build-optimizer/webpack-loader doesn't exist
Error: Entry module not found: Error: Can't resolve '@angular-devkit/build-optimizer/webpack-loader' in '/usr/local/app'
resolve '@angular-devkit/build-optimizer/webpack-loader' in '/usr/local/app'
  Parsed request is a module
  using description file: /usr/local/app/package.json (relative path: .)
  after using description file: /usr/local/app/package.json (relative path: .)
    resolve as module
      /usr/local/node_modules doesn't exist or is not a directory
      /usr/node_modules doesn't exist or is not a directory
      /node_modules doesn't exist or is not a directory
      looking for modules in /usr/local/app/node_modules
        using description file: /usr/local/app/package.json (relative path: ./node_modules)
        after using description file: /usr/local/app/package.json (relative path: ./node_modules)
          using description file: /usr/local/app/package.json (relative path: ./node_modules/@angular-devkit/build-optimizer/webpack-loader)
            no extension
              /usr/local/app/node_modules/@angular-devkit/build-optimizer/webpack-loader doesn't exist
            .js
              /usr/local/app/node_modules/@angular-devkit/build-optimizer/webpack-loader.js doesn't exist
            .json
              /usr/local/app/node_modules/@angular-devkit/build-optimizer/webpack-loader.json doesn't exist
            as directory
              /usr/local/app/node_modules/@angular-devkit/build-optimizer/webpack-loader doesn't exist
    at new BuildError (/usr/local/app/node_modules/@ionic/app-scripts/dist/util/errors.js:16:28)
    at callback (/usr/local/app/node_modules/@ionic/app-scripts/dist/webpack.js:121:28)
    at emitRecords.err (/usr/local/app/node_modules/@ionic/app-scripts/node_modules/webpack/lib/Compiler.js:269:13)
    at Compiler.emitRecords (/usr/local/app/node_modules/@ionic/app-scripts/node_modules/webpack/lib/Compiler.js:375:38)
    at emitAssets.err (/usr/local/app/node_modules/@ionic/app-scripts/node_modules/webpack/lib/Compiler.js:262:10)
    at applyPluginsAsyncSeries1.err (/usr/local/app/node_modules/@ionic/app-scripts/node_modules/webpack/lib/Compiler.js:368:12)
    at next (/usr/local/app/node_modules/tapable/lib/Tapable.js:218:11)
    at Compiler.compiler.plugin (/usr/local/app/node_modules/@ionic/app-scripts/node_modules/webpack/lib/performance/SizeLimitsPlugin.js:99:4)
    at Compiler.applyPluginsAsyncSeries1 (/usr/local/app/node_modules/tapable/lib/Tapable.js:222:13)
    at Compiler.afterEmit (/usr/local/app/node_modules/@ionic/app-scripts/node_modules/webpack/lib/Compiler.js:365:9)
```

## Solution
npm i @ionic/app-scripts@3.1.8
