# -*- coding: utf-8 -*-
from sys import argv
import csv

found = []

file = open(argv[2],'r')

def equal(A,B):
    if len(A) != len(B):
        return False
    for i in range(len(A)):
        if A[i] != B[i]:
            return False
    return True

def search_dna(A,B):
    s = 0
    for i in range(0,len(A)-len(B)):
        # print(A[i:i+len(B)],B[::],s,i)
        if equal(str(A[i:i+len(B)]),str(B)):
            s += 1
    found.append(s)
    return

ddd = []
def csv_reader(file_obj):
    reader = csv.reader(file_obj)
    for row in reader:
        ddd.append(row)


if __name__ == "__main__":
    with open(argv[1], "r") as f_obj:
        csv_reader(f_obj)

dok = ''

for l in file:
    dok = l

def sea(A):
    for i in range(1,len(A)):
        # print(A[i],'=',found[i-1])
        if str(A[i]) != str(found[i-1]):
            return False
    return True

for d in ddd:
    if d[0] == 'name':
        for i in range(1,len(d)):
            search_dna(dok,d[i])
    else:
        print(d[0] if sea(d) == True else 'No match')
print(found)