import numpy as np
import binascii
import cv2
"""
JPEG Parser v0.1 for Python3
"""

#marker = [b'ffd8',b'ffe0',b'ffe1',b'ffc0',b'ffc2',b'ffc4',b'ffdb',b'ffdd',b'ffda',b'ffd0',b'ffd1',b'ffd2',b'ffd3',b'ffd4',b'ffd5',b'ffd6',b'ffd7',b'fffe',b'ffd9']
#print("Offset : ",hex(offset)) for debug

offset = 0  #file offset


def read_marker(file,marker):
     global offset

     mv = 2
     offset = offset + mv

     tmp = file.read(mv) #FF D8
     print("%s : "%marker,bin_2_ascii_hex(tmp))

def read_len(file,marker):
     global offset

     mv = 2
     offset = offset + mv

     tmp = file.read(mv)
     print("%s_LEN : "%marker,int(bin_2_ascii_hex(tmp),16))
     return int(bin_2_ascii_hex(tmp),16)-mv

def is_next(file,marker):
     mv = 2
     tmp = file.read(mv)
     tmp = bin_2_ascii_hex(tmp)
     return marker == tmp

def bin_2_ascii_hex(argv):
     return binascii.b2a_hex(argv)

def SOI(file):
     global offset
     read_marker(file,"SOI")

     return file

def APP(file):
     global offset

     print("==============APP==============")
     marker = "APP"

     read_marker(file,marker)
     app_len = read_len(file,marker)
     app = file.read(app_len)

     tmp = is_next(file, b'ffe1')
     offset = offset + app_len

     file.seek(offset)
     if(tmp):
          APP(file)
     file.seek(offset)
     return file


def DQT(file):
     global offset

     print("=================DQT=================")
     marker = "DQT"

     read_marker(file,marker)
     dqt_len = read_len(file,marker)
     dqt = file.read(dqt_len)

     tmp = is_next(file, b'ffdb')
     offset = offset + dqt_len

     file.seek(offset)
     if(tmp == b'ffdb'):
          DQT(file)
     return file

def SOF(file):
     global offset

     print("=================SOF=================")
     marker = "SOF"
     
     read_marker(file,marker)
     sos_len = read_len(file,marker)
     sos = file.read(sos_len)

     offset = offset + sos_len
     tmp = is_next(file,b'ffc0')

     file.seek(offset)
     if(tmp):
          SOF(file)
     return file

def DHT(file):
     global offset

     print("=================DHT=================")
     marker = "DHT"

     read_marker(file, marker)
     dht_len = read_len(file, marker)
     dht = file.read(dht_len)
     
     offset = offset + dht_len
     tmp = is_next(file,b'ffc4')

     file.seek(offset)
     if(tmp):
          DHT(file)
     return file

def SOS(file):
     global offset

     print("=================SOS=================")
     marker = "SOS"

     read_marker(file, marker)
     sos_len = read_len(file, marker)
     sos = file.read(sos_len)
     
     offset = offset + 4 + sos_len
     tmp = is_next(file,b'ffda')

     if(tmp):
          file.seek(offset + 2)
          SOS(file)
     else:
          file.seek(offset - 1)
          return file

def DATA(file):
     global offset

     print("=================DATA=================")
     print("Data : ")
     #while(1):
          #data = file.read(1)
          #print(bin_2_ascii_hex(data),end='')

def find_marker(file):

     soi=SOI(file)
     app=APP(soi)
     sof=DQT(app)
     dht=SOF(sof)
     sos=DHT(dht)
     data=SOS(sos)
     eoi=DATA(data)

def main():
     src = open('{JPEG File Path}','rb')
     find_marker(src)


if __name__ == "__main__":
     main()
""" 
QY=np.array([[16,11,10,16,24,40,51,61],
                         [12,12,14,19,26,48,60,55],
                         [14,13,16,24,40,57,69,56],
                         [14,17,22,29,51,87,80,62],
                         [18,22,37,56,68,109,103,77],
                         [24,35,55,64,81,104,113,92],
                         [49,64,78,87,103,121,120,101],
                         [72,92,95,98,112,100,103,99]])

QC=np.array([[17,18,24,47,99,99,99,99],
                         [18,21,26,66,99,99,99,99],
                         [24,26,56,99,99,99,99,99],
                         [47,66,99,99,99,99,99,99],
                         [99,99,99,99,99,99,99,99],
                         [99,99,99,99,99,99,99,99],
                         [99,99,99,99,99,99,99,99],
                         [99,99,99,99,99,99,99,99]])
"""
