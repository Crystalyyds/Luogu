
nums =[]
b = input()
num = b.split(" ")
ave = sum(nums) / len(nums)
n_deltas = {abs(n - ave): n for n in nums}
nearest = n_deltas[min(n_deltas.keys())]
print(nearest) # 2.4