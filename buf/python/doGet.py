import urllib
import urllib2
import sys

url = "http://"+sys.argv[1]+"?"+sys.argv[2]

req = urllib2.Request(url)

res_data = urllib2.urlopen(req)
res = res_data.read()

f = open(sys.argv[3], 'wb')
f.write(res)
