from aip import AipSpeech
import sys
import os

APP_ID = '10948391'
API_KEY = '9yQw1QSYVG1DPgbMgIeeFzNT'
SECRET_KEY = 'YGq8EcLqd0opZreMGsujrWId6Fizm73H'

client = AipSpeech(APP_ID, API_KEY, SECRET_KEY)

r=open('./buf/reply.txt','r')

result  = client.synthesis(r, 'zh', 1, {
    'vol': 5,'per':4
})
r.close()


os.system("touch "+sys.argv[1])

if not isinstance(result, dict):
    with open(sys.argv[1], 'wb') as f:
        f.write(result)
