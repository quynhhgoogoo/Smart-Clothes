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
