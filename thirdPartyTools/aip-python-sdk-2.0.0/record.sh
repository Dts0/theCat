arecord -d 5 -r16000 -f S16_LE -t wav -D "plughw:1,0" test.pcm
echo '录音完毕,正在识别...'
python pytest.py
