import json
import random
import time
import os
from datetime import datetime

from flask import Flask, Response, render_template,request,redirect,url_for

application = Flask(__name__)
random.seed()  # Initialize the random number generator


@application.route('/')
def index():
    return render_template('visualization.html')


#@application.route('/chart-data')
#def chart_data():
#    def generate_random_data():
#        while True:
#            json_data = json.dumps(
#                {'time': datetime.now().strftime('%Y-%m-%d %H:%M:%S'), 'value': random.random() * 100})
#            yield f"data:{json_data}\n\n"
#            time.sleep(1)

#    return Response(generate_random_data(), mimetype='text/event-stream')

@application.route('/chart-data',methods=['GET','POST'])            
def userdata():
    def update_json_data():                                         
            data=[]
            with open("data.json", "r") as udoo_data:
                udoo_data = json.load(udoo_data)
                i=0
            for temperature in udoo_data:
                temperature = temperature[i]["Steps"]
                i= i+1 
                temperature_data = json.dumps(
                {'time': datetime.now().strftime('%Y-%m-%d %H:%M:%S'), 'value': temperature})
            yield f"data:{temperature_data}\n\n"
            time.sleep(1)
    return Response(update_json_data(), mimetype='text/event-stream')

if __name__ == '__main__':
    application.run(debug=True, threaded=True)