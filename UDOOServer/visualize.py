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

@application.route('/steps')
def steps():
    return render_template('steps.html')

@application.route('/distances')
def distances():
    return render_template('distances.html')

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
            for temperature in udoo_data:
                temperature = temperature["Temperature"]
                temperature_data = json.dumps(
                {'time': datetime.now().strftime('%Y-%m-%d %H:%M:%S'), 'value': temperature})
            yield f"data:{temperature_data}\n\n"
            time.sleep(1)
    return Response(update_json_data(), mimetype='text/event-stream')

@application.route('/steps-data',methods=['GET','POST'])            
def stepsdata():
    def update_json_data():                                         
            data=[]
            with open("data.json", "r") as udoo_data:
                udoo_data = json.load(udoo_data)
            for step in udoo_data:
                step = step["Steps"]
                step_data = json.dumps(
                {'time': datetime.now().strftime('%Y-%m-%d %H:%M:%S'), 'value': step})
            yield f"data:{step_data}\n\n"
            time.sleep(1)
    return Response(update_json_data(), mimetype='text/event-stream')

@application.route('/distances-data',methods=['GET','POST'])            
def distancesdata():
    def update_json_data():                                         
            data=[]
            with open("data.json", "r") as udoo_data:
                udoo_data = json.load(udoo_data)
            for distance in udoo_data:
                distance = distance["Distance"]
                distance_data = json.dumps(
                {'time': datetime.now().strftime('%Y-%m-%d %H:%M:%S'), 'value': distance})
            yield f"data:{distance_data}\n\n"
            time.sleep(1)
    return Response(update_json_data(), mimetype='text/event-stream')

if __name__ == '__main__':
    application.run(host = "0.0.0.0", debug=True, threaded=True)
