import ctypes
dl=ctypes.cdll.LoadLibrary
lib=dl("./libreply.so")
reply=lib.c_reply
reply.restype=ctypes.c_char_p

from aip import AipSpeech

APP_ID = '10948391'
API_KEY = '9yQw1QSYVG1DPgbMgIeeFzNT'
SECRET_KEY = 'YGq8EcLqd0opZreMGsujrWId6Fizm73H'

client = AipSpeech(APP_ID, API_KEY, SECRET_KEY)

def get_file_content(filePath):
    with open(filePath, 'rb') as fp:
        return fp.read()

result=client.asr(get_file_content('test.pcm'), 'pcm', 16000, {
    'dev_pid': '1536',
})

if result['err_no']==0:
	print(result['result'][0])
else:
	print(result)


r=reply(result['result'][0].encode("utf-8"))
print(r)
print("正在转语音")
...
result  = client.synthesis(r, 'zh', 1, {
    'vol': 5,'per':4
})


if not isinstance(result, dict):
    with open('auido.mp3', 'wb') as f:
        f.write(result)
import os
os.system('play auido.mp3')
