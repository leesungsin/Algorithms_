

number, money = input().split() # console 창에서 값 입력
number, money = [int(number), int(money)]  # input 은 string 으로 받아들이기 때문에 int로 형변환 필요

coins = []
index = 0
min_value_sum = 0 

while(index < number):	
	inputCoin = int(input())

	if(1 >= index):
		coins.append(inputCoin)
		index = index + 1
	elif(2 <=index and 0 == inputCoin%coins[index-1]):
		coins.append(inputCoin)
		index = index + 1
	else:
		continue


# 현재 coins 는 list 형식.

while(money != 0):
	index2     = 0
	temp 	   = int(coins[index2])
	temp_money = 0
	min_value  = money/temp

	for i in range(1,number):
		temp2 = int(coins[i])
		min_value2 = money/temp2
		if(min_value > min_value2 and min_value2 != 0 and min_value != 0):
			min_value = min_value2
			temp_money = int(coins[i]) * min_value

	money = money - temp_money
	min_value_sum = min_value_sum + min_value

print("min_value_sum : %d " % min_value_sum)
