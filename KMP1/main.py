# -*- coding: utf-8 -*-
"""
Created on Sat Apr  7 22:11:53 2018

@author: cjh
"""
import time

with open("pi1b.txt","r")as f:
    pai=f.read()

pwds = []
for num in range(10000):
    pwds.append("0" * (6 - len(str(num))) + str(num))
    
start = time.clock(); 
stat = []
for pwd in pwds:
    stat.append([pwd,pai.index(pwd)])
    if len(stat) % 1000 == 1:
        print(stat[-1])

end = time.clock();
print("The run time is: %s s." %(end-start));