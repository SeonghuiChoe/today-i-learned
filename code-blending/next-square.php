<?php
    /**
     * 2017-02-12
     * 입력받은 n의 제곱근 x가 정수라면 x + 1의 제곱 출력
     * 아니라면 'no' 출력
     * ex) 121 => 144
     * ex) 3 => 'no' 
     */

    $input1 = 3;
    $input2 = 121;
    function nextsquare($n) {
        $sqrt = sqrt($n);
        $floor = floor($sqrt);
        $diff = $sqrt - $floor;
        $result = $diff == 0 ? pow($sqrt + 1, 2) : 'no';
        return $result;
    }
    echo "num(3) : ".nextsquare($input1)."\n";
    echo "num(121) : ".nextsquare($input2)."\n";
?>
