#include "net_steepout_fsm_FileSystemInfo.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/statvfs.h>
#include <iostream>

using std::cout;
using std::endl;

JNIEXPORT jobject JNICALL Java_net_steepout_fsm_FileSystemInfo__1get_1fs_1info
  (JNIEnv * env, jclass clz, jint fd) {
	  struct statvfs fs;
	  fstatvfs(fd, &fs);
	  jclass cls = env->FindClass("net/steepout/fsm/FileSystemDesc");
	  jmethodID m = env->GetMethodID(cls, "<init>", "(JJJJJJJJJJJ)V");
	  jobject result = env->NewObject(cls, m, (jlong) fs.f_bsize, (jlong) fs.f_frsize, (jlong) fs.f_blocks, (jlong) fs.f_bfree, (jlong) fs.f_bavail, (jlong) fs.f_files, (jlong) fs.f_ffree, (jlong) fs.f_favail, (jlong) fs.f_fsid, (jlong) fs.f_flag, (jlong) fs.f_namemax);
	  return result;
  }

JNIEXPORT jint JNICALL Java_net_steepout_fsm_FileSystemInfo__1native_1open
  (JNIEnv *env, jclass clz, jstring device, jshort flags){
	  const char * dev = env->GetStringUTFChars(device, 0);
	  jint fd = open(dev, flags);
	  env->ReleaseStringUTFChars(device, dev);
	  return fd;
  }

JNIEXPORT jint JNICALL Java_net_steepout_fsm_FileSystemInfo__1native_1close
  (JNIEnv * env, jclass clz, jint fd){
	  return close(fd);
  }

JNIEXPORT jint JNICALL Java_net_steepout_fsm_FileSystemInfo__1native_1read
  (JNIEnv * env, jclass clz, jint fd, jbyteArray bytes, jint len) {
	  jbyte * pool = env->GetByteArrayElements(bytes, 0);
	  jint ret = read(fd, bytes, len);
	  env->ReleaseByteArrayElements(bytes, pool, 0);
	  return ret;
  }

JNIEXPORT jint JNICALL Java_net_steepout_fsm_FileSystemInfo__1native_1write
  (JNIEnv * env, jclass clz, jint fd, jbyteArray bytes, jint len){
	  jbyte * pool = env->GetByteArrayElements(bytes, 0);
	  jint ret = write(fd, bytes, len);
	  env->ReleaseByteArrayElements(bytes, pool, JNI_ABORT);
	  return ret;
  }

JNIEXPORT jint JNICALL Java_net_steepout_fsm_FileSystemInfo__1native_1lseek
  (JNIEnv * env, jclass clz, jint fd, jlong offset, jint whence){
	  return lseek(fd, offset, whence);
  }

JNIEXPORT jint JNICALL Java_net_steepout_fsm_FileSystemInfo__1fcntl_1basic
  (JNIEnv * env, jclass clz, jint fd, jint cmd) {
	  return fcntl(fd, cmd);
  }

