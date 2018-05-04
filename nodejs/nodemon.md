# [nodemon](https://github.com/remy/nodemon)
nodemon은 Node.js로 개발하면서 기본적으로 필요한 Application입니다.
nodemon을 시작하게되면 Directory안에 있는 File들을 관찰하면서 어떠한 파일이 바뀌더라도 감지하여 자동으로 Node application을 재시작합니다.

기본 사용법은 간단합니다.
```bash
npm i -g nodemon
```
Global로 설치하셔도 무관하지만 저는 Repository에 Install하는것을 더 선호합니다.
```bash
npm i -D nodemon
```

Local installation은 npm script나 npx를 사용해 실행합니다.

## Docker compose
Docker compose를 사용하면서 nodemon을 실행시키기 위해 Docker compose 파일에 설정을 추가합니다.
```yml
services:
    service-name:
        ports:
            - '9222:9222'
        ...
        command: [
            'node_modules/.bin/nodemon',
            '--inspect=0.0.0.0:9222',
            '--nolazy',
            'index.js'
        ]
```

### --inspect
디버깅을 위한 포트를 설정하고 npm script대신 node_modules/.bin로 실행합니다.

### [--nolazy](https://gist.github.com/sarupbanskota/a68e8148aa4cdc95e66a1b0e93df48ef#file-node_8_v8_options-L626)
- --nolazy는 node option중 v8의 lazy compliation을 쓰지 않는다는 설정입니다.
- --lazy는 --lazy==false 이와 같은 식이 아닌 --nolazy로 설정합니다. [Issue](https://github.com/nodejs/node-v0.x-archive/issues/6982)

