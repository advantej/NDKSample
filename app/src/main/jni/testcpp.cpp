#include <jni.h>
#include <android/log.h>

namespace com_advantej_ndksample {

    static jlong testCppReturnLong(JNIEnv *env, jclass clazz, jlong n) {
        return 1000;
    }

    static jstring testCppReturnString(JNIEnv *env, jclass clazz) {
        return env->NewStringUTF( "Hello from JNI cpp" );
    }

    static JNINativeMethod method_table[] = {
        {"testCppReturnLong", "(J)J", (void *) testCppReturnLong},
        {"testCppReturnString", "()Ljava/lang/String;", (void *) testCppReturnString}
    };
}

using namespace com_advantej_ndksample;

//extern "C"

jint JNI_OnLoad(JavaVM* vm, void* reserved)
{
    JNIEnv* env;
    if (vm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_6) != JNI_OK) {
        return -1;
    } else {
        jclass clazz = env->FindClass("com/advantej/ndksample/NativeLib");
        if (clazz) {
            env->RegisterNatives(clazz, method_table, sizeof(method_table) / sizeof(method_table[0]));
            env->DeleteLocalRef(clazz);
            return JNI_VERSION_1_6;
        } else {
            return -1;
        }
    }
}

