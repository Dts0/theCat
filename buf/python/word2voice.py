from aip import AipSpeech

APP_ID = '10948391'
API_KEY = '9yQw1QSYVG1DPgbMgIeeFzNT'
SECRET_KEY = 'YGq8EcLqd0opZreMGsujrWId6Fizm73H'

client = AipSpeech(APP_ID, API_KEY, SECRET_KEY)


r=open('reply.txt','r')
print 'word to voice...'.encode("utf-8")
result  = client.synthesis(r, 'zh', 1, {
    'vol': 5,'per':4
})
r.close()

import os
os.system("touch reply.mp3")

if not isinstance(result, dict):
    with open('reply.mp3', 'wb') as f:
        f.write(result)
