#include<iostream>
#include<stdlib.h>

using namespace std;

void printHello(){
	cout<<"你好"<<endl;
}
int getInt(int i){
	return i;
}
char* getCharArr(char* s){
	return s;
}
string getStr(string s){
	return s;
}
#include "/usr/include/python2.7/Python.h"
static PyObject *  Ext_printHello(PyObject *self, PyObject *args)  
{  
    printHello();  
    return (PyObject*)Py_BuildValue("");  
}  
static PyObject *  Ext_getInt(PyObject *self, PyObject *args)  
{  
    int num;  
    if (!PyArg_ParseTuple(args, "i", &num))  
        return NULL;  
    return (PyObject*)Py_BuildValue("i", getInt(num));  
}  
static PyObject *  Ext_getCharArr(PyObject *self, PyObject *args)  
{  
    char* s;  
    if (!PyArg_ParseTuple(args, "s", &s))  
        return NULL;  
    return (PyObject*)Py_BuildValue("s", getCharArr(s));  
}  
static PyObject *  Ext_getStr(PyObject *self, PyObject *args)  
{  
    string s;  
    if (!PyArg_ParseTuple(args, "s", &s))  
        return NULL;  
    return (PyObject*)Py_BuildValue("s", getStr(s));  
} 
static PyMethodDef  ExtMethods[] =  
{  
    { "printHello", Ext_printHello, METH_VARARGS },  
    { "getInt", Ext_getInt, METH_VARARGS },  
    { "getCharArr", Ext_getCharArr, METH_VARARGS }, 
    { "getStr",Ext_getStr,METH_VARARGS}, 
    { NULL, NULL },  
};  
extern "C"{
void initExt()  
{  
    Py_InitModule("Ext", ExtMethods);  
} 
}

