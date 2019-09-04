import os

os.system("g++ tree_gen.cpp -o tree_gen")
os.system("g++ check.cpp -o check")

for i in range(100):
	os.system("./tree_gen > in.in")
	os.system("./check < in.in > out.out")

	with open('out.out', 'r') as f:
		data = f.read()
		
		if(data == "OK!\n"):
			print("OK")
		else:
			print("Tree not connected!!")