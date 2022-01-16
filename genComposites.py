import csv
import math

def triangle(limit):
	composites = {9}
	lim = int((limit/3-1)/2)
	for i in range(1,int(math.sqrt(limit))+1):
		for j in range(1,i+1):
			if (2*i+1)*(2*j+1) < limit:
				composites.add((2*i+1)*(2*j+1))
	return sorted(list(composites))

composites = triangle(100000000)

with open("composites1.csv", "w") as f:
	write = csv.writer(f)
	write.writerow(composites)
