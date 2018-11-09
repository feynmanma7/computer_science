"""
1. pip install sendmail
2. run `sendmail`
"""

import smtplib
from email.mime.text import MIMEText
from email.header import Header

sender = "feynman@gmail.com"
receivers = ['flyingman26@sina.com', 'mayunlong1988@gmail.com']

message = MIMEText('Python email test', 'plain', 'utf-8')
message['From'] = Header("FEYNMAN", 'utf-8')
message['To'] = Header("FLYINGMAN", 'utf-8')

subject = 'Python send email test'
message['Subject'] = Header(subject, 'utf-8')

try:
    smtpObj = smtplib.SMTP('localhost')
    smtpObj.sendmail(sender, receivers, message.as_string())
    print('Send Successfully!')

except smtplib.SMTPException:
    print('Error: Cannot send email!')
