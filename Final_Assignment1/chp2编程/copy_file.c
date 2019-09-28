#include <unistd.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
 
#define	BUFFER_SIZE	1024		/* ÿ�ζ�д�����С��Ӱ������Ч��*/
//SRC_FILE_NAME	Դ�ļ��� 
//DEST_FILE_NAME Ŀ���ļ����ļ��� 
#define OFFSET		10240		/* ���������ݴ�С */
 	
int main()
{
	int src_file, dest_file;
	unsigned char buff[BUFFER_SIZE];
	int real_read_len;
	char SRC_FILE_NAME[BUFFER_SIZE],DEST_FILE_NAME[BUFFER_SIZE],c;
	printf("input source file name:\n");
	scanf("%s", SRC_FILE_NAME);
	printf("source file name: %s\n", SRC_FILE_NAME);
	scanf("%c",&c);
	printf("input destination file name:\n");
	scanf("%s", DEST_FILE_NAME);
	printf("destination file name: %s\n", DEST_FILE_NAME);
	/* ��ֻ����ʽ��Դ�ļ� */
	src_file = open(SRC_FILE_NAME, O_RDONLY);
	
	/* ��ֻд��ʽ��Ŀ���ļ��������ļ��������򴴽�, ����Ȩ��ֵΪ644 */
	dest_file = open(DEST_FILE_NAME, O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH);
	
	if (src_file < 0 || dest_file < 0)
	{
		printf("Open file error\n");
		exit(1);
	}
	
	/* ��Դ�ļ��Ķ�дָ���Ƶ����10KB����ʼλ��*/
	lseek(src_file, -OFFSET, SEEK_END);
	
	/* ��ȡԴ�ļ������10KB���ݲ�д��Ŀ���ļ��У�ÿ�ζ�д1KB */
	while ((real_read_len = read(src_file, buff, sizeof(buff))) > 0)
	{
		write(dest_file, buff, real_read_len);
	}
	
	close(dest_file);
	close(src_file);
	
	return 0;
	
}
