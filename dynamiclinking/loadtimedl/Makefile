# 컴파일러 설정
CC = gcc
CFLAGS = -Og -Wall
PICFLAGS = -fpic
LDFLAGS = -shared

# 파일 이름들
TARGET = prog2l
LIB = libvector.so
OBJS = addvec.o multvec.o
MAIN = main2.o

# 기본 타겟: prog2l 실행파일
all: $(TARGET)

# 공유 라이브러리 생성
$(LIB): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

# 벡터 연산 오브젝트 파일들 (PIC 필요)
addvec.o: addvec.c
	$(CC) $(CFLAGS) $(PICFLAGS) -c $<

multvec.o: multvec.c
	$(CC) $(CFLAGS) $(PICFLAGS) -c $<

# 메인 오브젝트 파일
$(MAIN): main2.c
	$(CC) $(CFLAGS) -c $<

# 최종 실행파일 링크 (동적 라이브러리 링크)
$(TARGET): $(MAIN) $(LIB)
	$(CC) $(CFLAGS) -o $@ $(MAIN) ./$(LIB)

# 정리
clean:
	rm -f *.o $(LIB) $(TARGET)
