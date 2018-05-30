# Ionic liveloading
Docker를 이용해서 ionic serve를 실행할 경우

```bash
docker run -p 8100:8100 docker-ionic
```
-ti --rm -v -w 와 같은 옵션은 빼고 담백하게 -p에 대해서만 설명하자면

## Liveloading port
Docker container안 8100 port와 host의 8100 port만 연결해 주면
저장할때 liveloading이 되지 않는다.

보기좋게 줄바꿈
```bash
docker run \
    -p 8100:8100 \
    -p 35729:35729 \
    -p 53703:53703 \
    docker-ionic
```
이렇게 Liveloading에 필요한 port도 연결해줘야 host의 변경사항으로 liveloading이 가능해진다.
