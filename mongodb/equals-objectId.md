# Equals objectId
node에서 mongoose를 사용중이다. 단순히 mongodb에서 document들이 갖고 있는 _id 를 비교하려 했다.
```javascript
const a: ObjectId;
const b: ObjectId;
a === b;
```
내 머리로는 당연히 될줄 알았는데 string으로 변환해서 비교하면 되지만 저 비교는 내가 원하는 비교가 되지 않았다. 찾아보니
```javascript
a.equals(b);
```
ObjectId에 equals가 있어서 그걸 사용하면 된다. ObjectId는 단순히 내가 설정한 field만 있는것이 아니였다. _id를 사용하기위해 id라는 field도 만들어서 사용하고있었는데 기본으로 제공되고 있었다. mongodb에서 반환된 객체에는 정말 많은 정보들을 담고 있었다.
