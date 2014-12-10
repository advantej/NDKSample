#include <jni.h>
#include <string.h>
#include <android/log.h>
#include <unistd.h> /* sleep() */

#include<pthread.h>

#define LOG_TAG "MyLib-helper"
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)


void* doTask(void *arg)
{
    LOGI("############## TaskStart ");
    sleep(5);
    LOGI("############## TaskEnd ");
    return NULL;
}



JNIEXPORT void JNICALL Java_com_advantej_ndksample_Helper_doAwesomeTask (JNIEnv *env, jobject obj, jstring some_arg) {

    pthread_t thread1;

    jclass clazz = (*env)->FindClass(env, "com/advantej/ndksample/Helper");

    if (clazz == NULL) {
       LOGI("============> Class is Null :(");
    } else {
       LOGI("============> Yaay");
    }

    jmethodID startService = (*env)->GetMethodID(env, clazz, "startService", "()V");
    jmethodID stopService = (*env)->GetMethodID(env, clazz, "stopService", "()V");

    (*env)->CallVoidMethod(env, obj, startService, NULL);

    // Here's the long running task
    pthread_create(&thread1, NULL, &doTask, NULL);

    //TODO ideally this should not block the main thread
    pthread_join(thread1, NULL);

    (*env)->CallVoidMethod(env, obj, stopService, NULL);
}

