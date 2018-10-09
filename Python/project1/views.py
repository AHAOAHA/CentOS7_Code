#!/usr/bin/python
#coding:utf-8
'''
使用flask框架建立web网站
'''
#pip install flask
from flask import Flask
#引入flask框架为我们提供的调用模板函数
from flask import render_template
#用Flask方法建立app对象，一般默认把本文件设置为app对象
app = Flask(__name__)


#设置编码
import sys
reload(sys)
sys.setdefaultencoding("utf-8")
#web网站初尝试之Hello world
#route路由 将url和函数进行一对一映射，访问url时，就会被路由转发到指定函数进行响应

#route map
@app.route("/hello/")#在网站端口号后面加上hello 就会执行hello函数 起名字就是为了设置一个标识
def Hello():
	return render_template("main.html")

@app.route("/main/")
def main():
	return "<h1>this is main</h1>"
#GET方法通过url后面追加键值对 key=value
#GET取值方式：request.args.get(key)
#POST方法通过form表单提交数据
#POST取值方式：request.form.get(name)
@app.route("/login/",methods=["GET","POST"])
def Login():
	if request.method == "POST":
		#print request.args
		getName = request.form.get("username")
		getPsw = request.form.get("userpsw")

		return getName + getPsw
	return render_template("login.html")


if __name__ == "__main__":
	app.run(host="0.0.0.0",port=4000)
