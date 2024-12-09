import smtplib
def sendmail():
	from email.MIMEMultipart import MIMEMultipart
	from email.MIMEText import MIMEText
	from email.MIMEImage import MIMEImage
	
	#Below two libraries are for mail attachment testing	
	import mimetypes
	import email.mime.application	

	sender='manjarekarhrishikesh98@gmail.com'
	receiver='manjarekarhrishikesh98@gmail.com'

##################################################################################################

#from to and subject details : 

	msgRoot=MIMEMultipart('alternative') 
	#msgRoot['Subject']='Procedure to perform mail program in Raspberry Pi'
	msgRoot['Subject']='Home surveilliance Detection'
	msgRoot['From']=sender
	msgRoot['To']=receiver
	msgRoot.preamble='this is a multi-part message in the mime format'

####################################################################################################

#adding text to the body : 

#	msgText=MIMEText('Procedure to install mail in raspberry pi\n1.In Gmail go to manage your account\n2.Then go to security in then turn on less secure app access\n3.Open Terminal and install below two commands\nsudo apt-get install ssmtp\nsudo apt-get install mailutils\n4.Write in program sender and receiver mails msgText=MIMEText\n5.Finally run the code\n')	
#	msgRoot.attach(msgText)
	msgText=MIMEText('Some object is detected at outside of your home')
	msgRoot.attach(msgText)

####################################################################################################

#adding image to the body : 

	fp=open('/home/pi/Desktop/Hrishikesh/capture.jpeg','rb')
	msgImg=MIMEImage(fp.read())
	fp.close()
	msgRoot.attach(msgImg)

####################################################################################################


#adding attachment to the body : 
#	filename = '/home/pi/Desktop/Hrishikesh/led.py'
#	fo = open(filename, 'rb')
#	file = email.mime.application.MIMEApplication(fo.read(),_subtype = "py")
#	fo.close()
#	attach.add_header('Content-Disposition','attachment',filename='led.py')
#	msgRoot.attach(file)

####################################################################################################

	server=smtplib.SMTP('smtp.gmail.com',587)
	server.set_debuglevel(1)
	server.ehlo()
	server.starttls()
	server.login(sender,'Hr!$h!1998@h')  # password of the mail
	server.sendmail(sender,receiver,msgRoot.as_string())
	server.quit()
	####################################################################################################
if __name__ == '__main__' :
	
	sendmail()


