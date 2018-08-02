# Cannot add foreign key constraint in mysql.

[아무이유없이 FK가 걸리지 않을 경우](http://blog.lyuwonkyung.com/amu-iyu-eobsi-mysql-foreign-key-an-geolril-ddae/)

정말 위에 제목처럼 아무 이유없이 FK가 걸리지 않는 현상이 나타났다. 계속해서 나는 오류에 검색을 해보니, 위에 글을 찾을 수 있었다.

mysql에서 ``SHOW ENGINE INNODB STATUS;``를 정보가 나온다. 보기 어려우니 복사해서 다른곳에서 붙여넣기를 해서 ``LATEST FOREIGN KEY ERROR``이 부분을 확인하면 락이 걸려있는걸 확인 할 수 있었다.

### Solution
``SET FOREIGN_KEY_CHECKS=0;`` 접속 세션에 대해 FK 검사를 일시적으로 무시하도록 만들고 다시 FK를 걸면 잘된다는 내용이다. 일시적으로 무시한다고 해서 조금 덜 부담스럽지만 그래도 왜 락이 걸려있는지 모르는 상황에서 작업하는게 조금 꺼림칙했다. 그래도 일시적으로 풀어보니 FK가 잘 걸렸다.

### More
FK만 넣으면 될줄 알았는데 아무 문제 없는 데이터를 insert하려고 하니 문제가 다시 발생해서 결국은 FK를 없애고 작업했다. 누가 락을 걸어놨는지 몰라서 답답히고 찝찝하지만 해결은 했다.
