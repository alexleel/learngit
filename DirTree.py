#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import os
class dir(object):
	def __init__(self):
		self.CONST = 0
		self.SPACE = ""
		self.list = []
	
	def p(self,dir):
		files = os.listdir(r''+dir)
		for file in files:
			myfile = dir + "/"+file
			size = os.path.getsize(myfile)
			if os.path.isfile(myfile):
				self.list.append(str(self.SPACE)+"|__"+file+" "+str(size)+"\n")
			if os.path.isdir(myfile):
				self.list.append(str(self.SPACE)+"|__"+file+"\n")
				self.SPACE =self.SPACE+"|    "
				self.p(myfile)
				#when sub-directory of iteration is finished,reduce "|    "  
				self.SPACE = self.SPACE[:-5]  
		return self.list
		
	def writeList(self, dir):
		f = open(dir,'w')
		f.writelines(self.list)
		#print (self.list)
		f.close()
		
if __name__ == '__main__':
	d = dir()
	d.p("/home/alex/PythonTest")
	d.writeList("testTree.txt")
		