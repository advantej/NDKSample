#include "com_advantej_ndksample_MainActivity.h"
#include <jni.h>
#include <string.h>
#include <android/log.h>

#define LOG_TAG "MyLib-test"
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)

JNIEXPORT jstring JNICALL Java_com_advantej_ndksample_MainActivity_getStringFromNative (JNIEnv *env, jobject obj) {

     jstring jstr = (*env)->NewStringUTF(env, "Hello from jni.");
     jclass clazz = (*env)->FindClass(env, "com/advantej/ndksample/MainActivity");

     if (clazz == NULL) {
        LOGI("============> Class is Null :(");
     } else {
        LOGI("============> Yaay");
     }

      jmethodID messageMe = (*env)->GetMethodID(env, clazz, "getStringFromJava", "(Ljava/lang/String;)Ljava/lang/String;");
      jobject result = (*env)->CallObjectMethod(env, obj, messageMe, jstr);

      const char* str = (*env)->GetStringUTFChars(env,(jstring) result, NULL); // should be released but what a heck, it's a tutorial :)

      return (*env)->NewStringUTF(env, str);
//  return (*env)->NewStringUTF(env, "Hello From JNI ! yaaaaay ");
}

