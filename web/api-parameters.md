## API의 상태 parameter의 값을 결정하는 방법
사용하는 API에 비슷한 로직이 생기면서 중복을 없애기 위해 특정한 parameter를 넘겨주면서 같은 API가 다른 동작을 하도록 로직을 만든다.

예를들어 어떤 함수가 있는데 parameter를 이용해 게시글을 등록하거나 수정하는 일들을 구분해서 실행한다.

작업하던 코드에서 enum과 같이 숫자를 넘겨주던가 'Y', 'N'와 같은 문자를 넘겨주는 부분을 많이 봤는데, 이 방식이 옳은것인지 대해 고민을 하게 되었다.

### GitHub API 방식
- ``Edit an issue`` 부분에 'state'라는 parameter가 있는데, description에
``State of the issue. Either open or closed.``라고 적혀있다.
의미를 알 수 없는 숫자여서 그 숫자의 의미를 찾아야 되는 것 보다 ``open, closed`` 처럼 의미를 바로 알 수 있도록 값을 보내는 방식을 GitHub는 사용하고 있었다.

**Parameters**

| Name   |      Type      |  Description |
|----------|:-------------:|------:|
| state |  string | State of the issue. Either open or closed. |


```json
{
  "title": "Found a bug",
  "body": "I'm having a problem with this.",
  "assignee": "octocat",
  "assignees": [],
  "milestone": 1,
  "state": "open",
  "labels": [
    "bug"
  ]
}
```