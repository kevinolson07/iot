
# from flask import Flask, render_template

# app = Flask(__name__)

# @app.route('/', methods = ['GET''POST'])
# def home():
# 	return render_template('index.html', temperature = temperature)
# @app.route('/hello')
# def hello():
# 	return("Hello ESP8266")

# if __name__ == "__main__":
# 	app.run(host = '0.0.0.0', port = 8090, debug = True)

from flask import Flask, request, render_template, jsonify, session

app = Flask(__name__)
app.config["SECRET_KEY"] = "hello"


@app.route('/post', methods = ["GET","POST"])
def post():
	
	if request.method == "POST":
		session['text'] = request.data
		print(session['text'])
	return ''
	# else:
	# 	text[x] = '0'
	# return render_template('index.html')
	
	


if __name__ == "__main__":
	app.run(host='0.0.0.0', port= 8090, debug = True)

	
