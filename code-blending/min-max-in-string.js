/**
 * 2017-02-09
 * 문자열에서 최소값과 최대값 출력
 * ex) "1 2 3 4" => "1 4"
 */

var input = '1 2 33 4';
var arr = input.match(/\d+/g).map(n => parseInt(n));

var arrMinMax = arr.reduce((pre, curr) => {
    var min  = curr < pre[0] ? curr : pre[0];
    var max = curr > pre[1] ? curr : pre[i];
    return [min, max];
}, [arr[0], arr[0]]);


console.log('input:', input);
console.log('min:', arrMinMax[0]);
console.log('max:', arrMinMax[1]);
