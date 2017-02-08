
# 2017-02-08
# 숫자 배열의 평균 구하기

def number_list_average(numbers):
    """Return the average of array"""
    return sum(numbers)/len(numbers)

NUMBER_LIST = [1, 2, 3, 5]

print(number_list_average(NUMBER_LIST))
