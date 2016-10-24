"""
forked from https://github.com/fiftin/bin2array
"""

import sys
import io
from io import FileIO

inputFileName = sys.argv[1]
outputFileName = sys.argv[2]
nInLine = 16
if len(sys.argv) >= 4:
    nInLine = int(sys.argv[4])

inputStream = FileIO(inputFileName, 'r')
outputFile = open(outputFileName, 'w')

inputData = inputStream.readall()
inputStream.close()

outputStr = 'static const uint8_t loader[] = {\n'

n = 0
for x in inputData:
    outputStr += "0x" + hex(ord(x))[2:].zfill(2) + ", "
    n += 1
    if n >= nInLine:
        outputStr += '\n'
        n = 0

outputFile.write(outputStr + '\n};')
outputFile.close()
