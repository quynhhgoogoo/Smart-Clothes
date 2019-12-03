import os
import json
from flask import Flask,render_template,request,redirect,url_for

app = Flask(__name__)

#conn = MySQLdb.connect(host="mysql.cc.puv.fi",user="e1601128",password="",db="Vn28YXTwjmPk")

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
