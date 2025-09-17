# 컴파일러 및 플래그
CC = gcc
CFLAGS = -Wall -Og
PICFLAGS = -fpic
SHAREDFLAGS = -shared -DRUNTIME
DLFLAGS = -ldl
TARGET = prog2r
LIB = libvector.so
SRC_OBJS = addvec.c multvec.c
MAIN = dll.c

# 기본 타겟
all: $(TARGET)

# 공유 라이브러리 생성
$(LIB): $(SRC_OBJS)
	$(CC) $(CFLAGS) $(SHAREDFLAGS) $(PICFLAGS) -o $@ $(SRC_OBJS)

# 실행파일 (dlopen, dlsym 사용)
$(TARGET): $(MAIN) $(LIB)
	$(CC) -rdynamic -o $@ $(MAIN) $(DLFLAGS)

# 정리
clean:
	rm -f $(TARGET) $(LIB) *.o
