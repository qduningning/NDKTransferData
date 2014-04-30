#include <stdio.h>
#include <stdlib.h>
#include <jni.h>
#include "com_znn_ndktransferdata_MainActivity.h"

#include <android/log.h>
#define LOG_TAG "System.out"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)


JNIEXPORT jint JNICALL Java_com_znn_ndktransferdata_MainActivity_add
  (JNIEnv *env, jobject clazz, jint a, jint b){
	LOGI("a=%d", a);
	LOGI("b=%d", b);
	return a+b;
}
//C语言中没有String类型，但是可以用char数组来表示
char *Jstring2CStr(JNIEnv* env, jstring jstr){
	char *rst = NULL;
	jclass classtring = (*env)->FindClass(env, "java/lang/String");
	jstring strencode = (*env)->NewStringUTF(env, "UTF-8");
	jmethodID mid = (*env)->GetMethodID(env, classtring,"getBytes", "(Ljava/lang/String;)[B");
	jbyteArray barr = (jbyteArray)(*env)->CallObjectMethod(env, jstr,mid,strencode);
	jsize alen = (*env)->GetArrayLength(env, barr);
	jbyte* ba = (*env)->GetByteArrayElements(env, barr, JNI_FALSE);
	if(alen>0)
	{
		rst = (char *)malloc(alen+1);
		memcpy(rst,ba,alen);
		rst[alen]='\0';
	}
	(*env)->ReleaseByteArrayElements(env, barr, ba, 0);
	return rst;
}

JNIEXPORT jstring JNICALL Java_com_znn_ndktransferdata_MainActivity_doString
  (JNIEnv *env, jobject clazz, jstring str){

	char *p = Jstring2CStr(env, str);
	LOGI("in C:%s", p);
	char *newstr = "Hello";
	return (*env)->NewStringUTF(env, strcat(p,newstr));
}
JNIEXPORT jintArray JNICALL Java_com_znn_ndktransferdata_MainActivity_doArray
  (JNIEnv *env, jobject clazz, jintArray jintarr){
	int len = (*env)->GetArrayLength(env, jintarr);
	LOGI("LEN=%d",len);
	//将数组中的所有元素存入到以jint*为首地址的数组中
	//第三个参数0代表不以复制的形式获取
	jint * arr = (*env)->GetIntArrayElements(env,jintarr,0);
	int i = 0;
	for(i=0; i<len; i++)
	{
		LOGI("ARR[%d]=%d", i, *(arr+i));
		*(arr+i) += 10;
	}
	return jintarr;
}
