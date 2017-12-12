import os, sys, time
from threading import Thread
from random import *
from pyautogui import press, typewrite, hotkey
import linecache

global lineNum
global fileReadTime

def getLastLine(fileName):
	global lineNum
	curTime =  getLastAccessedTime(fileName)

	if curTime > fileReadTime:
		lineNum += 1		# line num begins from 1 in the file
		l = linecache.getline(fileName, lineNum)
		return l if len(l) > 0 else None
	else:
		print( 'File not updated yet')
		return None


def getLastAccessedTime(fileName):
	return time.ctime(os.stat(fileName).st_mtime)


def appendToFile(fileName):
	for i in range(0, 100):
		action = randint(0,2)
		print( i)
		with open(fileName, "a+") as f:
			f.write(str(action)+"\n")
		time.sleep(3)



if __name__=='__main__':
	global fileReadTime, lineNum
	fileName, lineNum = 'input.txt', 0
	fileReadTime = getLastAccessedTime(fileName)
	writer = Thread(target = appendToFile, args = (fileName, ))
	writer.start()
	writer.join()
	
	print( 'finished')
