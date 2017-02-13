#include "com_szmedchat_myjni_JNIUtil.h"
#include <stdio.h>
JNIEXPORT jstring JNICALL Java_com_szmedchat_myjni_JNIUtil_test(JNIEnv *env, jobject obj)
{
    return env -> NewStringUTF("Hello World!");
}

JNIEXPORT jobject JNICALL Java_com_szmedchat_myjni_JNIUtil_createHashMap
        (JNIEnv *env, jobject thiz, jstring key1, jstring value1, jstring key2, jstring value2)
{
    //为了方便日后获取其他地方需要使用HashMap的类型，在这里可以定义为static，然后对jclass创建全局的内存引用。
    static jclass hashMapClass = NULL;
    if (hashMapClass == NULL)
    {
        jclass hashMapClassLocal = env -> FindClass("java/util/HashMap");
        hashMapClass = (jclass)env -> NewGlobalRef(hashMapClassLocal);
        env->DeleteLocalRef(hashMapClassLocal);
    }

    //获取构造方法标识和插入数据方法标识
    static jmethodID initMethodId = env -> GetMethodID(hashMapClass, "<init>", "()V");
    static jmethodID putMethodId = env -> GetMethodID(hashMapClass, "put", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;");

    //创建HashMap对象
    jobject hashMapInstance= env -> NewObject(hashMapClass, initMethodId);

    //放入对象到HashMap中，相当于调用HashMap的put方法
    env -> CallObjectMethod(hashMapInstance, putMethodId, key1, value1);
    env -> CallObjectMethod(hashMapInstance, putMethodId, key2, value2);

    return hashMapInstance;
}