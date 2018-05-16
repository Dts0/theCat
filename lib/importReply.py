import ctypes
dl=ctypes.cdll.LoadLibrary
lib=dl("./libreply.so")
reply=lib.c_reply
reply.restype=ctypes.c_char_p

reply("s")

