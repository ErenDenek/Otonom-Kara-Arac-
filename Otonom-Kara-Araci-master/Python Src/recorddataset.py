import os
import cv2
import serialCom

file_path = '/home/pi/Desktop/bitirme/dataset'
dataArr = []
cam = cv2.VideoCapture(0)
print("Setting made..")

def get_image():
    ret_val, img = cam.read()
    return img  
    
def save_image(count,img):
    cv2.imwrite(os.path.join(file_path,str(count)+'.jpg'),img)

def pauseRecord(recordData):
    while recordData == 2:
        speedCar, wheelCar, recordData = serialCom.getData()
        print("Pause record..")

def saveData(datasetArr):
    cam.release()
    text_path = open("/home/pi/Desktop/bitirme/dataset/dataset.txt","w")
           
    for x in range(0, len(datasetArr)):
        text_path.write(str(x) + ".jpg" + "\t" + str(datasetArr[x]) + "\n")
    
def main():
    
    count=0 
    print("Dataset recording..")
    
    while True:
        wheelCar, recordData = serialCom.getData()
        
        while wheelCar is -1 and recordData is -1:
            wheelCar, recordData = serialCom.getData()
            print("Error Data")
        image = get_image()
        save_image(count,image)
        #pauseRecord(recordData)
    
        dataArr.append(wheelCar)
    
        count = count + 1
        if count == 4000:
           print("Images and data was recorded..")
           saveData(dataArr)
           break
           

if __name__ == '__main__':
    main()

