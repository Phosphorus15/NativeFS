package net.steepout.fsm;

public class FileSystemInfo {
    public static native FileSystemDesc _get_fs_info(int fd);
    public static native int _native_open(String device, short flags);
    public static native int _native_close(int fd);
    public static native int _native_read(int fd, byte[] buffer, int len);
    public static native int _native_write(int fd, byte[] buffer, int len);
    public static native int _native_lseek(int fd, long offset, int whence);
    public static native int _fcntl_basic(int fd, int cmd);
    public static void main(String... args) {
	    System.out.println(System.getProperty("java.library.path"));
	    System.loadLibrary("nlib");
	    FileSystemDesc desc1 = new FileSystemDesc(1L,1L,1L,1L,1L,1L,1L,1L,1L,1L,1L);
	    int fd = _native_open("/dev/sdc", (short)0);
	    if(fd == -1) throw new NullPointerException();
	    FileSystemDesc desc = _get_fs_info(fd);
	    System.out.println(desc.bsize + " " + desc.blocks);
	    _native_close(fd);
    }
    //public static native int _unix_open(String device, short flags);
}
