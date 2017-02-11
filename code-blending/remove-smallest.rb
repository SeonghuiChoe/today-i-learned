# 2017-02-11
# 배열에서 가장 작은 수 제거

array = [4, 3, 5, 33, 2, 10]
min = array.inject(array[0]) { 
    |min, n|
        if  min < n 
            min
        else
            n
        end
}
 
puts "before: #{array}\n"
array.delete(min)
puts "after : #{array}\n"
 
