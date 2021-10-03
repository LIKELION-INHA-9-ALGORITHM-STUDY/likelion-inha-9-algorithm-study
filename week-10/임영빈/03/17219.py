read = __import__('sys').stdin.readline

def solution():
	pwd_dictionary = dict()
	n, m = map(int, read().split())
	for _ in range(n):
		address, pwd = read().split()
		pwd_dictionary[address] = pwd
	for _ in range(m):
		temp = read().strip()
		print(pwd_dictionary.get(temp))

solution()