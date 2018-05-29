# Ion-slides
App에 간단한 tutorial을 노출 시키기위해 ion-slide를 사용할 수 있다.

template
```html
<ion-slides>
  <ion-slide>
    <h1>Slide 1</h1>
  </ion-slide>
  <ion-slide>
    <h1>Slide 2</h1>
  </ion-slide>
</ion-slides>
```
slide는 따로 swipe를 생각 안해도 자연스럽게 화면이 넘어가도록 되어있다.

## swiper-slide
원하는 큰 이미지 하나로 여러 디바이스를 고려했을때 ion-slides의 css를
```css
.wrap {
  width: 100%;
  height: 100%;
}
```
이렇게 되면 넓이를 맞추고 높이가 가운데로 설정된다.

넓이를 맞추고 이미지 상단부터 보이도록 설정 하고 싶을때는
- ion-slide의 swiper-slide css와
- ion-slide가 자동으로 만들어주는 slide-zoom class의 height를 설정하고
- swiper-slide 안에 img class에 max-height를 none 해줘야 원하는 디자인이 가능하다.
```css
  .swiper-slide,
  .slide-zoom {
    height: 100%;

    .img {
      max-height: none;
    }
  }
```
