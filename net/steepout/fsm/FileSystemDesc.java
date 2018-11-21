package net.steepout.fsm;

public class FileSystemDesc {
	public FileSystemDesc(long bs, long fr, long bl, long bf, long ba, long fi, long ff, long fa, long fs, long fl, long na) {
		bsize = bs;
		frsize = fr;
		blocks = bl;
		bfree = bf;
		bavail = ba;
		files = fi;
		ffree = ff;
		favail = fa;
		fsid = fa;
		flag = fl;
		namemax = na;
	}
	public FileSystemDesc() {}
	public long bsize;
	long frsize;
	long blocks;
	long bfree;
	long bavail;
	long files;
	long ffree;
	long favail;
	long fsid;
	long flag;
	long namemax;
}
