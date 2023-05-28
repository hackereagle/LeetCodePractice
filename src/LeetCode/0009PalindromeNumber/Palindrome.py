
def IsPalindrome(x: int) -> bool:
	if(x != 0 and (x < 0 or x % 10 == 0)):
		return False
	
	if(x // 10 == 0):
		return True

	reverNum = 0
	while x > reverNum:
		reverNum = reverNum * 10 + x % 10
		x //= 10

	condition1 = x == reverNum
	condition2 = False
	if(reverNum >= 10):
		condition2 = x == reverNum // 10
		
	return condition1 or condition2 

#a = 121
a = 0
ret = IsPalindrome(a)
print(ret)