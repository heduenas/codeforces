n, k = map(int, input().split())

turn = false
done =  0
left = 1
right = n
while done < k:
	if turn:
		print right
		right -= 1
	else:
		print left
		left += 1
if turn:
	print range(left, right+1)
else:
	print range(right+1, left)
