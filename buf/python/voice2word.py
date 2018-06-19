from aip import AipSpeech
import sys

APP_ID = '10948391'
API_KEY = '9yQw1QSYVG1DPgbMgIeeFzNT'
SECRET_KEY = 'YGq8EcLqd0opZreMGsujrWId6Fizm73H'

client = AipSpeech(APP_ID, API_KEY, SECRET_KEY)

def get_file_content(filePath):
    with open(filePath, 'rb') as fp:
        return fp.read()

result=client.asr(get_file_content(sys.argv[1]), 'pcm', 16000, {
    'dev_pid': '1536',
})

f=open("result.txt","w")

if result['err_no']==0:
	print >> f, result['result'][0].encode("utf-8")
else:
	print >> f, "error"
	print >> f, result


