import cv2
from cvzone.HandTrackingModule import HandDetector
from cvzone.SerialModule import SerialObject

arduino = SerialObject()

cap = cv2.VideoCapture(0)
cap.set(10,150)
detector = HandDetector(detectionCon=0.8, maxHands=1)

while True:
    _, img = cap.read()
    hands, img = detector.findHands(img)

    if hands:
        hand = hands[0]
        fingers = detector.fingersUp(hand)
        arduino.sendData(fingers)

    cv2.imshow("image",img)
    cv2.waitKey(1)