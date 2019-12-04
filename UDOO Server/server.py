import os
import json
from flask import Flask, request, render_template

app = Flask(__name__)

#Rendering web template
#@app.route('/')                                 
#def web_template():                                              
#    return render_template("index.html")                                       

@app.route('/',methods=['GET','POST'])            
def userdata():                                           
    data=[]
    with open("test.json", "r") as json_data:
        data = json.load(json_data)
    return render_template("index.html", page_title="User data", test = data)

if __name__ == '__main__':
    app.run()
