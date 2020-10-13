# Smart-Clothes

This repository is our final project work for Embedded Systems and Programming course

## Hardware Installation

First is the UDOO Neo board with our system installed on it. This will also include the wrist unit that includes LCD and button controlling LCD display. Also, power source is required to run the board and wrist unit, powerbank is recommended for wireless use. Initial setup (wireless connection) needs to be done with external display and keyboard/mouse combo, so those are required as well. 

Running the RPi server in local network, one must have wireless router and PC with SSH connectivity (e.g. Putty). RPi also needs power source, preferably wall socketed. Raspberry can be any model, but needs to have our ready-made system

## Software Installation

### Environment settings
1. Install git : sudo apt install git-all
2. Check python3 version: python3 -V
3. Install python if needed: sudo apt-get install python3.6
4. Install Flask: pip install Flask

### Run the program
1. Clone this repository: git clone https://github.com/quynhhgoogoo/Smart-Clothes.git
2. Change directory path: cd UDOOServer
3. Run the server: python3 visualize.py
4. Access to the web page using RPi address

### Project Capture
Belows are some capture of our project
1. Hardware Structure
![image](https://user-images.githubusercontent.com/26543302/92230834-6be64b00-eeb4-11ea-906b-e192e1cc0532.png)
![image](https://user-images.githubusercontent.com/26543302/92230916-89b3b000-eeb4-11ea-8c09-a1480b012125.png)

2. Software demo
![image](https://user-images.githubusercontent.com/26543302/92230974-a18b3400-eeb4-11ea-8f72-d58d38a4dc05.png)
![image](https://user-images.githubusercontent.com/26543302/92231308-38f08700-eeb5-11ea-9dbb-7aea6de5c192.png)
![image](https://user-images.githubusercontent.com/26543302/92231119-dd25fe00-eeb4-11ea-83e4-8c4c08f171b6.png)

