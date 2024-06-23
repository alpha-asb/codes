class Solution:
	def bracketNumbers(self, str):
		# code here
		count = 1
		res = []
		stack = []
		for c in str:
		    if c == '(':
		        stack.append(count)
		        res.append(count)
		        count+=1
		    elif c == ')':
		        res.append(stack.pop())
		return res  
