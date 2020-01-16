# A small instruction to run server
## Environment settings
1. Install git : sudo apt install git-all
2. Check python3 version: python3 -V
3. Install python if needed: sudo apt-get install python3.6
4. Install Flask: pip install Flask

## Run the program
1. Clone this repository: git clone https://github.com/quynhhgoogoo/Smart-Clothes.git
2. Change directory path: cd UDOOServer
3. Run the server: python3 visualize.py

### If it still not working :(
1. Check the version, update if needed
2. Check host address in main visualize.py, modify if needed:  application.run(host = "<insert_RPI_address_here>", debug=True, threaded=True) (but it should works fine)
3. Asking Stackoverflow with your fingers crossed lol :D
