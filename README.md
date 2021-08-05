# ESP Connected to Database Using GET Method


In this project I will show how to connect ESP to database using GET method to control robot movement.
<br>
<br>

# Method of Work

First, after plugging ESP on, the user has to scan and connect to any Wi-Fi network, and once the connection is established, the rest of the program will run.
<br>
In my control panel there are five buttons as in the picture below:
<br>
<p align="center">
<img src="https://user-images.githubusercontent.com/85786699/128266898-b0035701-4061-4b03-8d0a-dccc8b1bca8b.png">
<br> 
Figure 1: index.html interface</p>
<br>
Whenever I press in any button it will return '1' to the database for that button's column and '0' for other buttons columns'.
<br>
to do this, I use these files:
- index.html
- style.css
- connect.php

Next, is to send these values to ESP, to do this I used these files:
- GetDataBackw.php
- GetDataForw.php
- GetDataRight.php
- GetDataLeft.php
- GetDataStop.php

In my project, I programmed my ESP to send five GET request, each request will be handled by one of these files to return a value either '0' or '1'. And based on the button pressed one of those five will give the value '1' and the others should give '0' so specific output will be executed.

For example:
the code to send GET request in ESP code is written as:

```C++
  String GetAddress1, LinkGet1, getData1;
  int id = 0; //--> ID in Database
  GetAddress1 = "/t3/GetDataForw.php";
  LinkGet1 = host + GetAddress1; //--> Make a Specify request destination
  getData1 = "ID=" + String(id);
  
  http.begin(LinkGet1); //--> Specify request destination
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");    //Specify content-type header
  int httpCodeGet1 = http.POST(getData1); //--> Send the request
  String payloadGet1 = http.getString(); //--> Get the response payload from server
  
  Serial.print("Response Code : "); //--> If Response Code = 200 means Successful connection, if -1 means connection failed.
  Serial.println(httpCodeGet1); //--> Print HTTP return code
  Serial.print("Returned data from Server : ");
  Serial.println(payloadGet1); //--> Print request response payload
  
// After recieveing the value and storing it in 'payloadGet':

  if (payloadGet1 == "1") {
    Serial.print("Move Forward");
```
<br>
So, as the code explained in the comments it sends GET request to the file GetDataForw.php
Then, it will recive the response in variable called "payloadGet1"
Then, If this value equals '1' send the sentence "Move Forward" in the serial monitor. It could be replaced to move the robot forward, for example if we used DC motors with H-Bridge driver:
<br>
```C++
digitalWrite(in1, LOW);
digitalWrite(in2, HIGH); 
digitalWrite(in3, LOW);
digitalWrite(in4, HIGH);
```
<br>

and the same for all other buttons and directions.
<br>

# Expirement Video



https://user-images.githubusercontent.com/85786699/128269630-ef78f45a-f1e8-4f6f-969e-f7f5969eaa42.mp4


<br>

**Note: I apologise for the recording video because my recording softwere would not record my cursor so it will be hard to follow.
I hope you like it!**


