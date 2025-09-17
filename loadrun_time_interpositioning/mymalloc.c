#ifdef RUNTIME 
#define _GNU_SOURCE 
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

/* malloc wrapper function */
void *malloc(size_t size)
{
    void *(*mallocp)(size_t size); 
    // 원래 malloc 함수 포인터
    
    char *error;
    
    // RTLD_NEXT를 사용해 다음(원본) malloc의 주소를 얻음
    mallocp = dlsym(RTLD_NEXT, "malloc"); 
    /* Get addr of libc malloc */
    
    // dlsym 에러 체크
    if ((error = dlerror()) != NULL) {
        fputs(error, stderr);
        exit(1);
    }
    // 원래 malloc 호출
    char *ptr = mallocp(size); /* Call libc malloc */
    // 할당 정보 출력
    fprintf(stderr, "malloc(%d) = %p\n", (int)size, ptr);
    return ptr;
}

/* free wrapper function */
void free(void *ptr)
{
    void (*freep)(void *) = NULL; 
    // 원래 free 함수 포인터
    char *error;
    if (!ptr){
        return; // NULL 포인터는 아무 작업도 하지 않음
    }
    
    // RTLD_NEXT를 사용해 다음(원본) free의 주소를 얻음
    freep = dlsym(RTLD_NEXT, "free"); /* Get address of libc free */
    
    // dlsym 에러 체크
    if ((error = dlerror()) != NULL) {
        fputs(error, stderr);
        exit(1);
    }
    // 원래 free 호출
    freep(ptr); /* Call libc free */
    // 해제 정보 출력
    fprintf(stderr, "free(%p)\n", ptr);
}

#endif