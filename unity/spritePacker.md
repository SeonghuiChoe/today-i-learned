# Sprite Packer
* Unity 4.6부터 UGUI제공한다.
* NGUI는 직접적으로 Atlas파일을 생성하지만 UGUI에서는 추상적으로 packing.
* UGUI에서 만들어지는 Atlas는 Library/AtalsCashe에 생성해 관리한다.

## Inside Resources Folder
* Resources안에서 packing을 하게되면 이중으로 메모리를 사용하기 때문에 엔진 자체에서 불가능 하게 되어있다.
* 다른 폴더로 옮긴뒤 Atals를 만들고 다시 리소스 폴더로 파일들을 옮겨 실행하면 가능하지만, 매번 packing을 해줘야 하기에 효율적이지 못하다.


# 참조
[사용영상](https://www.youtube.com/watch?v=Pj8Y48ecBZY)

[unity-4-5-sprite-packer-does-not-pack-images-inside-resources-folder](https://forum.unity3d.com/threads/unity-4-5-sprite-packer-does-not-pack-images-inside-resources-folder.248349/)
