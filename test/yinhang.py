#coding=gb2312
import string
utype=(5812,5814,5811,5813)
output=[0 for x in range(1,13)]
myfile=open('H:\\ceshi.txt')
for line in myfile.readlines():
	elem=line.split('\t')
	code=int(elem[5]) % 10000
	
	if int(elem[4]) in utype and code == 2900:
		mon_entry=int(elem[2].split(' ')[0].split('-')[1])
		money_entry=int(elem[3])
		output[mon_entry]+=money_entry

for i in range(1,12):
	if output[i] != 0:
		print('%d,%d' %(i,output[i]))

myfile.close()
