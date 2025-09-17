# 컴파일러와 플래그 설정
CC = gcc
CFLAGS = -Wall -DLINKTIME
WRAP_FLAGS = -Wl,--wrap,malloc -Wl,--wrap,free

# 타겟 이름
TARGET = intl

# 오브젝트 파일 목록
OBJS = int.o mymalloc.o

# 기본 타겟
all: $(TARGET)

# 링크 단계
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(WRAP_FLAGS) -o $@ $(OBJS)

# mymalloc.o는 LINKTIME 플래그 필요
mymalloc.o: mymalloc.c
	$(CC) -Wall -DLINKTIME -c $<

# int.o는 그냥 컴파일
int.o: int.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o $(TARGET)
