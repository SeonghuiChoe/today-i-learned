# Hash Table

데이터를 담는 테이블을 미리 크게 확보해 놓은 후 입력받은 데이터를 해시하여 테이블 내의 주소를 계산하고 이 주소에 데이터를 담는 궁극의 탐색 알고리즘, 공간을 팔아 얻어낸 성능이다.

데이터가 입력되지 않는 여유공간이 많아야 제 성능을 유지(70%~ 80%)하며 캐시 구현에 사용됨.

* Hash Table is store data in associative manner.
* In hash table, data is stored in array format where each data values has its own unique index value.
* Access of data becomes very fast if we know the index of desired data.
* Thus, it becomes a data structure in which insertion and search operations are very fast irrespective of size of data.
* Hash Table uses array as a storage medium and uses hash technique to generate index where an element is to be inserted or to be located form.

## Hashing
Hashing is a technique to convert a range of key values into a range of indexes of an array.

## Linear Probing
It may happen that the hashing technique used create already used index of the array.

In such case, we can search the next empty location in the array by looking into the next cell until we found an empty cell.

## 용어
* Collision : 동일한 해시 값, 즉 동일한 주소 반환하는 것. 충돌은 피할 수 없다.
* Cluster : 일부 지역의 주소들을 집중적으로 반환 하는 결과로 데이터들이 한곳에 모이는 문제.

[알고리즘 종류 및 충돌 해결 방법](http://luyin.tistory.com/191)

## 테이블 크기
나머지 연산의 값이 최대한 중복되지 않도록 테이블의 크기를 소수로 만드는 것이다.

소수로 만드는 것이 충돌을 줄이는 방법이지 [해결하기 위한 방법은 아니다](http://hyeonstorage.tistory.com/265)