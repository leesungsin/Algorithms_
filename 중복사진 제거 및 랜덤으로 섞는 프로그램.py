import numpy as np
import matplotlib.pyplot as plt
%matplotlib inline

import os, sys
import hashlib
import cv2
import random

DATAPATH = '/Users/leesungsin/Desktop/all'

# 특정 폴더 위치에 있는 데이터 정보가져오는 함수
def allfiles(path):
    imagesPath = [] # image file path를 저장하는 list 
    
    for root, dirs, files in os.walk(path):
        rootpath = os.path.join(os.path.abspath(path), root)   
        
        for file in files:
            filepath = os.path.join(rootpath, file)
            fname, ext = os.path.splitext(filepath)
            if('.jpg' == ext or '.JPG' == ext or '.jpeg' == ext or '.png' == ext or 
               '.PNG' == ext or '.bmp' == ext or '.gif' == ext):
                imagesPath.append(filepath)

    return imagesPath


# allfiles 의 return 값의 형태는 list 형식
# imagesPath에는 파일의 위치가 저장
images_path = allfiles(DATAPATH)

# images_path에 저장된 값을 random 으로 섞음.
random.Random(4).shuffle(images_path)

########################

# Hash 값을 비교하여 중복된 이미지를 제거.
image_filehash=[]
for im in images_path:
    image = cv2.imread(im)
    
    image_filehash.append(hashlib.md5(image).hexdigest())

# 중복된 hash 값을 제거
image_filehash= list(set(image_filehash))

########################

# dictionary 자료구조
# key 값은 각 이미지의 hash 값.
# value 값은 이미지 저장횟수. 1번 저장되면 value 값은 0->1로 변함.
# 이 값은 중복된 사진이 저장 안되게 조건비교를 할때 사용
dictionary_image = {}
for ih in image_filehash:
    dictionary_image[ih] = 0

index = 0
for im in images_path:
    img = cv2.imread(im)

    if(0 == dictionary_image[hashlib.md5(img).hexdigest()]):
        #formatted string 표현식 '{:06d}'.format(index)
        cv2.imwrite('{:06d}'.format(index) + ".jpg",img)
        index = index + 1
        dictionary_image[hashlib.md5(img).hexdigest()] = 1